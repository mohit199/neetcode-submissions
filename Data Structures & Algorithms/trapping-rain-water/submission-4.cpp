class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size() - 1;

        vector<int> prefixMax(len+1);
        vector<int> suffixMax(len+1);

        prefixMax[0] = height[0];
        for(int i = 1; i <= len; i++)
        {
            prefixMax[i] = max(height[i], prefixMax[i-1]);
        }

        suffixMax[len] = height[len];
        for(int i = len-1; i >= 0; i--)
        {
            suffixMax[i] = max(height[i], suffixMax[i+1]);
        }

        int sum = 0;
        for(int i = 0; i <= len; i++)
        {
            sum += min(prefixMax[i], suffixMax[i]) - height[i];
        }
        
        for(int i = 0; i <= len; i++)
        {
            cout << prefixMax[i];
        }
        cout <<endl;

        for(int i = 0; i <= len; i++)
        {
            cout << suffixMax[i];
        }
        cout << endl;

        return sum;
    }
};
