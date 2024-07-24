#include <bits/stdc++.h>
using namespace std;

class m_stack
{
public:
  int size;
  int top;
  int *arr;

  // constructor
  m_stack (int s)
  {
    this-> size =s;
    arr=new int[size];
    top=-1;
  }

  //member fuctions
  void push(int element)
  {
    if(top<size-1)
    {
      top++;
      arr[top]=element;
    }
    else
    cout<<" stack overflow "<<endl;
  }
  void pop()
  {
    if(top!=-1)
    {
      //dynamic deletion , from array also
      //   this is wrong , but correct for
      //dynamically deleting an element of a dynamic array
      // int dynamic_array = int[size-1];
      // for(int i=0;i<top;i++)
      // {
      //   dynamic_array[i]=arr[i];
      // }
      // delete[] arr;
      // arr=dynamic_array;

      //dynamically deleting the top element
      delete[] &arr[top];

      // without dynamic deletion
      //you can use a single line

      top--;

    }
    else
    cout<<" stack is empty , can't delete any element"<<endl;
  }

  void peek() // peek element means top element
  {
    if(top!=-1)
    {
      cout<< "Top element: "<<arr[top]<<endl;
    }
    else
      cout<<" stack is empty , there is no element at the top"<<endl;
  }

  bool isempty()
  {
    if(top!=-1)
    {
      return false;
    }
    else
    return true;
  }

  void display()
  {
    if(top!=-1)
    {
      int i=top;
      while(i>=0)
      {
        cout<<arr[i]<<endl;
        i--;
      }
    }
    else
    cout<<" stack is empty "<<endl;
  }

  //Destructor
  ~m_stack()
  {
    delete[] arr;
  }
  /*the dynamically allocated memory used by the
  Stack object (specifically, the array arr) would be
  automatically deallocated when the Stack object goes out of scope.
  This typically happens when the Stack object is no longer needed,
  such as when it's local to a function and that function finishes
  executing, or when it's explicitly deleted using the delete operator.*/

};

class two_stack
{
public:

  //data members
  int size;
  int top1;
  int top2;
  int *arr;

  // constructor
  two_stack(int s)
  {
    this->size= s;
    top1=-1;
    top2=s-1;
    arr = new int[size];
  }

  // member functions
  void push1(int element)
  {
    if( (top2-top1) > 1 )
    {
      top1++;
      arr[top1]=element;
    }
  }
  void push2(int element)
  {
    if( (top2-top1) > 1 )
    {
      top2--;
      arr[top2]=element;
    }
    else
    cout<<" stack overflow "<<endl;

  }

  void pop1()
  {
    if(top1!=-1)

    // without dynamic deletion
    //you can use a single line

    top1--;

  }

  void pop2()
  {
    if(top2!=size-1)

    // without dynamic deletion
    //you can use a single line

    top2++;

  }

  void peek1()
  {
    if(top1!=-1)
    {
      cout<< "Top element: "<<arr[top1]<<endl;
    }
    else
      cout<<" stack 1 has no elements"<<endl;
  }

  void peek2()
  {
    if(top2!=size-1)
    {
      cout<< "Top element: "<<arr[top2]<<endl;
    }
    else
      cout<<" stack 2 has no elements "<<endl;
  }

  bool isempty1()
  {
    if(top1!=-1)
      return false ;
    else
    return true ;
  }
  bool isempty2()
  {
    if(top2!=size-1)
      return false;
    else
      return true;
  }

  void display()
  {
    cout<<" stack 1 contains"<<endl;
    for(int i=top1;i>=0;i--)
      cout<<arr[i]<<endl;
    cout<<endl<<"****************"<<endl;
    cout<<endl<<" stack 2 contains "<<endl;
    for(int i=top2;i<size-1;i++)
      cout<<arr[i]<<endl;
  }

  //Destructor
  ~two_stack()
  {
    delete[] arr;
  }

};

void reverse_string( string &s)
{
  stack<char> st;
  // inserting the elements of string in the stack(LIFO)
  for(int i=0;i<s.length();i++)
  {
    st.push(s[i]);
  }
  // due to LIFO LAST WILL COME OUT FIRST MEANS ,
  // REVERSE OF THE WHOLE INPUT
  while(!st.empty())
  {
    cout<<st.top();
    st.pop();
  }

}

void delete_middle_element()
{

}

int main()
{
  string s="madhav";
  reverse_string(s);
  return 0;
}
