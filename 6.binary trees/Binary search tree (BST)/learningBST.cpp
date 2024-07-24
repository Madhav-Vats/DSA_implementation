#include<bits/stdc++.h>
using namespace std;

  bool searchInBST ( node* root , int element)
  {
    if(root == NULL)
      return false;
    if(root->data == element)
      return true;
    if(root->data >  element)
    {
      bool rightii = searchInBST(root->right , element);
      return rightii ;
    }

    else if (root->data < element)
    {
      bool leftii = searchInBST( root->left , element);
      return leftii ;
    }


  }



class ISBST_via_TRAVERSAL
{
public:

  void convt_into_vector(node* root , vector<int>& ans)
  {
    if(root==NULL)
      return;
    convt_into_vector(root , ans);
    ans.push_back(root->data);
    convt_into_vector(root->right , ans);
  }

  bool is_sorted(vector<int> & arr)
  {
    int size = arr.size();
    int i=0;
    bool flag = true;

    while(i<size-1)
    {
      if(arr[i]<=arr[i+1])
      {
        i++;
      }
      else
      {
        flag = false;
        break;
      }
    }

    return flag;
  }
  bool isBST( node* root)
  {
    vector<int> ans;
    convt_into_vector(root , ans);
    int flag = is_sorted( ans );
    return flag;
  }
};




class ISBST_recursion
{
public:
  node* minval ( node* &root)
  {
    node*temp = root;
    while(temp)
    {
      temp=temp->left;
    }
    return temp;
  }

  node* maxval(node* &root)
  {
    node*temp = root;
    while(temp)
    {
      temp=temp->right;
    }
    return temp;
  }

  pair<pair<bool , bool> , bool> is_BSTor_not(node* root)
  {
    if(root == NULL)
    {
      pair<bool , bool> p = make_pair(true , true);
      return {p , true};
    }
    pair<pair<bool , bool> , bool> leftii = is_BSTor_not(root->left);
    pair<pair<bool , bool> , bool> rightii = is_BSTor_not(root->right);

    //main condition
    int maxi_fromLEFT = maxval(root->left)->data;
    int mini_fromRight = minval(root->right)->data;

    bool main_condition = (root->data > maxi_fromLEFT && root->data < mini_fromRight);

    // if all of them are true them return true , true
    if( main_condition && leftii.first.first && leftii.first.second && leftii.second && rightii.first.first && rightii.first.second && rightii.second )
    {
      pair<bool,bool> p = make_pair( true , true);
      return {p,true};
    }
    else
    {
      pair<bool,bool> p = make_pair( true , true);
      return {p,false};
    }
  }


  bool result_isBST( node* & root )
  {
    if(root== NULL)
      return true;

    bool left_subTree = result_isBST(root->left);
    bool right_subTree = result_isBST(root->right);

    //main condition
    // int maxi_fromLEFT = maxval(root->left)->data;
    // int mini_fromRight = minval(root->right)->data;
    int maxi_fromLEFT = (root->left) ? maxval(root->left)->data : INT_MIN;
    int mini_fromRight = (root->right) ? minval(root->right)->data : INT_MAX;

    bool main_condition = (root->data > maxi_fromLEFT && root->data < mini_fromRight);

    if(left_subTree && right_subTree && main_condition )
    {
      return true;
    }

    else
      return false;
  }

  //in this above code we are traversing the whole tree
  // what if we could stop it the moment we find that a part of this tree in not a BST

  void good_result_isBST( node* &root , bool &flag )
  {
    if(root== NULL)
      return ;

    if( flag == false)
      return ;

    good_result_isBST(root->left , flag);
    good_result_isBST(root->right , flag);

    //main condition
    int maxi_fromLEFT = maxval(root->left)->data;
    int mini_fromRight = minval(root->right)->data;

    bool main_condition = (root->data > maxi_fromLEFT && root->data < mini_fromRight);

    if(!main_condition)
    {
      flag = false;
    }

  }
};


class Kth_element
{
public:

  void convt_into_vector(node* root , vector<int>& ans)
  {
    if(root==NULL)
      return;
    convt_into_vector(root , ans);
    ans.push_back(root->data);
    convt_into_vector(root->right , ans);
  }


  int Kth_smallest( node* & root , int K)
  {
    vector<int> preorder;
    convt_into_vector( root , preorder );
    int size = preorder.size();

    int i=K-1;
    return preorder[i];

  }

  int Kth_largest( node* & root , int K)
  {
    vector<int> preorder;
    convt_into_vector( root , preorder );
    int size = preorder.size();

    int i = size - K;
    return preorder[i];
  }




};


