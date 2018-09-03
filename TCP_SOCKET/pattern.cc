#include <iostream>
#include <string>
#include <map>


using namespace std;







int main()
{
  string str = "codesleepcode";
  string pattern = "XYX";
  string subStr = "";
  map<string,int> subStrMap; 
  map<char , int> patternMap;
  for (int i = 0; i < str.length(); ++i) {
    subStr += str[i];
    subStrMap[subStr]++;
  }

  int lenghtOfPattern  = pattern.length();

  for(int i = 0;i < lenghtOfPattern  ; i++){
    patternMap[pattern[i]]++;
  }


  if( ((str.length()-1) % lenghtOfPattern) != 0) {
    cout << "no pattern" << endl;
  }

  int start  = 0;
  int end = str.length();
  int i = 0,j = end;
  // cout << start  << "-" << end << endl;
  for (; i < end; i++,j--) {
    if(i == j){
      cout << i << ":"<< str[i] << endl;
      break;
    }
  }

  cout << i << " " << j << " " << (start + end)/2 << endl;

  return 0;
}
