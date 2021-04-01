#include<iostream>
#include<vector>
using namespace std;

class Fibonacci{
public:
  Fibonacci( vector<int> &arr, int target ){
    this->array = arr;
    this->target = target;
    this->len = arr.size();
    this->result = 0;
  }
public:
  int getResult(){
    InitFibArrayAndArray();
    int hIndexInA = len-1;
    int lIndexInA = 0;
    int hIndexInF = fibArray.size() - 1;
    while (1)
    {
      if( hIndexInA < lIndexInA ){
        return -1;
      }

      int mIndexInA = fibArray[hIndexInF-1] + lIndexInA;

      int middleValue = array[mIndexInA];
      int highValue = array[hIndexInA];
      int lowValue = array[lIndexInA];

      if( middleValue == target ){
        return mIndexInA;
      }else if( middleValue > target ){
        hIndexInA = mIndexInA - 1;
        int currentLen = hIndexInA - lIndexInA + 1;
        for (int i = 0; 1; i++){
          if( fibArray[i] >= currentLen ){
            hIndexInF = i;
            break;
          }
        }
      }else if( middleValue < target ){
        lIndexInA = mIndexInA + 1;
        int currentLen = hIndexInA - lIndexInA + 1;
        for (int i = 0; 1; i++){
          if( fibArray[i] >= currentLen ){
            hIndexInF = i;
            break;
          }
        }
      }
    }
  }
private:
  vector<int> array;
  vector<int> fibArray;
  int target;
  int len;
  int result;
  friend ostream& operator << ( ostream & in, Fibonacci &current );
private:
  void InitFibArrayAndArray(){
    fibArray.emplace_back(0);
    fibArray.emplace_back(1);
    for(int i=0; fibArray[1+i]<len; i++){
      fibArray.emplace_back( fibArray[1+i] + fibArray[i] );
    }
    int add = (*fibArray.rbegin()) - len;
    len += add;
    for( int i=0; i<add; i++){
      array.emplace_back(*array.rbegin());
    }
  }
  
};

ostream& operator << ( ostream & out, Fibonacci &current ){
  out<<current.result;
  return out;
}
int main (){
  vector<int> tem{1,2,3,4,6};
  Fibonacci test(tem, 5);
  cout<<test.getResult();
}