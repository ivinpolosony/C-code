#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person{
private:
public:    
    string name;
    int age;
    Person(int age, string name): age(age),name(name){
        //cout << "Object created";
   }
   ~Person(){}
  Person  getDetails();
};

Person  Person::getDetails(){
	return *this;
}



int main(int argc, char const *argv[])
{
	vector<Person> vecPerson;

	for(int i = 0; i < 10 ; i++){
		vecPerson.push_back(Person(i,"ivin")); //inline object creation 
	}
	for(auto item:vecPerson){
		/*cout << item.age;
		cout << item.name;*/
		cout << item.getDetails().age<<endl;
		//cout << item.getDetails();


	}

	return 0;
}