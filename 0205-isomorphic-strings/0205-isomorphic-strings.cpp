class Solution {
public:
    bool isIsomorphic(string s, string t) {
      if (s.size() != t.size()) {
        return false;
    }
    
    std::unordered_map<char, char> mapping;
    std::unordered_map<char, bool> used;
    
    for (int i = 0; i < s.size(); ++i) {
        char charS = s[i];
        char charT = t[i];
        
        if (mapping.find(charS) == mapping.end()) {
            if (used[charT]) {
                return false; 
            }
            mapping[charS] = charT;
            used[charT] = true;
        } else {
            if (mapping[charS] != charT) {
                return false;       }
        }
    }
    
    return true;
}
};