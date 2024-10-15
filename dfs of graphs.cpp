void dfs(int node, vector<vector<int>> &adj, vector<int> &arr, vector<int> &vis)
{
    vis[node] = 1;
    arr.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, arr, vis);
        }
    }
}

public:
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(vector<vector<int>> &adj)
{
    // Code here
    int n = adj.size();
    vector<int> vis(n, 0);
    int start = 0;
    vector<int> arr;

    dfs(start, adj, arr, vis);
    return arr;
}