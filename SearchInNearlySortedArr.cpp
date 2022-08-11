#include <iostream>
using namespace std;
int search(int *arr, int n, int x)
{
    int start = 0;
    int end = n - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == x)
            return mid;
        else if (mid - 1 >= start && arr[mid - 1] == x)
            return mid - 1;
        else if (mid + 1 <= end && arr[mid + 1] == x)
            return mid + 1;
        else if (x > arr[mid] && mid + 2 <= end)
            start = mid + 2;
        else if (x < arr[mid] && mid - 2 >= start)
            end = mid - 2;
        else if (mid + 2 > end || mid - 2 < start)
            return -1;
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
    cout << "Enter element to be searched " << endl;
    cin >> x;
    int ans = search(arr, n, x);
    if (ans == -1)
        cout << "Not found" << endl;
    else
        cout << "Element found at : " << ans << endl;
    return 0;
}