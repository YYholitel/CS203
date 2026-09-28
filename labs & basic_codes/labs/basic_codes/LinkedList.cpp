#include<iostream>
using namespace std; 
// this is the basis of LinkedList

// Traversal
ListNode* curr = head; 
while(curr != nullptr){
    cout<< curr->val <<endl;
    curr = curr-> next; 
}
// reverse 
ListNode* curr = head; 
ListNode* prev = nullptr ;

while( curr != nullptr){
  ListNode* next =curr -> next ; 
  curr -> next = prev ;
  
  prev = curr; 
  curr = prev ;
}
  return prev ; 
// 存后路 ，反转 ，prev 走 ， curr 走 ；

// merge 
listNode dummy ;
listNdoe* tail = &dummy;

ListNode* x = list1 ;
ListNode* y = list2 ;
while(x != nulltpr && y!= nullptr ){
if (x->val <= y->val){
  tail-> next = x ;
  x = x->next ;
  }
else{
  tail-> next = y ;
  y = y->next; 
  }
   tail = tail ->next ; //先接dummy再接入next ; 
}
//fast slow 

ListNode* fast  = head; 
ListNode* slow  = head;
while(fast != nullptr && fast->next->next != nullptr) { //两个都不能超界 
fast = fast -> next ->next ;
slow = slow->next ;
}