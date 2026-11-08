class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        // nums[i] + nums[j] = -nums[k]
        // array is not sorted 
        // sort the array
        // 2 sum
        // O(n2) time and O(1) space
        
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-1; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int start = i+1;
            int last = nums.size()-1;

            while(start < last)
            {
                int curr = nums[start] + nums[last] + nums[i];
                if(curr == 0)
                {
                    res.push_back({nums[start], nums[last], nums[i]});
                    start++;
                    last--;

                    while(start < last && nums[start] == nums[start-1])
                    {
                        start++;
                    }
                }
                else if(curr < 0)
                {
                    start++;
                }
                else if(curr > 0)
                {
                    last--;
                }
            }
        }
        return res;
    }
};
