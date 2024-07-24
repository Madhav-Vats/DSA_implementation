#include <bits/stdc++.h>
using namespace std;
#include<list>
# include<unordered_map>






class Solution {
public:


// we will use priority queue instead of set this time

    // int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //
    //     unordered_map<int , list< pair<int,int>>>  adjList;
    //
    //
    //     int size = times.size();
    //
    //
    //     for(int i=0;i<size;i++)
    //     {
    //         adjList[times[i][0]].push_back({times[i][1] , times[i][2]});
    //     }

        vector<int>distance(n+1 ,INT_MAX);


        // STARTING DIJKSTRA
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

            //here k is the source
            int src = k;
            distance[src]= 0;
            pq.push({0,src});

            while(!pq.empty())
            {
                auto current = pq.top();

                int node = current.second;
                int node_weight = current.first;

                pq.pop();

                if(node_weight > distance[node]) continue;


                for(auto nbr: adjList[node])
                {
                    int nbr_node = nbr.first;
                    int nbr_distance = nbr.second;

                    if(node_weight + nbr_distance < distance[nbr_node])
                    {

                        distance[nbr_node] = node_weight + nbr_distance;

                        pair<int,int> temp = make_pair(distance[nbr_node] , nbr_node);

                        pq.push(temp);
                    }
                }
            }



        // ENDING DIJKSTRA



        int answer = INT_MIN;
               for(int i = 1; i <= n; i++){
                   answer = max(answer, distance[i]);
               }
               return (answer != INT_MAX) ? answer : -1;

    }
};



























// template <typename T>

// using int only
class graph{
public:
  unordered_map<int,list<pair<int,int>>> adjList;
  // tis map will handle both type of graphs
  // if undirected , make each weight as 1

  void addedge(int u, int v, int weight, bool directed)
  {

    pair<int,int> p = make_pair(v ,weight);
    adjList[u].push_back(p);

    //if not directed both edge should be added on both side elements
    if(!directed)
    {
      pair<int,int> p2 = make_pair(u ,weight);
      adjList[v].push_back(p2);
    }
    // no need to write for directed , bcoz its already been handled
  }

  void printadjList()
  {
    for(auto node : adjList)
    {
      cout<<node.first<<" --> ";
      for(auto neighbour: node.second)
      {
        cout<<"("<<neighbour.first<<","<<neighbour.second<<") ";
      }
      cout<<endl;
    }
  }

  void bfs(int src , unordered_map<int, bool> & visited) // or you could have written ( int src)
  {

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty())
    {
      int frontNode = q.front();
      q.pop();

      cout<<frontNode<<" ";
      // nbr or neighbour
      for(auto nbr: adjList[frontNode])
      {
        if(!visited[nbr.first])
        {
          q.push(nbr.first);
          visited[nbr.first]=true;
        }
      }
    }
  }

  void dfs(int src, unordered_map<int, bool> & visited)
  {
    visited[src]= true;
    cout<<src<<",";
    // there is no base case in it ,bcoz the time when
    //there is no neighbour of the src , then the recursion stack will return
    // and automatically it will end
    for(auto nbr : adjList[src])
    {
      if(!visited[nbr.first])
        dfs(nbr.first , visited);
    }
  }

  void djkstra_algo(int src , int des , unordered_map<int,int> &distance , int n)
  {
      // distance (unordered_map) should have all the values INT_MAX in the starting
      // making src's distance as 0
      distance[src] = 0;

      // here in this set we will push ( weight , value)
      // int adjList weight is given by node.second
      // and value is given by node.first

      set<pair<int,int>> sett;
      // pushing source in the set ( int the required format)
      int weight_src = 0;
      int value_src = src;
      sett.insert(make_pair(0 , src));  // curly brackets automatically converts dat into pair


      while(!sett.empty())
      {
        pair<int,int> frontNode = *(sett.begin());

        int node_weight = frontNode.first; // as the pair stored in the set is in format of
        int node = frontNode.second;       // (weight , node)

        // erase the begining element
        sett.erase(sett.begin());

        for(auto nbr : adjList[node])
        {

      // MAIN CONDITION CHECK ---> understand this thing , why we are using node_weight
          // we want to check whether what we are finding out from the set ,
          // is less than the stored value in distance or not
          if( node_weight + nbr.second  < distance[nbr.first] )
          {

      // SEARCHING , IF PRESENT ERASING THE PAIR
            // searching if the node is already present or not
            auto result = sett.find(make_pair(distance[nbr.first] , nbr.first));   // finding pair(weight , node)

            // if result becomes equal to the end of the set that means , the required pair is not found
            if(result != sett.end())
            {
              // that means its present , therefore need to remove it
              sett.erase(result);
            }

      // UPDATING THE DISTANCE MAP
            distance[nbr.first] = node_weight+ nbr.second;

      // UPDATIN THE SET BY INSERTING THE NEW PAIR
            sett.insert(make_pair(distance[nbr.first] , nbr.first));

            // change in set ( on the basis of the distance map conditions)
            // now we are going to search the previous value  present in the the distance

          }

        }



      }

    // NOW THE DISTANCE MATRIX IS COMPLETED ,

    // you can either get the shortest distance in the main function
    // or in any another function , so that you can you this function once
    //for all the shortest distances from  the source

    cout<<endl;
    cout<<"shortest distance btw source"<< src;
    cout<< " and the destination"<< des << " is == "<< distance[des]<<endl;

    // for the the distances
    cout<<"for all the nodes"<<endl;
    for(int i=0; i<n ; i++)
      cout<<"for "<< i << "-->" << distance[i] <<endl;


    }
























    void djks(int src , int &n)
    {
      set<pair<int,int>> sett;
      vector<int>distance(n,INT_MAX);

      distance[src]=0;
      sett.insert({0,src});
      // pairs are off form { weight, node value};



      while(!sett.empty())
      {
        pair<int,int> topElement = *(sett.begin());

        int node = topElement.second;
        int weight = topElement.first;


        sett.erase(sett.begin());


        // main condition
        for(auto nbr : adjList[node])
        {
          int nbr_weight = nbr.second;
          int nbr_node =nbr.first;
          if(weight + nbr_weight < distance[nbr_node] )
          {
            // updation in the set
            pair<int,int> pairFind = {distance[nbr_node] , nbr_node};
            auto result = sett.find(pairFind);

            if(result != sett.end())
            {
              sett.erase(result);
            }


            // updation in the distance map
            distance[nbr_node]= weight + nbr_weight;

            // adding the new pair in the sett
            sett.insert(make_pair(distance[nbr_node] , nbr_node));
          }

        }

      }

      cout<<"for all the nodes"<<endl;
      for(int i=0; i<n ; i++)
        cout<<"for "<< i << "-->" << distance[i] <<endl;

    }

};


