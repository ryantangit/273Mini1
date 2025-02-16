#include <stdexcept>
#include "reader.h"

		CSVReader::CSVReader(std::string filename, bool firstLineHeader=true) {
			this->filename = filename;
			this->firstLineHeader = firstLineHeader;	
		}

		void CSVReader::init() {
			this->filestream.open(this->getFilename());
			if(!this->filestream.is_open()){ 
				throw std::runtime_error("Runtime Exception: Unable to open file: " + this->getFilename());	
			}
		}

		void CSVReader::tearDown() {
			this->filestream.close();
		}

		std::string CSVReader::readLine() {
			std::string line;
			if (getline(this->filestream, line)) {
				return line;	
			} 
			return "";
		}

int main() {
		CSVReader reader = CSVReader("../csv/hello.csv");
		try {
			reader.init();
			std::cout << reader.readLine();
			reader.tearDown();
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			return -1;
		}
}

