#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;


class dataset
{
    public:
        vector<long int> splitInput(char tempInput[]);
        visDataSet(vector<long int> inputList);
        vector<long int> bubbleSort(vector<long int> unsortedList);

    protected:

    private:
};

#endif // DATASET_H
