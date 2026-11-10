class Solution {
public:

    int binarysearch(int l, int r, vector<int>& nums, int target)
    {
        if(l>r) return -1;
        int m = l+(r-l)/2;

        if(nums[m] == target) return m;
        return((nums[m]>target)?
                binarysearch(l, m-1, nums, target):
                binarysearch(m+1, r, nums, target)
                );
    }

    int search(vector<int>& nums, int target) {
        return binarysearch(0, nums.size()-1, nums, target);
    }
};
