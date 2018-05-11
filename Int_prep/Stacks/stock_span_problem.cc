#include <iostream>
#include <stack>
using namespace std;

void display(int arr[], int size){
  cout << "O/P" << endl;
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << endl;
  }
}



int main()
{
  // Stock span problem
  // Span is defined as number of consecutive days before the given day where the price of stock was less than or equal to price at given day.
  int stocks[] = {100, 60,70,65, 80, 85};
  // {1,1,2,1,4,5}
  size_t size = sizeof(stocks)/sizeof(int);
  int spans[size];
  spans[0] = 1; // since first day span is always 1
  int span;

  // brute force 
  for (int i = 0; i < size; ++i) {
    span = 1; // min span
    for(int j = i-1;j >= 0; j--){
      if(stocks[j]>=stocks[i]){
        spans[i] = span;
        break;
      }else{
        span++;
        spans[i] = span;
      }
    }
  }

  display(spans, size);


  stack<int> st;
  int spans1[size];
  st.push(0);
  for (int i = 1; i < size; ++i) {
    span = 1;
    while(!st.empty() && stocks[st.top()] <= stocks[i]){ // pop until the number which larger
      st.pop();
    }
    if(st.empty()){
      spans[i]= i+1;
    }else{
      spans[i]= i - st.top(); 
    }
    st.push(i);
  }
  display(spans, size);
  return 0;
}

