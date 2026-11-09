class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s2.length() < s1.length()) return false;

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for(char c = 'a'; c <= 'z'; c++)
        {
            mp1[c] = 0;
            mp2[c] = 0;
        }
        
        for(char c:s1)
        {
            mp1[c]++;
        }

        for(int i = 0; i < s1.length(); i++)
        {
            mp2[s2[i]]++;
        }

        if(mp1 == mp2) return true;

        int l=1;
        int r = s1.length();

        while(r < s2.length())
        {
            mp2[s2[l-1]]--;
            mp2[s2[r]]++;
            if(mp1 == mp2)
                return true;

            l++;
            r++;
        }

        return false;

    }
};
