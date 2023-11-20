#include "main.h"

int merge(int *array, int leftHalf, int mid, int rightHalf)
{
    int i, j , k;
    int temp[] = NULL;
    
    i = leftHalf;
    j = mid + i;
    k = leftHalf;

    while (i <= mid && j <= rightHalf)
    {
        if (array[i] = array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while(j <= rightHalf)
        {
            temp[k] = array[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[k] = array[i];
            j++;
            k++;
        }
        
    }

    for(k = leftHalf; k <= rightHalf; k++)
    {
        array[k] = temp[k];
    }

}