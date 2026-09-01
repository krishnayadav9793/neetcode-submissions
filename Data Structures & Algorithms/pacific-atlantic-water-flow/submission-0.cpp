class Solution {
    vector<int>dx={1,-1,0,0},dy={0,0,1,-1};
public:
    void reachPossiable(vector<vector<int>>& heights,
    queue<pair<int,int>>&q,vector<vector<int>>&reach){
        int n=heights.size(),m=heights[0].size();
        auto check =[&](int x,int y)->bool{
            return x>=0 and y>=0 and x<n and y<m;
        };
        while(!q.empty()){
            auto [row , col] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int newRow=row+dx[k],newCol=col+dy[k];
                if(check(newRow,newCol) and 
                heights[newRow][newCol]>=heights[row][col] and
                !reach[newRow][newCol]){
                    reach[newRow][newCol]=1;
                    q.push({newRow,newCol});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>reachP(n,vector<int>(m)),reachA(n,vector<int>(m));
        queue<pair<int,int>>queueP,queueA;
        for(int i=0;i<n;i++){
            reachP[i][0]=1;
            queueP.push({i,0});
            reachA[i][m-1]=1;
            queueA.push({i,m-1});
        }
        for(int j=0;j<m;j++){
            reachA[n-1][j]=1;
            queueA.push({n-1,j});
            reachP[0][j]=1;
            queueP.push({0,j});
        }
        reachPossiable(heights,queueA,reachA);
        reachPossiable(heights,queueP,reachP);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(reachA[i][j] and reachP[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
