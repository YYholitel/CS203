vector<int> v = {10,20,30};

for(auto it = v.begin(); it != v.end(); ++it){
  cout <<*it << endl; 
}
//不暴露Node* 