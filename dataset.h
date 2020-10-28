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
        dataset(vector<long int> sortedList, int renderPosL, int renderPosR, int renderPosT, int renderPosB, int spacingWidth, int elementWidth);
        vector<long int> splitInput(char tempInput[]);
        vector<long int> bubbleSort(vector<long int> unsortedList);
        visDataSet(vector<long int> sortedList, int renderPosL, int renderPosR, int renderPosT, int renderPosB, int spacingWidth, int elementWidth);

        int left, right, bottom, top = 0;
    protected:

    private:
};

#endif // DATASET_H
