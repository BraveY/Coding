/*
 * @Author: your name
 * @Date: 2021-04-12 22:29:11
 * @LastEditTime: 2021-04-12 22:37:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\exps\errorsTest.cc
 */
#include <iostream>

using namespace std;

void SegFault() {
    // int* p = 0;
    int* p = nullptr; // 都可以，0是未映射的地址
    *p =17;
}

void BusError() {
    union {
        char a[10];
        int i;
    }u;
    int *p = (int *) &(u.a[1]);
    *p = 17;
    
}

int main() {
    // SegFault();
    BusError();
    return 0;
}

