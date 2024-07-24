#include <bits/stdc++.h>
using namespace std;

class delete_middle
{
public:

void delete_st_mid( stack<int> &st , int &size , int n)
{
  //base case
  if(n==size/2){
    st.pop();
    return; }
  // processing
  int temp= st.top();
  st.pop();
  //rec call
  delete_st_mid(st , size , n+1);
  // processing
  st.push(temp);
}



  //rec call or // processing
void middle_element_deletion( stack<int> &st )
{
  int size = st.size();
  delete_st_mid(st, size, 0);
}

};

class insert_at_bottom
{public:

  void push_last(stack<int> &st , int size , int n , int element){

    //base
    if(n==size)
    {
      st.push(element);
      return;
    }
    //processing
    int temp=st.top();
    st.pop();
    //rec call
    push_last(st,size, n+1, element);
    st.push(temp);
  }

  void PUSH_AT_END( stack<int> &st , int element)
  {
    int size = st.size();
    push_last(st,size,0,element);
  }

};
class reverse_stack
{
public:
  void insert_at_bot(stack<int> &st, int element)
  {
    if(st.empty())
    {
      st.push(element);
      return;
    }
    //processing of deleting
    int temp= st.top();
    st.pop();
    //rec call
    insert_at_bot(st,element);
    //processing of retrieving the
    // temporarily deleted elements back
    st.push(temp);
  }

  void reverse( stack<int> &st )
  {
    //base
    if(st.empty())
      return;
    int temp = st.top();
    st.pop();

    insert_at_bot(st , temp);
    //rec call for whole stack elements call
    reverse(st);

    //rec for inserting the top elements at the bottom

  }

};
class sort_stack
{
public:
  void ascend(stack<int> &st , int size , int n)
  {

  }

  void descend( stack<int> &st , int size , int n)
  {

  }
  void sort_st(stack<int> &st , int asc_or_desc)
  {
    int size= st.size();
    if(asc_or_desc==1)
      ascend(st,size,0);
    else
      descend(st,size,0);
  }
};


#include <iostream>
#include <stack>

void traverseStack(std::stack<int> &st) {
    // Base case: If the stack is empty, return
    if (st.empty()) {
        return;
    }

    // Pop the top element from the stack
    int topElement = st.top();
    st.pop();
    std::cout << topElement << " ";

    // Recursively call traverseStack for the remaining elements
    traverseStack(st);

    // Print the current element
    

    // Push the element back onto the stack to maintain its original state
    st.push(topElement);
}

int main() {
    std::stack<int> myStack;

    // Push some elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    std::cout << "Stack elements (in reverse order): ";
    traverseStack(myStack);
    std::cout << std::endl;

    return 0;
}
