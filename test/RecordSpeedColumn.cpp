#include "../src/Reader.h"
#include "../src/Records.h"
#include <chrono>
#include <vector>

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
	std::cout << "Read time taken: " << duration.count() << " seconds" <<std::endl;

	size_t totalColumns = 29;
	std::vector<std::vector<std::string>> recordVector;
	std::vector<std::string> attribute1;
	recordVector.push_back(attribute1);
	std::vector<std::string> attribute2;
	recordVector.push_back(attribute2);
	std::vector<std::string> attribute3;
	recordVector.push_back(attribute3);
	std::vector<std::string> attribute4;
	recordVector.push_back(attribute4);
	std::vector<std::string> attribute5;
	recordVector.push_back(attribute5);
	std::vector<std::string> attribute6;
	recordVector.push_back(attribute6);
	std::vector<std::string> attribute7;
	recordVector.push_back(attribute7);
	std::vector<std::string> attribute8;
	recordVector.push_back(attribute8);
	std::vector<std::string> attribute9;
	recordVector.push_back(attribute9);
	std::vector<std::string> attribute10;
	recordVector.push_back(attribute10);
	std::vector<std::string> attribute11;
	recordVector.push_back(attribute11);
	std::vector<std::string> attribute12;
	recordVector.push_back(attribute12);
	std::vector<std::string> attribute13;
	recordVector.push_back(attribute13);
	std::vector<std::string> attribute14;
	recordVector.push_back(attribute14);
	std::vector<std::string> attribute15;
	recordVector.push_back(attribute15);
	std::vector<std::string> attribute16;
	recordVector.push_back(attribute16);
	std::vector<std::string> attribute17;
	recordVector.push_back(attribute17);
	std::vector<std::string> attribute18;
	recordVector.push_back(attribute18);
	std::vector<std::string> attribute19;
	recordVector.push_back(attribute19);
	std::vector<std::string> attribute20;
	recordVector.push_back(attribute20);
	std::vector<std::string> attribute21;
	recordVector.push_back(attribute21);
	std::vector<std::string> attribute22;
	recordVector.push_back(attribute22);
	std::vector<std::string> attribute23;
	recordVector.push_back(attribute23);
	std::vector<std::string> attribute24;
	recordVector.push_back(attribute24);
	std::vector<std::string> attribute25;
	recordVector.push_back(attribute25);
	std::vector<std::string> attribute26;
	recordVector.push_back(attribute26);
	std::vector<std::string> attribute27;
	recordVector.push_back(attribute27);
	std::vector<std::string> attribute28;
	recordVector.push_back(attribute28);
	std::vector<std::string> attribute29;
	recordVector.push_back(attribute29);

	//For each row of record, process the attributes.
	//
	#pragma omp parallel for

	for (int j = 0; j < totalColumns; j++) {
		for (int i = 0; i < lines.size(); i++){
			recordVector[j].push_back(lines[i][j]);
		}
	} 

	auto endTime2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration<double>(endTime2 - startTime);
	auto processDuration = std::chrono::duration<double>(endTime2 - endTime);
	std::cout << "Row processing time: " << processDuration.count() << " seconds" << std::endl;
	std::cout << "Total Time taken: " << duration2.count() << " seconds" << std::endl;
}
