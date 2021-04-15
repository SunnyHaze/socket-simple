#include <iostream>
#include <thread>
void s1(){
    std::cout << "s1 activate" << std::endl;
}
void s2(){
    for(int i = 0 ; i < 10 ; i++){
        std::cout << "s2 activate " << i << std::endl;
    }
}
int main(){
    std::thread t1(s2);
    std::thread t2(s1);
    t1.join();
    t2.join();
    return 0;
}