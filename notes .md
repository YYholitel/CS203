	welcome to the world of C! 
	欢迎来到C的世界 ！
	因为是速通和手写，我们主要关注一下C对内存的工作是怎么运行的，缓存是如何分配的， 以及对别的语言来说有什么区别 
# 基本运行
 - C语言需要编译完后才能运行
 ```C
$ gcc hello.c -o a.out  // 使用gcc编译 
$ ./ a.out   // 运行
 ```
## Token 
- token 是程序的基本组成单元 ，编译器通过对源代码进行词法分析 ，讲其转化成令牌 
### Keywords
### Identifiers 
- C是大小写敏感的 
### Constants 
```C 
const char P = '\n'

char greeting[] = "Hello,World !" ; //字符串常量 ，尾部包含 \0

```

### String Literals 
### Operators 
![[Pasted image 20260823150134.png]]
 - 用到再说 
### Seperators  

- （） 语句顺序 
- {}函数体，控制流 ，以及结构体的初始化 
- / [ /]  申明数组和元素访问 



  ## 预处理指令 
 ```C
# include <stodio.h>  //头文件 
# define PI 3.14159  // 宏定义 
 
int main (int a, int b ) ; //只声明函数 ， java不允许 

int main (){
...
}  //主函数 

int a ; // 变量声明 ，如果变量不初始化，就会生成垃圾 
 ``` 


# CPP basis
## OPP
 - CPP是面向对象的，可以调用内存分布的语言 

### overload 
 - CPP 的overload  不需要添加关键字样 
 - 但是必须添加

### 继承 
```C++
class MyDog : public Base MyPets{
 
}
```
### override 重写 
```C++ 
override 
```
## reference
-  索引指向同一对象
```C++
 int x = 10 ; 
int& ref = x ; 
const int& cref = x; //constant字样类似Java的final ,数据不可被修改  
```

- 一般使用传参结构
```C++
void change (int& x ){
	x = 100; 
}
int a = 5 ;
change(a) ; 
 
```

- 我们把a 叫做x的alias

## pointer 指针 
```C++
int* p  //我们把P叫做指向int的指针
int* x = &10 ; //&为取址符号  
*p // p指针指向的对象 
p -> getAge(); // ->对指针 
*p.getAge(); //相当于.方法 ，*p是解引用 
```
- 什么是double free ? 什么是copy constructor ?  他是浅拷贝还是深拷贝 ？如何区别浅拷贝和深拷贝？ 什么时候用 copy constructor ?  什么时候使用 copy assigment 
- operator(两个对象之间的赋值)？常见的三种错误？ 
### Rule of five
```C++
class A {
	private : 
		int* p ;
	~A(){};// 
	A(int* &x){
	} //
	A& x = int* w ;  
}
```
- 知道常见写法
```C++
A b = a ; //Copy Constructor ;
b = a; // copy Assigment ;
A c = std::move(a); //move constructor i
c =std::move(b); // move assigment 
```
- C ++ 常见内存错误 
## double free
 ```C++
 a.p ;
 b.p ;
 delete p ; 
 delete p ; //内存泄漏 ，shallow copy 特性 
 ```

## memory leak  内存泄漏 
内存存在 ，由于删除指针 ，无法找回 
```C++
int* p = new int(10);

p = nullptr;  //p无法被删除 

```
## dangling pointer 悬空指针  
内存不在 ，指针保留 ，指针悬空 
```C++
int* p = new int(10);
delete p ; // p =nullptr 
```
## parameters 
	关注函数的值的传递 ，以及参数的变化 (是否可可以修改，修改的是本身还是参数？)
### pass by value
- 直接赋值 ，x相当于 a的一个拷贝（和java)一样 
```C++
void f(int x ){
	x = 20 ;
}

int a =10 ;
f(a);
```
### pass by reference 
```C++
void f(int& x ){
	x = 20 ;
}
int a = 10 ;
f(a) ; // a==20 
```
### const reference 
 ```C++
 void print(const A& x ){
 //无法发修改 
 }
 ```

### pointer parameter

