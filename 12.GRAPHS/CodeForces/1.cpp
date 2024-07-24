#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5000;
const int MAX_M = 5000;

vector<pair<int, int>> adj[MAX_N];

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back({v - 1, 1});
            adj[v - 1].push_back({u - 1, 1});
        }

        vector<int> sources(M), destinations(M);
        for (int i = 0; i < M; i++) {
            cin >> sources[i] >> destinations[i];
            sources[i]--;
            destinations[i]--;
        }

        vector<vector<int>> dp(M + 1, vector<int>(2, INT_MAX));
        dp[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int time = pq.top().first;
            int day = pq.top().second.first;
            int f = pq.top().second.second;
            pq.pop();

            if (day == M) {
                cout << time << endl;
                break;
            }

            for (int i = 0; i < 2; i++) {
                int next_f = 1 - f;
                int next_day = day + 1;
                int next_time = time + abs(sources[day] - sources[day - 1]) + abs(destinations[day] - sources[day]);

                if (next_time < dp[next_day][next_f]) {
                    dp[next_day][next_f] = next_time;
                    pq.push({next_time, {next_day, next_f}});
                }
            }

            for (auto& edge : adj[sources[day]]) {
                int next_time = time + abs(sources[day] - edge.first) + 1;

                if (next_time < dp[day + 1][f]) {
                    dp[day + 1][f] = next_time;
                    pq.push({next_time, {day + 1, f}});
                }
            }
        }
    }

    return 0;
}
