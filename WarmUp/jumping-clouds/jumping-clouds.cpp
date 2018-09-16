#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n; cin >> n;
  vector<int> v(n);
  for(auto& i: v)
    cin >> i;

  int jumps = -1;
  for(int i = 0; i < n; jumps++)
    i = !v[i] && i < n-2 ? i+2 : i+1;
  cout << jumps << endl;
  
  return 0;
}