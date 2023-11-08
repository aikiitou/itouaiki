#include<iostream>

using namespace std;

int main(void)
{
    for(int i = 1; i <= 100; i++)
    {
        if(i % 3 == 0 && i % 5 == 0)
        {
            cout << i << "fizz buzz" << endl; 
        }
        else if(i % 3 == 0)
        {
            cout << i << "fizz" << endl; 
        }
        else if(i % 5 == 0)
        {
            cout << i << "buzz" << endl; 
        }
    }

    return 0;
}