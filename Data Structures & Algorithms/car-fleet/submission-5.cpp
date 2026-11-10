class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        if(position.size() == 0) return 0;

        vector<pair<int, float>> pos_time(position.size());
        for(int i = 0 ; i<position.size(); i++)
        {
            pos_time[i] = {position[i], static_cast<float>(target-position[i])/static_cast<float>(speed[i])};
        }

        sort(pos_time.begin(), pos_time.end(), std::greater<>());
        stack<float> stack;
        int count = 1;
        stack.push(pos_time[0].second);
        for(int i = 1; i < position.size(); i++)
        {
            if(pos_time[i].second > stack.top())
            {
                count++;
                stack.push(pos_time[i].second);
            }
            // else
            // {
            //     stack.push(pos_time[i].second);
            // }
        }

        // find time for each car
        // sort time according to pos.
        // if next elem takes less time than top of stack than itis a fleet

        return count;

    }
};
