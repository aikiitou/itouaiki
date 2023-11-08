#include<iostream>

using namespace std;

int main(void)
{
    int data[10] = {1,5,9,7,2,4,6,3,8,0}; // 10個の乱数が入った配列

    // 0から配列の長さ分繰り返すループ
    for(int i = 0; i < sizeof(data)/sizeof(int); i++)
    {
        cout << data[i] << endl; // 配列のi番目を表示
    }

    return 0;
}