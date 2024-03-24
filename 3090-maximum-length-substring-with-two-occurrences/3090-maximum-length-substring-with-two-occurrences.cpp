class Solution {
public:
    int maximumLengthSubstring(string s) {

        unordered_map<char, int> nums;
        int maxi= 0;
        int left = 0;
    
        for (int right = 0; right < s.length(); ++right) {
            nums[s[right]]++;
            while (nums[s[right]] > 2) {
                nums[s[left]]--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
    
        return maxi;
        
    }
};