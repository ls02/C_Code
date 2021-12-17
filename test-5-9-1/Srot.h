#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

// ≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);

// œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);

// —°‘Ò≈≈–Ú
void SelectSort(int* a, int n);

// ∂—≈≈–Ú
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// √∞≈›≈≈–Ú
void BubbleSort(int* a, int n);

void Print(int* a, int size);

//øÏÀŸ≈≈–Ú
void QuickSort(int* a, int begin, int end);
void QuickSort1(int* a, int begin, int end);

// πÈ≤¢≈≈–Úµ›πÈ µœ÷
void MergeSort(int* a, int n);

// πÈ≤¢≈≈–Ú∑«µ›πÈ µœ÷
void MergeSortNonR(int* a, int n);

// º∆ ˝≈≈–Ú
void CountSort(int* a, int n);