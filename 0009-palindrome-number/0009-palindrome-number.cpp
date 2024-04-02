class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;
        if(n<0)
            return false;
        else
        {
            int sum=0;
            while(n!=0)
            {
                int a=n%10;
                if((sum>INT_MAX/10) || (sum<INT_MIN/10))
                    return false;
                sum=sum*10+a;
                n=n/10;
            }
            if(sum==x)
                return true;
        }
        return false;
    }
};