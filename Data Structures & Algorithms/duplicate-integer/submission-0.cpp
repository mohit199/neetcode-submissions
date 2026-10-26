class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numset;

        for(auto i:nums)
        {
            numset.insert(i);
        }

        if(numset.size() != nums.size())
            return true;
        
        return false;
    }
};