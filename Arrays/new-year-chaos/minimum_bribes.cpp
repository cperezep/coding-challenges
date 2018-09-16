#include <iostream>
#include <vector>

using namespace std;

string minimum_bribes(vector<int> v){
	int bribes, temp;
	bribes = 0;
	for (int i = 0; i < v.size()-1; i++){
		if(v[i]-(i+1) > 2)
			return "Too chaotic";

		if(v[i] && v[i] > v[i+1]){
			temp = v[i];
			v[i] = v[i+1];
			v[i+1] = temp;
			bribes++;
			i = i < 2 ? 0 : i-2; 
		}
	}
	return to_string(bribes);
}

int main(){
	vector<int> v = {2,1,5,3,4};
	cout << minimum_bribes(v) << endl;
	return 0;
}