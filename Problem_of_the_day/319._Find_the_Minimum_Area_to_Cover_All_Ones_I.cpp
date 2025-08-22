class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int h_s= INT_MAX,w_s = INT_MAX;
        int h_e = INT_MIN,w_e = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    //find start and end point of height and width of the grid...
                    h_s = min(h_s, i);
                    h_e = max(h_e, i);
                    w_s = min(w_s, j);
                    w_e = max(w_e, j);
                }
            }
        }

        int x = (h_e - h_s)+1;
        // cout<<x<<" ";
        int y = (w_e - w_s)+1;
        // cout<<y;
        return (x)*(y);
    }
};

TC: O(n^2)
SC: O(1)