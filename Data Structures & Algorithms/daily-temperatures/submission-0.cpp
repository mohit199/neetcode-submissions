class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int, int>> stack;
        vector<int> res(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++)
        {
            // stack empty - push
            // if stack top >= elem - push
            // if stack top < elem - pop and fill res

            if(stack.empty())
            {
                stack.push({temperatures[i], i});
            }
            else if(stack.top().first >= temperatures[i])
            {
                stack.push({temperatures[i], i});
            }
            else
            {
                while(!stack.empty() && stack.top().first < temperatures[i])
                {
                    res[stack.top().second] = i-stack.top().second;
                    stack.pop();
                }

                stack.push({temperatures[i], i});
            }
        }

        return res;
    }
};
