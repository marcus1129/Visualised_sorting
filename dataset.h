#ifndef DATASET_H
#define DATASET_H

#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


class dataset
{
    public:
        dataset();
        dataset(int x, int y, int width, int height, int PosB);
        newPoint(vector<long int> sortedList, int renderPosL, int renderPosR, int renderPosT, int renderPosB, int spacingWidth, vector<dataset*>& pointList);
        vector<long int> splitInput(char tempInput[]);
        vector<long int> bubbleSort(vector<long int> unsortedList);
        int left, right, bottom, top, x, y, width, height, PosB = 0;
    protected:

    private:
};

#endif // DATASET_H
