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

void* kreverse()
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  #endif

  node* head =NULL;
  head =  Build_until_neg1(head);
  printLL(head);


return 0;
}
