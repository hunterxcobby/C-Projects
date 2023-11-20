
int quicksort(int *array, int low, int high)
{
    int location;

    if (low < high)
    {
        location = partition(array, low, high);
        quicksort(array, low, location - 1);
        quicksort(array, location + 1, high);
    }
}