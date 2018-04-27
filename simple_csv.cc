#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<vector<double> > values;
    vector<double> valueline;
    ifstream fin("in.csv");
    ofstream fout("out.csv");
    string item;
    for (string line; getline(fin, line); )
    {
        istringstream in(line);

        while (getline(in, item, ','))
        {
            valueline.push_back(atof(item.c_str()));
        }

        values.push_back(valueline);
        valueline.clear();
    }

    vector<vector<double> >::iterator myIterator; 
    myIterator = valueline.begin();
    cout << (*myIterator).second();
    for (auto val:values){
    	fout << endl << endl;
    	for (auto v:val){
    		fout << v;
    		fout << "|\t|";
    	}
    }
}
