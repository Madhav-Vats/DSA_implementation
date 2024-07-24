#include <bits/stdc++.h>
using namespace std;
#include<list>
# include<unordered_map>

// void Swap( char &a , char &b)
// {
//   char temp = a;
//   a = b;
//   b =temp;
// }

vector<vector<string>> WordLadder(string &src , string &des , set<string>&wordSet)
{
  //We are going to use BFS

  //Data Structures Required
  queue<vector<string>>q;
  vector<vector<string>>ans;

  int level = 0;
  //bcoz initially we are at zero level
  //the moment we enter the while loop and pop out all the levels

  q.push({src});

  //DS which stores the Vectors which we have added after this currLevel traversal

  vector<string>UsedWordsOnLevel;
  UsedWordsOnLevel.push_back(src);

  while(!q.empty())
  {
    vector<string> currVec = q.front();
    q.pop();
    // if we are at level one , we will have one elements
    // at two , we will have 2 or more than 2
    //thats why we initilized our level as 0
    // the moment the size of the currVec becomes greater than level
    // means the elements present in the currVec is more than level
    // means if initially the level was 0
    // and now we have element whose count is > 0
    // that means we are at a new level now
    // if we are at a new level we shoul delete those elements which we added in the last
    //levels traversal

    // that means we have reached the next level , so before traversing it
    // delete the strings from the set that you found in the last level
    if(currVec.size() > level)
    {
      level += 1;
      for(auto &it:UsedWordsOnLevel)
      {
        wordSet.erase(it);
      }

      //clearing the Usedwrds vector
      UsedWordsOnLevel.clear();
    }

    //now here we will add the strings which are present is the word list to the currVec
    string endingWord = currVec.back();

    //Checking For des string
    if(endingWord == des)
    {
      //checking whethers its the first time when we encounter this des
      if(ans.size() ==0)
      {
        ans.push_back(currVec);
      }
      else if(ans[0].size() == currVec.size())
      {
        ans.push_back(currVec);
      }
    }

    // this loopstakes us to every char of this endingWord
    for(int j=0;j<endingWord.length();j++)
    {
      //this loop is going to help us to swap everytime the curr char with it
      // and then we will chech whether it exist in the wordSet or not
      char original = endingWord[j];
      for(char c= 'a'; c<='z' ;c++)
      {
        endingWord[j] = c;

        //now this ending word is changed to a new one
        //here we will check whether it exists in the set or not
        if(wordSet.count(endingWord)>0)
        {
          currVec.push_back(endingWord);

          //adding this newly obtained vec to the queue
          q.push(currVec);

          //adding this recently added elements to the UsedWords list ,
          // so that after this level's traversal we can delete it
          UsedWordsOnLevel.push_back(endingWord);

          // now we have added a string to the currVec
          //but there might exist others paths also where we can find our des string
          //So we delete this added element
          currVec.pop_back();
        }
      }
      //changing endingWord to its original state
      endingWord[j] = original;
    }
  }

  return ans;
}

vector<vector<string>>findLadders(string &src , string &des , vector<string>&wordList)
{
  //making the set which stores the wordList strings
  set<string>wordSet(wordList.begin() , wordList.end());
  return WordLadder(src , des , wordSet);
}

int main()
{
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    #endif
  }

  string src = "hit";
  string des = "cog";

  vector<string>wordList = {"hot" ,"dot" ,"dog", "lot", "log", "cog"};

  vector<vector<string>>ans = findLadders(src , des , wordList);

  for(auto &it: ans)
  {
    for(auto &i: it)
    {
      cout<<i<<" "<<"->"<<" ";
    }
    cout<<endl;
  }
}
