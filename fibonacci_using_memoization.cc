#include <iostream>
using namespace std;
int fibonacci_memo(int num){
  int first = 0, second = 1, result;
  if (num == 0){
    return first;
  }else if(num == 1){
    return second;
  }
  for (int i = 0; i < num; ++i) {
    result = first+second;
    first = second;
    second = result;
  }
  return result;
}


int main(int argc, char *argv[])
{
  cout << fibonacci_memo(8);
  return 0;
}
