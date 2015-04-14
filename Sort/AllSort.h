#ifndef ALL_SORT_H
#define ALL_SORT_H

#include <stdio.h>
#include <stdlib.h>
//swap
void Swap(int* a, int* b);

//BubbleSort;
void BubbleSort(int* arr, int n);

//quicksort:
int QSPartition(int* arr, int low, int high);
void QuickSort(int* arr, int low, int high);

//insert sort:
void InsertSort(int* arr, int n);

//shell sort:
void ShellSort(int* arr, int n);

//HeapSort:
void PerDown(int* arr, int index, int n);
void HeapSort(int* arr, int n);

//MergeSort:
void Merge(int* arr, int* tempArr, int lPos, int rPos, int rightEnd);
void MergeSort(int* arr, int N);
void MSort(int* arr, int* tempArr, int left, int right);

#endif

