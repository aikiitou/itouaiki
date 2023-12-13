#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

const int QUEUE_SIZE = 5;
string dequeue_data;

class Queue
{
private:
    int queue_num = 0;
    int head_num = 0;
    string data[QUEUE_SIZE];

public:
    void queueprint()
    {
        cout << "queue[";
        for(int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
        {
            cout<< data[i] << ",";
        }
        cout << "]\n";
    }

    void enqueue(string new_data)
    {
        data[queue_num % QUEUE_SIZE] = new_data;
        queue_num++;
        cout << "enqueue:" << new_data << " ";
        queueprint();
    }

    string dequeue()
    {
        string return_data;
        if(head_num < QUEUE_SIZE)
        {
            return_data = data[head_num];
            data[head_num] = "";
            head_num++;
            return return_data;

        }
        else
        {
            head_num = 0;
            return_data = data[head_num];
            data[head_num] = "";
            head_num++;
            return return_data;
        }
    }

};

int main(void)
{
    Queue queue;

    queue.enqueue("A");
    queue.enqueue("B");
    queue.enqueue("C");
    queue.enqueue("D");
    queue.enqueue("E");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("F");
    queue.enqueue("G");
    queue.enqueue("H");
    queue.enqueue("I");
    queue.enqueue("J");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("K");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("L");
        dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("M");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("N");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("O");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("P");
    queue.enqueue("Q");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("R");
    queue.enqueue("S");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("T");
    queue.enqueue("U");
    queue.enqueue("V");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("W");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("X");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("Y");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    queue.enqueue("Z");
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
    dequeue_data = queue.dequeue();
    cout << "dequeue:" << dequeue_data << " ";
    queue.queueprint();
}