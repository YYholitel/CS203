#include<iostream> 
#include<algorithm> 
using namespace std ; 
//看看这个长度能不能跑 
bool check(int arr[] , int n , int m ,int L ,int test){
  int temp = test;
  int num  =  m ;
  for( inti )

}
    
    
int BinarySearch(int L ){
  left = 0 ; 
  right = L - 1 ; 
  int answer = 0 ;
  while(left < right){
    mid = left + (right - left) /2 ; 
    if(check(arr,mid)){
      answer = mid ;
      right = mid -1 ; 
    }else {
      left = mid  +1 ;
    } 
  }
  return left ;
}

int main (){
int L , n , m ; 
cin >> L >> n >> m; 
int* arr [] = new int [n] ;
for(int i = 0 ; i < n ; i++){
  cin >> arr[i] ;
  }
sort(arr,arr+n); 
BinarySearch();

}