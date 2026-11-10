class Solution {
public:

    int binarySearch(int l, int r, vector<int> &nums)
    {
        if(l == r) return nums[l];
        //if(l+1 == r) return min(nums[l], nums[r]);
        int m = l + (r-l)/2;
        return (nums[m] > nums[r])? binarySearch(m+1, r, nums):
                binarySearch(l, m, nums);
    }

    int findMin(vector<int> &nums) {
        return binarySearch(0, nums.size()-1, nums);
    }
};
