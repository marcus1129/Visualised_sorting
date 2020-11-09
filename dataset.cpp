#include "dataset.h"
#include <bitset>
#include <thread>

<<<<<<< Updated upstream
=======
dataset::dataset(){

}

dataset::dataset(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

dataset::~dataset(){

}

>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
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
=======
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

void bubbleSort(vector<rectangleObj*>& unsortedList, bool accessGate, bool looper){
    int var1 = 0;
    int var2 = 0;

    bool checker = false;
    bool bonk = true;

    if(accessGate){
        //Runs the loop until no changes are made to the array
        while(bonk){
            //Loops through the array
            for(int n = 0; (n+1) < unsortedList.size(); n++){
                unsortedList[n]->color = Color::Red;
                unsortedList[n+1]->color = Color::Red;

                //Draws the sorting in a window
                //animate(unsortedList, window, rec);

                unsortedList[n]->color = Color::White;
                unsortedList[n+1]->color = Color::White;

                //Half a second delay
                Sleep(150);

                //Checks if 1 element is larger than the next one
                if(unsortedList[n]->height > unsortedList[n+1]->height){
                    //Flips the elements
                    var1 = unsortedList[n+1]->height;
                    var2 = unsortedList[n+1]->y;

                    unsortedList[n+1]->height = unsortedList[n]->height;
                    unsortedList[n+1]->y = unsortedList[n]->y;

                    unsortedList[n]->height = var1;
                    unsortedList[n]->y = var2;

                    checker = true;
                }

                //If element 1 is smaller than or equal to element 2 it continues the loop
                if(unsortedList[n]->height <= unsortedList[n+1]->height){
                    continue;
                }
                else{
                    throw runtime_error("Runtime error: Bubble sort failed");
                }
                //clock.restart();
            }
            //If we haven't changed the list, it exits the loop
            if(!checker){
                bonk = false;
            }
            checker = false;
>>>>>>> Stashed changes
        }
        accessGate = false;
    }
<<<<<<< Updated upstream
    return unsortedList;
}

dataset::visDataSet(vector<long int> sortedList, int renderPosL, int renderPosR, int renderPosT, int renderPosB)
{
    //cout << "renderPosL: " << renderPosL << endl;
=======
    //animate(unsortedList, window, rec);
}

rectangleObj::rectangleObj(){

}

void test(vector<rectangleObj*>& unsortedList/*, RenderWindow& window, RectangleShape& rec, bool accessGate, bool looper*/){
    cout << "test" << endl;
}

rectangleObj::animate(vector<rectangleObj*>& unsortedList, RenderWindow& window, RectangleShape& rec, bool accessGate, bool looper){
    //Sorts the array in a separate thread
    thread sorting(bubbleSort, ref(unsortedList), accessGate, looper);

    while(looper){
        if(accessGate){
            window.clear();

            //Draws a square for each element
            for(int n = 0; n < unsortedList.size(); n++){
                cout << "Height: " << unsortedList[n]->height << "\t" << "X: " << unsortedList[n]->x << "\t" << "Y: " << unsortedList[n]->y << endl;;
                rec.setPosition(unsortedList[n]->x, unsortedList[n]->y);
                rec.setSize(Vector2f(unsortedList[n]->width, unsortedList[n]->height));
                rec.setFillColor(unsortedList[n]->color);
                window.draw(rec);
            }
            window.display();
        }
    }
    sorting.join();
    cout << "\n" << "\n" << endl;
>>>>>>> Stashed changes
}