class Solution {
public:

    void dijkstra(int &src , vector<int> & distance ,unordered_map<int,list<pair<int,int>>> &adjList)
    {
        set<pair<int,int>> st;

        distance[src]=0;
        st.insert({ 0, src});

        while(!st.empty())
        {
            auto current = *(st.begin());

            int node_weight = current.first;
            int node = current.second;

            st.erase(st.begin());

            for(const auto &nbr: adjList[node])
            {

                int nbr_val = nbr.first;
                int nbr_distance = nbr.second;
                // checking the main condition
                if(node_weight + nbr_distance < distance[nbr_val] )
                {

                    // search in the set and update if found
                    auto result = st.find(make_pair(distance[nbr_val] , nbr_val));

                    if(result != st.end())
                    {
                        st.erase(result);
                    }


                    // update in the distance vector
                    distance[nbr_val] = node_weight + nbr_distance;

                    // push this new pair into the set
                    st.insert({distance[nbr_val]  , nbr_val});

                }
            }
        }

    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int , list< pair<int,int>>>  adjList;



        for(auto it : times)
        {
            adjList[it[0]].push_back( {it[1] , it[2]} );
        }

        vector<int>distance(n+1 ,INT_MAX);



        dijkstra( k , distance , adjList );

        int answer = INT_MIN;
               for(int i = 1; i <= n; i++){
                   answer = max(answer, distance[i]);
               }
               return (answer != INT_MAX) ? answer : -1;

    }
};





int main()
{
//   graph g;
//
// // for integer graph
//   g.addedge(6,5,9,0);
//   g.addedge(5,4,6,0);
//   g.addedge(4,3,11,0);
//   g.addedge(4,2,15,0);
//   g.addedge(2,3,10,0);
//   g.addedge(6,3,2,0);
//   g.addedge(6,1,11,0);
//   g.addedge(1,3,9,0);
//   g.addedge(1,2,7,0);
//
//   g.printadjList();
//
// cout<<endl<<"--------------------------"<<endl;
// // number of nodes = 7;
// int n = 7;
//
// unordered_map<int,int>distance;
//
// //making all the values as INT_MAX
// for(int i=0 ; i<n ; i++)
//   distance[i]=INT_MAX;
//
// g.djkstra_algo(6 , 2 , distance , n);
// cout<<"---------------------> "<<endl;
//
// g.djks(6,n);
// return 0;


Solution solution;
// vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
// int n = 4;
// int k = 2;
// int result = solution.networkDelayTime(times, n, k);
//
// cout << "Network Delay Time: " << result << endl;

string a = "11100011010111111010100100110001101000000000000000";
cout<<a.length();
return 0;


}
