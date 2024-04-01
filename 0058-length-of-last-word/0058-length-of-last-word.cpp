class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if((s[i]>=65 && s[i]<=90)||(s[i]>=90 && s[i]<=122))
                c++;
            if(s[i]==' '&&s[i+1]!=' ')
            {
                c=0;
            }
        }
        int n=s.size();
        if(s[n-1]!=' ')
        return c+1;
        else
            return c;
    }
};