```C++
void f(int* p ){
*p =20; 
}

int a  =10 ;
f(&a) //地址索取 ，直接修改原地址 
```

- 函数拿到地址 ，就修改指针 

## life cycle 
### initializer list
- 这是C++的语法糖 
```C++ 
Student(int x ): age(x){

}
Student(int x ){
int age = x ; 
}

```
## operator overloading  操作符重载 
- 操作符重载解决了自定义类和未定义类的计算

 - grammar  : Point operator+ (const Point& other );
```C ++ 
```

 - 手写一个数组相加例子 
 ```C++
 class Array5 {
 public :
  Array5 x = [5];  
 

 Array5 operator+(const Array5& other){
 	 Array5 result ; // 变量引用放外面
 for(int i = 0 ; i <= 4 ; i++){
	 result.x[i] = x[i] + other[i];
	 	   }
	 return result ;     
    } 
 }
 ```
# templates  模板 
- 像极了java里面的模板 ,直接在里面添加；
```C++
template <typename T> 
class Array5 {
public : 
	T x[5];
};
Array5<int> a ; 
Array5<double? b ;
```
# STL 
# inheritance in C ++ 
- encapsulation ,abstraction ,polymorphism 封装 ，继承，多态 ； 
继承语法糖
```C++
class Fruit {
	public : 
	vitural std::string getName() =0 ;
};
class Apple :publlic  Fruit {
};
```
## struct 结构体 
 - 结构体通过封装实现 数据组合 
 - struct A{
 } 内部都是 public ,class 内部成员都是public
 
# Arrays 
## Arrays 和 数组的关系 
本质上 ，a就是一个指向数组的指针 ；由于数组的内存的连续性 ，我们可以得到 
```C++
int a[5]={1,2,3,4,5};
// a 约等于 &a[0] ; 是一个指针 
//因此 *a 
```
## 二分法 

## 动态数组 
### 均摊复杂度 
# 写在前面 
	 每学一个数据结构，我们关心以下问题： 这个数据结构具有什么特点？ 存储的数据有什么特点？ 具有什么性质？ 实现的方法是什么（是抽象数据类型吗？） 会涉及什么算法结构？ 
# Linked List 
	关注核心 ：链表的性质 ； 链表实现 ；增删查减的复杂度分析 ；
## Linked List 的性质 
![[Pasted image 20260903133744.png]]
- 其中节点一般不连续存储
## Linked List的实现
### Node 
 一个Node包括一个值和一个指针 ；
 - 每个指针都指向下一个 **节点** 的地址（注意不是节点的属性） 

```C++
construct Node  {
	int val ;
	Node* next ;
	
	Node(int x){
		val = x ;
		next = nullptr ;
	}
}
Node* a = new Node(10);
Node* b = new Node(20);
Node* c = new Node(30);
a->next =  b ; //指针，相当于解引用 
b->next = c ;
```
## 遍历 
```C++
Node* curr = head;
while(curr != nullptr){
	cout<< curr->val<< endl; 
	curr = curr-> next;
}
```
## 插入头指针 
```C++
Node* curr = new Node(10); //存入值 
curr->next = head;  
head = newNode ; //记得插入后要更新 
```
## 删除
```C++
Node* temp = head; 
head = head-> next;
delete temp ;  
```
## 中间插入 
```C++
Node* 1 = new Node(10);
Node* 2 = new Node(20);
Node* 4 = new Node(40);

Node* 3 = new Node(30);
2->next = 3 ; 
3->next = 4 ;

```
## 中间删除 
```C++
//删除 3 :
2->next = 4 ;
3-> next = null ; 
delete 3 ;
```
## 链表反转 
- 为了不让链表断裂；一定要加上源地址 
```C++ 
next = curr-> next ; //存后路
curr-> next = prev;  //后改前
prev = curr ;  //偷换尾
curr = next ;//尾换头 
```
## Dummy Node 假节点 
- Dummy Node通过添加边界节点（值无效） ，减少边界情况
- 接链表 ，加dummy 
```C++ 
ListNode dummy ;
ListNode* tail = &dummy ;
tail-> next = x ;
tail = tail->next;
//最后 
return dummy.next;

```
## Fast/ Slow Pointer 
+ 链表运动速度不同 
+ 解决找中点，判断循环，找环入口，回文链表 
```C++
ListNode* slow = head ; 
ListNode* fast = head; 
while(fast != nullptr && fast-> next != nullptr){
	slow = slow-> next ;
	fast = fast -> next -> next; 
}

```
- 快指针到了终点 ，慢指针到中点
## 前后双指针 / 固定间距 



