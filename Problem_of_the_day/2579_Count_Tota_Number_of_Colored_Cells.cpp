class Solution {
    public:
        long long coloredCells(int n) {
            // Formula for finding blue cells that touches uncolored cells 
            return pow(n,2)+pow(n-1,2);
        }
    };