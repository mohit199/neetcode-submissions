class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(!nums.size())
        {
            return 0;
        }

        unordered_map<int, int> mp;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int length = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            int j = 1;
            while(numSet.find(nums[i]+j) != numSet.end())
            {
                if(mp.find(nums[i]+j) != mp.end())
                {
                    j += mp[nums[i]+j];
                }
                else
                {
                    j++;
                }
            }
            mp[nums[i]] = j;
            length = (length > j)?length:j;
        }
        return length;
    }
};
