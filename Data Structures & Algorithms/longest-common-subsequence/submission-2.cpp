class Solution {
public:
    vector<vector<int>>dp;
    int fun(string s,string t,int i,int j){
        if(i==-1||j==-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])return dp[i][j]=1+fun(s,t,i-1,j-1);
        return dp[i][j]=max(fun(s,t,i-1,j),fun(s,t,i,j-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        dp.resize(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j])dp[i+1][j+1]=1+dp[i][j];
                else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[n][m];
    }
};
