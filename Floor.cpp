#include <iostream>
using namespace std;
int floor(int *arr, int n, int x)
{
    int start = 0;
    int end = n - 1;
    int mid, res = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] <= x)
        {
            res = mid;
            start = mid + 1;
        }
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
    int x;
    cout << "Enter element" << endl;
    cin >> x;
    int ans = floor(arr, n, x);
    cout << "Floor of the element is at index : " << ans << endl;
    if (ans != -1)
        cout << "Floor is : " << arr[ans];
    return 0;
}