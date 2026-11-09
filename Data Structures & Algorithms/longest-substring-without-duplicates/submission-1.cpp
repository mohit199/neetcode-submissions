class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l=0, r=0;
        int maxLength = 0;
        unordered_map<char, int> seen;

        for(r = 0; r < s.length(); r++)
        {
            if(seen.find(s[r]) != seen.end())
            {
                l = max(seen[s[r]]+1, l);
            }
            seen[s[r]] = r;
            maxLength = max(maxLength, r-l+1);
        }
        
        return maxLength;
    }
};
