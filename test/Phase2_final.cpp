#include "../src/Reader.h"
#include "../src/Records.h"
#include <chrono>
#include <omp.h>


int main() {
	auto startTime = std::chrono::high_resolution_clock::now();
	CSVReader reader = CSVReader("test/csv/Motor_Vehicle_Collisions_-_Crashes_20250219.csv", true);	
	Records records;
	std::vector<std::vector<std::string>> lines;
	std::string currentLine;
    size_t totalLines = 0;
	while((currentLine = reader.readLine()) != "") {
		std::vector<std::string> parsedRecord = (records.parseRecord(currentLine));
		lines.push_back(parsedRecord);
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration<double>(endTime - startTime);
	std::cout << "Read time taken: " << duration.count() << " seconds" <<std::endl;
			#pragma omp parallel
			{ 
					#pragma omp for 
					for (size_t i = 0; i < lines.size(); ++i) {
							{
									#pragma omp critical
									records.addRecord(lines[i]);
							}
					}
			}
	
	auto endTime2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration<double>(endTime2 - endTime);
	std::cout << "Process Time taken: " << duration2.count() << " seconds" << std::endl;
	auto durationTotal = std::chrono::duration<double>(endTime2 - startTime);
	std::cout << "Total Time: " << durationTotal.count() << " seconds" << std::endl;
}
