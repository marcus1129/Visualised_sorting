#include "speed.h"
#include <SFML/Graphics.hpp>

speed::speed()
{
    //ctor
}

void speed::bubble_test(vector<rectangleObj*>& temp){
    int var1 = 0;
    int var2 = 0;


    bool checker = false;
    bool bonk = true;

    while(bonk){
        //Loops through the array
        for(int n = 0; (n+1) < temp.size(); n++){
            //Checks if 1 element is larger than the next one
            if(temp[n]->height > temp[n+1]->height){
                //Flips the elements
                var1 = temp[n+1]->height;

                temp[n+1]->height = temp[n]->height;

                temp[n]->height = var1;

                checker = true;
            }
        }
        //If we haven't changed the list, it exits the loop
        if(!checker){
            bonk = false;
        }
        checker = false;
    }
}
