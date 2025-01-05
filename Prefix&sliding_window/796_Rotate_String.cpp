class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;

        vector<char>m1;
        for(int i=0;i<goal.length();i++){
            m1.push_back(goal[i]);
        }

        vector<char>m2;

        string str = s + s;
        int l=0,r=0;
        while(r<str.length()){
            if(r-l+1<goal.length()){
                m2.push_back(str[r]);
                r++;
            }else{
                m2.push_back(str[r]);
                 if(m1==m2) return true;
                m2.erase(m2.begin());
                l++;
                r++;
            }
        }
        return false;
    }
};

// we can also solve this using find() which has time complexity of O(n)