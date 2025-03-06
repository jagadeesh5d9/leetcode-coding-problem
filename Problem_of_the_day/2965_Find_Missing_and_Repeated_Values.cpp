class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            unordered_map<int,int>v;
            int total = 0,rep;
            int n = grid.size();
            int temp = 0;//To Ignore checking of repeated values...
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    total += grid[i][j];//find sum of the elements in the grid...
    
                    if(v.find(grid[i][j])!=v.end() && temp==0){
                        v[grid[i][j]]++;
                        rep = grid[i][j];
                        temp = 1;
                    }
                    v[grid[i][j]]++;
                }
            }
            int repeat = total - rep;//sum without repeat element
            n = n*n;//No of elements in the grid...
            int sum = (n*(n+1)/2);//Sum of the n elements if no duplicate is there...
            int orginal = sum - repeat;//Missing values in the grid...
            vector<int>val;
            val.push_back(rep);
            val.push_back(orginal);
            return val;
        }
    };