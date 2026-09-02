class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>nse(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top();
            }
            st.push(i);
        }
        while(st.size())st.pop();
        vector<int>pse(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() and nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<nse[i]<<" "<<pse[i]<<endl;
            ans=max(ans,(nse[i]-pse[i]-1)*nums[i]);
        }
        return ans;
    }
};
