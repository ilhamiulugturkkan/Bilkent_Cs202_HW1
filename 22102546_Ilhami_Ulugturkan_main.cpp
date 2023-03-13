/**
* Title: Algorithm analysis & Sorting
* Author : İlhami Uluğtürkkan
* ID: 22102546
* Section : 002
* Homework : 1
* Description : Main Class
*/

#include <iostream>
#include <chrono>
#include <cmath>
#include "22102546_Ilhami_Ulugturkkan.h"
using namespace std::chrono;
int main()
{
    cout << "***************************************************************" << endl;
    cout << "Part 2-b-1: Performance analysis of random integers array" << endl<<endl;
    for (int o = 0; o < 4; o++)
    {
        int moveCount = 0;
        int moveCount1 = 0;
        int compCount = 0;
        int compCount1 = 0;
        int moveCount2 = 0;
        int moveCount3 = 0;
        int compCount2 = 0;
        int compCount3 = 0;
        int moveCount4 = 0;
        int compCount4 = 0;
        int size;
        switch (o)
        {
        case 0:
            size = 1000;
            break;
        case 1:
            size = 5000;
            break;
        case 2:
            size = 10000;
            break;
        case 3:
            size = 20000;
            break;
        default:
            size = 1000;
            break;
        }
        int *arr0 = new int[size];
        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];
        int *arr4 = new int[size];
        for (int i = 0; i < size; i++)
        {
            int k = rand();
            arr0[i] = k;
            arr1[i] = k;
            arr2[i] = k;
            arr3[i] = k;
            arr4[i] = k;
        }

        Sorting aga;
        auto beg = high_resolution_clock::now();
        aga.insertionSort(arr0, size, compCount, moveCount);
        // Taking a timestamp after the code is ran
        auto end = high_resolution_clock::now();
        auto insertionDuration = duration_cast<microseconds>(end - beg);

        auto beg1 = high_resolution_clock::now();
        aga.bubleSort(arr1, size, compCount1, moveCount1);
        auto end1 = high_resolution_clock::now();
        auto bubleDuration = duration_cast<microseconds>(end1 - beg1);

        auto beg2 = high_resolution_clock::now();
        aga.mergeSort(arr2, size, compCount2, moveCount2);
        auto end2 = high_resolution_clock::now();
        auto mergeDuration = duration_cast<microseconds>(end2 - beg2);

        auto beg3 = high_resolution_clock::now();
        aga.quickSort(arr3, size, compCount3, moveCount3);
        auto end3 = high_resolution_clock::now();
        auto quickDuration = duration_cast<microseconds>(end3 - beg3);

        auto beg4 = high_resolution_clock::now();
        aga.hybridSort(arr4, size, compCount4, moveCount4);
        auto end4 = high_resolution_clock::now();
        auto hybridDuration = duration_cast<microseconds>(end4 - beg4);

        printf("%-25s%-20s%-20s%-20s\n", "", "Elpased Time", "Comp. Count", "Move Count");
        cout << "Array Size: " << size << endl;
        printf("%-25s%-20i%-20i%-20i\n", "Insertion Sort: ", insertionDuration.count(), compCount, moveCount);
        printf("%-25s%-20i%-20i%-20i\n", "Bubble Sort: ", bubleDuration.count(), compCount1, moveCount1);
        printf("%-25s%-20i%-20i%-20i\n", "Merge Sort: ", mergeDuration.count(), compCount2, moveCount2);
        printf("%-25s%-20i%-20i%-20i\n", "QuickSort: ", quickDuration.count(), compCount3, moveCount3);
        printf("%-25s%-20i%-20i%-20i\n", "Hybrid Sort: ", hybridDuration.count(), compCount4, moveCount4);
        cout << "---------------------------------------------------------------------" << endl;
        delete arr0;
        delete arr1;
        delete arr2;
        delete arr3;
        delete arr4;
    }
    cout << "********************************************************************" << endl;
    cout << "Part 2-b-2: Performance analysis of partially ascending integers array" << endl<<endl;
    for (int o = 0; o < 4; o++)
    {
        int moveCount = 0;
        int compCount = 0;
        int moveCount1 = 0;
        int compCount1 = 0;
        int moveCount2 = 0;
        int compCount2 = 0;
        int moveCount3 = 0;
        int compCount3 = 0;
        int moveCount4 = 0;
        int compCount4 = 0;
        int size;
        switch (o)
        {
        case 0:
            size = 1000;
            break;
        case 1:
            size = 5000;
            break;
        case 2:
            size = 10000;
            break;
        case 3:
            size = 20000;
            break;
        default:
            size = 1000;
            break;
        }
        int *arr0 = new int[size];
        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];
        int *arr4 = new int[size];
        int c = 0;
        int dif = 0;
        for (int i = 0; i < size / (log2(size)) + 1; i++)
        {
            int count = 0;
            while (c < size && count < log2(size))
            {
                int k = rand() % 21 + dif;
                arr0[c] = k;
                arr1[c] = k;
                arr2[c] = k;
                arr3[c] = k;
                arr4[c] = k;
                c++;
                count++;
            }
            dif = dif + 22;
        }
        Sorting aga;
        auto beg = high_resolution_clock::now();
        aga.insertionSort(arr0, size, compCount, moveCount);
        // Taking a timestamp after the code is ran
        auto end = high_resolution_clock::now();
        auto insertionDuration = duration_cast<microseconds>(end - beg);

        auto beg1 = high_resolution_clock::now();
        aga.bubleSort(arr1, size, compCount1, moveCount1);
        auto end1 = high_resolution_clock::now();
        auto bubleDuration = duration_cast<microseconds>(end1 - beg1);

        auto beg2 = high_resolution_clock::now();
        aga.mergeSort(arr2, size, compCount2, moveCount2);
        auto end2 = high_resolution_clock::now();
        auto mergeDuration = duration_cast<microseconds>(end2 - beg2);

        auto beg3 = high_resolution_clock::now();
        aga.quickSort(arr3, size, compCount3, moveCount3);
        auto end3 = high_resolution_clock::now();
        auto quickDuration = duration_cast<microseconds>(end3 - beg3);

        auto beg4 = high_resolution_clock::now();
        aga.hybridSort(arr4, size, compCount4, moveCount4);
        auto end4 = high_resolution_clock::now();
        auto hybridDuration = duration_cast<microseconds>(end4 - beg4);

        printf("%-25s%-20s%-20s%-20s\n", "", "Elpased Time", "Comp. Count", "Move Count");
        cout << "Array Size: " << size << endl;
        printf("%-25s%-20i%-20i%-20i\n", "Insertion Sort: ", insertionDuration.count(), compCount, moveCount);
        printf("%-25s%-20i%-20i%-20i\n", "Bubble Sort: ", bubleDuration.count(), compCount1, moveCount1);
        printf("%-25s%-20i%-20i%-20i\n", "Merge Sort: ", mergeDuration.count(), compCount2, moveCount2);
        printf("%-25s%-20i%-20i%-20i\n", "QuickSort: ", quickDuration.count(), compCount3, moveCount3);
        printf("%-25s%-20i%-20i%-20i\n", "Hybrid Sort: ", hybridDuration.count(), compCount4, moveCount4);
        cout << "------------------------------------------------------------------------" << endl;
        delete arr0;
        delete arr1;
        delete arr2;
        delete arr3;
        delete arr4;
    }
    cout << "********************************************************************" << endl;
    cout << "Part 2-b-3: Performance analysis of partially descending integers array" << endl<<endl;
    for (int o = 0; o < 4; o++)
    {
        int moveCount = 0;
        int compCount = 0;
        int moveCount1 = 0;
        int compCount1 = 0;
        int moveCount2 = 0;
        int compCount2 = 0;
        int moveCount3 = 0;
        int compCount3 = 0;
        int moveCount4 = 0;
        int compCount4 = 0;
        int size;
        switch (o)
        {
        case 0:
            size = 1000;
            break;
        case 1:
            size = 5000;
            break;
        case 2:
            size = 10000;
            break;
        case 3:
            size = 20000;
            break;
        default:
            size = 1000;
            break;
        }
        int *arr0 = new int[size];
        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];
        int *arr4 = new int[size];
        int c = 0;
        int dif = 0;
        for (int i = 0; i < size / (log2(size)) + 1; i++)
        {
            int count = 0;
            while (c < size && count < log2(size))
            {
                int k = rand() % 21 + dif;
                arr0[size-1-c] = k;
                arr1[size-1-c] = k;
                arr2[size-1-c] = k;
                arr3[size-1-c] = k;
                arr4[size-1-c] = k;
                c++;
                count++;
            }
            dif = dif + 22;
        }
        Sorting aga;
        auto beg = high_resolution_clock::now();
        aga.insertionSort(arr0, size, compCount, moveCount);
        // Taking a timestamp after the code is ran
        auto end = high_resolution_clock::now();
        auto insertionDuration = duration_cast<microseconds>(end - beg);

        auto beg1 = high_resolution_clock::now();
        aga.bubleSort(arr1, size, compCount1, moveCount1);
        auto end1 = high_resolution_clock::now();
        auto bubleDuration = duration_cast<microseconds>(end1 - beg1);

        auto beg2 = high_resolution_clock::now();
        aga.mergeSort(arr2, size, compCount2, moveCount2);
        auto end2 = high_resolution_clock::now();
        auto mergeDuration = duration_cast<microseconds>(end2 - beg2);

        auto beg3 = high_resolution_clock::now();
        aga.quickSort(arr3, size, compCount3, moveCount3);
        auto end3 = high_resolution_clock::now();
        auto quickDuration = duration_cast<microseconds>(end3 - beg3);

        auto beg4 = high_resolution_clock::now();
        aga.hybridSort(arr4, size, compCount4, moveCount4);
        auto end4 = high_resolution_clock::now();
        auto hybridDuration = duration_cast<microseconds>(end4 - beg4);

        printf("%-25s%-20s%-20s%-20s\n", "", "Elpased Time", "Comp. Count", "Move Count");
        cout << "Array Size: " << size << endl;
        printf("%-25s%-20i%-20i%-20i\n", "Insertion Sort: ", insertionDuration.count(), compCount, moveCount);
        printf("%-25s%-20i%-20i%-20i\n", "Bubble Sort: ", bubleDuration.count(), compCount1, moveCount1);
        printf("%-25s%-20i%-20i%-20i\n", "Merge Sort: ", mergeDuration.count(), compCount2, moveCount2);
        printf("%-25s%-20i%-20i%-20i\n", "QuickSort: ", quickDuration.count(), compCount3, moveCount3);
        printf("%-25s%-20i%-20i%-20i\n", "Hybrid Sort: ", hybridDuration.count(), compCount4, moveCount4);
        cout << "------------------------------------------------------------------------" << endl;
        delete arr0;
        delete arr1;
        delete arr2;
        delete arr3;
        delete arr4;
    }

}