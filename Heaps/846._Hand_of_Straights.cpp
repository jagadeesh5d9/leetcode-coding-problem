class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        //Check for the grouping is possible or not...
        if((n % groupSize) !=0)
            return false; 

        priority_queue<int>pq;//max Heap...
        
        for(int i:hand){
            pq.push(i);
        }

        while(!pq.empty()){
            vector<int>v;
            //Count element for a group...
            int c = 1;
            int temp = pq.top();
            pq.pop();

            while(c<groupSize){
                if(pq.empty())//No elements , we can't make a group...
                    return false;

                int top = pq.top();
                // cout<<temp<<"- "<<top<<"; ";
                pq.pop();

                if(temp == top){//Handles the duplicates...
                    v.push_back(top);
                }else if(temp == top+1){
                    c++;
                }else{
                    return false;
                }
                temp = top;
            }
            //pushing duplicates in priority queue..
            for(int i:v){
                // cout<<i<<" ";
                pq.push(i);
            }
     
        }
        
        return true;
    }
};