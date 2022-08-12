#include <iostream>
using namespace std;
int ceil(int *arr, int n, int x)
{
    int start = 0;
    int end = n - 1;
    int mid, res = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] >= x)
        {
            res = mid;
            end = mid - 1;
        }
        else if (arr[mid] < x)
            start = mid + 1;
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
    int ans = ceil(arr, n, x);

    if (ans != -1)
    {
        cout << "Ceil of the element is at index : " << ans << endl;
        cout << "ceil is : " << arr[ans];
    }
    else if (ans == -1)
        cout << "Ceil not found";
    return 0;
}