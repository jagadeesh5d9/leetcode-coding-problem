class Solution {
public:
//For validate given cell..
    bool isValid(int i,int j, char c,vector<vector<char>>& board){
        //row..
        for(int l=0;l<9;l++){
            if(board[i][l]==c) return false;
        }
        //col...
        for(int l=0;l<9;l++){
            if(board[l][j]==c) return false;
        }
        //For 3x3 matrix...
        for(int l=0;l<9;l++){
            //Row will be changed at some particular interval so we used "3*(i/3)+(l/3)"
            //Col will be channged in every iteration so that we used "3*(j/3)+(l%3)"...
            if(board[3*(i/3)+(l/3)][3*(j/3)+(l%3)] == c) return false;
        }
        return true;
    }

    bool helper(vector<vector<char>>& board){
        //Traverse the 2D array..
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.'){
                    //Check for all possibilities...
                    for(char p='1';p<='9';p++){
                        if(isValid(i,j,p,board)){
                            board[i][j] = p;
                            //check for the remaining empty place when p is inserted...
                            if(helper(board) == true){//recursion in the loop i->9...
                                return true;
                            }else{
                                board[i][j] = '.';//change back it into empty because that will not create a valid sudoko..
                            }
                        }
                    }
                    return false;
                }
            }
        }
        //If not "FALSE" then "True"...
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};