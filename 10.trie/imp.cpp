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

class Trie
{
public:
  TrieNode* root; //= NULL;

  //coonstructor
  Trie()
  {
    root = new TrieNode('\0');
  }

  void insertuntill(TrieNode* & root , string word)
  {
    if(word.length() <= 1)
    {
      //that means we are at the last Character of word
      // so we need to make its terminal as true;
      root->isTerminal = true;

      return;
    }

    //number of char in the english Alphabets
    int index = word[0] - 'A';

    TrieNode* child; // = NULL;

    // checking if the currCharacter exists
    if(root->children[index] != NULL)
    {
      child = root->children[index];
    }

    //else if it does not ewxist
    else
    {
      child = new TrieNode(word[0]);

      //connect this child to the root
      root->children[index] = child;
    }


    // handling the leftover characters of word Using recursion
    insertuntil( child , word.substr(1));
    // passing child here to build its children
  }

  void INSERT_THE_WORD(string word)
  {
    insertuntil(root , word);
  }


  bool searchuntill(TrieNode* &root , string word)
  {
    //base condition Of isTerminal
    if(word.length() == 1)
    {
      return root->isTerminal;
    }

    int index = word[0]-'A';

    if(root->children[index]==NULL)
      return false;

    TrieNode * child = root->children[index];

    //else condition
    return searchuntil(child , word.substr(1));

  }

  bool SEARCH_THE_STRING(string word)
  {
    return searchuntil(root , word);
  }

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


  void DeleteAWord(string word , TrieNode* &root)
  {
    //there is no need to delete any node
    // just make theTerminal of this word as FALSE
    if(word.length() == 0)
    {
      root->isTerminal = false;
      return;
    }

    int index = word[0]- 'A';

    //check if doesnt Exist
    if(root->children[index] == NULL)
    {
      cout<<"word not FOUND , cant delete"<<endl;
    }

    //else , word is present
    DeleteAWord(word.substr(1) , root->children[index]);
  }

};




int main()
{
  Trie *trr = new Trie();

  string s = "Madhav";

  trr->insertword(s);

  bool ans = trr->search(s);

  cout<<ans<<endl;

  return 0;
}
