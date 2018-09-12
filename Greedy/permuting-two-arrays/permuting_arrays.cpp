// Permuting Two Arrays
#include <iostream>
#include <vector>

using namespace std;

bool my_function (int i,int j) { return (i>j); }

string twoArrays(int k, vector<int> A, vector<int> B){
	sort(A.begin(), A.end(), my_function);
	sort(B.begin(), B.end());
	for(int i = A.size()-1; i >= 0; i--){
		if(A[i] + B[i] < k)
			return "NO";
	}
	return "YES";
}

int main(){
	vector<int> A = {2,1,3};
	vector<int> B = {7,8,9};
	cout << twoArrays(10, A, B) << endl;
	return 0;
}