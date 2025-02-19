#include "Records.h"
/* Perform a sliding window algorithm to parse the recordString
 * Slide window until encountering a comma (,), complete window and append to record. 
 *
 * Edge Cases: 
 * 1. last value needs to be appended to the record
 * 2. when a quotation mark (") is encountered , hold on completeing window until an ending (").
 */
std::vector<std::string> Records::parseRecord(std::string recordString) {
	MotorRecord motorRecord;	
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
}

