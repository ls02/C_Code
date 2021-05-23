#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);

// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);

void Print(int* a, int size);

//��������
void QuickSort(int* a, int begin, int end);
void QuickSort1(int* a, int begin, int end);

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);

// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);