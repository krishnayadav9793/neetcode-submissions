class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
            nge[i]=i;
            while(st.size() and 
            temperatures[st.top()]<=temperatures[i])st.pop();
            if(st.size())nge[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            nge[i]-=i;
        }
        return nge;
    }
};
