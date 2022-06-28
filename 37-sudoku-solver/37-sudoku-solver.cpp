class Solution {
public:
    bool isSafe(vector<vector<char>>board,int i,int j,char key,int n){
        for(int k=0;k<n;k++){
            if(board[k][j]==key){
                return false;
            }
            if(board[i][k]==key){
                return false;
            }
        }
        for(int k=3*(i/3);k<3*(i/3)+3;k++){
            for(int l=3*(j/3);l<3*(j/3)+3;l++){
                if(board[k][l]==key){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            
            for(int j=0;j<9;j++){
                
                if(board[i][j]=='.'){
                    
                    for(char k='1';k<='9';k++){
                        bool safe=isSafe(board,i,j,k,9);
                        if(safe){
                            board[i][j]=k;
                        
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';                            
                            }
                            
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};