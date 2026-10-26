class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> num_frequency;
        for(auto& elem:mp)
        {
            num_frequency.push_back({elem.second, elem.first});
        }

        sort(num_frequency.rbegin(), num_frequency.rend());

        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(num_frequency[i].second);
        }

        return res;
    }
};
