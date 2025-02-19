#include "Records.h"
/* Perform a sliding window algorithm to parse the recordString
 * Slide window until encountering a comma (,), complete window and append to record. 
 *
 * Edge Cases: 
 * 1. last value needs to be appended to the record
 * 2. when a quotation mark (") is encountered , hold on completeing window until an ending (").
 */
std::vector<std::string> Records::parseRecord(std::string recordString) {
	std::vector<std::string> recordAttributes;
	std::string attribute = "";

	int startIndex = 0;
	bool quotationFlag = false;
	for (int currentIndex = 0; currentIndex < recordString.length(); currentIndex++) {
		//End of Quotation
		if (recordString[currentIndex] == '"' && quotationFlag) {
			quotationFlag = false;
		//Start of Quotation
		} else if (recordString[currentIndex] == '"') {
			quotationFlag = true;
		//Comma Encounter
		} else if (!quotationFlag && recordString[currentIndex] == ',') {
			attribute = recordString.substr(startIndex, currentIndex - startIndex);
			recordAttributes.push_back(attribute);
			startIndex = currentIndex + 1;
		}
	}
	//last Attribute
	recordAttributes.push_back(recordString.substr(startIndex, recordString.length() - startIndex + 1));
	return recordAttributes;
};


void intAttribute(int* recordValue, std::string attribute) {
	int missingInt = -1;
	try {
		*recordValue = std::stoi(attribute);
	} catch(const std::invalid_argument& e) {
		*recordValue = missingInt;
	}
}

void dblAttribute(double* recordValue, std::string attribute) {
	double missingDbl = -1.0;
	try {
		*recordValue = std::stod(attribute);
	} catch(const std::invalid_argument& e) {
		*recordValue = missingDbl;
	}
}

void Records::addRecord(std::vector<std::string> recordAttributes) {
	MotorRecord motorRecord;	
	motorRecord.crashDate = recordAttributes[0];
	motorRecord.crashTime = recordAttributes[1];
	motorRecord.borough = recordAttributes[2];
	intAttribute(&motorRecord.zipCode, recordAttributes[3]);	
	dblAttribute(&motorRecord.latitude, recordAttributes[4]);
	dblAttribute(&motorRecord.longitude, recordAttributes[4]);
	motorRecord.location = recordAttributes[6];
	motorRecord.onStreeName = recordAttributes[7];
	motorRecord.crossStreetName = recordAttributes[8];
	motorRecord.offStreetName = recordAttributes[9];
	intAttribute(&motorRecord.numberOfPersonInjured, recordAttributes[10]);
	intAttribute(&motorRecord.numberOfPersonKilled, recordAttributes[11]);
	intAttribute(&motorRecord.numberOfPedestrianInjured, recordAttributes[12]);
	intAttribute(&motorRecord.numberOfPedestrianKilled, recordAttributes[13]);
	intAttribute(&motorRecord.numberOfCyclistInjured, recordAttributes[14]);
	intAttribute(&motorRecord.numberOfCyclistKilled, recordAttributes[15]);
	intAttribute(&motorRecord.numberOfMotoristInjured, recordAttributes[16]);
	intAttribute(&motorRecord.numberOfMotoristKilled, recordAttributes[17]);
	motorRecord.contributingFactorVehicle1 = recordAttributes[18];
	motorRecord.contributingFactorVehicle2 = recordAttributes[19];
	motorRecord.contributingFactorVehicle3 = recordAttributes[20];
	motorRecord.contributingFactorVehicle4 = recordAttributes[21];
	motorRecord.contributingFactorVehicle5 = recordAttributes[22];
	intAttribute(&motorRecord.collisonId, recordAttributes[23]);
	motorRecord.vehicleTypeCode1 = recordAttributes[24];
	motorRecord.vehicleTypeCode2 = recordAttributes[25];
	motorRecord.vehicleTypeCode3 = recordAttributes[26];
	motorRecord.vehicleTypeCode4 = recordAttributes[27];
	motorRecord.vehicleTypeCode5 = recordAttributes[28];
	records.push_back(motorRecord);
		
}
