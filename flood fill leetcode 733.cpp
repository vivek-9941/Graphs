

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        int startColor = image[sr][sc];
        if (startColor == color)
            return image; // No need to proceed if the target color is the same

        q.push({sr, sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color; // Fill the starting pixel with the new color

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && image[nrow][ncol] == startColor)
                {

                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color; // Fill the connected pixels with the new color
                }
            }
        }

        return image;
    }
};
