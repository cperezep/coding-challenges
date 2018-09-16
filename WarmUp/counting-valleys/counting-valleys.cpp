#include <iostream>

using namespace std;

int main(){
  int n; cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string s; getline(cin, s);
  
  int counter, valleys;
  counter = valleys = 0;
  for(auto& i: s){
    valleys = (!counter && i=='D') ? valleys+1 : valleys+0;
    counter = (i=='U') ? counter+1 : counter-1;
  }
  cout << valleys << endl;

  return 0;
}