/**
* Title: Algorithm analysis & Sorting
* Author : İlhami Uluğtürkkan
* ID: 22102546
* Section : 002
* Homework : 1
* Description : H Class
*/
#include <iostream>
using namespace std;
class Sorting
{
public:
    void insertionSort(int*arr,const int size,int &compCount,int &moveCount);
    void bubleSort(int*arr,const int size,int &compCount,int &moveCount);
    void mergeSort(int*arr,const int size,int &compCount,int &moveCount);
    void quickSort(int*arr,const int size,int &compCount,int &moveCount);
    void hybridSort(int*arr,const int size,int &compCount,int &moveCount);
};