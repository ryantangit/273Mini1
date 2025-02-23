#include "../src/Reader.h"
#include "../src/RecordVectors.h"
#include <chrono>

int main() {
	RecordVectors records;
	auto startTime = std::chrono::high_resolution_clock::now();
	CSVReader reader = CSVReader("test/csv/Motor_Vehicle_Collisions_-_Crashes_20250219.csv", true);	
	std::string currentLine;
	int i = 2;
	while((currentLine = reader.readLine()) != "") {
		std::vector<std::string> parsedRecord = (records.parseRecord(currentLine));
		records.addRecord(parsedRecord);
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration<double>(endTime - startTime);
	std::cout << "Time taken: " << duration.count() << " seconds" <<std::endl;
}
