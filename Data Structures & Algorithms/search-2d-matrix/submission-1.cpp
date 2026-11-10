class Solution {
public:

    bool binarySearch(int l, int r, vector<vector<int>>& matrix, int target)
    {
        if(l > r) return false;
        int m = l+(r-l)/2;
        int i = m/matrix[0].size();
        int j = m%matrix[0].size();
        
        if(matrix[i][j] == target) return true;

        return((matrix[i][j] > target)?
                binarySearch(l, m-1, matrix, target):
                binarySearch(m+1, r, matrix, target)
            );
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearch(0, matrix.size()*matrix[0].size()-1, matrix, target);
    }
};
