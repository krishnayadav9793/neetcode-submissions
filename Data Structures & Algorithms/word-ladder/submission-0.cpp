class Solution {
public:
    vector<string> nextWords(string &s,vector<string>& wordList){
        vector<string>ans;
        auto check = [&](string &a,string &b)->bool{
            int n=a.size();
            int ans=0;
            for(int i=0;i<n;i++){
                if(a[i]!=b[i])ans++;
            }
            return ans==1;
        };
        for(auto i:wordList){
            if(check(i,s))ans.push_back(i);
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        const int INF=1e9+7;
        unordered_map<string,vector<string>>graph;
        graph[beginWord]=nextWords(beginWord,wordList);
        for(auto i:wordList){
            graph[i]=nextWords(i,wordList);
        }
        priority_queue<pair<int,string>,
        vector<pair<int,string>>,greater<pair<int,string>>>pq;
        pq.push({1,beginWord});
        unordered_map<string,int>res;
        res[beginWord]=1;
        while(!pq.empty()){
            auto top = pq.top();
            int dist=top.first;
            string str=top.second;
            pq.pop();
            if(res[str]<dist)continue;
            if(str==endWord)return dist;
            for(auto i:graph[str]){
                if(res.find(i)==res.end()){
                    res[i]=INF;
                }
                if(res[i]>dist+1){res[i]=dist+1;pq.push({dist+1,i});}
            }
        }
        return 0;
    }
};
