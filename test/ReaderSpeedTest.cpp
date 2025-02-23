#include "../src/Reader.h"
#include "../src/Records.h"
#include <chrono>
#include <vector>

// TESTING HOW LONG IT TAKES TO READ THE CSV FILE AND UPLOAD ALL RECORDS INTO A VECTOR
int main() {
	auto startTime = std::chrono::high_resolution_clock::now();
	CSVReader reader = CSVReader("test/csv/Motor_Vehicle_Collisions_-_Crashes_20250219.csv", true);	
	Records records;
	std::cout << "Total time to read and push records" << std::endl;
	std::vector<std::vector<std::string>> lines;
	std::string currentLine;
	while((currentLine = reader.readLine()) != "") {
		std::vector<std::string> parsedRecord = (records.parseRecord(currentLine));
		lines.push_back(parsedRecord);
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration<double>(endTime - startTime);
	std::cout << "Time taken: " << duration.count() << " seconds" <<std::endl;
}
