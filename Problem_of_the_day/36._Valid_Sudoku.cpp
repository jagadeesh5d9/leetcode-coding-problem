class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        //For rows...
        for(int i=0;i<n;i++){
            int arr_el = 0;
            unordered_set<int>s;
            for(int j=0;j<m;j++){
                if(board[i][j]!='.'){
                    s.insert(board[i][j]);
                    arr_el++;
                    if(arr_el!=s.size()) return false;
                }
            }
        }
        //For cols...
        for(int i=0;i<m;i++){
            int arr_el = 0;
            unordered_set<int>s;
            for(int j=0;j<n;j++){
                if(board[j][i]!='.'){
                    s.insert(board[j][i]);
                    arr_el++;
                    if(arr_el!=s.size()) return false;
                }
            }
        }

        //For 3X3 matrix...
        //Initialize a 3x3 grid as a cell in 2D vector...
        vector<vector<unordered_set<int>>> v(3, vector<unordered_set<int>>(3));
        vector<vector<int>>ele(3,vector<int>(3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='.'){
                    //To set them in the 2D vector with set()..
                    int x = i/3;
                    int y = j/3;
                    v[x][y].insert(board[i][j]);
                    ele[x][y]+=1;
                    //Check for duplicates..
                    if(ele[x][y]!=v[x][y].size()) return false;
                }
            }
        }
        return true;
    }
};