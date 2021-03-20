#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> v;
	v.push_back(vector<int>(2));
	cout << v[0][0] << endl;
	cout << "hello" << endl;
	return 0;
}