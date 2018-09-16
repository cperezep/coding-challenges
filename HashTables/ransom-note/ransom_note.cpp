#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
  int m, n; 
  unordered_map<string, int> mymap;
  string word;
  
  cin >> m >> n;
  for(int i = 0; i < m; i++){
    cin >> word;
    mymap[word]++;
  }
  
  for(int j = 0; j < n; j++){
    cin >> word;
    if(!mymap[word]){
      cout << "No" << endl;
      return 0;
    } else
      mymap[word]--;      
  }
  cout << "Yes" << endl;
  return 0;
}   