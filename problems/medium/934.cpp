// Number: 934
// Name: Shortest Bridge
// Tags: matrix, DFS

// O(N + M + N*M) ; O(N + M)
class Solution_0 {
public:
    void collectIslandPoints(int i, int j, vector<pair<int, int>>& island, vector<vector<int>>& grid) {
        island.push_back(make_pair(i, j));
        grid[i][j] = 0;
        if (i < grid.size() - 1 && grid[i + 1][j] == 1) collectIslandPoints(i + 1, j, island, grid);
        if (i > 0 && grid[i - 1][j] == 1) collectIslandPoints(i - 1, j, island, grid);
        if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) collectIslandPoints(i, j + 1, island, grid);
        if (j > 0 && grid[i][j - 1] == 1) collectIslandPoints(i, j - 1, island, grid);
    }
    
    void findMinimalDistance(const pair<int, int>& x, const vector<pair<int, int>>& island, int& ans_dist) {
        for (const auto& p : island)
            ans_dist = min(ans_dist, abs(x.first - p.first) + abs(x.second - p.second) - 1);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        // find points of the first island
        // find points of the second island
        // go through all points of first island and calculate distance to all other points of another island
        // return the min of them
        // O(N + M + N*M) => O(N*M) time; O(N + M) space
        vector<pair<int, int>> firstIsland;
        vector<pair<int, int>> secondIsland;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    if (firstIsland.empty()) collectIslandPoints(i, j, firstIsland, grid);
                    else collectIslandPoints(i, j, secondIsland, grid);
                }
                if (!firstIsland.empty() && !secondIsland.empty()) {
                    j = grid[0].size();
                    i = grid.size();
                }
            }
        }
        // now we calculace and compare all distances between islands
        // by going through all points of first island
        int ans_distance = INT_MAX;
        for (const auto& x : firstIsland) {
            findMinimalDistance(x, secondIsland, ans_distance);
        }
        return ans_distance;
    }
};

