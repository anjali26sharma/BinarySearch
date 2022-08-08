#include <iostream>
using namespace std;
int BinarySearch(int *arr, int size, int x)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            start = mid + 1;
        else if (arr[mid] > x)
            end = mid - 1;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ele;
    cout << "Enter Element to be searched" << endl;
    cin >> ele;
    int index = BinarySearch(arr, n, ele);
    cout << "Element is found at index : " << index << endl;
    return 0;
}