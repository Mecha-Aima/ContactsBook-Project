#include "Comparator.h"

template <typename C>
void sort_list(C* arr, int n, Comparator<C>* comp, bool (*fptr)(const C& a, const C& b))
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
           if (comp->compare(arr[j+1], arr[j], fptr))
           {
               C temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
        }
    }
}