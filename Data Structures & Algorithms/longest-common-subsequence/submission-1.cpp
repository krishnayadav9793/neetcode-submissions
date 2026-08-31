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
        dp.resize(n,vector<int>(m,-1));
        return fun(text1,text2,text1.size()-1,text2.size()-1);
    }
};
