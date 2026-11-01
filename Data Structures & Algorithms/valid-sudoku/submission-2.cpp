class Solution {
public:

    bool checkRow(vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; i++)
        {   
            unordered_set<char> check;
            for(int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                else
                {
                    if(check.find(board[i][j]) != check.end())
                    {
                        return false;
                    }
                    else
                    {
                        check.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; i++)
        {   
            unordered_set<char> check;
            for(int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                {
                    continue;
                }
                else
                {
                    if(check.find(board[j][i]) != check.end())
                    {
                        return false;
                    }
                    else
                    {
                        check.insert(board[j][i]);
                    }
                }
            }
        }
        return true;
    }

    bool checkSubBoxes(vector<vector<char>>& board)
    {
        for(int i = 0 ; i <=6; i = i+3)
        {
            for(int j = 0; j <= 6; j = j+3)
            {   
                unordered_set<char> check;
                for(int k = i; k<i+3; k++)
                {
                    for(int l = j; l<j+3; l++)
                    {
                        if (board[k][l] == '.')
                        {
                            continue;
                        }
                        else
                        {
                            if(check.find(board[k][l]) != check.end())
                            {
                                return false;
                            }
                            else
                            {
                                check.insert(board[k][l]);
                            }
                        }
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool row = checkRow(board);
        if(!row)
            return false;
        
        bool col = checkCol(board);
        if(!col)
            return false;

        bool subbox = checkSubBoxes(board);
        if(!subbox)
            return false;

        return true;
    }
};
