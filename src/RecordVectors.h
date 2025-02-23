#ifndef RECORDSVECTORS_H 
#define RECORDSVECTORS_H

#include <iostream>
#include <vector>
#include "MotorRecordVector.h"

class RecordVectors{
	private:
		MotorRecordVector records;
	public:
		std::vector<std::string> parseRecord(std::string recordString);
		void addRecord(std::vector<std::string> recordAttributes);
};

#endif
