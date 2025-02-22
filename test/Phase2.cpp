#include "../src/Reader.h"
#include "../src/Records.h"
#include <chrono>
#include <omp.h>

const size_t CHUNK = 100000;

int main() {
	auto startTime = std::chrono::high_resolution_clock::now();
	CSVReader reader = CSVReader("test/csv/Motor_Vehicle_Collisions_-_Crashes_20250210.csv", true);	
	Records records;
    std::vector<std::string> chunk;
    chunk.reserve(CHUNK);
	std::string currentLine;
    size_t totalLines = 0;
	while(true) {
        chunk.clear();
        for (size_t i = 0; i < CHUNK; ++i) {
            currentLine = reader.readLine();
            if (currentLine.empty()){
                break;
            }
            chunk.push_back(std::move(currentLine));   
        }
        if(chunk.empty()) {
            break;
        }
        #pragma omp parallel
        {
            Records localRecords;
            // Dynamic: (https://610yilingliu.github.io/2020/07/15/ScheduleinOpenMP/)
            //    Split task into iter_size/chunk_size chunks, but distribute trunks to threads dynamically without any specific order.
            //    Dynamic gives most efficiency 
            #pragma omp for schedule(dynamic, 1000)  
            for (size_t i = 0; i < chunk.size(); ++i) {
                std::vector<std::string> parsedRecord = localRecords.parseRecord(chunk[i]);  
                #pragma omp critical //critical region to avoid race condition -> one resource access at a time
                {
                    records.addRecord(parsedRecord);
                    totalLines++;
                    // Printing increases time --> decreases efficiency
                    // std::cout << "Processed " << totalLines << " lines" << std::endl;
                }
            }
        }
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration<double>(endTime - startTime);
	std::cout << "Time taken: " << duration.count() << " seconds" <<std::endl;
}