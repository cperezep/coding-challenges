// Permuting Two Arrays
#include <iostream>
#include <vector>

using namespace std;

bool my_func (int i,int j) { return (i>j); }

string twoArrays(int k, vector<int>& A, vector<int>& B){
	sort(A.begin(), A.end(), my_function);
	sort(B.begin(), B.end());
	for(int i = A.size()-1; i >= 0; i--){
		if(A[i] + B[i] < k)
			return "NO";
	}
	return "YES";
}

int main(){
	int q; cin >> q;
	int n, k;
	for(int i = 0; i < q; i++){
		cin >> n >> k;
		vector<int> A(n);
		vector<int> B(n);

		for(auto& j: A)
			cin >> j;
		for(auto& k: B)
			cin >> k;

		cout << twoArrays(k, A, B); << endl;	
	}
	return 0;
}