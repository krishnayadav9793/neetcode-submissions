class Solution {
public:
    vector<vector<string>>ans;
    bool check(int i,int j,int n,vector<string>&arr){
        for(int k=j;k<n;k++){
            if(arr[i][k]=='Q')return 0;
        }
        for(int k=j;k>=0;k--){
            if(arr[i][k]=='Q')return 0;
        }
        for(int k=i;k<n;k++){
            if(arr[k][j]=='Q')return 0;
        }
        for(int k=i;k>=0;k--){
            if(arr[k][j]=='Q')return 0;
        }
        for(int k=i,l=j;k>=0 and l>=0;k--,l--){
            if(arr[k][l]=='Q')return 0;
        }
        for(int k=i,l=j;k>=0 and l<n;k--,l++){
            if(arr[k][l]=='Q')return 0;
        }
        for(int k=i,l=j;k<n and l>=0;k++,l--){
            if(arr[k][l]=='Q')return 0;
        }
        for(int k=i,l=j;k<n and l<n;k++,l++){
            if(arr[k][l]=='Q')return 0;
        }
        return 1;
    }
    void fun(int row,int n,vector<string>&arr){
        if(row==n){
            ans.push_back(arr);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(row,i,n,arr)){
                arr[row][i]='Q';
                fun(row+1,n,arr);
                arr[row][i]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++)s+='.';
        vector<string>arr(n,s);
        fun(0,n,arr);
        return ans;
    }
};
