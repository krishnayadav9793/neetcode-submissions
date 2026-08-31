class dsu{
    public:
        vector<int>parent,rank;
        dsu(int n){
            parent.resize(n+1);
            rank.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int find(int node){
            if(parent[node]==node)return parent[node];
            return parent[node]=find(parent[node]);
        }

        bool unite(int u,int v){
            int parU=find(u),parV=find(v);
            if(parU==parV)return 1;
            if(rank[parU]>rank[parV]){
                parent[parV]=parU;
            }else if(rank[parU]<rank[parV]){
                parent[parU]=parV;
            }else{
                parent[parU]=parV;
                rank[parV]++;
            }
            return 0;
        }
};



class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        dsu * node = new dsu(n);
        for(auto i:edges){
            if(node->unite(i[0],i[1]))return {i[0],i[1]};
        }
        return {};
    }
};
