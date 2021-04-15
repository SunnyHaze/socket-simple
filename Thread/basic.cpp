#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
mutex m;
void proc(int &a)
{
    m.lock();
    // printf("我是子线程,传入参数为%d\n",a);
    // printf("子线程中显示子线程id为%d",this_thread::get_id());
    cout << "我是子线程，传入参数为" << a << endl;
    cout << "子线程中显示子线程id为" << this_thread::get_id() <<endl;
    m.unlock();
}
int main()
{
    cout << "我是主线程\n";
    int a = 9;
    thread th2(proc,std::ref(a));   //第一个参数为函数名，第二个参数为该函数的第一个参数，如果该函数接收多个参数就依次写在后面。此时线程开始执行。
    m.lock();
    cout << "主线程中显示子线程id为" << th2.get_id() << endl;
    m.unlock();
    th2.join();  //此时主线程被阻塞直至子线程执行结束。
    cout << "子线程执行结束" << endl;
    return 0;
}