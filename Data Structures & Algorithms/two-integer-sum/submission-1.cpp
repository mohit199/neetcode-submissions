class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> um;

        for(int i=0; i<nums.size(); i++)
        {
            int num_to_find = target - nums[i];
            if(um.find(num_to_find) == um.end())
            {
                um.insert({nums[i], i});
            }
            else
            {
                return vector<int>({um[num_to_find], i});
            }
        }
        return vector<int>();
    }
};
