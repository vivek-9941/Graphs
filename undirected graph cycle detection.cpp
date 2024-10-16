public:
bool dfs(vector<int> &vis, int prev, int node, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] && it != prev)
            return true;
        if (!vis[it])
        {
            if (dfs(vis, node, it, adj))
                return true;
        }
    }
    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    // Code here\\

    // upto tthis is okay if graph 9ns fully connvected
    vector<int> vis(V, 0);
    int prev = -1;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(vis, prev, i, adj))
            {
                return true;
            }
        }
        // if graph is not connected fully
    }
    return false;
}