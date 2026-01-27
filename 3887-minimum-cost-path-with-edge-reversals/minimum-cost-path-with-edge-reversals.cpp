class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adj(n);
        for(auto p : edges){
            int u = p[0];
            int v = p[1];
            int wt = p[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2*wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist, node
        vector<int> dist(n, INT_MAX);
        pq.push({0, 0});
        dist[0] = 0;

        while(!pq.empty()){
            int currNode = pq.top().second;
            int currWt = pq.top().first;
            pq.pop();
            for(auto nei : adj[currNode]){
                int num = nei.first;
                int wt = nei.second;
                if(currWt + wt < dist[num]){
                    dist[num] = currWt + wt;
                    pq.push({dist[num], num});
                }
            }
        }
        if(dist[n-1]==INT_MAX) return -1;
        return dist[n-1];
    }
};