class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int last=INT_MIN,ans=0;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(last<=intervals[i][0]){
                last=intervals[i][1];
            }else{
                ans++;
               
            }
        }
        return ans;
    }
};
