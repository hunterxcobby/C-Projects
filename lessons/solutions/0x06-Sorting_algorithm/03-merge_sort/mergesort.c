#include "main.h"

void mergesort(int *array, int leftHalf, int rightHalf)
{
    int mid;

    if(leftHalf < rightHalf)
    {
        mid = (leftHalf + rightHalf) / 2;
        mergesort(array, leftHalf, mid);
        mergesort(array, mid + 1,rightHalf);
        merge(array, leftHalf, mid, rightHalf);
    }
}

