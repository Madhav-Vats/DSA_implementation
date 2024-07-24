#include <bits/stdc++.h>
#include <vector>
using namespace std;

class node
{
public:
  int data ;
  node* left;
  node* right;

  //constructor
  node(int data)
  {
    this->data=data;
    left=NULL;
    right=NULL;
  }
};

node* BuildTree( node*  &root)
{
  cout<<" enter the data"<<endl;
  int data;
  cin>>data;
    if(data==-1)
    return NULL;
  root=new node(data);
  cout<<" enter the data for the left of "<<data<<endl;
  root->left = BuildTree(root->left);
  cout<<" enter the data for the right of "<<data<<endl;
  root->right = BuildTree(root->right);

  return root;
}

// class Solution {
// public:
//
//   vector<vector<int>> level_orderNULL( node* &root )
//   {
//
//     vector<vector<int>> ans;
//     queue<node*> q;
//     q.push(root);
//     q.push(NULL);
//     //we dont want the data , so you can push +1 for exist and -1 for NULL
//     while(!q.empty())
//     {
//       vector<int>v;
//       node* temp = root;
//       q.pop();
//       if(temp)
//       {
//         v.push_back(temp->data);
//         if(temp->left)
//           v.push_back(temp->left->data);
//         if(temp->right)
//           v.push_back(temp->right->data);
//         else if(!temp->left)
//           v.push_back(-1);
//         else if(!temp->right)
//           v.push_back(-1);
//       }
//       else if(!temp)
//       {
//         ans.push_back(v);
//         v.clear();
//         if(!q.empty())
//         {
//           q.push(NULL);
//         }
//       }
//     }
//
//     return ans;
//   }
//
//
//     int widthOfBinaryTree(TreeNode* root) {
//
//     }
// };

//
// vector<vector<int>> level_orderNULL( node* &root )
// {
//
//   vector<vector<int>> ans;
//   queue<node*> q;
//   q.push(root);
//   //we dont want the data , so you can push +1 for exist and -1 for NULL
//   while(!q.empty())
//   {
//     vector<int>v;
//
//     int level_size = q.size();
//     for(int i=0 ;i< level_size;i++)
//     {
//       node*temp = q.front();
//       q.pop();
//       if(temp)
//       {
//         v.push_back(temp->data);
//         if(temp->left)
//         {
//
//         }
//         if(temp->right)
//       }
//     }
// }
// }

//
// void InorderTraversal( node* &root)
// {
//   if(root==NULL)
//     return;
// // left most call
//   InorderTraversal(root->left);
//   //printing the root data after returning from left tree
//   cout<<root->data<<" ";
//   //goint to the right tree
//   InorderTraversal(root->right);
// }





// int maxi_width( node*root)
// {
//   if(root===NULL)
//     return -1;
//
//   queue<pair<node* ,int>> q; // pair of node and int
//   int pos = 0
//   q.push({root , pos });
//
//   while(!q.empty)
//   {
//     lenght = q.size();
//     int start = q.front().second;
//
//     for(int i=0; i< length ;i++)
//     {
//       node* temp = q.front().first;
//       q.pop();
//       if(temp->left)
//       {
//         q.push({temp->left , ++pos});
//       }
//       if(temp->right)
//       {
//         q.push({temp->right , ++pos});
//       }
//     }
//
//     int end = pos;
//     int res = end-start+1;
//     maxi = max( maxi , res)
//
//   }
//
// }


int dist_betweenTwo(queue<node*> q)
{
  int cnt = 2;
  q.pop();
  while( q.front()->data== -1)
  {
    cnt++;
    q.pop();
  }

  return cnt;

}

void maxWidth_new( node* &root , int & max_width)
{
  queue<node* > current_level ;
  queue<node*> next_level;
  current_level.push(root);
  int width = 1;
  node* onenode = new node(-1);
  while(!current_level.empty())
  {
    node*temp = current_level.front();
    int level_size = current_level.size();

    for(int i=0; i< level_size ; i++)
    {
      current_level.pop();  /////////////////////////////////////////////pop the element each time

      if(temp->left)
        next_level.push(temp->left);

      if(!temp->left)
      {
        if(!next_level.empty())
          next_level.push(onenode);
      }

      if( temp->right)
        next_level.push(temp->right);

      if(!temp->right)
      {
        if(!next_level.empty())
          next_level.push(onenode);
      }

      if( temp->data == -1)
      {
        next_level.push(onenode);
        next_level.push(onenode);
      }

    }

    // width of this new level =  distance between non -1 values
    width = dist_betweenTwo( next_level );
    max_width = max( max_width , width );

    swap(current_level , next_level);
  }
}


int maxWid( node* &root )
{
  int ans =0;
  maxWidth_new( root , ans);
  return ans;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  #endif

  node* root =NULL;
  root = BuildTree(root);
  int ans = maxWid(root);
  cout<<ans;

}
