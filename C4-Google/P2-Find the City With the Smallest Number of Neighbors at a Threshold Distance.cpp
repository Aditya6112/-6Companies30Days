// Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        // Floyd-Warshall algorithm to compute all pairs shortest paths
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Find the city with the smallest number of reachable cities within distanceThreshold
        int minCount = n, city = -1;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            if (count <= minCount) {
                minCount = count;
                city = i;
            }
        }
        
        return city;
    }
};