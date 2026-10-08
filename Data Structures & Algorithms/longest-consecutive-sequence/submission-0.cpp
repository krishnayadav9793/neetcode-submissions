class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto val:nums){
            st.insert(val);
        }
        int ans=0;
        for(auto val:nums){

            while(st.find(val)!=st.end() and st.find(val-1)==st.end()){
                int cnt=0,curr=val;
                while(st.find(curr)!=st.end()){
                    st.erase(curr);
                    cnt++;
                    curr++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
