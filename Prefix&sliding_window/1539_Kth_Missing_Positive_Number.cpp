class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int size = arr.size();
        int n = arr[size-1];//last element to be traversed...

        int i=1;//check each no from 1 to n whether matching or not
        int p=0;//For traversing the array elements..

        while(i<=n && p<size){
            if(i == arr[p]){
                p++;
            }else{
                k--;
            }
            if(k==0) return i;
            i++;
        }

        return (arr[size-1]+k);
    }
};

