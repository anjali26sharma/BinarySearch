// https://leetcode.com/problems/find-peak-element/

class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int n = arr.size();
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
                else if (arr[mid - 1] > arr[mid])
                    end = mid - 1;
                else if (arr[mid + 1] > arr[mid])
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
};