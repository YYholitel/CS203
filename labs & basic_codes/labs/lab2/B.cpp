#include<iostream>
#include<algorithm>
using namespace std ;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while(T--){

    int n;
    cin >> n;

    int* arr = new int[n];

    for(int i = 0 ; i < n ; i++){
      cin >> arr[i];
    }

    //selection sort 从小到大
    for(int i = 0 ; i < n ; i++){

      int minIndex = i;

      for(int j = i + 1 ; j < n ; j++){

        if(arr[j] < arr[minIndex]){
          minIndex = j;
        }
      }

      swap(arr[i], arr[minIndex]);
    }

    //第三大
    int third = arr[n - 3];

    //检查 third 是否出现多次
    int count = 0;

    for(int i = 0 ; i < n ; i++){

      if(arr[i] == third){
        count++;
      }
    }

    if(count > 1){
      cout << "wa" << '\n';
    }else{
      cout << third << '\n';
    }

    delete[] arr;
  }

  return 0;
}