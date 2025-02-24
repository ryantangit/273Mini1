#include "../src/Reader.h"
#include "../src/Records.h"
#include <chrono>



int main() {
	auto startTime = std::chrono::high_resolution_clock::now();
	CSVReader reader = CSVReader("test/csv/Motor_Vehicle_Collisions_-_Crashes_20250219.csv", true);	
	Records records;
	std::string currentLine;
	std::vector<std::vector<std::string>> lines;
	int i = 2;
	while((currentLine = reader.readLine()) != "") {
		std::vector<std::string> parsedRecord = (records.parseRecord(currentLine));
		lines.push_back(parsedRecord);
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration<double>(endTime - startTime);
	std::cout << "Time taken to read: " << duration.count() << " seconds" <<std::endl;


	for (int i = 0; i < lines.size(); i++) {
		records.addRecord(lines[i]);
	}
	auto endTime2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration<double>(endTime2 - endTime);
	auto totalTime = std::chrono::duration<double>(endTime2 - startTime);
	std::cout << "Time taken to process: " << duration2.count() << " seconds" << std::endl;
	std::cout << "Total Time: " << totalTime.count() << " second" << std::endl;
}
