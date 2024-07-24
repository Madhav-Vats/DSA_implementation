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


void InsertionAtAnyPosition( node* &head , int d ,int pos)
{
  if(pos==1)
  { InsertionAtHead(head , d);}
  else
  { node* new_node =new node(d);
    node*temp = head;
    //we want the element at postion of (pos-1)
    // bcoz at first call also temp is becoming temp->next

    for(int i=1; i<pos-1 ;i++)
    {
      temp=temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }
}


void deleteNodeAtAnyPosition(node* &head , int pos)
{
  if(pos==1)
  {
    node*delete_node=head;
    head=head->next;
    delete_node=NULL;
  }

  else
  {
    node*temp =head;

    for(int i=1; i<pos-1 ;i++)
    {
      temp=temp->next;
    }
    node* removal_node = temp->next;
    temp->next = temp->next->next;
    removal_node->next = NULL;

  }
}

void Merge_two_sorted_LL (node* &head1 , node* &head2 ,node* &newLL)
{
  //pointers in two LL
  node* temp1 = head1;
  node* temp2 = head2;


  while(temp1->data < temp2->data)
  { InsertionAtTheEnd(newLL , temp1->data);
    temp1=temp1->next;
  }
  while(temp1->data > temp2->data)
  { InsertionAtTheEnd(newLL , temp2->data);
    temp2=temp2->next;
  }
  while(temp1!=NULL)
  { InsertionAtTheEnd(newLL , temp1->data);
    temp1=temp1->next;
  }
  while(temp2!=NULL)
  { InsertionAtTheEnd(newLL , temp2->data);
    temp2=temp2->next;
  }

}


void LL_print(node* &root)
{
  node*temp = root;
  while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
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
node* head1= NULL;
head1 = Build_until_neg1(head1);
node* head2=NULL;
head2 = Build_until_neg1(head2);
node* newLL =NULL;
Merge_two_sorted_LL(head1 , head2 , newLL);
LL_print(newLL);
return 0;
}
