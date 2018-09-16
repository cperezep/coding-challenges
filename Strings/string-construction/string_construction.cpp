#include <iostream>
#include <vector>

using namespace std;

int main(){
  int q; cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');  
  for(int i = 0; i < q; i++){    
    string s;
    getline(cin, s);
    int counter = 0;
    vector<bool> letters(26);
    for(auto i: s){
      if(!letters[(int)i-97]){
        letters[(int)i-97] = 1;
        counter++;
      }
    }
    cout << counter << endl;
  }
  return 0;
}
