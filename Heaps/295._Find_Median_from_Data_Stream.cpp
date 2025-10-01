//Using min-max heap technique..
//optimal solution...
    class MedianFinder {
    public:
        priority_queue<int,vector<int>,greater<int>>min;
        priority_queue<int>max;

        MedianFinder() {
            
        }
        
        //flow:- minHeap -> MaxHeap -> MinHeap(if min.size()<max.size())
        void addNum(int num) {
            min.push(num);
            int mini = min.top();
            min.pop();
            max.push(mini);
            if(min.size()<max.size()){
                min.push(max.top());
                cout<<max.top()<<" ";
                max.pop();
            }
        }
        
        double findMedian() {
            if(min.size()>max.size())
                return (double)min.top();
            
            return (double)(min.top()+max.top())/2;
            
        }
    };

    Time complexity : 
        addNum : O(log n) 
        findMedian : O(1)

    Space complexity: O(n) for priority queues...

// Brute force approach:
    class MedianFinder {
    public:
        priority_queue<int>pq;
        MedianFinder() {
        }
        
        void addNum(int num) {
            pq.push(num);
        }
        
        double findMedian() {
            int n = pq.size();
            double median;
            vector<int>v;

            if((n&1) ==1){
                int c = n/2;
                while(c--){
                    v.push_back(pq.top());
                    pq.pop();
                }
                median = (double)pq.top();
            }else{
                int c = (n/2)-1;
                cout<<pq.size()<<"-:";
                while(c--){
                    v.push_back(pq.top());
                    pq.pop();
                }

                int temp = pq.top();
                v.push_back(pq.top());
                pq.pop();
                temp = temp + pq.top();
                // cout<<temp<<endl;
                median = (double)temp/2;
            }
            for(int i:v){
                pq.push(i);
            }
            return median;
        }
    };

    Time complexity :
        addNum : O(log n)
        findMedian : O(n)
    Space complexity:
        O(1)