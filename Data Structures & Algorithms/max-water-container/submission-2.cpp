class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        // max(min(heights[i], heights[j]) * (j-i)) - n2

        int l = 0;
        int r = heights.size()-1;

        int max=0;
        while(l<r)
        {
            int curr = min(heights[l],heights[r]) * (r-l);
            max = (max > curr)?max:curr;

            if(heights[l] <= heights[r])
                l++;
            else
                r--;
        }
        return max;
    }
};
