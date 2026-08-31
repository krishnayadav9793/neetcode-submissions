class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>graph[n];
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<bool>visited(n);
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int top=q.front();
                    q.pop();
                    visited[top]=1;
                    for(auto i:graph[top]){
                        if(!visited[i]){
                            q.push(i);
                        }
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};
