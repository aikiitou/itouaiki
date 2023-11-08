#include<iostream>

using namespace std;

int main(void)
{
    int data[10] = {1,5,9,7,2,4,6,3,8,0};

    for(int i = 0; i < sizeof(data)/sizeof(int); i++)
    {
        cout << data[i] << endl;
    }

    return 0;
}