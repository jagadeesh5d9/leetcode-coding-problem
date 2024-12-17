class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pref_xor(n);
        pref_xor[0] = arr[0];
        for(int i=1;i<n;i++){
            pref_xor[i] = pref_xor[i-1]^arr[i];
        }

        vector<int> v;
        for(int i=0;i<queries.size();i++){
           
            int l = queries[i][0];

            int r = queries[i][1];

            if(l==0) 
                v.push_back(pref_xor[r]);
            else
                v.push_back((pref_xor[r]^pref_xor[l-1]));
        }

        return v;
    }
};