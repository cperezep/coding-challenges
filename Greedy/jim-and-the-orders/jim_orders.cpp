#include <iostream>
#include <map>

using namespace std;

int main(){
  int n, ord, prep; 
  cin >> n;
  multimap<int, int> m;
  for(int i = 1; i <= n; i++){
    cin >> ord >> prep;
    m.insert(pair<int,int>(ord+prep, i));
  }
  
  for(auto& it: m)
    cout << it.second << " ";
  
  return 0;
}