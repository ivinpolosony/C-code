#include <iostream>
#include <stack>
using namespace std;
int main(){
  int T,size;
  cin >> T;
  while(T--){
    int num,mid,flag,cnt;
    num=mid=flag=cnt=0;
    stack<int> st;
    cin >> size;
    while(size--){
      cin >> num;
      if( (st.size() > 0) && !cnt)
        cnt++;
      if(cnt){
        if( !st.empty()){
            int top = st.top(); 
            top = top + 1;
            if (num == top){
              cnt++;
            }
        }
      }
      if( (num != 7) && !mid ){
        st.push(num);
      }
      if( !mid && (num == 7)){
        mid = 1;
        continue;
      }else if(mid){
        if(!st.empty()){
          if(  st.top() == num ) {
            // cout << num << st.top() << endl;
            st.pop();
          }else{
            flag = 1; 
            break;
          }
        }else{
          // cout << "num exceeded";
          flag = 1;
          break;
        }
      }
    } //while size
    if(!mid){
      cout << "no" << endl;
    }else if(flag){
      cout << "no" << endl;
    }else if(cnt < 6){
      cout << "no";
    }
    else{
      cout << "yes" << endl;
    }
    cout << endl; 
  }
    
}
