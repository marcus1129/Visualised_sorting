#include "dataset.h"
#include <math.h>
#include <bitset>
#include <thread>

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

void bubbleSort(vector<rectangleObj*>& unsortedList, atomic<bool>& accessGate, atomic<bool>& looper){
    int var1 = 0;
    int var2 = 0;

    bool checker = false;
    bool bonk = true;

    //Runs the loop until no changes are made to the array
    while(bonk){
        //Loops through the array
        for(int n = 0; (n+1) < unsortedList.size(); n++){
            if(accessGate){
                if(n > 0){
                    unsortedList[n-1]->color = Color::White;
                }
                unsortedList[unsortedList.size()-1]->color = Color::White;
                unsortedList[unsortedList.size()-2]->color = Color::White;
                unsortedList[n]->color = Color::Red;
                unsortedList[n+1]->color = Color::Red;

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
                else if(unsortedList[n]->height <= unsortedList[n+1]->height){

                }
                else{
                    throw runtime_error("Runtime error: Bubble sort failed");
                }
            }
            else{
                n--;
            }
            accessGate = false;
        }
        //If we haven't changed the list, it exits the loop
        if(!checker){
            while(!accessGate){}
            for(int n = 0; n < unsortedList.size(); n++){
                unsortedList[n]->color = Color::Green;
            }
            accessGate = false;
            bonk = false;
            looper = false;
        }
        checker = false;
    }
}

rectangleObj::rectangleObj(){

}

void mergeS(vector<rectangleObj*>& unsortedList, atomic<bool>& accessGate, atomic<bool>& looper){
    mergeSort *mergeObj = new mergeSort(unsortedList, accessGate, looper);
}

rectangleObj::animate(vector<rectangleObj*>& unsortedList, RenderWindow& window, RectangleShape& rec, atomic<bool>& accessGate, atomic<bool>& looper){
    thread sorting(mergeS, ref(unsortedList), ref(accessGate), ref(looper));


    /*vector<rectangleObj*> copyList = {};
    for(int n = 0; n < unsortedList.size(); n++){
        rectangleObj *recCopy = new rectangleObj(unsortedList[n]->width, unsortedList[n]->height, unsortedList[n]->color, unsortedList[n]->x, unsortedList[n]->y);
        copyList.push_back(recCopy);
    }


    while(looper){
        window.clear();
        if(!accessGate){
            for(int n = 0; n < unsortedList.size(); n++){
                copyList[n] = unsortedList[n];
                accessGate = true;
            }
        }
        for(int i = 0; i < copyList.size(); i++){
            rec.setPosition(copyList[i]->x, copyList[i]->y);
            rec.setSize(Vector2f(copyList[i]->width, copyList[i]->height));
            rec.setFillColor(copyList[i]->color);
            window.draw(rec);
        }
        window.display();
    }
    cout << "Complete" << endl;
    sorting.join();
    for(int n = copyList.size(); n > 0; n--){
        delete copyList[n];
        delete unsortedList[n];
    }*/

    Text text;
    text.setString("Success");
    text.setCharacterSize(30);
    text.setFillColor(Color::Green);
    window.draw(text);
    while(1){
        window.display();
    }
}


mergeSort::mergeSort(){

}

mergeSort::mergeSort(int height, int yVal){
    this->height = height;
    this->yVal = yVal;
}


vector<int> Sort(vector<int> temp1, vector<int> temp2){
    vector<int> sorted{};

    for(int n = 0; n < temp1.size(); n++){
        for(int i = 0; i < temp2.size(); i++){
            if(temp1[n] < temp2[i]){
                sorted.push_back(temp1[n]);
                if(temp1.size() == 1){
                    sorted.insert(end(sorted), begin(temp2), end(temp2));
                    temp2.erase(begin(temp2), end(temp2));
                }
                else{
                    temp1.erase(begin(temp1)+n);
                }
            }


            else if(temp1[n] > temp2[i]){
                sorted.push_back(temp2[i]);
                if(temp2.size() == 1){
                    sorted.insert(end(sorted), begin(temp1), end(temp1));
                    temp1.erase(begin(temp1), end(temp1));
                }
                else{
                    temp2.erase(begin(temp2)+i);
                    i--;
                }
            }

            else if(temp1[n] == temp2[i]){
                sorted.push_back(temp1[n]);
                sorted.push_back(temp2[i]);

                temp1.erase(begin(temp1)+n);
                temp2.erase(begin(temp2)+i);

                i--;
            }
        }

    }

    return sorted;
}


vector<int> split(vector<int> temp1, vector<int> temp2){
    vector<int> newArr1{};
    vector<int> newArr2{};
    vector<int> newArr3{};
    vector<int> newArr4{};

    vector<int> toSort1{};
    vector<int> toSort2{};
    vector<int> toSort3{};
    vector<int> toSort4{};

    vector<int> sorted{};

    for(int n = 0; n < temp1.size(); n++){
        if(n < temp1.size()/2){
            newArr1.push_back(temp1[n]);
        }
        if(n >= temp1.size()/2){
            newArr2.push_back(temp1[n]);
        }
    }

    for(int n = 0; n < temp2.size(); n++){
        if(n < temp2.size()/2){
            newArr3.push_back(temp2[n]);
        }
        if(n >= temp2.size()/2){
            newArr4.push_back(temp2[n]);
        }
    }

    if(newArr1.size() > 1 && newArr2.size() > 1){
        toSort1 = split(newArr1, newArr2);
    }
    if(newArr3.size() > 1 && newArr4.size() > 1){
        toSort2 = split(newArr3, newArr4);
    }

    if(newArr1.size() == 1 && newArr2.size() == 1){
        if(newArr1[0] < newArr2[0]){

            toSort1.push_back(newArr1[0]);
            toSort1.push_back(newArr2[0]);
        }

        else if(newArr1[0] >= newArr2[0]){
            toSort1.push_back(newArr2[0]);
            toSort1.push_back(newArr1[0]);
        }
    }

    if(newArr3.size() == 1 && newArr4.size() == 1){
        if(newArr3[0] < newArr4[0]){
            toSort2.push_back(newArr3[0]);
            toSort2.push_back(newArr4[0]);
        }

        else if(newArr3[0] >= newArr4[0]){
            toSort2.push_back(newArr3[0]);
            toSort2.push_back(newArr4[0]);
        }
    }
    sorted = Sort(toSort1, toSort2);

    return sorted;



}


mergeSort::mergeSort(vector<rectangleObj*>& unsortedList, atomic<bool>& accessGate, atomic<bool>& looper){
    bool bonk = true;

    vector<int> temp1{};
    vector<int> temp2{};
    vector<int> sortedArr{};


    if(accessGate){
        for(int n = 0; n < unsortedList.size(); n++){
            if(n < unsortedList.size()/2){
                temp1.push_back(unsortedList[n]->height);
            }
            else if(n >= unsortedList.size()/2){
                temp2.push_back(unsortedList[n]->height);
            }
        }
    accessGate = false;
    }

    sortedArr = split(temp1, temp2);
    for(int n = 0; n < sortedArr.size(); n++){
        cout << sortedArr[n] << endl;
    }


    /*while(!accessGate){}
    int layer = log2(unsortedList.size());
    int layerSize = unsortedList.size()/pow(2,layer);*/


}

