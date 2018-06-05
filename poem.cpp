/*
Author: Michelle Chiquitero
Course: CSCI-136
Instructor: Eric
Assignment: Lab 11D

This program keeps a poem in the pointer p pointing to string
and uses new in order to allocate new memmory for the string 
and be able to pass it as an argument and return it as a variable
and then deletes the memory after it's been used 
(from the main function) in order to not run out of memory. 
*/


#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
        delete p;
        p=NULL;

        // assume that the poem p is not needed at this point

    }
}