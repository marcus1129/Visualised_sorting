#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(800,600), "Visualized sorting"/*, Style::Fullscreen*/);
Event event;
vector<int> inputList = {};
string tempInput = "";

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
                    cin >> tempInput;

                    dataset obj;
                    //Splits the input in to individual indexes
                    inputList = obj.splitInput(tempInput);

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
