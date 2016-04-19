#include <iostream>
#include <vector>

#define MAX_N 10005  // maximum # nodes in graph
#define LOG_MAX_N 14 // (ceil(log_2(MAX_N)))

using namespace std;

int N;
vector<int> adj[MAX_N]; // adjacency list
int centroid_ancestors[MAX_N][LOG_MAX_N]; // centroid_ancestors[i][j] = ancestor of i at level j
int centroid_lengths[MAX_N][LOG_MAX_N]; // centroid_lengths[i][j] = distance from i to ancestor at level j
int centroid_levels[MAX_N]; // centroid_levels[i] = level of node i
int _centroid_sizes[MAX_N]; // used internally, no meaning after constructing

int dfs(int node, int parent, int prev, int dist) {
    // *** note: assumes unweighted edges (edge lengths always 0)
    _centroid_sizes[node] = 1;
    if (prev != -1)
        centroid_lengths[node][centroid_levels[prev]] = dist;
    for (int i = 0; i < adj[node].size(); i++) {
        int u = adj[node][i];
        if (u == parent || centroid_levels[u] != -1)
            continue;
        _centroid_sizes[node] += dfs(u, node, prev, dist + 1);
    }
    return _centroid_sizes[node];
}

void setup_centroid(int start) {
    for (int i = 0; i < MAX_N; i++) {
        centroid_levels[i] = -1;
        for (int j = 0; j < LOG_MAX_N; j++) {
            centroid_ancestors[i][j] = -1;
            centroid_lengths[i][j] = -1;
        }
    }
    dfs(start, start, -1, 0);
}

void centroid(int start, int prev, int size, int level) {
    // already know sizes of all subtrees
    int biggest = -1;
    for (int i = 0; i < adj[start].size(); i++) {
        int u = adj[start][i];
        int s = _centroid_sizes[u];
        if (s > size/2) {
            biggest = u;
        }
    }
    if (biggest != -1) {
        // this node can't be the centroid because one subtree is > n/2
        _centroid_sizes[start] = size - _centroid_sizes[biggest];
        _centroid_sizes[biggest] = size;
        centroid(biggest, prev, size, level);
    } else {
        // this node is the centroid
        centroid_levels[start] = level;
        _centroid_sizes[start] = 0;
        // *** if necessary:
        centroid_ancestors[start][level] = start;
        centroid_lengths[start][level] = 0;
        // centroid_ancestors[node][level] = ancestor of node at level
        for (int i = level-1, p = prev; i >= 0; i--, p = centroid_ancestors[p][i]) {
            centroid_ancestors[start][i] = p;
        }
        // now find smaller centroids
        for (int i = 0; i < adj[start].size(); i++) {
            int u = adj[start][i];
            if (centroid_levels[u] == -1) {
                dfs(u, start, start, 1);
                centroid(u, start, _centroid_sizes[u], level + 1);
            }
        }
    }
}

void init_centroid(int root) {
    setup_centroid(root);
    centroid(root, -1, N, 0);
}

int main() {

    init_centroid(root);

    return 0;

}
