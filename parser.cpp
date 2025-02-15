#include <iostream>
#include <fstream>
#include <stdexcept>

class CSVParser {
	private:
		std::string filename;
		bool firstLineHeader;
		std::fstream filestream;
	public:
		CSVParser(std::string filename, bool firstLineHeader=true) {
			this->filename = filename;
			this->firstLineHeader = firstLineHeader;	
		}

		void init() {
			this->filestream.open(this->getFilename());
			if(!this->filestream.is_open()){ 
				throw std::runtime_error("Runtime Exception: Unable to open file: " + this->getFilename());	
			}
		}

		void tearDown() {
			this->filestream.close();
		}

		void readLine() {
			std::string line;
			while(getline(this->filestream, line)) {
					std::cout << line << std::endl;
				}
		}
		

		// Setters and Getters
		void setFilename(std::string filename){
			this->filename = filename;	
		}
		std::string getFilename(){
			return this->filename;
		}
		void setFirstLineHeader(bool firstLineHeader) {
			this->firstLineHeader = firstLineHeader;
		}
		bool getFirstLineHeader(){
			return this->firstLineHeader;
		}
		

};

int main() {
		CSVParser parser = CSVParser("hello.csv");
		try {
			parser.init();
			parser.readLine();
			parser.tearDown();
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			return -1;
		}
}

