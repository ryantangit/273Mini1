#include "../src/Reader.h"
#include "../src/Records.h"

int main() {
	CSVReader reader = CSVReader("csv/hello.csv", false);	
	std::string testString = reader.readLine();
	std::cout << testString << std::endl;
	Records records;
	std::vector<std::string> parsedRecord = (records.parseRecord(testString));
	for (const std::string element: parsedRecord) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
	std::cout << parsedRecord.size() << std::endl;
}
