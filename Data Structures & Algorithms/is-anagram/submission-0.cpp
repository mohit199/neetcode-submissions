class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length())
            return false;

        unordered_map<char, int> um_s;
        unordered_map<char, int> um_t;

        for(int i=0; i<s.length(); i++)
        {
            um_s[s[i]]++;
            um_t[t[i]]++;
        }

        if(um_s == um_t)
            return true;

        return false;
    }
};
