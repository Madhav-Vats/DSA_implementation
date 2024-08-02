class Solution {
public:
    vector<int>color;
    unordered_map<int,list<int>>adjList;

    bool bp(int src)
    {

        queue<int>q;
        q.push(src);
        color[src]=0;

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(auto nbr: adjList[curr])
            {
                if(color[nbr] == -1)
                {
                    color[nbr] = 1-color[curr];
                    q.push(nbr);
                }
                else if(color[nbr] == color[curr])
                    return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        for(int i=0;i<n;i++)
        {
            for(auto it: graph[i])
            {
                adjList[i].push_back(it);
                adjList[it].push_back(i);
            }
        }

        color = vector<int>(n , -1);


        for(int i=0;i<n;i++)
        {
            if(color[i] == -1)
            {
                if(bp(i) == false)
                    return false;
            }
        }

        return true;
    }
};
