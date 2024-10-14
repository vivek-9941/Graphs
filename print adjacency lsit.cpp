 vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>> adjacent(V);
        for(int i = 0 ; i< edges.size(); i++){
            int u = edges[i].first;
            int v = edges[i].second;
            adjacent[u].push_back(v);
            adjacent[v].push_back(u);
            
            
        }
    
        return adjacent;
        
    }