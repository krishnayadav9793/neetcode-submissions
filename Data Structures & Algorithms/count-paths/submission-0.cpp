class Solution {
public:
    vector<vector<int>>dp;
    int fun(int i,int j,int n,int m){
        if(i==m-1 and j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(i+1<m)ans+=fun(i+1,j,n,m);
        if(j+1<n)ans+=fun(i,j+1,n,m);
        return dp[i][j]=ans;
    }
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,-1));
        return fun(0,0,n,m);
    }
};
