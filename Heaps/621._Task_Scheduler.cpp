class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //Count the frequency of the elements...
        unordered_map<char,int>map;

        for(char i:tasks){
            map[i]++;
        }

        priority_queue<int>pq;
        int maxi = INT_MIN;
        for(auto i:map){
            pq.push(i.second);
            maxi = max(maxi,i.second);
        }

        int ans = 0;

        while(!pq.empty()){
            int c=0;//count the elements per block i.e, n+1 elements per block...
            vector<int>v;//For maintaining the frequencies of the poped frequencies from the pq...
            while(!pq.empty() && c<=n){
                int top = pq.top()-1;
                pq.pop();
                if(top!=0){//Nothing to push...
                    v.push_back(top);
                }
                c++;
            }
            //After updating the frequencies of the elements...
            for(int i:v){
                pq.push(i);
            }
            
            ans += pq.empty() ? c : n+1;//Condition for the last block which doesn't need idles
        }

        return ans;
    }
};