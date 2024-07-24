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

  cout<<"enter the data for left node of "<<data<<endl;
  // recursion for buiding left nodes
  root->left= BuildTree(root->left);

  cout<<"enter the data for right node of "<<data<<endl;
  //recursive call
  root->right= BuildTree(root->right);

  return root;
}

void levelOrderTraversal(node* &root) {
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

class PATHsum_III
{
public:

void path_sum( node* & root , int & target , int curr_sum , int & total)
{
  if(root== NULL)
    return;
  curr_sum += root->data;
  if( curr_sum == target)
    total ++;

  path_sum( root->left , target , curr_sum , total );
  path_sum( root->right , target , curr_sum , total );

}


void pathSum_III ( node* root , int & target , int &sum)
{
  if( root == NULL)
    return;

    path_sum( root , target , 0 , sum);
    pathSum_III( root->left , target , sum);
    pathSum_III( root->right , target , sum);
}

};


bool goodone( node* & root , int & target )
{
    if( root == NULL)
        return false;
    if( root-> data > target)
        return false;
    if( root-> data == target)
        return true;

    bool left = goodone( root-> left , target);
    bool right = goodone( root-> right , target);

    if( left || right )
        return true;

    return false;
}

void counter( node * & root , node * &curr , int & ans)
{
    if( root == NULL)
        return;
    if( curr == NULL)
        return;

    if(goodone(root , curr->data) == true)
        ans+=1;

    counter( root , curr -> left , ans);
    counter( root , curr -> right , ans);
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
  root = BuildTree(root);

  levelOrderTraversal(root);

  cout<<endl;


  addOneRow(root , 1 , 2);

  cout<<7;

  levelOrderTraversal(root);


  //   levelOrderTraversal(root);
  //   cout<<endl;
  //
  //   int ans =0;
  //   node* curr = root;
  //   counter( root , curr , ans);
  //   cout<<ans;
  //


  // int cnt=0;
  // Number_leaf_nodes(root , cnt);
  // cout<<endl;


return 0;
}
