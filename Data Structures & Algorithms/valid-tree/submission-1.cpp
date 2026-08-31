class Solution {
public:
    vector<bool>visited;
    bool isCycle(int i,vector<int>graph[],int par){
        visited[i]=1;
        for(auto child:graph[i]){
            if(!visited[child]){
                if(isCycle(child,graph,i))return 1;
            }else if(child!=par)return 1;
        }
        return 0;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        visited.resize(n);
        vector<int>graph[n];
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i] and i!=0)return 0;
            if(!visited[i] and isCycle(i,graph,-1))return 0;
            
        }
        return 1;
    }
};
