class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> mp;
        int l = 0, r=0;
        int res = 0;

        for(r = 0; r < s.length(); r++)
        {
            mp[s[r]]++;
            
            int maxf = 0;
            for(auto m : mp)
            {
                maxf = max(maxf, static_cast<int>(m.second));
            }

            while((r-l+1) - maxf > k)
            {
                mp[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
