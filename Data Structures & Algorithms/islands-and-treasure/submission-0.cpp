class Solution {
    vector<int>dx={0,0,-1,1},dy={1,-1,0,0};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        const int INF = 2147483647;
        int n=grid.size(),m=grid[0].size();
        auto check = [&](int x,int y)->bool{
            return x>=0 and y>=0 and x<n and y<m;
        };
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            auto top = q.front();
            int dist=top[2],i=top[0],j=top[1];
            q.pop();
            for(int k=0;k<4;k++){
                int x=i+dx[k],y=j+dy[k];
                if(check(x,y) and grid[x][y]!=-1 and grid[x][y]>dist+1){
                    grid[x][y]=dist+1;
                    q.push({x,y,dist+1});
                }
            }
        }
    }
};
