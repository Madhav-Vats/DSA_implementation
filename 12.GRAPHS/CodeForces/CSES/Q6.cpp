#include <bits/stdc++.h>
using namespace std;

vector<int> color;
unordered_map<int, list<int>> adjList;

bool bfs(int src) {
    queue<pair<int, int>> q;
    q.push({src, 0});

    while (!q.empty()) {
        auto [node, currCol] = q.front();
        q.pop();

        for (auto nbr : adjList[node]) {
            if (color[nbr] == -1) {
                color[nbr] = !currCol;
                q.push({nbr, color[nbr]});
            }
            if (color[nbr] != -1 && color[nbr] == currCol) {
                return false;
            }
        }
    }
    return true;
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

    color = vector<int>(n + 1, -1);

    bool ans = true;

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            ans = bfs(i);
            if (!ans) break;
        }
    }

    //Main idea , non approachable groups can be
    // all classified into any of the grp

    if (!ans) {
        cout << "IMPOSSIBLE";
    } else {
        for (int i = 1; i <= n; i++) {
            if(color[i] == -1)
            {
                cout<<1<<" ";
            }
            else{
                cout << color[i] + 1 << " "; // Output 1-based coloring
            }
        }
    }

    return 0;
}
