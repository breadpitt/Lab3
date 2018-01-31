#include <iostream>
#include <fstream>
#include "PageFrameAllocator.h"

// Lab3
// Group 5 - Robert Zachrich / James Shannon

int main(int argc, char** argv) {

    // Input
        std::fstream inFile;
        std::string file_name = argv[1];
        inFile.open(file_name);
        //inFile.open("sample1.txt");

        // Variables to for the first line of the file
        std::vector<uint32_t> first_vector;
        std::string first_line;
        uint32_t first_value;
        // open check
        if(!inFile) {
            std::cerr << "File failed to open" << "\n";
            exit(1);
        }

        // Reads the first line of the file and make it the number of page frames for the
        // PageFrameAllocatorMemory object
        std::getline(inFile, first_line);
        std::istringstream first_stream(first_line);
        first_stream >> std::hex >> first_value;

       PageFrameAllocator virtualMemory(first_value);

    // Cleans up
    inFile.close();

    return 0;
}
