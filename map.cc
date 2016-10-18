#include <iostream>
#include <string>
using namespace std;

enum Color { red, green, blue };

class map
{
private: 
	Color color;
public:
	map(Color c):color(c){

		cout << color;

	}
	

	/* data */
};


// int fun(){
// 	return 23;
// }
//  std::string& nsGetDestinationHostname(const std::string& destinationId ) {
//  	string host = "vms101";
//  	return host;
//  }

// // int& fun_ref(const  int &a){
// // 	a = 10;
// // 	return a;
// // }

 int main(int argc, char const *argv[])
{

	map test(red);
	// const int a = 23;
	// cout << a << endl;
	// const int& b = fun_ref(a);
	// cout << b << endl;

	// string des = "dest12:123";
	// string &a = nsGetDestinationHostname(des);	
	// cout << a;
	return 0;
}