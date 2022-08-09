#include <iostream>
using namespace std;

int BinarySearch(int *arr, int size, int x)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = start + ((end - start) / 2);
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            start = mid + 1;
        else if (arr[mid] > x)
            end = mid - 1;
    }
    return -1;
}

int DescBinarySearch(int *arr, int size, int x)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = start + ((end - start) / 2);
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            start = mid + 1;
        else if (arr[mid] < x)
            end = mid - 1;
    }
    return -1;
}

int AgnosticSearch(int *arr, int n, int x)
{
    if (n == 1)
    {
        if (arr[0] == x)
            return 0;
        else
            return -1;
    }
    else if (arr[0] < arr[1])
    {
        return BinarySearch(arr, n, x);
    }
    else
    {
        return DescBinarySearch(arr, n, x);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ele;
    cout << "Enter element to be searched" << endl;
    cin >> ele;
    int index = AgnosticSearch(arr, n, ele);
    cout << "Element found at index : " << index << endl;
    return 0;
}