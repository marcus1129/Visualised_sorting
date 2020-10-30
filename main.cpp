#include "dataset.h"
#include <cstring>


RenderWindow window(VideoMode(800,600), "Visualized sorting"/*, Style::Fullscreen*/);
Event event;
string stringInput = "2 8 3 32 12 5 21 4";
vector<long int> inputList = {};
vector<long int> sortedList = {};


//The distance between data points, in pixels
int spacingWidth = 5;

int main()
{
    try{
        while(window.isOpen()){
            while (window.pollEvent(event)){
                if (event.type == Event::Closed){
                    window.close();
                }
                else{
                    /*cout << "Please enter any amount of integer seperated by a space" << endl;
                    //Get an input from the user
                    getline(cin, stringInput);*/

                    //Converts the input to a char
                    char input[stringInput.size()] = "";
                    for(int i = 0; i < sizeof(input); i++) {
                        input[i] = stringInput[i];
                    }

                    dataset *obj = new dataset();

                    //Creates a vector for the data points to be kept in
                    vector<dataset*> points = {};


                    vector<rectangleObj*> rectangleList = {};


                    //Splits the input in to individual indexes
                    inputList = obj->splitInput(input);

                    //Sorts the list according to the bubblesort algorithm
                    obj->setPoints(inputList, points, spacingWidth, window);

                    RectangleShape rec;

                    //Draws a rectangle for each data point
                    for(int n = 0; n < points.size(); n++){
                        rectangleObj *rect = new rectangleObj(points[n]->width, points[n]->height, Color::White, points[n]->x, points[n]->y);
                        rectangleList.push_back(rect);
                    }

                    rectangleObj *obj1 = new rectangleObj();
                    obj1->bubbleSort(rectangleList, window, rec);
                }
            }
        }
        return 0;
    }

    catch(exception& e){
        cerr << e.what() << endl;
    }
}
