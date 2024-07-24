#include<bits/stdc++.h>
using namespace std;

class node
{
public:
  int data ;
  node* right;
  node* left;

  node( int d)
  {
    this->data= d;
    left= NULL;
    right= NULL;
  }
};

node* insertInBST(node* &root , int d)
{
  if(root==NULL)
  {
    root = new node(d);
    return root;
  }
  if(d > root->data)
    root->right = insertInBST(root->right,d);
  else
    root->left = insertInBST(root->left,d);

  return root;
}

void buildBST(node* &root)
{
  int data ;
  cin>>data;
  while(data != -1)
  {
    root = insertInBST(root , data);
    cin>>data;
  }
}


void levelOrderTraversal(node* root)
 {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
      node* temp = q.front();
      q.pop();

      if(temp) {
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
      else if(temp == NULL)
      {
        //purana level complete traverse ho chuka hai
        cout << endl;
        if(!q.empty())
        {
            //queue still has some child ndoes
            q.push(NULL);
        }
      }
    }
  }

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  #endif


  node* root=NULL;
  buildBST(root);
  levelOrderTraversal(root);

return 0;
}
