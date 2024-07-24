 #include<bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  char data;
  TrieNode* children[26];
  bool isTerminal;

  TrieNode(char ch )
  {
    this->data = ch;
    for(int i=0;i<26;i++)
      children[i]=NULL;

    isTerminal = false;
  }
};

class Trie{
public:
  TrieNode* root ; //global root
//constructor for trie
  Trie()
  {
    root = new TrieNode('\0');
  }
//recursive code
// start from string[0] , and in next recursive call , make  a substring that starts from string[1]
// in that wy we are reducing the stringhypothtically for recursion
void insertuntil( TrieNode* &root , string word)
{
  // base case ... when the substring becomes zero , make the is Terminal as True
  if(word.length()<=1)
    {
      root->isTerminal = true;
      return;
    }

  //checking the index of the first eement of string ( according to the alphabatec order )
  int index = word[0] - 'A' ; // subtracting with ascii value of A ...... Assuming all alpha in word are capital

  TrieNode* child; // this node will be used as an iterator
// IF THE ELEMENT IS ALREADY PRESENT
  if(root->children[index]!=NULL) // bcoz maybe the element is already present , so just strore that into child for further recursion
  {
    child = root->children[index];
  }
// IF THE ELEMENT IS NOT PRESENT
// create a new TrieNode
// and insert it at that position ... maybe we are inserting
  else
  {
    child = new TrieNode( word[0] );
    root->children[index]= child;
  }

  //building the Trie further

  insertuntil(child , word.substr(1));

}

void insertword(string word)
{
  insertuntil(root , word );
}

bool searchuntil( TrieNode* &root , string word)
{
  // checking is Terminal is important
  // base condition
  if(word.length()==1)
    return root->isTerminal;

  int index = word[0] - 'A';
  TrieNode * child;
  if(root->children[index]!=NULL)
  {
    child= root->children[index];
  }
  else
  {
    return false;
  }

  return searchuntil(child , word.substr(1));
}

bool search(string word)
{
  return searchuntil(root , word);
}
//
void removeunil( TrieNode* &root , string word)
{
  //base condition
  if(word.length()==1)
  {
    root->isTerminal= false;
    return;
   }

  int index = word[0]- 'A';
  TrieNode* child;

  if(root->children[index]!=NULL)
  {
    child = root->children[index];
  }

  else
  {
    cout<<"the given element is not present in the trie so can't be deleted";
    return;
  }

  return removeunil(child , word.substr(1));
}

void removeWord(string word)
{
  removeunil(root,word);
}
void printTRIE( TrieNode* &root )
{
  TrieNode* child;
  for(int i =0; i<26 ;i++)
  {
    if(root->children[i]!=NULL)
    {
      child = root->children[i];
      cout<<root->children[i]->data;
      // printTRIE(child);
    }
    else
      return;
  }
}

void printTrie()
{
  printTRIE(root);
}
};

// void deletion( TrieNode* &root )


int main()
{
  string name = "MADHAV";
  Trie *t = new Trie() ;
  t->insertword(name);
  bool ans = t->search(name);
  cout<<ans<<endl;
  // t->removeWord(name);
  // bool an = t->search(name);
  // cout<<an<<endl;
  // cout<<endl;
  t->printTrie();
  return 0;
}
