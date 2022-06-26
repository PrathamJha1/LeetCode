class Solution {
public:
    vector<vector<string>>ret;
    bool isPossible(vector<string>board,int row,int col){
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q')return false;
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row,j=col;j<board.size() && i>=0;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void helper(int i,int n,vector<string>&board){
        if(i==n){
            ret.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isPossible(board,i,j)){
                board[i][j]='Q';
                helper(i+1,n,board);
                board[i][j]='.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n==1){
            vector<string > temp;
            temp.push_back("Q");
            ret.push_back(temp);
            return ret;
        }
        if(n<=3){
            return ret;
        }
        vector<string> board(n,string(n,'.'));
        helper(0,n,board);
        return ret;
    }
};