class Solution {
public:
    //To get the No from the array of int elements...
    int getNo(vector<int>&v){
        int temp=0;
        for(int i:v){
            temp = temp*10 + i;
        }
        return temp;
    }

    bool reorderedPowerOf2(int n) {
        vector<int>v;
        while(n!=0){
            v.push_back(n%10);
            n/=10;
        }
        sort(v.begin(),v.end());

        do{
            if(v[0]!=0){
                int temp = getNo(v);
                if((temp&(temp-1)) == 0) return true;
            }
        }while(next_permutation(v.begin(),v.end()));//Built-in function to find all permutaions...
        return false;
    }
};