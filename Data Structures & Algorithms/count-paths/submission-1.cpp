class Solution {
public:
    vector<vector<int>>dp;
    int fun(int i,int j,int n,int m){
        if(i==0 and j==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(i-1>=0)ans+=fun(i-1,j,n,m);
        if(j-1>=0)ans+=fun(i,j-1,n,m);
        return dp[i][j]=ans;
    }
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i)dp[i][j]+=dp[i-1][j];
                if(j)dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
