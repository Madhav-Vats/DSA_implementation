#include <bits/stdc++.h>
#include <vector>
using namespace std;

class node
{
public:
  int data ;
  node* next;

  //constructor
  node(int data)
  {
    this->data=data;
    this->next=NULL;
  }
};
node* Build_until_neg1( node* &head)
{
  int data;
  cin>>data;

head = new node(data);
  //base condition
  if(data==-1)
    return NULL;


  //recursive call , untill data value is -1 , build the linkd list
  head->next = Build_until_neg1(head->next);
  return head;
}
void InsertionAtHead( node* &head ,int d)
{
  node* new_node = new node(d);
  new_node->next= head;
  head=new_node;
}
void InsertionAtTheEnd(node* &head ,int d)
{
  if(head==NULL)
    head=new node(d);
  //making a dummy node(temp) for reaching the end
  else{
    node* last = head;
    //making t he node to be added
    node* new_node=new node(d);
    //reaching the end
    while(last->next!=NULL)
    {last=last->next;}
    //inserting at the end
    last->next= new_node ;
  }
}
void printLL(node* &head)
{
  node*temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

/**
 * Definition for singly-linked list.
 * struct node {
 *     int val;
 *     node *next;
 *     node() : val(0), next(nullptr) {}
 *     node(int x) : val(x), next(nullptr) {}
 *     node(int x, node *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

void Insert_at_tail(node* &ans , node* &d )
{
    if (ans == NULL)
    {
        ans = d;
    }
    else
    {
        node* temp = ans;
        while(temp && temp->next )
        {
            temp = temp->next;
        }

        temp->next= d;
    }

}

// while ans.size() does not become equal to the  2d matriz size

    node* mergeKLists(vector<node*>& lists) {

        priority_queue <node*, vector<node*>, greater<node*>  > min_heap;

        node* ans = NULL;

        int size = lists.size();
        int i =0;

        for(int i=0; i<size ;i++)
        {
            min_heap.push(lists[i]);
        }




        while(min_heap.size() > 0)
        {
            node* curr = min_heap.top();

            if(curr->next)
            {
                min_heap.push(curr->next);
            }

            Insert_at_tail( ans , curr);

            min_heap.pop();
        }

        return ans;


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

  // node* head =NULL;
  // head =  Build_until_neg1(head);
  // printLL(head);

  node* l1 = NULL;
  Build_until_neg1(l1);
  node* l2 = NULL;
  Build_until_neg1(l2);
  node* l3 = NULL;
  Build_until_neg1(l3);

  vector<node*> list;
  list.push_back(l1);
  list.push_back(l2);
  list.push_back(l3);
  Solution obj1;
  node* ans = obj1.mergeKLists( list);
  while(ans)
  {
    cout << ans->data;
    ans = ans->next;
  }


return 0;
}
