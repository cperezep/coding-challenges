#include <iostream>
#include <vector>

using namespace std;

string game_of_thrones(string s){
  vector<int> abc(26);
  bool middle = false;
  for(auto& it: s){
    abc[(int)*it-97]++;
  }
  for(auto& it: abc){
    if(*it%2 != 0){
      if(!middle) middle = true;
      else return "NO";
    }
  }
  return "YES";
}

int main(){
  string s;
  getline(cin, s);

  cout << game_of_thrones(s);
  return 0;
}