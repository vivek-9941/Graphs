bool dfs(int node, vector<int> pathvis, vector<int> vis, vector<int> adj[])
{

    vis[node] = 1;
    pathvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, pathvis, vis, adj))
                return true;
        }
        else if (pathvis[it])
            return true;
    }
    pathvis[node] = 0;
    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<int> vis(V, 0);
    vector<int> pathvis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, pathvis, vis, adj))
                return true;
        }
    }
    return false;
}