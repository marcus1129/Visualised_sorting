#include <SFML/Graphics.hpp>
#include "dataset.h"
#include <cstring>

using namespace sf;


RenderWindow window(VideoMode(800,600), "Visualized sorting"/*, Style::Fullscreen*/);
Event event;
vector<int> inputList = {};
string stringInput = "26172 1283 19";

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

                    dataset obj;

                    //Splits the input in to individual indexes
                    inputList = obj.splitInput(input);

                    //Draws a rectangle for each data point
                    obj.visDataSet(inputList);

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
