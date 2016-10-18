#include <iostream>

using namespace std;
class test {
public:
  typedef enum {NS_MULTI_AGRS_DIST_MODE_ALL_LOCAL=1,NS_MULTI_AGRS_DIST_MODE_ALL_REMOTE=2,NS_MULTI_AGRS_DIST_MODE_MIXED=3} nsMultiDistributionMode ;

  nsMultiDistributionMode nsGetRoutableAgrsMultiDistributionMode(){
    return NS_MULTI_AGRS_DIST_MODE_MIXED;
  }
  void  te1(){
    bool LOCAL_FLAG = 1;
    bool REMOTE_FLAG = 1; 
    if((LOCAL_FLAG) && (REMOTE_FLAG != 1)){
      std::cout <<  "L:OOOCL" << std::endl;

    }else if((LOCAL_FLAG != 1) && (REMOTE_FLAG)){
      std::cout <<  "REMOTE" << std::endl;

    }else{
      std::cout <<  "MIXED" << std::endl;

    }


  }
};



int main(int argc, char *argv[]){
  cout << "Hello";
  test ob1l;
  ob1l.te1();
  cout << ob1l.nsGetRoutableAgrsMultiDistributionMode();
  return 0;
}
