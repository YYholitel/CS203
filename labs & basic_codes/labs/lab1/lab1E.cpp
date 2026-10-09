#include<iostream> 
#include<algorithm> 
using namespace std ; 

//跑通逻辑： 1.对于给定长度： n个位置和 m个人 ，
bool check(int arr[] , int n , int m ,int L ,int test){
  //fasle就是不能跑通，true就是可以跑通 
  int current = 0 ;
  int num  =  1 ;
  //循环 结构 ，每个位置放置一个人， 然后计算位置；
  int i = 0 ;

  while(L - current > test){
    int next = current ;

    while(i < n && arr[i] - current <= test){
      next = arr[i] ;
      i ++ ;
    }

    if(next == current) return false ;

    current = next ;
    num ++ ;

    if(num > m) return false ;
  }

  return true ;
}

int BinarySearch(int arr[] , int n , int m , int L ){
  int left = 1 ; 
  int right = L ; 
  int answer = L ;

  while(left <= right){
    int mid = left + (right - left) /2 ; 

    if(check(arr,n,m,L,mid)){
      answer = mid ;
      right = mid -1 ; 
    }else {
      left = mid  +1 ;
    } 
  }

  return answer ;
}

int main (){
  int L , n , m ; 

  while(cin >> L >> n >> m){

    int* arr = new int [n] ;

    for(int i = 0 ; i < n ; i++){
      cin >> arr[i] ;
    }

    sort(arr,arr+n); 

    cout << BinarySearch(arr,n,m,L)<< endl;

    delete[] arr ;
  }

  return 0 ;
}