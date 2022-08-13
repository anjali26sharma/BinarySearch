class BinaryInfinetArray
{
public
    int fun(int arry[], int key, int start, int end)
    {
        int result = -1;
        while (key > arry[end])
        {
            if (arry[end] < key)
            {
                start = end;
                end = end * 2;
            }
        }
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arry[mid] == key)
            {
                result = mid;
                end = mid - 1;
            }
            else if (arry[mid] > key)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return result;
    }
}