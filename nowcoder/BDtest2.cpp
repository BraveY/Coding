/*
 * @Author: your name
 * @Date: 2021-04-11 20:10:26
 * @LastEditTime: 2021-04-11 21:16:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\nowcoder\BDtest2.cpp
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

class BDtest2
{
private:
    /* data */
    vector<queue<int>> data;
    // unordered_map<int, int> addres;
    vector<int> addres;
public:
    BDtest2(int n);
    ~BDtest2();
    void close(int a, int b) {        
        while (!data[a].empty())
        {
            data[b].push(data[a].front());
            addres[data[a].front()] = b;
            data[a].pop();
        }        
    }

    int query(int a, int b) {
        if (addres[a] != addres[b]) {
            return -1;
        }
        int addr = addres[a];
        queue<int> tmp = data[addr];
        int cnt = -1;
        int first = 0;
        int second = -1;
        while (!tmp.empty())
        {
            if (!first) {
                if ( tmp.front() == a) {
                    cnt = 0;
                    second = b;
                    first = 1;
                }
                if ( tmp.front() == b)                    {
                    cnt = 0;
                    second = a;
                    first = 1;
                }
                tmp.pop();
            }else {
                if (tmp.front() == second) {
                    return cnt;
                }
                tmp.pop();
                ++cnt;
            }

        }        
        return 0;
    }
};

BDtest2::BDtest2(int n)
{
    data = vector<queue<int>> (n+1);
    addres = vector<int> (n+1);
    for(int i = 1; i <= n; ++i) {
        data[i].push(i);
        addres[i] = i;
    }
}

BDtest2::~BDtest2()
{
    data = {};
    addres = {};
}



int main(){
    int n, m;
    cin >> n >> m;
    BDtest2 test =  BDtest2(n);
    while(m--){
        char command;
        int a, b;
        cin >> command >> a >> b;
        if (command == 'C') {
            test.close(a, b);
        }else if (command == 'Q')  {
            cout << test.query(a, b) << endl;
        }else {
            return -1;
        }
    }
    return 0;
}