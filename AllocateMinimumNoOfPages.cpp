//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int maxInArr(int A[],int N)
    {
        int max = 0;
        int res = -1;
        for(int i =0; i< N; i++)
        {
            if(max<A[i])
            {
                max = A[i];
                res = i;
            }
        }
        return res;
    }
    int totalSum(int A[], int N)
    {   int sum =0;
        for(int i =0; i<N ; i++)
        {
            sum += A[i];
        }
        return sum;
    }
    bool isValid(int A[], int N, int M , int mid )
    {   
        int student = 1;
        int sum =0;
        for(int i =0; i<N ; i++)
        {
            sum+=A[i];
            if(sum > mid)
            {
                student++;
                sum = A[i];
            }
            if(student> M)
            return false;
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {   if(M > N)
        return -1;
        int max = maxInArr(A,N);
        int sum = totalSum(A,N);
        int start = A[max];
        int end = sum;
        int mid,res;
        while(start<=end)
        {
            mid = start + (end -start)/2;
            if(isValid(A,N,M,mid)== true)
            {
                res = mid;
                end = mid-1;
            }
            else
            start = mid+1;
        }
        return res;
    }
};
