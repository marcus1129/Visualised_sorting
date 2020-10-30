#ifndef DATASET_H
#define DATASET_H

#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>

using namespace sf;
using namespace std;


class dataset
{
    public:
        dataset();
        dataset(int x, int y, int width, int height);
        vector<long int> splitInput(char tempInput[]);
        setPoints(vector<long int> unsortedList, vector<dataset*>& pointList, int spacingWidth, RenderWindow& window);
        int left, right, bottom, top, x, y, width, height, PosB = 0;
    protected:

    private:
        int getTop(vector<long int> unsortedList);
        int getBottom(vector<long int> unsortedList);
};


class rectangleObj{
    public:
        rectangleObj();
        rectangleObj(int width, int height, Color color, int x, int y);
        bubbleSort(vector<rectangleObj*>& unsortedList, RenderWindow& window, RectangleShape& rec);
        Color color = Color::White;
        int width, height, x, y = 0;

    private:
        animate(vector<rectangleObj*>& unsortedList, RenderWindow& window, RectangleShape& rec);
};

#endif // DATASET_H