### 题目 
- [ ] LC206 9.3red  9.6yellow 
- [ ] LC203 9.3 red 
- [ ] LC21 9.6 red 
- [ ] LC876
- [ ] LC141
- [ ] LC19
- [ ] LC160
- [ ] LC234
- [ ] LC142
- [ ] LC 83 
- [ ] LC 24 
- [ ] LC 92 
- [ ] LC 143 
- [ ] LC  2
# Stack 
## 性质
- LIFO （last in first out) 
- 操作
```C++
#include<stack>
using namespace std; 
stack<int> st; 

st.push(3); //入栈
st.top(); //看栈顶 （底部） 
st.pop(); //弹出栈顶 
st.empty();  // 是否为空
st.size(); //大小 

```

## 操作杂度
- 所有的操作都是 o(1)
## 实现 
 - Stack是ADT（抽象数据类型 ） ，可以通过 **Array**或**Linked List** 实现 
 - 通过ADT分离了implementation
 - 
## 常见框架 
### 括号模板
- 括号，成对，嵌套，匹配
```C++
stack<char> st ; 

for(char c :s ){
	if(c =='('){
	st.push(c); // 左括号入栈 
	}else{
		if (st.empty()) return false ; //空栈无效
		
		if (st.top() != c) return false ; //栈顶非c无效 
	
		st.pop(); //出战
	}
}
return st.empty()
```

- 本质 
### 状态栈 
- 存储之前发生了什么  ，比如 撤销 ，返回 ，DFS！，表达式解析， 函数调用 
```C++
stack<State> st; 
st.push(initial);

while(){
	State cur = st.top() //栈顶为今
	
	if(new state){
		st.push(NewState); //新状态入栈
	}
	if(返回状态){
		st.pop(); //返回出栈 
	}
}
```

### 单调栈
 - 常见比大小排列 
```C++
stack<int> st; 

for( int i = 0 ; i < nums.size() ; i++){

while (!st.empty() && nums[i] > nums[st.top()]){
	int j = st.top();  //j小入栈 
	st.pop(); 
  }
  st.push(i);
}
```
- 本质 
- 画图 
# Queue 

##  properties 
- FIFO 先进先出
 - 类比 stack, Queue有常见的操作： 
	- push
	- front 队头
	- pop
	- empty
	- 对头： $$ front = (size+size)\% capacity $$
## implements (Array)
 - Circular Array ,通过移动指针循环实现 
```C++ 
int []
```

## implements(Linkedlist )
## enqueue/dequeue
```C++
back -> next = newNode; 
back = newNode ;
//dequeue 

*Node temp = front ; //先存一个位置  
front = front -> next; 
delete temp ;
```
## resize 
```C++
void resize(){
	int newCapacity = capacity * 2;
	T* newData = new T[newCapacity];
	
	for (int i = 0 ; i < size ; i ++){
		newData[i] = data[(front + i) % capacity ] ;
		
	}
	delete[] data ; 
	
	data  = newData ;
	capacity = new Capacity ;
	front = 0 ; //放数组 ，存数组 ，改位置 ，重命名 
}
//armotized analysis  of resize : O(1)  (操作复杂度相加（考虑最坏情况) /操作次数） 
```
# String
## substring

## 字符串匹配 

### Brute Force 

### RKA 
### FSA 

### KMP 

# iterator 
 - 对于AVL ，封装数据使用方式 ，实现统一数据迭代 
- iterator迭代器的使用方式 
```C++
vector<int> v = {10,20,30};

		for(auto it = v.begin(); it != v.end() ; ++it){
	cout << *it << endl ;
}
```
# Tree
	 既然都学到tree 了，为啥不看看BFS /DFS/recursion 呢？ 
