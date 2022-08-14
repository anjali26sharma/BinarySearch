// Max element in Bitonic Array
#include <iostream>
using namespace std;
int Bitonic(int *arr, int n)
{
    if (n == 1)
        return 0;
    int start = 0;
    int end = n - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (mid != 0 && mid != n - 1)
        {

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid] < arr[mid - 1])
                end = mid - 1;
            else if (arr[mid] < arr[mid + 1])
                start = mid + 1;
        }
        else
        {
            if (mid == 0)
            {
                if (arr[0] > arr[1])
                    return 0;
                else
                    return 1;
            }
            else if (mid == n - 1)
            {
                if (arr[n - 1] > arr[n - 2])
                    return n - 1;
                else
                    return n - 2;
            }
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
    int ans = Bitonic(arr, n);
    cout << "Maximum element is at : " << ans << endl;
    cout << "Maximum element is : " << arr[ans] << endl;
    return 0;
}