#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<thread>
#include <ctime>
using namespace std;
void Getsum(vector<int>::iterator first, vector<int>::iterator last,int &result){
    result = accumulate(first,last,0);
}
int main(){
    clock_t t1,t2,t3;;
    vector<int> largeArrays;
    for(int i = 0 ; i < 100000000; i++){
        if(i%2 == 0)
            largeArrays.push_back(i);
        else
            largeArrays.push_back(-1 * i);
    }
    int n;
    cin >>n;
    int result[n];
    t1 = clock();
    int start = 0,finish = 100000000 / n, d = 100000000/n;
    thread *temp[n];
    for(int i = 0 ; i < n ; i++){
        temp[i] = new thread(Getsum,largeArrays.begin() + start,largeArrays.begin()+ finish,ref(result[i]));
    }
    for(int i = 0 ; i < n ; i++){
        temp[i]->join();
    }
    int ressum = 0;
    for(auto i : result){
        ressum += i;
    }
    t2 = clock();
    cout << "sum is" << ressum << endl;
    cout << "time1 : " << 1.0*(t2-t1) / CLK_TCK << endl;
    t2 = clock();
    ressum =accumulate(largeArrays.begin(),largeArrays.end(),0);
    t3 = clock();
    cout << "sum2 is" << ressum << endl;
    cout << "time2 :" << 1.0 * (t3-t2) /CLK_TCK << endl; 
    for(int i = 0 ; i < n ;i++){
        delete temp[i];
    }
}