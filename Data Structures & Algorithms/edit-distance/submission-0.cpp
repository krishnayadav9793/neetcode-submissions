class Solution {
public:
    vector<vector<int>>dp;
    int fun(string word1,string word2,int i,int j){
        if(i==-1)return j+1;
        if(j==-1)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])return dp[i][j]= fun(word1,word2,i-1,j-1);
        return dp[i][j]=1 + min({
            fun(word1,word2,i-1,j-1),
            fun(word1,word2,i-1,j),
            fun(word1,word2,i,j-1)
        });
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        dp.resize(n,vector<int>(m,-1));
        return fun(word1,word2,n-1,m-1);
    }
};
