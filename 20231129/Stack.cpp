#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

const int STACK_SIZE = 5;
string pop_data;

class Stack
{
private:
    int stack_num = 0;
    string data[STACK_SIZE];

public:
    void stackprint()
    {
        cout << "stack[";
        for(int i = 0; i < stack_num; i++)
        {
            cout << " " << data[i];
        }
        cout << "]\n";
    }

    void push(string new_data)
    {
        if(stack_num < STACK_SIZE)
        {
            data[stack_num] = new_data;
            stack_num++;
            cout << "push:" << new_data << " ";
        }
        stackprint();
    }

    string pop()
    {
        string return_data;
        if(stack_num > 0)
        {
            stack_num--;
            return_data = data[stack_num];
            data[stack_num] = "";
            return(return_data);
        }
    }
};



int main(void)
{
    Stack stack;
    stack.push("A");
    stack.push("B");
    stack.push("C");
    stack.push("D");
    stack.push("E");
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    stack.push("F");
    stack.push("G");
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    stack.push("H");
    stack.push("I");
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    stack.push("J");
    stack.push("K");
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    stack.push("L");
    stack.push("M");
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    stack.push("N");
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    stack.push("O");
    stack.push("P");
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    stack.push("Q");
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    stack.push("R");
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    stack.push("S");
    stack.push("T");
    stack.push("U");
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    stack.push("V");
    stack.push("W");
    stack.push("X");
    stack.push("Y");
    stack.push("Z");
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();
    pop_data = stack.pop();
    cout << "pop:" <<pop_data << " ";
    stack.stackprint();

    cout << endl;
    return 0;
}