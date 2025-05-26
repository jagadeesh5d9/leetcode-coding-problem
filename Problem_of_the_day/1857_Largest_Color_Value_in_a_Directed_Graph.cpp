class Solution {
public:

    int dfs(int s,vector<vector<int>>&adj,vector<int>&vis,string &colors,vector<vector<int>>&dp){
        
        if(vis[s] == 1) return INT_MAX;//any cycle observerd...

        if(vis[s] == 0){ //when it is not visited...
            vis[s] =1;
            for(auto temp:adj[s]){
                int res = dfs(temp,adj,vis,colors,dp);//Recurssive call for the adjecent nodes...

                if(res == INT_MAX) return INT_MAX; // any cycle observed...

                for(int i=0;i<26;i++){
                    //find the max in the "s"th coloum...
                    dp[i][s] = max(dp[i][s],dp[i][temp]);//make the column as the max value instead of finding the max value..
                }
            }
            //make it as follows when backtrack is started...
            vis[s] = 2;
            dp[colors[s]-'a'][s]++;
        }
        return dp[colors[s]-'a'][s];//because this is the max value in the 's' coloum...
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }

        //vis array for status of the nodes , here we are using the 3 color code
            // 0-unvisited
            // 1-vis under processing [chance of cycle formation]
            // 2-vis and processed.. [traversing completed...]

        vector<int>vis(n);

        vector<vector<int>>dp(26,vector<int>(n,0));

        int ans = 0;
        for(int i=0;i<n;i++){
            int res = dfs(i,adj,vis,colors,dp);
            if(res == INT_MAX) return -1;//any cycle identified...

            ans = max(ans,res);
        }
        return ans;
    }
};