#include <iostream>
#include <fstream>
#include "PageFrameAllocator.h"

// Lab3
// Group 5 - Robert Zachrich / James Shannon

int main(int argc, char** argv) {

    //Test
    /*
    std::vector<uint32_t > pageFrames;
    PageFrameAllocator page(10);
    page.Allocate(2, pageFrames);
    page.Deallocate(1, pageFrames);
    */

    // Input
        std::ofstream inFile;
        std::string file_name = argv[1];
        inFile.open("sample0.txt");
        //inFile.open("sample1.txt");

        // open check
        if(!inFile) {
            std::cerr << "File failed to open" << "\n";
            exit(1);
        }

    // Does all the work
    PageFrameAllocator Print(std::ofstream inFile);


    // Cleans up
    inFile.close();

    return 0;
}
