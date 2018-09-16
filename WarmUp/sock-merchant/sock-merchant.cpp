#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n; cin >> n;
  vector<int> v(101);

  int element, pairs = 0;
  for(int i = 0; i < n; i++){
    cin >> element;
    v[element]++;
    if(v[element]%2 == 0) pairs++;
  }
  cout << pairs << endl;

  return 0;
}