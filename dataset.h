#ifndef DATASET_H
#define DATASET_H

#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>
<<<<<<< Updated upstream
=======
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <atomic>

using namespace sf;
>>>>>>> Stashed changes
using namespace std;


class dataset
{
    public:
<<<<<<< Updated upstream
=======
        dataset();
        dataset(int x, int y, int width, int height);
        ~dataset();
>>>>>>> Stashed changes
        vector<long int> splitInput(char tempInput[]);
        vector<long int> bubbleSort(vector<long int> unsortedList);
        visDataSet(vector<long int> sortedList, int renderPosL, int renderPosR, int renderPosT, int renderPosB);

<<<<<<< Updated upstream
    protected:

    private:
=======
class rectangleObj{
    public:
        rectangleObj();
        rectangleObj(int width, int height, Color color, int x, int y);
        Color color = Color::White;
        int width, height, x, y = 0;
        animate(vector<rectangleObj*>& unsortedList, RenderWindow& window, RectangleShape& rec, bool accessGate, bool looper);
>>>>>>> Stashed changes
};

void bubbleSort(vector<rectangleObj*>& unsortedList, bool accessGate, bool looper);

#endif // DATASET_H
