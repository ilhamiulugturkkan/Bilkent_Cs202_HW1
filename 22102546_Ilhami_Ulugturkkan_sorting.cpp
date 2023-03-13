/**
* Title: Algorithm analysis & Sorting
* Author : İlhami Uluğtürkkan
* ID: 22102546
* Section : 002
* Homework : 1
* Description : Method Implementation
*/
#include <iostream>
#include "22102546_Ilhami_Ulugturkkan.h"
using namespace std;

// Helper Method
void swap(int &x, int &y, int &moveCount)
{
   int temp = x;
   x = y;
   y = temp;
   moveCount = moveCount + 3; // 3 data moves
}

void Sorting::insertionSort(int *arr, const int size, int &compCount, int &moveCount)
{
   for (int unsorted = 0; unsorted < size; ++unsorted)
   {
      int nextItem = arr[unsorted];
      moveCount++;
      int loc = unsorted;

      for (; (loc > 0) && (arr[loc - 1] > nextItem); --loc)
      {
         swap(arr[loc], arr[loc - 1], moveCount);
         compCount++;
      }
   }
}
void Sorting::bubleSort(int *arr, const int size, int &compCount, int &moveCount)
{

   bool sorted = false;

   for (int pass = 0; (pass <= size) && !sorted; ++pass)
   {
      sorted = true;
      for (int index = 0; index <= size - pass; ++index)
      {
         int nextIndex = index + 1;
         if (arr[index] > arr[nextIndex])
         {
            swap(arr[index], arr[nextIndex], moveCount);
            sorted = false; // signal exchange
         }
         compCount++;
      }
   }
}

// helper for mergesort
void merge(int theArray[], int first, int mid, int last, int size, int &compCount, int &moveCount)
{

   int tempArray[size]; // temporary array

   int first1 = first;   // beginning of first subarray
   int last1 = mid;      // end of first subarray
   int first2 = mid + 1; // beginning of second subarray
   int last2 = last;     // end of second subarray
   int index = first1;   // next available location in tempArray

   for (; (first1 <= last1) && (first2 <= last2); ++index)
   {
      compCount++;
      if (theArray[first1] < theArray[first2])
      {
         tempArray[index] = theArray[first1];
         moveCount++;
         ++first1;
      }
      else
      {
         tempArray[index] = theArray[first2];
         moveCount++;
         ++first2;
      }
   }
   // finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index)
   {
      tempArray[index] = theArray[first1];
      moveCount++;
   }

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index)
   {
      tempArray[index] = theArray[first2];
      moveCount++;
   }

   // copy the result back into the original array
   for (index = first; index <= last; ++index)
   {
      theArray[index] = tempArray[index];
      moveCount++;
   }
}

// classic mergeSort but as a helper method cuz in assignment parameters are weird.
void mergeHelper(int *theArray, int first, int last, int &compCount, int &moveCount, int size)
{
   if (first < last)
   {
      int mid = (first + last) / 2; // index of midpoint
      mergeHelper(theArray, first, mid, compCount, moveCount, size);
      mergeHelper(theArray, mid + 1, last, compCount, moveCount, size);
      // merge the two halves
      merge(theArray, first, mid, last, size, compCount, moveCount);
   }
}
void Sorting::mergeSort(int *arr, const int size, int &compCount, int &moveCount)
{
   mergeHelper(arr, 1, size, compCount, moveCount, size);
}

void partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount)
{

   int pivot = theArray[first];
   moveCount++;
   int lastS1 = first;
   int firstUnknown = first + 1;

   // move one item at a time until unknown region is empty
   for (; firstUnknown <= last; ++firstUnknown)
   {

      compCount++;
      if (theArray[firstUnknown] < pivot)
      { // belongs to S1
         ++lastS1;
         swap(theArray[firstUnknown], theArray[lastS1]);
      } // else belongs to S2
   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1]);
   pivotIndex = lastS1;
}
void quickSortHelper(int *arr, int start, int end, int &compCount, int &moveCount)
{
   // choose the first element as pivot
   int pivotIdx;
   // divide the array from the partition
   if (start < end)
   {
      // divide from the pivot
      // start, pivot, end
      partition(arr, start, end, pivotIdx, compCount, moveCount);

      // sort the first half of the array
      quickSortHelper(arr, start, pivotIdx - 1, compCount, moveCount);
      quickSortHelper(arr, pivotIdx + 1, end, compCount, moveCount);
   }
}
void Sorting::quickSort(int *arr, const int size, int &compCount, int &moveCount)
{
   quickSortHelper(arr, 0, size - 1, compCount, moveCount);
}


void bubleHybridSort(int *arr, int low,int high, int &compCount, int &moveCount)
{

   bool sorted = false;

   for (int pass = 0; (pass <= high-low+1) && !sorted; pass++)
   {
      sorted = true;
      for (int index = low; index < high - pass; ++index)
      {
         int nextIndex = index + 1;
         if (arr[index] > arr[nextIndex])
         {
            swap(arr[index], arr[nextIndex], moveCount);
            sorted = false; // signal exchange
         }
         compCount++;
      }
   }
}
int partitionn(int arr[], int low, int high,int &compCount, int &moveCount)
{
  int pivot = arr[high];moveCount++;
  int i ,j;
  i = low;
  j = low;
 
  for (int i = low; i < high; i++)
     {
      compCount++;
      if(arr[i]<pivot)
      {
        int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      j += 1;
      moveCount = moveCount + 3;
      }
    }
   
    int temp = arr[j];
    arr[j] = arr[high];
    arr[high] = temp;
    moveCount = moveCount + 3;
 
  return j;
}
void hybrid_quick_sort(int arr[], int low, int high, int &compCount, int &moveCount)
{
  while (low < high)
    {
 
    // If the size of the array is less
    // than threshold apply insertion sort
    // and stop recursion
 
    if (high-low + 1 < 20)
      {
        bubleHybridSort(arr, low, high,compCount,moveCount);
      break;
    }
 
    else
       
        {
          int pivot = partitionn(arr, low, high,compCount,moveCount) ;
 
      // Optimised quicksort which works on
      // the smaller arrays first
 
      // If the left side of the pivot
      // is less than right, sort left part
      // and move to the right part of the array
 
      if (pivot-low<high-pivot)
        {
          hybrid_quick_sort(arr, low, pivot - 1,compCount,moveCount);
        low = pivot + 1;
      }
      else
        {
 
        // If the right side of pivot is less
        // than left, sort right side and
        // move to the left side
           
        hybrid_quick_sort(arr, pivot + 1, high,compCount,moveCount);
        high = pivot-1;
        }
 
     }
 
   }
}
void Sorting::hybridSort(int *arr, const int size, int &compCount, int &moveCount)
{
   hybrid_quick_sort(arr, 0, size, compCount, moveCount);
}