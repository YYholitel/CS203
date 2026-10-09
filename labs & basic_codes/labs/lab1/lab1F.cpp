#include<iostream>
#include<algorithm> 
using namespace std;

int main(){

int n , T ;
cin >> n >> T ;

// 输入  
int* a = new int[n];
int* b = new int[n];

for(int i = 0 ; i < n ; i++){
   cin >> a[i];
}

for(int i = 0 ; i < n ; i++){
    cin >> b[i];
}

while(T > 0){

  int l;
  int r; 
  cin >> l >> r;

  int first = l - 1;
  int last = r - 1; 

  int len = r - l + 1;

  int* current = new int[2 * len];
  
  int i = 0;
  int left = first;
  int right = first; 

  while(left <= last && right <= last){

    if(a[left] <= b[right]){
      current[i] = a[left];
      i++;
      left++;
    }else{
      current[i] = b[right];
      i++;
      right++;
    }

  }

  if(left <= last){

    while(left <= last){
      current[i] = a[left];
      left++;
      i++; 
    }

  }else{

    while(right <= last){
      current[i] = b[right];
      right++;
      i++;
    }

  }

  int median = current[len - 1];

  cout << median << endl;

  delete[] current;

  T--;
}

delete[] a;
delete[] b; 

return 0;
}