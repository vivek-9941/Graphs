class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses); // Correct adj declaration
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]); // Fix indexing
        }

        vector<int> indegree(numCourses, 0); // Use numCourses for indegree size
        for (int i = 0; i < numCourses; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo.size() == numCourses;
    }
};
