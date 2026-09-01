class Solution {
    vector<int>dx={0,0,-1,1},dy={-1,1,0,0};
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        auto check = [&](int a,int b)->bool{
            return a>=0 and b>=0 and a<n and b<m;
        };
        vector<vector<bool>>visited(n,vector<bool>(m));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' and !visited[i][0]){
                visited[i][0]=1;
                q.push({i,0});
            }
            if(board[i][m-1]=='O' and !visited[i][m-1]){
                visited[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' and !visited[0][j]){
                visited[0][j]=1;
                q.push({0,j});
            }
            if(board[n-1][j]=='O' and !visited[n-1][j]){
                visited[n-1][j]=1;
                q.push({n-1,j});
            }
        }
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i=top[0],j=top[1];
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(check(x,y) and !visited[x][y] and board[x][y]=='O'){
                    visited[x][y]=1;
                    q.push({x,y});
                }
            } 
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] and board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
