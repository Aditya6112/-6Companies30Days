// Link: https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,vector<int>>rows_val;
        unordered_map<int,vector<int>>cols_val;

        //rows operation
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                else rows_val[i].push_back(board[i][j]-'0');
            }
        }
        for(auto it:rows_val){
            vector<int>temp=it.second;
            unordered_map<int,int>freq;
            for(int i=0;i<temp.size();i++){
                freq[temp[i]]++;
            }
            for(auto f:freq){
                if(f.second>1)return false;
            }
        }

        //cols operation
        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                if(board[i][j]=='.')continue;
                else cols_val[j].push_back(board[i][j]-'0');
            }
        }
        for(auto it:cols_val){
            vector<int>temp=it.second;
            unordered_map<int,int>freq;
            for(int i=0;i<temp.size();i++){
                freq[temp[i]]++;
            }
            for(auto f:freq){
                if(f.second>1)return false;
            }
        }

        //do operations on each 3X3 matrix

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_set<char> seen;
                for (int m = i; m < i + 3; ++m) {
                    for (int n = j; n < j + 3; ++n) {
                        if (board[m][n] == '.') continue;
                        if (seen.count(board[m][n])) return false;
                        seen.insert(board[m][n]);
                    }
                }
            }
        }
        return true;
    }
};