class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int>count(26);
       for(auto i:s){
        count[i-'a']++;
       }
       for(auto i:t){
        count[i-'a']--;
       }
       for(auto i:count){
        if(i)return 0;
       }
       return 1;
    }
};
