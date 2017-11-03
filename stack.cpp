#include <iostream>
using namespace std;
#define N 10
template<typename T>

class Stack
{
    private:
        T *m_head;//栈头
        T *m_tail;//栈尾
        T buffer[N];
        int count;//下标
    public:
    Stack(T value)
{
    for(int i = 0; i < N; i++)
    {
         
          buffer[i] =value;
    }                                   //初始化
    m_tail = m_head = &buffer[N-1] ;     //默认栈头等于栈尾等于数组最后一个元素
    count  = N-1;                        //最初下标
}

 void in_stack(T data)
 {
    
     if(empty())
     {
         cout<<"栈满"<<endl;
     }
     else
     {
          buffer[count] = data;        //栈不满才执行入栈
          count--;
     }

 }

 void out_stack()
 {
     
     if(empty())
     {
         cout<<"栈空"<<endl;
     }
     else
     {
        *m_head = 0;                   //栈不为空才出栈
        count++;
        m_head= m_tail = &buffer[count];
     }
 }

 int empty()
 {
     if(count == N-1)
     {
         return -1;
     }
     if(count == 0)
     {
         return 1;
     }
 }

 void res_stack()
 {
     T *tmp;           //交换指向位置（不确定）
     tmp = m_head;
     m_head = m_tail;
     m_tail = tmp;
 }
 void show()
 {
     for(int i = count; i < N; i++)
     {
         cout<<buffer[i]<<' ';
     }

 }
       
};



 int main(void)
 {
     Stack<int> a(0);
     a.in_stack(1);
     a.in_stack(2);
     a.in_stack(3);
     a.show();
     a.out_stack();
     a.show();
     a.res_stack();
     a.show();

 }
