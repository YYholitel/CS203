// 匹配括号 
#include<stack> 
#include<string> 
using namespace std; 
stack<char> st; 
//检索左栈， 右侧空 ，非空要是top,最后检查空栈 
for(char c: s){
  if(c =='(' || c== '[' || c == '{'){
    st.push(c);
  }
  else{
    if(st.empty()){
      return false ;
    }else{
      if(c == ')' && st.top() != '(') return false ;
      if(c == ']' && st.top() != '[') return false ;
      if(c == '}' && st.top() != '{') return false; 
    }
    st.pop();
  }
}
return st.empty() //若最后成功 ，则栈空 
//单调栈 找第一个更 大元素 

for(int i = 0 ; i< num.size(); i++){

  while(!st.empty() && num[i] > num[st.top()]){

    int j = st.top();
    st.pop() ;
  }
  st.push(i) ;
}
//小入栈 ，大出栈循环 ；


// implementation
//push 
int new1;  
ListNode* node =new node; 
node->value = new1 ;
node->next = head;  //相同的指针指向的是相同的对象 
head  = node ; 
//pop
ListNode* temp = head; 
head = head->next; 
delete temp ;
//top
cout << head->val<< endl ; 


//DFS 

