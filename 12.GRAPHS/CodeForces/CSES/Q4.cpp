#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
int n, m;
vector<int>parent;

vector<int>path;
unordered_map<int , list<int>>adjList;
int bfs(int src, int des)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            int front = q.front();
            q.pop();

            if(front == des)
            {
                while(true)
                {
                    path.push_back(front);
                    
                    if(front == src)
                        return level+1;
                        
                    front = parent[front];
                }
            }
            for(auto it: adjList[front])
            {
                if(!visited[it])
                {
                    parent[it] =  front;
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        level++;
    }

    return -1;
}

int main()
{
    cin >> n >> m;

    visited = vector<bool>(n , false);
    parent = vector<int>(n ,-1);

    for(int i=0;i<m;i++)
    {
        int a;
        int b;
        cin>>a>>b;
        a--;
        b--; //conv into 0 based indexing
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int ans = bfs(0 , n-1);

    if(ans != -1)
    {
        cout<<ans<<endl;
        for(int i=path.size()-1;i>=0 ;i--)
            cout<<path[i]+1<<" ";

    }
    else{
        cout<<"IMPOSSIBLE";
    }

}
