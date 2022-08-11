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
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int num = rotate(arr, n);
    if (num == 0)
        cout << "No. of times the array is rotated is : 0 or " << n;
    else
        cout << "No of times this array is rotated : " << n - num << endl;
}
