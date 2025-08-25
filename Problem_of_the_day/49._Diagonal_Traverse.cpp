class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int i=0,j=0;
        bool up = true;//For the Direction...
        
        vector<int>ans;
        while((i*j)<=(row*col)){//until the last cell..
            if(up){//If direction is going up
                while(i>=0 && j<col){
                    ans.push_back(mat[i][j]);
                    i--;//Row is decreased..
                    j++;//col is increased..
                }
                //If out of bound,back to the posion
                if(j==col){
                    i+=2;
                    j-=1;
                }else{
                    i+=1;
                }
                up = false;
            }else{//if direction is down..
                while(j>=0 && i<row){
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }

                if(i==row){
                    j+=2;
                    i-=1;
                }else{
                    j+=1;
                }
                up=true;
            }
        }
        return ans;
    }
};