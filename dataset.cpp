#include "dataset.h"
#include <math.h>
#include <bitset>

dataset::dataset(){

}

dataset::dataset(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

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

int dataset::getTop(vector<long int> unsortedList){
    int top = 0;
    for(int n = 0; n+1 < unsortedList.size(); n++){
        if(top < unsortedList[n]){
            top = unsortedList[n];
        }
        else{
            continue;
        }
    }
    return top;
}

int dataset::getBottom(vector<long int> unsortedList){
    int bottom = 0;
    for(int n = 0; n+1 < unsortedList.size(); n++){
        if(bottom > unsortedList[n]){
            bottom = unsortedList[n];
        }
        else{
            continue;
        }
    }
    return bottom;
}

dataset::setPoints(vector<long int> unsortedList, vector<dataset*>& pointList, int spacingWidth, RenderWindow& window){
    WINDOWINFO wiInfo;

    //Gets the position of the window
    GetWindowInfo(window.getSystemHandle(), &wiInfo);

     //Calculates the area the program draws on
    int PosL = wiInfo.rcClient.left;
    int PosR = wiInfo.rcClient.right;
    int PosT = (wiInfo.rcClient.top*1.2);
    int PosB = (wiInfo.rcClient.bottom*0.8);

    //Calculates the drawable distance
    int difX = PosR - PosL;
    int difY = PosB - PosT;

    //Calculates the width of each data point
    int elementWidth = (difX - unsortedList.size()*spacingWidth)/unsortedList.size();

    //Calculates the top and bottom point the program can draw on
    int topPoint = getTop(unsortedList);
    int bottomPoint = getBottom(unsortedList);

    //Creates an object for each data point
    for(int n = 0; n < unsortedList.size(); n++){
        //Calculates the x coordinates for the data points
        int x = spacingWidth + ((spacingWidth + elementWidth)*n);

        //Calculates the height of the pillar based on the top point
        int height = floor(float(difY) * (float(unsortedList[n])/float(topPoint)));

         //Calculates the y coordinates for the data points
        int y = PosB - height;

        //Creates the object
        dataset *point = new dataset(x, y, elementWidth, height);
        pointList.push_back(point);
    }
}



rectangleObj::rectangleObj(int width, int height, Color color, int x, int y){
    this->width = width;
    this->height = height;
    this->color = color;
    this->x = x;
    this->y = y;
}

rectangleObj::bubbleSort(vector<rectangleObj*>& unsortedList, RenderWindow& window, RectangleShape& rec){
    rectangleObj *var = new rectangleObj(0, 0, Color::White, 0, 0);
    bool checker = false;
    bool bonk = true;
    Clock clock;

    //Runs the loop until no changes are made to the array
    while(bonk){
        //unsortedList[0]->color = Color::Red;
        //Loops through the array
        for(int n = 0; (n+1) < unsortedList.size(); n++){
            animate(unsortedList, window, rec);
            while(clock.getElapsedTime().asSeconds() < 0.5f){

            }
            //unsortedList[n+1]->color = Color::Red;
            //Checks if 1 element is larger than the next one
            if(unsortedList[n]->height > unsortedList[n+1]->height){
                //Flips the elements

                var = unsortedList[n+1];

                unsortedList[n+1] = unsortedList[n];

                unsortedList[n] = var;

                checker = true;
            }

            //If element 1 is smaller than or equal to element 2 it continues the loop
            else if(unsortedList[n]->height <= unsortedList[n+1]->height){
                continue;
            }
            else{
                throw runtime_error("Runtime error: Bubble sort failed");
            }
            //unsortedList[n]->color = Color::White;
            clock.restart();
        }
        //If we haven't changed the list, it exits the loop
        if(!checker){
            bonk = false;
        }
        checker = false;
    }
    animate(unsortedList, window, rec);
}

rectangleObj::rectangleObj(){

}

rectangleObj::animate(vector<rectangleObj*>& unsortedList, RenderWindow& window, RectangleShape& rec){
    for(int n = 0; n < unsortedList.size(); n++){
        cout << unsortedList[n]->height << endl;;
        rec.setPosition(unsortedList[n]->x, unsortedList[n]->y);
        rec.setSize(Vector2f(unsortedList[n]->width, unsortedList[n]->height));
        rec.setFillColor(unsortedList[n]->color);
        window.draw(rec);
        window.display();
    }
    cout << "\n" << "\n" << endl;
}
