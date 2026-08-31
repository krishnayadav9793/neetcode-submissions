class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>in(n);
        vector<int>graph[n];
        for(auto i:prerequisites){
            graph[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int top=q.front();
            ans.push_back(top);
            q.pop();
            for(auto i:graph[top]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()!=n)return {};
        return ans;
    }
};
