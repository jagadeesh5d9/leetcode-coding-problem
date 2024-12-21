class Solution {
public:
    //Function to find whether the character is vowel or not...

    bool isVowel(char str){
        if(str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u'){
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix_sum(words.size());
        int sum=0;
        //Finding prefix_sum array...
        for(int i=0;i<words.size();i++){
            string str = words[i];
            if(isVowel(str[0]) && isVowel(str[str.length()-1])){
                sum += 1;
            }
            prefix_sum[i] = sum;
        }

        vector<int> ans;//Store the result of each query

        //function to find no of strings that starts and ends with a vowel...
        for(int i=0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int temp = prefix_sum[r]-prefix_sum[l];
            temp += (isVowel(words[l][0]) && isVowel(words[l][words[l].length()-1])) ? 1:0;

            ans.push_back(temp);
        }

        return ans;
    }
};