## basis
 - 根节点 ，子节点 ，叶节点 ， 路径 ，深度（从根节点到目前节点的长度）  ，高度 
	 - depth + height  = ...
- N个节点 ， N-1 条边 
- 树中间不包括环 
## time complexity 
 对于二叉搜索树 ，其时间节点永远是 
$O(\log n)$
 
## implementation 
```C++
struct TreeNode{
	int val ; 
	TreeNode* left ;
	TreeNode* right; 
}; 
```

## 二叉树 
- 直接在 LinkedList 基础上添加 ...

	下面解释三种常见的算法结构 

### Preorder 前序遍历 
- 遵循根-左-右 顺序 
```C++
void preorder(TreeNode* root){
	if (root == nullptr) return ;
	
	cout << root->val << " " ;
	preorder(root->left);
	preorder(root -> right);
}
```
## B  树
## 红黑树 （ 手写！）

# BST/AVL
# Heap 
# Hash Table 

# Graph 

# Union Find 
# Sorting 
## Bubble Sort 冒泡排序 
- 比较相邻的数据并排序
```C++ 
int main(){
int [] arr ; 
for(int i = 0 ; i < arr.length(); i++){
	cin << arr[i] ;
	}
for(int i = 0 ; i< arr.length(); i++){
	if(i!= 0)
		if(arr[i]<arr[i-1]){
			int temp = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] =temp;
			}
		} 
	}
}
```
- 时间复杂度 ： 
- O($n^{2}$) (worst case )
- O($n^{2}$)(armotized case)
##  Selection Sort选择排序 
 - 每次找到最小的数 ，之后根据位置排序 
```C++
int main(){
int [] arr ; 
for(int i = 0 ; i < arr.length(); i++){
	cin << arr[i];
	}
int [] arr1 = arr;
for(int i = 0 ; i < arr.length(); i++){
	int min; 
	for(int j = i ; j < arr.length(); j ++){
		if(min> arr[j]){
			min = arr[j];
			}
		}
	arr1[i] = min; 
	}	
}
```
- 时间复杂度： O($n^{2}$) (worst case )
	-  O（ $n^{2}$ ）(armotized case )

## Insetion Sort 

## Merge Sort  
- 与
# Binary Search 
- 二分查找
```C++
int main(){
	int left = 0 ;
	int right = n ; 
	while(left< right){
	int mid = left + (right -left) /2 ; 
	if(arr[mid] < left){
	left += 1;
		}
	if(arr[mid] > right){
	right -=1;	}
	}
 }
```
 - 复杂度是 $\log n$
 - 考虑边界条件 ： 
 - first >= x : return left
 - first> x (if arr[mid] <left )  , return left 
 - last <= x  if(arr[mid] <= left) return right 
# 
# Greedy 

# Backtracking 

# Divide & Conquer

# DP 
# GA2

# 课堂lab整理
# RAM 计算模型 
![[Pasted image 20260922024710.png]]
 - DSAA关注CPU的开销 ，不关心 input/output的开销

- ALU 算数逻辑单元  CPU给ALU传入指引 ，ALU通过在RAM中间的寄存器计算 ，得到并输出结果 
- CPU 中心处理单元 
	-  由固定个寄存器组成 
	- 基础操作过程：
		- initialization 初始化 
		- Arithmetic (ALU)计算 
		- Comprasion / Branching  比较 
		- Memory Access 知识记忆 

# 写在前面 
	 如何去思考一个算法问题： 计算的开销是多少（ 时间复杂度会超时吗 ？ CPU操作过程复杂度是如何的 ？Worst Case是如何考虑的？如何去写伪代码？ 如何判断一个算法的正确性？是否有更简单的算法？ 

# Time complexity 
- 时间的开销包括算法开销和 机器时间开销 


#  Case Analysis 
## worst case analysis
- best case: 二分查找 ，思考一下算法复杂度为什么是 $O(\log_{2}n)$
  - $2^{ x } = n$
  - $x= \log_{2}n$

## Average case  平均输入 


## Amortized   case 摊销输入

# Asymptotic Analysis 渐近分析 



