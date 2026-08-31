class Solution {
public:
    vector<vector<int>>dp;
    int fun(vector<int>& nums,int i,int prev){
        if(i>=nums.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take=0;
        for(int j=i;j<nums.size();j++){
            if(prev==-1 or nums[j]>nums[prev]){
                take=max(take,1+fun(nums,j+1,j));
            }
        }
        int notTake = fun(nums,i+1,prev);
        return dp[i][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(nums.size()+1,-1));
        return fun(nums,0,-1);
    }
};
