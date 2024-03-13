class Solution {
public:
bool ispossible(int m,int mo,vector<int>& v)
{
    int ans=0;
    for(auto it:v)
    {
        if(it>m)
        {
            double q=it;
            q=ceil(q/m)-1;
            ans+=q;
        }
    }
    return ans<=mo;
}
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=-1e9;
        for(auto it:nums)
        high=max(high,it);
        int ans=1;
        sort(nums.rbegin(),nums.rend());
        while(low<=high)
        {
            int m=low+(high-low)/2;
            if(ispossible(m,maxOperations,nums))
            {
                ans=m;
                high=m-1;
            }
            else
            low=m+1;
        }
        return ans;
    }
};
