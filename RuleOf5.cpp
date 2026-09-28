#include <iostream>
#include <cstring> 
class A{
  private : 
    int* p ; 

  public :
    A(int x ){
      p = new int(x) ; 
      A b = a  ; //指向同一块内存 

  }

}

class B {
  public : 
    ~A();

    A(const A& other ); // copy constructor 
    A(const A& other ){
      p = new int(*other.p) //拷贝一个地址的对象的 指针 ；属于深拷贝 
    }

    A& operator  = (const A& other ) //copy  Assignment；不创建新内存，只是赋值 

    A(A&& other ) //move operator ;右值引用 
    A a = 32 ;//32为右值 
    A(A&& other ){
      p = other.p;
      other.p = nullptr;
    }

    A& operator=(A&& other ){
      if (this != &other){
        delete p ; //delete p是堆区对象 ；delete >= 析构和释放内存 ，对象要是 newdelete 
        p = other.p;
        other.p = nullptr;
      }

    }
}