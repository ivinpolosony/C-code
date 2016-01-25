#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<string> v;
	std::vector<std::vector<char>> v1;
	for (int i = 0; i < 3; ++i){
		v.push_back("sd");
	}
	for(auto item:v){
		cout<<item<<std::endl;
	}
	for(unsigned int i = 0; i < v.size(); i++){
		cout << v[i];
	}
	for(auto i = begin(v); i != end(v) ; i++){
		cout << *i << endl; // Notice the *i 
	}

	return 0;


}