#pragma once

template <typename T>
class Comparator
{
public:
    virtual bool compare(const T& a, const T& b, bool (*fptr)(const T& a, const T& b)) const = 0;
    virtual ~Comparator() {};
};

// Use cases:
// 1. Compare contact's names (first name, last name)
// 2. Compare contact's email addresses
// 3. Compare two time objects
// 4. Compare two date objects
// 5. Compare two History objects
// sort(T* arr, int n, Comparator<T>* comp, bool (*fptr)(const T& a, const T& b))
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//            if (comp->compare(arr[j+1], arr[j], fptr))
//            {
//                T temp = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = temp;
//            }
//}
// e.g. sort(contacts, n, new Contact(), Contact::fn_less_than);