class Predeccesor_and_Successor
{
public:

void pred_step_II( node* root , node* temp )
{
  if(root->right == NULL)
    temp = root;

  pred_step_II( root ->right , temp);
}

node* predeccessor ( node* root )
{
  //step_I ---
  node* current = root->left;
  node* temp;
  pred_step_II(current , temp);

  return temp;
}


void succ_step_II( node* root , node* temp )
{
  if(root->left == NULL)
    temp = root;

  succ_step_II( root ->left , temp);
}

node* successor( node* root )
{
  //step_I ---
  node* current = root->right;
  node* temp;
  succ_step_II(current , temp);

  return temp;
}

};


class LCA_inBST
{
public:

  void find_requiredNode(node*root , int d1 , int d2 , node*temp)
  {
    //find the elemental nodes
    // if(node->data == d1 || node->data == d1)
    //   return;
    if( root == NULL)
      return;

    //any node for which the condtion , mentioned below , if true , thats our answer
    if(root->data > d1 && root->data <d2 || root->data > d2 && root->data <d1 )
      temp = root;

    find_requiredNode(root->left , d1 , d2 , temp);
    find_requiredNode(root->right , d1 , d2 , temp);
  }

  int LCA_dataValue(node* root , int d1 , int d2)
  {
    node* temp;
     // condition = for any node when root->data > d1 and root->data < d2 or vice versa
     //return that node

     find_requiredNode( root , d1 , d2 , temp);

     return temp->data;

  }


};

//two sum in bst
class two_SUM__inBST
{
public:

  void convt_into_vector(node* & root , vector<int> & ans)
  {
    if(root==NULL)
      return;
    convt_into_vector(root->left , ans);
    ans.push_back(root->data);
    convt_into_vector(root->right , ans);
  }




  pair<int , int> two_sum_pair(node* & root , int target)
  {
    vector<int> ans;
    convt_into_vector(root , ans);
    int size = ans.size();
    int i = 0;
    int j = size-1;
    pair<int,int> p;
    while(i<=j)
    {
      int sum = ans[i]+ ans[j];

      if( sum == target)
      {
        p.first = ans[i];
        p.second = ans[j];
        break;
      }
      else if(sum > target)
        j--;
      else if( sum < target)
        i++;
    }

    return p;
  }


    void NUMM_nodes(node*& root , int &cnt)
    {
      if(root==NULL)
        return;
      cnt+=1;
      NUMM_nodes(root->left , cnt);
      NUMM_nodes(root->right , cnt);
    }


    bool search_node( node* & root , int search_target )
    {
      if(root == NULL)
        return false;

      if(root->data == search_target)
      {
        return true;
      }
      if(root->data > search_target)
      {
        //left
        return search_node(root->left , search_target );
      }

      return search_node(root->right , search_target );

        //right
    }

// worst code
    pair<int,int> ans_two_sum( node* &root , int target)
    {
      //initializing that they ae not found therefore -1
      int a =-1;
      int b =-1;

      // making a queue to push and pop element one by one
      //and then checking for the remaining part
      queue<node*> q;
      q.push(root);
      bool brk = false;
      while(!q.empty() || brk ==false)
      {
        //level vise we are going to traverse the elements and then we will check for remaining part
        int size = q.size();
        for(int i = 0;i<size ;i++)
        {
          node* temp = q.front();

          a = temp->data;
          //our root = a
          //b = remaining part that need to be searched
          b = target - a;

          q.pop();
          //check for remaining part
          bool leftii = search_node(temp->left , b);
          bool rightii = search_node(temp->right , b);



          if(temp->left)
            q.push(temp->left);

          if(temp->right)
            q.push(temp->right);
        }
      }

      return make_pair(-1,-1);
    }



};

//flatten bst into a linked list
class Flatten_aBST
{
public:
  //convert tree into inorder vector
  void convt_into_vector(node* & root , vector<int> & ans)
  {
    if(root==NULL)
      return;
    convt_into_vector(root->left , ans);
    ans.push_back(root->data);
    convt_into_vector(root->right , ans);
  }


  void flatten(node* & root , vector<int> &arr ,int &i, int &size)
  {
    if(i>= size || root == NULL )
      return;

    flatten(root , arr ,i , size);

    root->data = arr[i++];
    root->right = NULL;

  }

  void result(node* & root)
  {
    vector<int> arr;
    convt_into_vector(root , arr);
    int size = arr.size();
    flatten(root, arr, 0 , size);

  }




};
