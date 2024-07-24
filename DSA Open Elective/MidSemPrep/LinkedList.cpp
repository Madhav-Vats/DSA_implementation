#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node* next;

  node(int d)
  {
    this->data = d;
    this ->next = NULL;
  }
};

node* BuildUntil()
{
  node* root = NULL ;

  node* tail = NULL;


  while(true)
  {
    int val;
    cin>>val;

    if(val < 0)
      break;

    else
    {
      node* newNode = new node(1);

      if(!root)
      {
        root = newNode;
        tail = root;
      }
      else
      {
        tail->next = newNode;
        tail = tail->next;
      }
    }
  }

  return root;
}


void printLL( node* & root)
{
  node* temp  =  root;

  while(temp != NULL)
  {
    cout<<temp->data;
    temp= temp->next;

  }
}




int main()
{
  node* root = BuildUntil();
  printLL(root);

  return 0;
}
