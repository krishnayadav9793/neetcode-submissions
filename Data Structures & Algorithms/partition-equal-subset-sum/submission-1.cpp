class Solution {
public:
    vector<vector<int>>dp;
    bool fun(vector<int>&nums,int i,int sum){
        if(sum==0)return 1;
        if(i<=-1)return 0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool ans=0;
        if(sum>=nums[i])ans|=fun(nums,i-1,sum-nums[i]);
        ans|=fun(nums,i-1,sum);
        return dp[i][sum]=ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto i:nums)sum+=i;
        if(sum%2)return 0;
        dp.resize(n+1,vector<int>(sum/2+2));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                bool ans=0;
                if(j>=nums[i])dp[i+1][j]|=dp[i][j-nums[i]];
                dp[i+1][j]|=dp[i][j];
            }
        }
        return dp[n][sum/2];
    }
};
