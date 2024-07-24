class merge_BST
{
public:
  /*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void convt_into_vector (TreeNode* & root , vector<int> &ans)
    {
      if(root==NULL)
        return;

      convt_into_vector(root->left , ans);
      ans.push_back(root->data);
      convt_into_vector(root->right , ans);
    }

TreeNode* insertInBST(TreeNode* &root , int d)
{
  if(root==NULL)
  {
    root = new TreeNode(d);
    return root;
  }
  if(d > root->data)
    root->right = insertInBST(root->right,d);
  else
    root->left = insertInBST(root->left,d);

  return root;
}

vector<int> merge(vector<int> &arr1 ,vector<int> &arr2 )
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> arr3 (n1+n2,-1);

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    int k=0;
    int i=0;
    int j=0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else {
            arr3[k] = arr2[j];
            j++;
            k++;
        }

    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    return arr3;
}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> arr1;
    vector<int> arr2;
    convt_into_vector( root1 , arr1);
    convt_into_vector( root2 , arr2);
    vector<int> arr = merge(arr1 , arr2);
    return arr;



}



};

class merge_BST_optimal
{
public:

  /*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void conver_into_DLL(TreeNode*& root , TreeNode* & head)
{
    if( root ==NULL)
        return ;

    conver_into_DLL(root->right , head);
    root->right = head;
    if( head )
    {
        head->left = root;
    }

    head = root;

    conver_into_DLL(root->left , head);
}

void insert_into_DLL_tail(TreeNode* & tail , int d)
{
    if(tail ==NULL)
    {
        tail = new TreeNode(d);
    }
    else
    {

        TreeNode *newNode = new TreeNode(d);
        tail->right = newNode;
        newNode->left = tail;
        tail = tail->right;
    }
}
TreeNode* merge_DLL( TreeNode* & head1 , TreeNode* & head2)
{
    // DLL that needs to be returned after processing
    TreeNode*ans;
    // pointer that will move forward
    TreeNode*temp = ans;

    TreeNode* curr1next = head1;

    TreeNode* curr2next = head2;

    while(curr1next && curr2next)
    {
        if(curr1next->data < curr2next->data)
        {
            insert_into_DLL_tail(temp , curr1next->data);
            curr1next = curr1next->right;
        }
        else
        {
            insert_into_DLL_tail(temp , curr2next->data);
            curr2next = curr2next->right;
        }
    }

    while(curr1next)
    {
        insert_into_DLL_tail(temp , curr1next->data);
        curr1next = curr1next->right;
    }

    while(curr2next)
    {
        insert_into_DLL_tail(temp , curr2next->data);
        curr2next = curr2next->right;
    }

    return ans;


}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{

    // Write your code here.
    TreeNode * head1;
    TreeNode * head2;

    conver_into_DLL( root1 , head1);
    conver_into_DLL( root2 , head2);
    TreeNode*ans  = merge_DLL( head1 , head2);
    vector<int> arr;
    while(ans)
    {
        arr.push_back(ans->data);
        ans=ans->right;
    }

    return arr;




}
};
