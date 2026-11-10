class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxK=0;
        for(int i:piles)
        {
            maxK = max(maxK, i);
        }
        int l = 1, r = maxK;
        int k = maxK;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            int t = 0;
            int flag = 0;
            for(int i:piles)
            {
                t += (i%m == 0)? i/m:i/m+1;
                if(t>h)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
            {
                l = m+1;
            }
            else
            {
                k = m;
                r = m-1;
            }
        }
        return k;
    }
};
