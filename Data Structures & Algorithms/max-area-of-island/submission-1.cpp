class Solution {
    vector<int>dx={0,0,-1,1},dy={1,-1,0,0};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        auto check = [&](int x,int y)->bool{
            return x>=0 and y>=0 and x<n and y<m;
        };
        int ans=0;
        vector<vector<bool>>visited(n,vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] and (grid[i][j])){
                    queue<vector<int>>q;
                    q.push({i,j});
                    int sum=1;
                    while(!q.empty()){
                        auto top = q.front();
                        q.pop();
                        int i=top[0],j=top[1];
                        // cout<<i<<" "<<j<<endl;
                        visited[i][j]=1;
                        for(int k=0;k<4;k++){
                            int x=i+dx[k],y=j+dy[k];
                            if(check(x,y) and !visited[x][y] 
                            and (grid[x][y])){
                                visited[x][y]=1;
                                sum++;
                                q.push({x,y});
                            }
                        }
                    }
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};
