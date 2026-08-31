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
        for(auto i:nums)sum+=i;
        if(sum%2)return 0;
        dp.resize(nums.size(),vector<int>(sum/2+1,-1));
        return fun(nums,nums.size()-1,sum/2);
    }
};
