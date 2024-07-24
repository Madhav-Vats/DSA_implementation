#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll ,ll> pp;


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n , m;
    cin>>n>>m;

    // unordered_map<int,list<pair<int,int>>>adjList;
    unordered_map<int,list<pp>>adjList;

    for(int i=0;i<m;i++)
    {
        int a , b , d;
        cin>>a>>b>>d;
        adjList[a].push_back({b , d});
    }

    vector<ll>dist(n+1, LLONG_MAX);
    dist[1] = 0;

    priority_queue<pp , vector<pp> , greater<pp>>pq;
    pq.push({0 , 1});

    while(!pq.empty())
    {
        auto [soFar , node] = pq.top();
        pq.pop();

        if(soFar > dist[node]) continue;

        for(auto [nbr , weight] : adjList[node])
        {
            if(weight + soFar < dist[nbr])
            {
                dist[nbr] = weight + soFar;
                pq.push({dist[nbr], nbr});
            }
        }

    }

    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
        
}