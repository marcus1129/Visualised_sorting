#include <SFML/Graphics.hpp>
#include "dataset.h"
#include <cstring>

using namespace sf;


RenderWindow window(VideoMode(800,600), "Visualized sorting"/*, Style::Fullscreen*/);
Event event;
WINDOWINFO wiInfo;
vector<long int> inputList = {};
string stringInput = "";
vector<long int> sortedList = {};

int main()
{
    try{
        while(window.isOpen()){
            while (window.pollEvent(event)){
                if (event.type == Event::Closed){
                    window.close();
                }
                else{
                    cout << "Please enter any amount of integer seperated by a space" << endl;
                    //Get an input from the user
                    getline(cin, stringInput);

                    //Converts the input to a char
                    char input[stringInput.size()] = "";
                    for(int i = 0; i < sizeof(input); i++) {
                        input[i] = stringInput[i];
                    }

                    dataset obj;

                    //Splits the input in to individual indexes
                    inputList = obj.splitInput(input);

                    //Sorts the list according to the bubblesort algorithm
                    sortedList = obj.bubbleSort(inputList);
                    for(int n = 0; n < sortedList.size(); n++){
                        cout << sortedList[n] << endl;
                    }


                    GetWindowInfo(window.getSystemHandle(), &wiInfo);
                    /*cout << wiInfo.rcClient.right - wiInfo.rcClient.left << endl;
                    cout << wiInfo.rcClient.bottom - wiInfo.rcClient.top << endl;*/



                    //Draws a rectangle for each data point
                    obj.visDataSet(sortedList, wiInfo.rcClient.left, wiInfo.rcClient.right, wiInfo.rcClient.top, wiInfo.rcClient.bottom);
                    window.clear();
                    //window.draw(rectangle);
                    window.display();
                }
            }
        }
    }

    catch(exception& e){
        cerr << e.what() << endl;
    }
}
