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




node* FlattenTree ( node* &root )
{
  
}
