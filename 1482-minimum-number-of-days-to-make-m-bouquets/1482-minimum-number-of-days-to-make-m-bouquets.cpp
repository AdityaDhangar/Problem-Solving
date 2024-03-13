class Solution {
public:
bool possible(int day,vector<int>& v,int k,int m)
{
    int c=0,q=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<=day)
        {
            c++;
            if(c==k)
            {
            q++;
            c=0;
            }
        }
        else
        c=0;
    }
    return q>=m;
}
    int minDays(vector<int>& blooms, int m, int k) {
        int low=INT_MAX,high=INT_MIN;
        for(auto it:blooms)
        {
            low=min(low,it);
            high=max(high,it);
        }
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(possible(mid,blooms,k,m))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};