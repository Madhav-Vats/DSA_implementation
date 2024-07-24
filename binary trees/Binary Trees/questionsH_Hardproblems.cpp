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
node* BuildTree( node* &root)
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


// ---------------------------------------------------------

class nodeLL
{
public:
  int data ;
  nodeLL* next;

  //constructor
  nodeLL(int data)
  {
    this->data=data;
    this->next=NULL;
  }
};
void InsertionAtTheEnd(nodeLL* &head ,int d)
{
  if(head==NULL)
    head=new nodeLL(d);
  //making a dummy node(temp) for reaching the end
  else{
    nodeLL* last = head;
    //making t he node to be added
    nodeLL* new_node=new nodeLL(d);
    //reaching the end
    while(last->next!=NULL)
    {last=last->next;}
    //inserting at the end
    last->next= new_node ;
  }
}

class flatten
{
public:
  void PreorderTraversal_Tree_To_LL( node* &root , nodeLL* &head )
  {
    if(root==NULL)
      return;
    //printing the node data( root value)
    InsertionAtTheEnd(head , root->data);
    // going to the left tree
    PreorderTraversal_Tree_To_LL(root->left , head);
    //going to the right tree
    PreorderTraversal_Tree_To_LL(root->right , head);
  }

  nodeLL* conversionPrint(node* &root )
  {
    nodeLL* head = NULL;
    PreorderTraversal_Tree_To_LL(root , head);
    return head;
  }

};

class flatten2
{
public:

};
// -----------------------------------------------------------------------------
vector<int> levelorderVECTOR(node* root) {
    queue<node*> q;
    q.

    (root);
    q.

    (NULL);
    vector<int> v;

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            //purana level complete traverse ho chuka hai
            v.push_back(-1);
            if(!q.empty()) {
                //queue still has some child ndoes
                q.

                (NULL);
            }
        }
        else{
            v.push_back(temp->data);
            if(temp ->left) {
                q.

                (temp ->left);
            }

            if(temp ->right) {
                q.

                (temp ->right);
            }
        }
    }
    return v;

}

int required_level(node*root)
{
  vector<int> v= levelorderVECTOR(root);
  int size = v.size();
  vector<vector<int>> ans;
  int i=0;
  while(v[i]!=-1)
  {
    vector<int>temp;
    temp.


  }
}



class width
{
public:
  vector<vector<int>> levelorder(node* & root)
  {

  }
  int required_level(node* &root)
  {
    //level order travesal <vector<vector<int>>> from
    //last whick one has atleast 2 members will give us the value of level
    //level = size - that vector(searching from last) having 2 nodes atleast

  }

};
// --------------------------------------------------------------------------
bool nodePATH(node* root , vector<int> & v , int finding_node)
{
  //base for NULL
  if(root==NULL)
    return false ;

  if(root->data== finding_node)
  {
    v.push_back(root->data);
    return true;
  }

  bool leftTree = nodePATH(root->left ,  v , finding_node);
  bool rightTree = nodePATH(root->right , v , finding_node);
  if(leftTree)
    v.push_back(root->data);
  if(rightTree)
    v.push_back(root->data);

}

void LL_print(nodeLL* &root)
{
  nodeLL*temp = root;
  while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
}
//flatten the binary tree
// tree preorder traversal in linked list













int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  #endif

  node* root=NULL;
  BuildTree(root);
  // int cnt=0;
  // Number_leaf_nodes(root , cnt);
  // cout<<endl;
  // cout<<cnt<<endl;
  vector<int> v= levelorderVECTOR(root);
    for(auto it: v)
      cout<<it<<" ";
return 0;
}
