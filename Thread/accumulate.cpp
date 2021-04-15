#include <iostream>
#include <vector>
#include <string>
#include<numeric>
#include <algorithm>
using namespace std;
struct Grade{
    string name;
    int grade;
};
int main()  
{  
    Grade subject[3] = {  
        { "English", 80 },  
        { "Biology", 70 },  
        { "History", 90 }  
    };  
  
    int sum = accumulate(subject, subject + 3, 0, [](int a, Grade b){return a + b.grade; });  
    cout << sum << endl;  
  
    system("pause");  
    return 0;  
}  
 