#include "dataset.h"
#include <cstring>
#include <iostream>
#include <functional>
#include "speed.h"

using namespace std;

Event event;
speed test_obj;
Text text;
sf::Clock clock1;
string stringInput = "2 8 3 32 12 5 21 4 213 32 2 523 2 123 52 423 129 48 236 27 378 26 135 237 5 43 21";
string testStringInput;
vector<long int> inputList = {};
vector<long int> testInputList = {};
vector<long int> sortedList = {};


//The distance between data points, in pixels
int spacingWidth = 5;

int main()
{
    try{
        for(int n = 1; n < 3643; n++){
            testStringInput += to_string(n%4+1);
            testStringInput += " ";
        }
        testStringInput += to_string(5);
        atomic<bool> looper{true};
        atomic<bool> accessGate{true};
        RenderWindow window(VideoMode(400,600), "Visualized sorting"/*, Style::Fullscreen*/);
        window.setFramerateLimit(60);
        while(window.isOpen()){
            while (window.pollEvent(event)){
                if (event.type == Event::Closed){
                    window.close();
                }
                else{

                    //Converts the input to a char
                    char input[stringInput.size()] = "";
                    for(int i = 0; i < sizeof(input); i++) {
                        input[i] = stringInput[i];
                    }
                    char testInput[testStringInput.size()] = "";
                    for(int i = 0; i < sizeof(testInput); i++) {
                        testInput[i] = testStringInput[i];
                    }

                    dataset *obj = new dataset();

                    //Creates a vector for the data points to be kept in
                    vector<dataset*> points = {};
                    vector<dataset*> testPoints = {};

                    vector<rectangleObj*> rectangleList = {};
                    vector<rectangleObj*> testRectangleList = {};


                    //Splits the input in to individual indexes
                    inputList = obj->splitInput(input);
                    testInputList = obj->splitInput(testInput);

                    obj->setPoints(inputList, points, spacingWidth, window);
                    obj->setPoints(testInputList, testPoints, spacingWidth, window);

                    //Creates a rectangle
                    RectangleShape rec;

                    //Draws a rectangle for each data point
                    for(int n = 0; n < points.size(); n++){
                        rectangleObj *rect = new rectangleObj(points[n]->width, points[n]->height, Color::White, points[n]->x, points[n]->y);
                        rectangleList.push_back(rect);
                    }


                    for(int n = 0; n < testPoints.size(); n++){
                        rectangleObj *testRect = new rectangleObj(testPoints[n]->width, testPoints[n]->height, Color::White, testPoints[n]->x, testPoints[n]->y);
                        testRectangleList.push_back(testRect);
                    }



                    //Sorts the array
                    clock1.restart();
                    test_obj.bubble_test(testRectangleList);
                    cout << "Bubble sort took " << clock1.getElapsedTime().asMilliseconds() << " milliseconds to sort " << testRectangleList.size() << " elements" << endl;


                    rectangleObj *obj1 = new rectangleObj();
                    obj1->animate(rectangleList, window, rec, accessGate, looper);

                    text.setString("Success");
                    text.setCharacterSize(30);
                    text.setFillColor(Color::Green);
                    window.draw(text);
                    window.clear();
                    while(!GetKeyState(32) & 0x8000){
                        window.display();
                    }
                    for(int n = rectangleList.size(); n > 0; n--){
                        delete rectangleList[n];
                    }
                    delete obj1;
                    delete obj;
                }
            }
        }
        return 0;
    }

    catch(exception& e){
        cerr << e.what() << endl;
    }
}
