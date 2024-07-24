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

node* BuildTree( node*  root)
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


//to find the max sum of nodes any path connected to root path
//pair< data value , sum of max height below it >

//maximum sum branch
pair<int,int> MaximumSum_branch(node* root)
{
  //base condition
  if(root==NULL)
  { pair<int,int> p = make_pair(0,0);
    return p; }

  pair<int,int> left= MaximumSum_branch(root->left);
  pair<int,int> right= MaximumSum_branch(root->right);

  int leftSum= left.first + left.second;
  int rightSum= right.first + right.second;
  int val= max(leftSum,rightSum);

  pair<int,int>ans;

  ans.first=root->data;
  ans.second = val;

  return ans;

}

//pair <    sum of longest branch    , maximum height below it>
//        below it including itself

//longest branch Sum
pair<int, int> SumOfNodes(node*root)
{
  if(root==NULL)
  { pair<int,int> p = make_pair(0,0);
    return p; }

  pair<int,int> left = SumOfNodes(root->left);
  pair<int,int> right = SumOfNodes(root->right);

  int leftHeight =left.second;
  int rightHeight = right.second;

  int val_sum;
  if(left.second>right.second)
    val_sum = left.first + root->data;
  else if(left.second < right.second)
    val_sum = right.first + root->data;

  int val_height= max(leftHeight,rightHeight) + 1 ;
  pair<int,int> ans;
  ans.second = val_height;
  ans.first = val_sum;

  return ans;

}

//longest common ancentor

//pair( data value ,  pair(      if first element     ,  if second element    )
//                         present below =1 else 0    present below =1 else 0



//take a look on this code
// pair<int, pair<bool,bool>> commonAncestor_print( node*root , int element1  , int element2)
// {
//   //base condition
//   if(root==NULL)
//   {
//     pair<bool,bool> p =make_pair(false,false);
//     pair<int, pair<bool,bool>> pp = make_pair(0,p) ;
//     return pp;
//   }
//
//
//  pair<int, pair<bool,bool>> left =commonAncestor(root->left , element1 ,element2 );
//  pair<int, pair<bool,bool>> right =commonAncestor(root->right , element1 ,element2 );
//
//   //data value storage for , ans.first
//   //internal pair of ans
//
//   pair<int, pair<bool,bool>> ans;
//
//   int val= root->data;
//   ans.first=val;
//   //first bool
//   if(!left.second.second && !left.second.first)
//   {if(val==element1)
//     ans.second.first=true;
//   //second bool
//   else if(val==element2)
//     ans.second.second=true;
//   }
//
// if(!ri)
//   {if(val==element1)
//     ans.second.first=true;
//   //second bool
//   else if(val==element2)
//     ans.second.second=true;
//   }
//
//
//   if (pp.second.first == 1 && pp.second.second == 1 && pp.first == 0)
//   {
//     pp.first = root->data;
//   }
//
//   commonAncestor(root->right ,pp, element1, element2 );
//
//
// }

//take a look on this code
// void common_Ancestor( node*root , int element1  , int element2 , int fir , int sec)
//   {
//     //base condition
//     if(root==NULL)
//       return ;
//     if(fir==1 && sec==1)
//       cout<<root->data;
//
//     //recursive call to reach last element
//   common_Ancestor(root->left , element1 , element2 , fir , sec);
//   common_Ancestor(root->right ,element1 , element2 , fir , sec);
//
//
//     if(root->data==element1)
//       fir=1;
//     else if(root->data==element2)
//       sec=1;
//
//   }
//



node* CommonAncestor( node*root , int element1 , int element2)
{
  if(root==NULL)
    return NULL;

  if(root->data==element1 || root->data==element2)
  {
    return root;
  }

  node* left = CommonAncestor(root->left , element1 , element2);
  node* right = CommonAncestor(root->right , element1 , element2);

  if(left!= NULL && right!=NULL)
    return root;

  else if(left==NULL && right!=NULL)
    return right;

  else if( left!=NULL && right==NULL)
    return left;

  else if( left==NULL && right==NULL)
    return NULL;

}

class kthAncestor_usingVectors
{
  void kth()
  {

  }
};


class kthAncestor
{
public:
  // decrease k each time and when it becomes zero print the data
  // of that node
  node* K_th_Ancestor(node*root , int k , int elementData )
  {
    //base codition
    if(root==NULL)
      return NULL;

    if(root->data == elementData)
    {
      return root;
    }
    node* rootFromleft = K_th_Ancestor(root->left , k , elementData);
    node* rootFromright = K_th_Ancestor(root->right , k , elementData);

    //jb khi se bhi ya to  , left se ek node aayegi ya right se
    // if(left!=NULL || right!=NULL)
    //return root
    if(k==0)
      return root;

    else if(rootFromleft) //if they are non NULL
    {
      k--;
      return rootFromleft;
    }
    else if(rootFromright)
    {
      k--;
      return rootFromright;
    }
    else if (!rootFromleft)
      return NULL;
    else if(!rootFromright)
      return NULL;
  }
};












int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  #endif


  node* root= NULL;
  root=BuildTree(root);

  return 0;
}
