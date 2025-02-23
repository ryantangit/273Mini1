# mini1 

## Installation
- Download CSV File from https://data.cityofnewyork.us/Public-Safety/Motor-Vehicle-Collisions-Crashes/
- **Bug** on line 1448935 of the csv, there is a record that is disjointed, a manual correction is required to fit the record on a singular line. Failure to do so will result in segfault during parsing.
- move the csv file to ```test/csv```


## Phase 1 Testing
- set-up: make sure in ```test/Phase1.cpp:8```, initialization of CSVReader is pointed at the correct filename.
- To compile the code
``` clang++ -std=c++11 src/Records.cpp src/Reader.cpp test/Phase1.cpp -o phase1 ```
- Run the binary
``` ./phase1 ```

## Phase 2 Testing
- set-up: make sure in ```test/Phase2.cpp:8```, initialization of CSVReader is pointed at the correct filename.
- To compile the code
``` clang++ -std=c++11 -fopen src/Records.cpp src/Reader.cpp test/Phase2.cpp -o phase2 ```
- Run the binary
``` OMP_NUM_THREADS=4 ./phase2 ```


