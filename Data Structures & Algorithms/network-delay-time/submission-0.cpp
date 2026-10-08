class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 1e5;
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto &edge:times)graph[edge[0]].push_back({edge[1],edge[2]});
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>ans(n+1,INF);
        ans[k]=0;
        while(!pq.empty()){
            auto top = pq.top();
            // cout<<dist<<" "<<u<<endl;
            pq.pop();
            int dist=top.first,u=top.second;
            // if(ans[u]<dist)continue;
            for(auto node:graph[u]){
                int v=node.first , wt=node.second;
                // cout<<u<<" "<<v<<" "<<wt<<endl;
                
                if(ans[v]>dist+wt){
                    ans[v]=dist+wt;
                    pq.push({dist+wt,v});
                }
            }
        }
        int maxtime=0;
        for(int i=1;i<=n;i++){
            // cout<<i<<" ";
            // cout<<ans[i]<<" ";
            if(ans[i]!=INF)maxtime = max(ans[i],maxtime);
            else return -1;
        }
        return maxtime;
    }
};
