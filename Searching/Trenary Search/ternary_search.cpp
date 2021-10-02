// This code is contributed by Anurag Mukherjee

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Recursive approach

int Ternary_Search(int left, int right, int value, int arr[])
{
    if (right > left)
    {
        // Finding the midterms
        int mid1 = left + (right - 1) / 3;
        int mid2 = right - (right - 1) / 3;

        // Check if the value is present in the first mid term
        if (arr[mid1] == value)
        {
            return mid1;
        }

        // Check if the value is present in the second mid term
        if (arr[mid2] == value)
        {
            return mid2;
        }

        // If the element is not present in the mid positions, the following cases can be a possibility.

        // Checking if the value is less than mid1 element
        if (value < arr[mid1])
        {
            return Ternary_Search(left, mid1 - 1, value, arr);
        }

        // Checking if the value is greater than mid2 element
        if (value > arr[mid2])
        {
            return Ternary_Search(mid2 + 1, right, value, arr);
        }

        // The last possibility is that, the element may be present between the mid1 and mid2
        else
        {
            return Ternary_Search(mid1 + 1, mid2 - 1, value, arr);
        }
    }

    // If all the possibilities fail, the element is not present inside the array
    else
    {
        return -1;
    }
}

// Testing Code
int main()
{
    int arr[100], n, left, right, element_to_search, index;

    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;

    cout << "Enter the elements: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Sorting the given array
    sort(arr, arr + n);

    // Setting the left and right values
    left = -1;
    right = n;

    // Taking the input of the element to be searched in the array
    cout << "Enter the element you want to search" << endl;
    cin >> element_to_search;

    index = Ternary_Search(left, right, element_to_search, arr);

    if (index == -1)
    {
        cout << "The element is absent in the array";
    }

    else
    {
        cout << "The given element is present in the array" << endl;
    }

    return 0;
}