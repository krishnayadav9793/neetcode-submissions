class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i:s){
            if(i=='(' or i=='{' or i=='[')st.push(i);
            else{
                if(st.empty())return 0;
                if(i==')'){
                    if(st.top()!='(')return 0;
                }else if(i=='}'){
                    if(st.top()!='{')return 0;
                }
                else{
                    if(st.top()!='[')return 0;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
