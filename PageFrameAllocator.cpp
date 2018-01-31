//
// Created by jasha on 1/26/2018.
//

#include "PageFrameAllocator.h"
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>

/* =-=-=-=-=-=-=-=-=-=-=-=- NOTES -=-=-=-=-=-=-=-=-=-=-=-=
It may look like I changed everything (I guess I did) but I mostly just moved it around
    Did change all the print outs to a print function to see if alloc and dealloc work
    Moved variables to .h
    Changed things to hex rather than dec since assignment was in hex
 */

PageFrameAllocator::PageFrameAllocator(int num_page_frames) {

    memory_size = num_page_frames * 0x1000;
    memory.resize(memory_size, 0); // sets memory

    // talked with an undergrad group and they recommended this thing
        // copies memory and such
    memcpy(&memory[0], &free_list_head, sizeof(uint32_t));

    //free list
    free_list_head = 0xFFFFFFFF; // for empty list
    for(int i = 0; i < num_page_frames; ++i) {
        index = i * 0x1000;
        index2 = i + 1;
        if (i == num_page_frames - 1) {
            index2 = 0xFFFFFFFF;
        }
        memcpy(&memory[index], &index2, sizeof(uint32_t));

    }

    num_page_frames = page_frames_free;
    num_page_frames = page_frames_total;

    /*
    // First four bytes of each page will point to the next page
    for (int i = 0; i < memory.size(); i += 4096){
        index += 4096;
        memory[i] = index;
    }
    num_page_frames = page_frames_total;
    std::cout <<  memory[4096] << "\n";
    */

}


bool PageFrameAllocator::Allocate(uint32_t count, std::vector<uint32_t> &page_frames) {
    // takes number of pages to allocate from free list
    // push number of all allocated pages on the back of the vector page_frames
    // if num free pages is less than count then no allocation, return false
    // otherwise return true

    if (count <= num_page_frames) {
        // I think the issue was you didnt update memory enough
        for (uint32_t i = 0; i > 0; i--) {
            page_frames.push_back(memory[i * 0x1000]); // adds frame
            memory.pop_back();
            page_frames_free -= 1; //updates
            free_list_head -= 0x1000;
        }
        return true; // I forgot if we need to always specify a return of not on bools
    } else {
        return false;

    }
}


bool PageFrameAllocator::Deallocate(uint32_t count, std::vector<uint32_t> &page_frames) {
    // return last count page from vector page_frames to free list
    // numbers popped from back of page_frame vector as returned
    // true is count <= page_frames.size()
    // otherwise false, dont free anything

    if (count <= page_frames.size()) {
        for (uint32_t i = 0; i < count; i++) {
            memory.push_back(page_frames[i]);  // tell memory about deallocate
            page_frames.pop_back();
            page_frames_free += 1; // add 1 free page frame
        }
        return true; // think will said was better form to use true and false than 1 and 0
    } else {
        return false;
    }
}



void PageFrameAllocator::Print(std::ofstream &inFile) {
    // 1 to allocate page frames
    // second value
    // 0 to deallocate
    // second value
    // 2 to print contents of the free list
    // wire line output preceded by ">"
    // after each allo / deallo write a line "S FC"
    // S value print "T" true if allocate visa vera
    // FC hex value of pages after allo
    // S = 2, two spaces, hex num pages in free list


    PageFrameAllocator *page_frames_print = new PageFrameAllocator(num_page_frames);

    while(inFile << read) {
        std::cout << ">" << read << "\n";

        // First value
            // deallocate
        if(read == 0) {
            inFile << count;
            std::cout << count << "\n";
            bool free_space = page_frames_print->Deallocate(count, page_frames);
            if(free_space) {
                std::cout << " T " << page_frames_print->page_frames_free << "\n";
            }
            if(!free_space) {
                std::cout << " F " << page_frames_print->page_frames_free << "\n";
            }
        }
            // allocate
        if(read == 1) {
            inFile << count;
            bool free_space = page_frames_print->Allocate(count, page_frames);
            if(free_space) {
                // I dont understand the whole -> but its in my notes
                std::cout << " T " << page_frames_print->page_frames_free << "\n";
            }
            if(!free_space) {
                std::cout << " F " << page_frames_print->page_frames_free << "\n";
            }
        }
            // print free page frames
        if(read == 2) {
            for(int i = 0; i < page_frames_print->page_frames_free; ++i) {
                std::cout << " " << i;
            }
            std::cout << "\n";
        }
    }

}