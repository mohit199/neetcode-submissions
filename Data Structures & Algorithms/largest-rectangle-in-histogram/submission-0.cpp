class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stack;  //start index, height
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++)
        {
            int j = i;
            while(!stack.empty() && heights[i] <= stack.top().second)
            {
                int area = (i - stack.top().first) * stack.top().second;
                maxArea = max(maxArea, area);
                j = stack.top().first; 
                stack.pop();
                
            }
            stack.push({j, heights[i]});    
        }

        while(!stack.empty())
        {
            int area = (heights.size() - stack.top().first) * stack.top().second;
            maxArea = max(maxArea, area);
            stack.pop();
        }
        return maxArea;
    }
};
