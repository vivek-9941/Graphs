class Solution
{
public:
    void dfs(vector<vector<int>> &adjl, int node, vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adjl[node])
        {
            if (!vis[it])
            {
                dfs(adjl, it, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &adj)
    {
        int cnt = 0;

        vector<vector<int>> adjl(adj.size());
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj.size(); j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjl[j].push_back(i);
                    adjl[i].push_back(j);
                }
            }
        }
        int n = adjl.size();

        vector<int> vis(n, 0);

        for (int i = 0; i < adj.size(); i++)
        {

            if (!vis[i])
            {
                dfs(adjl, i, vis);
                cnt++;
            }
        }
        return cnt;
    }
};