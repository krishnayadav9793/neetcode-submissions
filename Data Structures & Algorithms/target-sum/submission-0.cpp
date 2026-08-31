class Solution {
public:
     map<vector<int>,int>dp;
    int fun(vector<int>& arr, int target,int i){
        int n = arr.size();
        if(i==n)return target==0;
        if(dp.count({i,target}))return dp[{i,target}];
        int ans=fun(arr,target-arr[i],i+1);
        int ans1=fun(arr,target+arr[i],i+1);
        return dp[{i,target}]=ans+ans1;
    }
    int totalWays(vector<int>& arr, int target) {
        //  code here
        return fun(arr,target,0);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return totalWays(nums,target);
    }
};
