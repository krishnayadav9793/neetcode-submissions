class Solution {
    vector<int>dx={0,0,1,-1};
    vector<int>dy={1,-1,0,0};
public:
    vector<vector<bool>>visited;
    void fun(int i,int j,vector<vector<char>>& grid){
        int n=grid.size(),m=grid[0].size();
        auto check = [&](int a,int b)->bool {
            if(a<n and b<m and a>=0 and b>=0)return 1;
            return 0;
        };
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k],y=j+dy[k];
            if(check(x,y) and !visited[x][y] and grid[x][y]-'0'==1){
                fun(x,y,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        visited.resize(n,vector<bool>(m));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] and grid[i][j]-'0'){
                    ans++;
                    fun(i,j,grid);
                }
            }
        }
        return ans;
    }
};
