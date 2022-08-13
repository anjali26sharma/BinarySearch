#include <iostream>
using namespace std;
int BinarySearch(int *arr, int n, int x)
{
    int start = 0;
    int end = n - 1;
    int mid;
    if (x < arr[0])
        return arr[0];
    else if (x > arr[n - 1])
        return arr[n - 1];
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == x)
            return arr[mid];
        else if (arr[mid] < x)
            start = start + 1;
        else if (arr[mid] > x)
            end = end - 1;
    }

    if ((arr[start] - x) < (x - arr[end]))
        return arr[start];
    else
        return arr[end];
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cout << "Enter Element" << endl;
    cin >> x;
    int ans = BinarySearch(arr, n, x);
    cout << "Minimum Difference Element is : " << ans << endl;
    return 0;
}