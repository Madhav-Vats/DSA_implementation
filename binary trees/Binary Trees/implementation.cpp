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
node* BuildTree( node* root)
{
  cout<<"enter the data"<<endl;
  int data;
  cin>>data;
  root= new node(data);

  if(data==-1)
  {
    return NULL;
  }

  cout<<"enter the data for left node of "<<data<<endl;
  // recursion for buiding left nodes
  root->left= BuildTree(root->left);

  cout<<"enter the data for right node of "<<data<<endl;
  //recursive call
  root->right= BuildTree(root->right);

  return root;
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) {
                //queue still has some child ndoes
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}
// --------------------------------------------------------------------
// Inorder = L N R ( left-node-root)
// go until last values ( down most become null ) /
//return at NULL
//  and then print then , root print and then right print
void InorderTraversal( node* root)
{
  if(root==NULL)
    return;
// left most call
  InorderTraversal(root->left);
  //printing the root data after returning from left tree
  cout<<root->data<<" ";
  //goint to the right tree
  InorderTraversal(root->right);
}
// --------------------------------------------------------------------
// N L R  (node left right)
// start printing from fist root , then go to left
void PreorderTraversal( node* root)
{
  if(root==NULL)
    return;
  //printing the node data( root value)
  cout<<root->data<<" ";
  // going to the left tree
  PreorderTraversal(root->left);
  //going to the right tree
  PreorderTraversal(root->right);
}

// -------------------------------------------------------------------
// L R N ( left right node)

// go to the left most print it ,
// then print it's parent then parent's right

void PostorderTraversal(node* root)
{
  if(root==NULL)
    return;
  // go to the left most
  PostorderTraversal(root->left);
  // then after left go to rightSum
  PostorderTraversal(root->right);
  // print the node data
  cout<<root->data<<" ";
}
// -----------------------------------------------------------------
// go to all leaf and make couter ++
void Number_leaf_nodes( node* root ,int &cnt)
{
  if(root->left==NULL && root->right==NULL)
  {cnt++;
  return;}
  Number_leaf_nodes(root->left , cnt);
  Number_leaf_nodes(root->right ,cnt);
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
  // int cnt=0;
  // Number_leaf_nodes(root , cnt);
  // cout<<endl;
  // cout<<cnt<<endl;

PreorderTraversal(root);
return 0;
}
