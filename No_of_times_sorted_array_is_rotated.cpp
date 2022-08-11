#include <iostream>
using namespace std;
int rotate(int *arr, int n)
{
    int start = 0;
    int end = n - 1;
    int mid;
    int next;
    int prev;
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
                start = mid + 1;
            else if (arr[mid] <= arr[n - 1])
                end = mid - 1;
        }
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
    int num = rotate(arr, n);
    cout << "No of times this array is rotated : " << n - num << endl;
}