#include <iostream>
using namespace std;
int firstIndex(int *arr, int size, int x)
{
    int start = 0;
    int end = size - 1;
    int mid, res = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == x)
        {
            res = mid;
            end = mid - 1;
        }
        else if (arr[mid] < x)
            start = mid + 1;
        else if (arr[mid] > x)
            end = mid - 1;
    }
    return res;
}
int lastIndex(int *arr, int size, int x)
{
    int start = 0;
    int end = size - 1;
    int mid, res = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == x)
        {
            res = mid;
            start = mid + 1;
        }
        else if (arr[mid] < x)
            start = mid + 1;
        else if (arr[mid] > x)
            end = mid - 1;
    }
    return res;
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
    int first = firstIndex(arr, n, ele);
    int last = lastIndex(arr, n, ele);
    cout << "First index is : " << first << endl;
    cout << "Last indes is : " << last << endl;
    return 0;
}