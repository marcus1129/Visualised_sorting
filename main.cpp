#include <SFML/Graphics.hpp>
#include "dataset.h"
#include <cstring>

using namespace sf;


RenderWindow window(VideoMode(800,600), "Visualized sorting"/*, Style::Fullscreen*/);
Event event;
<<<<<<< Updated upstream
WINDOWINFO wiInfo;
=======
string stringInput = "2 8 3 32 12 5 21 4";
bool loop = true;
>>>>>>> Stashed changes
vector<long int> inputList = {};
string stringInput = "";
vector<long int> sortedList = {};
atomic<bool> accessGate{true};
atomic<bool> looper{true};

rectangleObj *obj1 = new rectangleObj();
vector<rectangleObj*> rectangleList{};
RectangleShape rec;

<<<<<<< Updated upstream
=======

//The distance between data points, in pixels
int spacingWidth = 5;


>>>>>>> Stashed changes
int main()
{
    try{
        while(window.isOpen()){
            while (window.pollEvent(event)){
                if(event.type == Event::Closed){
                    window.close();
                }
<<<<<<< Updated upstream
                else{
                    cout << "Please enter any amount of integer seperated by a space" << endl;
                    //Get an input from the user
                    getline(cin, stringInput);

=======
                else if(loop){
>>>>>>> Stashed changes
                    //Converts the input to a char
                    char input[stringInput.size()] = "";
                    for(int i = 0; i < sizeof(input); i++) {
                        input[i] = stringInput[i];
                    }

                    dataset obj;

                    //Splits the input in to individual indexes
                    inputList = obj.splitInput(input);

<<<<<<< Updated upstream
                    //Sorts the list according to the bubblesort algorithm
                    sortedList = obj.bubbleSort(inputList);
                    for(int n = 0; n < sortedList.size(); n++){
                        cout << sortedList[n] << endl;
                    }
=======
                    //vector<rectangleObj*> rectangleList{};
>>>>>>> Stashed changes


                    GetWindowInfo(window.getSystemHandle(), &wiInfo);
                    /*cout << wiInfo.rcClient.right - wiInfo.rcClient.left << endl;
                    cout << wiInfo.rcClient.bottom - wiInfo.rcClient.top << endl;*/


<<<<<<< Updated upstream

                    //Draws a rectangle for each data point
                    obj.visDataSet(sortedList, wiInfo.rcClient.left, wiInfo.rcClient.right, wiInfo.rcClient.top, wiInfo.rcClient.bottom);
                    window.clear();
                    //window.draw(rectangle);
                    window.display();
=======
                    //Creates a rectangle
                    //RectangleShape rec;

                    //Draws a rectangle for each data point
                    for(int n = 0; n < points.size(); n++){
                        rectangleObj *rect = new rectangleObj(points[n]->width, points[n]->height, Color::White, points[n]->x, points[n]->y);
                        rectangleList.push_back(rect);
                    }

                    //rectangleObj *obj1 = new rectangleObj();

                    //Runs the graphics
                    obj1->animate(rectangleList, window, rec, accessGate, looper);

                    delete obj;
                    delete obj1;
                    for(int n = points.size(); n > 0; n--){
                        delete points[n];
                        delete rectangleList[n];
                    }
>>>>>>> Stashed changes
                }
                loop = false;
            }
        }
    }

    catch(exception& e){
        cerr << e.what() << endl;
    }
}
