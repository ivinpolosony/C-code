#include <iostream>
#include <string> 
#include <map>
using namespace std;
int main()
{
	string i,j;
	cout << "first";
	cin >> i; 
	cout << "Second";
	cin >> j;
	(i.length() > j.length()) ? cout << i : cout <<j; 
	std::map<int, int> map;
	//map.insert(12,12);
	return 0;
}