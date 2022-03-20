#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	int b = v.at(2) + 40;
	b = v[2] - '0';
	cout << v.at(2) << endl;
	cout << b;
	return 0;
}