#include<iostream>
#include<algorithm>
using namespace std ;
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int T ;
cin >> T ;
while(T > 0){
 int n, m;
 cin >> n >> m;

  int* a = new int[n];
  int* b = new int[m];

  for(int i = 0; i < n; i++){
      cin >> a[i];
  }

  for(int i = 0; i < m; i++){
      cin >> b[i];
  }

 int j  = 0 ; 
 int k = 0 ;
 int l = 0 ;
 int* c = new int [m+n];
  while(j< n  && k < m){
    if(a[j] <= b[k]){
      c[l++] = a[j++];
    }else{
      c[l++] = b[k++];
    }
  }

  while(j < n){
    c[l++] = a[j++];
  }
  while(k < m){
    c[l++] = b[k++];
  }
for(int o = 0 ; o <m+n ;o++){
  cout << c[o];
  if(o != m+n-1){
    cout << " ";
  }
}
  cout << '\n';
  delete[] a;
  delete[] b;
  delete[] c ;
  T -- ; 
  }

}