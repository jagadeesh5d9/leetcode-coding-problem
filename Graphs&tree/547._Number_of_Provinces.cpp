class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //Make the map which map the elements...
        unordered_map<int,vector<int>>map;
        int n = isConnected.size();

        //make the map like Ex : {1:{1,4,7}}
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    map[i+1].push_back(j+1);
                }
            }
        }
        
        //Maintain the visited nodes...
        vector<bool> vis(n+1,false);
        int ans = 0;

        for(int i=1;i<=n;i++){
            if(vis[i]) continue;

            //BFS algorithm...
            queue<int>q;
            q.push(i);
            
            ans++;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int i:map[node]){
                    if(!vis[i]){
                        vis[i] = true;
                        q.push(i);
                    }
                }
            }

        }
        return ans;
    }
};