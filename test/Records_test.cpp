#include "../src/Records.h"

void printStringVector(std::vector<std::string> stringVector);
void testCaseNormal();
void testCaseInnerComma();
void testCaseMissingValues();

int main() {
	testCaseNormal();		
	std::cout << std::endl;
	testCaseInnerComma();
	std::cout << std::endl;
	testCaseMissingValues();
}

void testCaseNormal() {
	Records testRecord = Records();
	std::string input = "1,2,3,4";
	std::vector<std::string> expectedOutput = {"1","2","3","4"}; 
	std::vector<std::string> output = testRecord.parseRecord(input);
	std::cout << "Test Case #1: Normal Inputs" << std::endl;
	std::cout << "Expected: " << std::endl;
	printStringVector(expectedOutput);
	std::cout << "Result: " << std::endl;
	printStringVector(output);
}

void testCaseInnerComma() {
	Records testRecord = Records();
	std::string input = "1,2,3,4,\"5,6\",7";
	std::vector<std::string> expectedOutput = {"1","2","3","4","\"5,6\"","7"}; 
	std::vector<std::string> output = testRecord.parseRecord(input);
	std::cout << "Test Case #2: Inner Comma" << std::endl;
	std::cout << "Expected: " << std::endl;
	printStringVector(expectedOutput);
	std::cout << "Result: " << std::endl;
	printStringVector(output);
}

void testCaseMissingValues() {
	Records testRecord = Records();
	std::string input = ",,,1,";
	std::vector<std::string> expectedOutput = {"","","","1",""}; 
	std::vector<std::string> output = testRecord.parseRecord(input);
	std::cout << "Test Case #3: Missing Values" << std::endl;
	std::cout << "Expected: " << std::endl;
	printStringVector(expectedOutput);
	std::cout << "Result: " << std::endl;
	printStringVector(output);
}

void printStringVector(std::vector<std::string> stringVector) {
	for (std::string element: stringVector) {
		std::cout << element << " ";
	}
		std::cout << std::endl;
}


