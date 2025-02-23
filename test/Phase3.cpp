#include "../src/Reader.h"
#include "../src/RecordVectors.h"
#include <chrono>
#include <omp.h>

const size_t LINE_CHUNK = 200000;

int main() {
	auto startTime = std::chrono::high_resolution_clock::now();
	RecordVectors records;
	CSVReader reader = CSVReader("test/csv/Motor_Vehicle_Collisions_-_Crashes_20250219.csv", true);	
	std::string currentLine;
	std::vector<std::string> chunk;
	chunk.reserve(LINE_CHUNK);
	while(true){
		chunk.clear();
		for (size_t i = 0; i < LINE_CHUNK; ++i) {
				currentLine = reader.readLine();
				if (currentLine.empty()){
						break;
				}
				chunk.push_back(std::move(currentLine));   
		}
		if(chunk.empty()) { break;}
		#pragma omp parallel 
		{
			RecordVectors localRecords;
      #pragma omp for schedule(static, 1000)  
			for (size_t i = 0; i < chunk.size(); ++i) {
					std::vector<std::string> parsedRecord = localRecords.parseRecord(chunk[i]);  
					{
							#pragma omp critical
							records.addRecord(parsedRecord);
					}
       }
		}
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration<double>(endTime - startTime);
	std::cout << "Time taken: " << duration.count() << " seconds" <<std::endl;
}
