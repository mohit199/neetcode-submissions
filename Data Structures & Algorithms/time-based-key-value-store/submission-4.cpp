class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> m_map;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m_map[key].push_back({timestamp, value});    
    }
    
    string get(string key, int timestamp) {

        if(m_map.find(key) == m_map.end())
            return "";
        
        auto& values = m_map[key];
        int l = 0; int r = values.size()-1;
        string result = "";

        while(l<=r)
        {
            int m = l + (r-l)/2;
            if(values[m].first <= timestamp)
            {
                result = values[m].second;
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        return result;
    }
};
