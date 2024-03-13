class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
          int l = 0,h = s.length(),mid,ans;
        while(l<=h){
            mid = l+(h-l)/2;
            if(isPossible(s,t,maxCost,mid)){
                ans = mid;
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ans;
    }
        
   bool isPossible(string& s,string&t,int maxCost,int len){
        if(len==0) return true;
        int cost=0,l=0;
        while(l<len){
            cost+=abs(s[l]-t[l]);
            l++;
        }
        if(cost<=maxCost) return true;
        for(;l<s.length();l++){
            cost-=abs(s[l-len]-t[l-len]);
            cost+=abs(s[l]-t[l]);
            if(cost<=maxCost) return true;
        }
        return false;
    }
};