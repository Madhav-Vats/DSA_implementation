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

void LL_print(node* &root)
{
  node*temp = root;
  while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
}

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

void reverse_LL(node* &head)
{
  if(head->next==NULL)
    return;

  node* temp = head;
  head=head->next;
  reverse_LL(head);
  InsertionAtTheEnd(head ,temp->data);
}

class Add_TwoNumbers
{
public:
  void Number_to_LL( int &num , node* &head)
  {
    while(num!=0)
    {
      int val = num%10;
      InsertionAtTheEnd(head ,val);
      num=num/10;
    }
  }
  int SizeOf_LL(node* head)
  {
    if(head==NULL)
      return 0;
    else
    {
      int cnt=0;
      node*temp=head;
      while(temp!=NULL)
      {
        cnt++;
        temp=temp->next;
      }
      return cnt;
    }
  }
  void add_TwoNumbers_twoLL(int &num1 , int &num2)
  {
    node* head1=NULL;
    node* head2=NULL;
    Number_to_LL(num1, head1);
    Number_to_LL(num2, head2);
    // you can get the size values through Number_to_LL function
    // so you can optimize a little bit of time complexity
    int size1 = SizeOf_LL(head1);
    int size2 = SizeOf_LL(head2);
    node* ans=NULL;
    // this is only for size1= size 2 .. solve for other cases also
    if(size1==size2)
    {
      node*temp1 = head1;
      node*temp2 = head2;
      while(temp1!=NULL && temp2!= NULL)
      {
        InsertionAtTheEnd(ans , temp1->data + temp2->data);
        temp1=temp1->next;
        temp2=temp2->next;
      }
    }

    LL_print(ans);
    // if(size1>size2)
    // {
    //
    //
    // }
    // else
    // {
    //
    // }

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

  Add_TwoNumbers obj1;
  int a =502;
  int b =304;
  obj1.add_TwoNumbers_twoLL(a,b);
return 0;
}
