class Solution {
public:
    bool isPalindrome(string s) {
        
        std::string res;
        for(unsigned char ch:s)
        {
            if(std::isalnum(ch))
            {
                res += static_cast<char>(std::tolower(ch));
            }
        }
        
        int len = res.length();
        for(int i = 0; i < len/2; i++)
        {
            if(res[i] != res[len - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
