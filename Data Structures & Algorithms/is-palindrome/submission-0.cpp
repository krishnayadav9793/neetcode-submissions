class Solution {
public:
    bool isPalindrome(string s) {
        auto check = [](char c){
            if(c>='a' and c<='z')return 1;
            else if(c>='A' and c<='Z')return 1;
            else if(c>='0' and c<='9')return 1;
            return 0;
        };
        string ans="";
        for(auto i:s){
            if(check(i)){
                ans+=tolower(i);
            }
        }
        string temp=ans;
        reverse(temp.begin(),temp.end());
        return ans==temp;
    }
};
