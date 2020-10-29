#include <SFML/Graphics.hpp>
#include "dataset.h"
#include <cstring>

using namespace sf;


RenderWindow window(VideoMode(800,600), "Visualized sorting"/*, Style::Fullscreen*/);
Event event;
WINDOWINFO wiInfo;
string stringInput = "2 332 551 22 4123 552 2483 273 213 42 33 521 23 2 543 283";
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


                    //Splits the input in to individual indexes
                    inputList = obj->splitInput(input);

                    //Sorts the list according to the bubblesort algorithm
                    sortedList = obj->bubbleSort(inputList);

                    //Gets the position of the window
                    GetWindowInfo(window.getSystemHandle(), &wiInfo);

                    //Draws a rectangle for each data point
                    for(int n = 0; n < sortedList.size(); n++){
                        obj->newPoint(sortedList, wiInfo.rcClient.left, wiInfo.rcClient.right, wiInfo.rcClient.top, wiInfo.rcClient.bottom, spacingWidth, points);
                    }

                    window.clear();
                    for(int n = 0; n < points.size(); n++){
                        RectangleShape rectangle;
                        rectangle.setSize(Vector2f(points[n]->width, points[n]->height));
                        rectangle.setFillColor(Color::White);
                        rectangle.setPosition(points[n]->x, points[n]->PosB - points[n]->height);
                        window.draw(rectangle);
                    }
                    window.display();
                }
            }
        }
    }

    catch(exception& e){
        cerr << e.what() << endl;
    }
}
