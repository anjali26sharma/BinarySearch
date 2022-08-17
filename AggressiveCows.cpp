// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?leftPanelTab=0
bool isValid(vector<int> &stalls, int k, int mid)
{
    int cow = 1;
    int lastpos = stalls[0];
    for(int i =0; i< stalls.size();i++)
    {
        if(stalls[i]-lastpos >= mid)
        {
            cow++;
            
            lastpos = stalls[i];
        }
        if(cow >= k)
                return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{   sort(stalls.begin(), stalls.end());
    int start =0;
    int max1 = -1, min1 = -1;
    for(int i =0; i<stalls.size(); i++)
        max1 = max(max1,stalls[i]);
 for(int i =0; i<stalls.size(); i++)
        min1 =min(min1,stalls[i]);
    int end = max1-min1;
    int mid, res = -1;
    while(start <= end)
    {
        mid = start + (end-start)/2;
        if(isValid(stalls,k,mid))
        {
            res = mid;
            start = mid+1;
        }
        else
            end  = mid -1;
    }
   return res;
}
