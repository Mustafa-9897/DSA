class Solution {
public:
    void helper(int col,vector<vector<string>>&ans,vector<string>&board,vector<int>&leftrow,vector<int>&lowerd,vector<int>&upperd,int n){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowerd[row+col]==0 && upperd[n-1+col-row]==0){
                leftrow[row]=1;
                upperd[n-1+col-row]=1;
                lowerd[row+col]=1;
                board[row][col]='Q';
                helper(col+1,ans,board,leftrow,lowerd,upperd,n);
                board[row][col]='.';
                leftrow[row]=0;
                upperd[n-1+col-row]=0;
                lowerd[row+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>board(n);
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftrow(n,0);
        vector<int>lowerd(2*n-1,0);
        vector<int>upperd(2*n-1,0);
        helper(0,ans,board,leftrow,lowerd,upperd,n);
        return ans;
    }
};