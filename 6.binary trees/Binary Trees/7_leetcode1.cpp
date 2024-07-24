#include <bits/stdc++.h>
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

node* BuildTree( node* & root)
{
  cout<<"enter the data"<<endl;
  int data;
  cin>>data;
  root= new node(data);

  if(data==-1)
  {
    return NULL;
  }
  root=new node(data);
  cout<<" enter the data for the left of "<<data<<endl;
  root->left = BuildTree(root->left);
  cout<<" enter the data for the right of "<<data<<endl;
  root->right = BuildTree(root->right);

  return root;
}




void level_order_traversal( node* root)
{
    if(root==NULL)
      return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
      node*temp = q.front();
      q.pop();
      if(temp!=NULL)
      {
        cout<<temp->data<<" ";
        if(temp->left)
        {
          q.push(temp->left);
        }
        if(temp->right)
        {
          q.push(temp->right);
        }
      }

      else if(temp==NULL)
      {cout<<endl;

       if(!q.empty())
        {
          q.push(NULL);
        }
      }
    }

  }



void ChildAtDistance_k(node* &root , int &k , int level , vector<int> & child)
  {
    if(root == NULL)
      return;

    if(level!=0 && level==k)
    {
      child.push_back(root->data);
      return;
    }

    ChildAtDistance_k( root->left , k , level+1, child);
    ChildAtDistance_k( root->right , k , level+1 ,child);

  }

void StoreParent( node* &root ,  node* parent_node , unordered_map<node*,node*> & map_parent)
  {
    if(root == NULL)
      return;

    map_parent[root] = parent_node;

    StoreParent(root->left , root ,map_parent );
    StoreParent(root->right , root , map_parent);
  }



void getLeafAdress( node*&root , node*&target)
{
  if(root==NULL)
    return;

  if(root->left==NULL && root->right== NULL)
  {
    target = root;
    return;
  }

  getLeafAdress(root->left , target);
  getLeafAdress(root->right , target);
}

void parentDist( node* &root , node*&target , unordered_map<node*, node*>& map_parent , int& k , vector<int>&childs)
{

  queue<pair<node* , pair<int ,bool>>>q;

  q.push({target,{0 ,false}});

  bool fromLeft = true;

  int idx = 0;
  int kLeft = k;
  while(!q.empty() && idx < k)
  {

    node*curr = q.front().first;

    //checking if target
    if(curr == target)
    {
      ChildAtDistance_k( target , k , 0 ,childs);
    }

    else if(curr != target)
    {

      //checking for source direction and taking actions accordingly
      bool dir = q.front().second.second;
      int dist = q.front().second.first  - 1;   // pushing one lesser

      if(dir == true)
        ChildAtDistance_k(curr->right , dist , 0 , childs);
      else if(!dir)
        ChildAtDistance_k(curr->left , dist , 0 , childs);
    }

    //chexking its parent if exist
    if(map_parent[curr] ==NULL)
      return;


    q.pop();


    //pushing a new value in queue
    node*currParent = map_parent[curr];
    if(currParent->right && currParent->right == curr)
    {
      fromLeft = false;
    }
    else if(currParent->right && currParent->right != curr)
    {
      fromLeft = true;
    }

    q.push({currParent , {--kLeft , fromLeft }});

    idx++;

  }

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  #endif


  node* root = NULL;

  root = BuildTree(root);

  node*target = NULL;
  getLeafAdress(root , target);
  level_order_traversal(root);

  cout<<endl<<" NOW THE CODE BEGINS"<<endl;


  unordered_map<node*,node*>map_parent;
  StoreParent(root , NULL , map_parent);

  // all nodes at dist k from target

  vector<int> childs;
  int k = 2;
  parentDist(root , target , map_parent , k , childs);

  for(auto &it: childs)
    cout<<it<<" ";

  // vector<int>child ;
  // int level = 0;
  // int k =2;
  //
  // ChildAtDistance_k(root , k , level , child);
  // for(auto it: child)
  //   cout<<it<<" ";
  //
  // cout<<endl<<endl;
  //
  // unordered_map<node*,node*>map_parent;
  //
  // StoreParent(root , NULL , map_parent);
  //
  // for (const auto& pair : map_parent) {
  //       std::cout << "Node " << pair.first->data;
  //       if (pair.second != nullptr) {
  //           std::cout << " has parent " << pair.second->data;
  //       } else{
  //           std::cout << " is the root";
  //       }
  //       std::cout << std::endl;
  //   }
  //
  //

}
