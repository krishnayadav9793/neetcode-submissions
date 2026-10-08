class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        auto subBoxCheck=[&](int x,int y){
            unordered_map<char,int>mp;
            for(int i=x;i<x+3;i++){
                for(int j=y;j<y+3;j++){
                    if(mp.count(board[i][j]))return 0;
                    if(board[i][j]!='.')mp[board[i][j]]++;
                }
            }
            return 1;
        };
        auto rowCheck=[&](int row){
            unordered_map<char,int>mp;
            for(int j=0;j<n;j++){
                if(mp.count(board[row][j]))return 0;
                if(board[row][j]!='.')mp[board[row][j]]++;
            }
            return 1;
        };
        auto colCheck=[&](int col){
            unordered_map<char,int>mp;
            for(int i=0;i<n;i++){
                if(mp.count(board[i][col]))return 0;
                if(board[i][col]!='.')mp[board[i][col]]++;
            }
            return 1;
        };
        for(int row=0;row<n;row++){
            if(!rowCheck(row))return 0;
        }
        for(int col=0;col<n;col++){
            if(!colCheck(col))return 0;
        }
        for(int i=0;i<n;i+=3){
            for(int j=0;j<n;j+=3){
                if(!subBoxCheck(i,j))return 0;
            }
        }
        return 1;
    }
};
