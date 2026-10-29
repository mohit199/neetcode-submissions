class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size);
        vector<int> suffix(size);

        prefix[0] = 1;
        for(int i = 1; i < size; i++)
        {
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        suffix[size-1] = 1;
        for(int i = size-2; i >= 0; i--)
        {
            suffix[i] = nums[i+1] * suffix[i+1];
        }

        vector<int> result(size);
        for(int i = 0; i < size; i++)
        {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};
