//
// Created by jasha on 1/30/2018.
//

#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>

bool memAlloc(std::vector<int> &pageFrames, int count){
       for (int i = 0; i < count; i++){
           pageFrames.push_back(i);
       }

        if (&memory.size() < count*4096){

        }
}

int main(){
    std::vector<int> memory;
    std::vector<int> page_frames;
    int pageTotal;
    int pageFree;
    int freeListHead;


    pageTotal = 10*4096; // Ten page frames
    memory.resize(pageTotal);

    return 0;
}