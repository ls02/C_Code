#pragma once
#include "vector.h"
#include <assert.h>
//����˳���
//��ʼ��
//����: ����(�������㿪���ڴ�Ĵ�С)
Vector InitVector(int n)
{
    Vector vector;
    //����һ���յı�,��̬���봢��
    vector.pV = (int*)malloc(sizeof(int) * n);
    //�ж�: �������ʧ��
    if (!vector.pV)
    {
        printf("�ڴ�����ʧ��!\n");
        //����ʧ��,�˳�����,�쳣����:-1
        exit(-1);
    }
    vector.size = 0;
    vector.capacity = n;
    return vector;
}
//����˳���
//����
//����: ��ָ�� ����
Vector* CheckCapacityVector(Vector* pVector)
{
    //1.�ж��Ƿ��д���ռ�
    //2.������� ������
    if (pVector->capacity <= pVector->size)
    {
        //1.��¼ԭ�����ڴ�
        int* ptemp = pVector->pV;
        //2.�����µ��ڴ�
        pVector->pV = (int*)calloc(sizeof(int), pVector->capacity *= 2);
        if (!pVector->pV)
        {
            printf("�ڴ�����ʧ��!\n");
            //����ʧ��,�˳�����,�쳣����:-1
            exit(-1);
        }
        //����
        for (int i = 0; i < pVector->size; i++)
        {
            pVector->pV[i] = ptemp[i];
        }
        //�ͷ�
        free(ptemp);
        ptemp = NULL;
    }
    //���ر�ָ��
    return pVector;
}
//β������Ԫ��
//��
//����: ��ָ�� ��ֵ
Vector* PushBackVector(Vector* pVector, int num)
{
    assert(pVector != NULL);
    //�ж��Ƿ��д���ռ�
    CheckCapacityVector(pVector);
    //����
    pVector->pV[pVector->size] = num;
    pVector->size++;
    return pVector;
}
//����λ�ò���Ԫ��
//����
//����: ��ָ�� ��ֵ λ��
Vector* InsertVector(Vector* pVector, int num, int pos)
{
    assert(pVector != NULL);
    //�жϲ����Ƿ��������
    if (pos >= pVector->size || pos < 0)
    {
        return pVector;
    }
    //�ж��Ƿ��д���ռ�
    CheckCapacityVector(pVector);
    //����
    //1����
    for (int i = pVector->size; i >= pos; i--)
    {
        pVector->pV[i + 1] = pVector->pV[i];
    }
    //2.����
    pVector->pV[pos] = num;
    pVector->size++;
    return pVector;
}
//�ͷű�
//�ͷ�
//���� ��
void DestoryVector(Vector temp)
{
    free(temp.pV);
    temp.pV = NULL;
}
//����Ԫ��
//����
//����: �� ��ֵ
int FindWithVector(Vector* pVector, int num)
{
    assert(pVector != NULL);
    for (int i = 0; i < pVector->size; i++)
    {
        if (num == pVector->pV[i])
        {
            //����ҵ��˷��������
            return i;
        }
    }
    //���û���ҵ�����-1
    return -1;
}
//ɾ�������Ԫ��
//ɾ��
//����: ��ָ�� ����
Vector* DelPosVector(Vector* pVector, int pos)
{
    assert(pVector != NULL);
    //�ж�ɾ����λ���Ƿ���ȷ
    if (pos >= pVector->size || pos < 0)
    {
        printf("ɾ����λ�ò���!");
        exit(-1);
    }
    //ɾ��
    for (int i = pos; i < pVector->size; i++)
    {
        pVector->pV[i] = pVector->pV[i + 1];
    }
    pVector->size--;
    return pVector;
}
//ɾ��β����Ԫ��
//ɾ��
//����: ��ָ��
Vector* PopBackVector(Vector* pVector)
{
    assert(pVector != NULL);
    DelPosVector(pVector, pVector->size);
    return pVector;
}
