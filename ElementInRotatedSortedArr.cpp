#include <iostream>
using namespace std;
int rotate(int *arr, int n)
{
    int start = 0;
    int end = n - 1;
    int mid;
    int next;
    int prev;
    if (arr[0] < arr[n - 1])
        return 0;
    while (start <= end)
    {
        mid = start + ((end - start) / 2);
        next = (mid + 1) % n;
        prev = (mid + n - 1) % n;
        if (arr[mid] < arr[prev] && arr[mid] < arr[next])
        {
            return mid;
        }
        else
        {
            if (arr[mid] >= arr[0])
                start = (mid + 1) % n;
            else if (arr[mid] <= arr[n - 1])
                end = (mid + n - 1) % n;
        }
    }

    return -1;
}
int BinarySearch(int *arr, int start, int end, int x)
{
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
    int n, x;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter Element";
    cin >> x;
    int num = rotate(arr, n);
    int first = BinarySearch(arr, 0, num - 1, x);
    int second = BinarySearch(arr, num, n - 1, x);
    if (first != -1)
        cout << "Element found at : " << first << endl;
    else if (second != -1)
        cout << "Element found at : " << second << endl;
    else if (first == -1 && second == -1)
        cout << "Element not found " << endl;
    return 0;
}