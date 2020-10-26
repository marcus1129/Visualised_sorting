#include "dataset.h"
#include <bitset>

vector<int> dataset::splitInput(char input[])
{
    vector<int> tempList;
    string tempString = "";
    int tempInt = 0;
    int n = 0;
    bool bonk = true;

    //Runs a loop until it reaches the end of the c string
    while(bonk){
        //Cycles through each character and ads them to a string if they aren't a space
        if(input[n] != 32){
            tempString.push_back(input[n]);
        }

        //Ads the chars to the string if it is a space
        else if(input[n] == 32){
            tempInt = stoi(tempString);
            tempList.push_back(tempInt);
            tempString = "";
        }

        //Ends the loop if the char array ends
        if(input[n] == 0b00000000){
            tempInt = stoi(tempString);
            tempList.push_back(tempInt);
            tempString = "";
            bonk = false;
        }

        else{
            throw runtime_error("Runtime error: input splitting failed");
        }
        n++;
    }
    return tempList;
}

dataset::visDataSet(vector<int> inputList)
{

}
