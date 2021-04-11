/*
 * @Author: your name
 * @Date: 2021-04-11 21:50:27
 * @LastEditTime: 2021-04-11 21:58:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\exps\constructAndDestruct.cc
 */
#include <iostream>

using namespace std;
class  Base{
    public:
        Base()
        {
            cout<<"Constructing Base\n";
        }
    ~Base()
    {
        cout<<"Destructing Base\n";
    }
};

class Derived: public Base{
public:
    Derived()
    {
        cout<<"Constructing Derived\n";
    }
    ~Derived()
    {
        cout<<"Destructing Derived\n";
    }
};
int main() {
    Derived* d = new Derived();
    Base* b = d;
    delete b;
    delete d;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}