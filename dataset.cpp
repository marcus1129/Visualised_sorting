#include "dataset.h"
#include <bitset>

vector<long int> dataset::splitInput(char input[])
{
    vector<long int> tempList = {};
    string tempString = "";
    long int tempInt = 0;
    int n = 0;
    bool bonk = true;

    //Runs a loop until it reaches the end of the c string
    while(bonk){
        //Cycles through each character and ads them to a string if they aren't a space
        if(input[n] != 32){
            if(input[n] == 0b00000000){
                tempInt = stoi(tempString);
                tempList.push_back(tempInt);
                tempString = "";
                bonk = false;
            }
            else{
                tempString.push_back(input[n]);
            }
        }
       //Ads the chars to the string if it is a space
        else if(input[n] == 32){
            tempInt = stoi(tempString);
            tempList.push_back(tempInt);
            tempString = "";
        }
        //Ends the loop if the char array ends
        else{
            throw runtime_error("Runtime error: input splitting failed");
        }
        n++;
    }
    return tempList;
}

vector<long int> dataset::bubbleSort(vector<long int> unsortedList){
    int var = 0;
    bool checker = false;
    bool bonk = true;

    //Runs the loop until no changes are made to the array
    while(bonk){
        //Loops through the array
        for(int n = 0; n+1 < unsortedList.size(); n++){
            //Checks if 1 element is larger than the next one
            if(unsortedList[n] > unsortedList[n+1]){
                //Flips the elements
                var = unsortedList[n+1];
                unsortedList[n+1] = unsortedList[n];
                unsortedList[n] = var;

                checker = true;
            }
            //If element 1 is smaller than or equal to element 2 it continues the loop
            else if(unsortedList[n] <= unsortedList[n+1]){
                continue;
            }
            else{
                throw runtime_error("Runtime error: Bubble sort failed");
            }
        }
        //If we haven't changed the list, it exits the loop
        if(!checker){
            bonk = false;
        }
        checker = false;
    }
    return unsortedList;
}

dataset::visDataSet(vector<long int> sortedList, int renderPosL, int renderPosR, int renderPosT, int renderPosB)
{
    //cout << "renderPosL: " << renderPosL << endl;
}
