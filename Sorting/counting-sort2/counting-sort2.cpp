#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n, element; 
    cin >> n;    
    vector<int> freq(101);
    for(int i = 0; i < n; i++){
        cin >> element;
        freq[element]++;
    }

    for(int i = 0; i < freq.size(); i++){
        for(int j = 0; j < freq[i]; j++){
            cout << i << " ";
        }
    }
    return 0;
}