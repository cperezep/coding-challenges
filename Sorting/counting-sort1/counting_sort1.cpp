#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, element; 
    cin >> n;    
    vector<int> freq(100);
    for(int i = 0; i < n; i++){
        cin >> element;
        freq[element]++;
    }
    
    for(auto& i: freq)
        cout << i << " ";
    
    return 0;
}