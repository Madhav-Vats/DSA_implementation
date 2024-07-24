#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
unordered_map<int, list<int>> adjList;
vector<int>parent;

void dfs(int src ) {

    visited[src] = true;

    for(auto nbr: adjList[src])
    {
        if(!visited[nbr])
        {
            dfs(nbr);
        }
        else if(visited[nbr] && nbr != parent[src])
        {
            
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    parent = vector<int>(n + 1, -1);
    visited = vector<bool>(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int ans = bfs(i);
            if(ans !=-1)
                break;
        }
    }

    //backtracking ans for soln




    return 0;
}
