#include <stdio.h>
#include <random>
#include <time.h>

int main(void)
{
    int data[100];
    int size = sizeof(data) / sizeof(data[0]);

    srand(time(NULL));

    //100個の乱数を配列にいれる
    for(int i = 0; i < size; i++)
    {
        data[i] = rand();
    }

    for(int i = 0; i < size; ++i)
    {
        for(int j = size; j >= i + 1; --j)
        {
            int valueA = data[i];
            int valueB = data[j];

            if(valueA > valueB)
            {
                int max = valueA;
                int min = valueB;

                data[i] = min;
                data[j] = max;
            }
        }
    }

    for(int i = 0; i < size; ++i)
    {
        printf("%d\n",data[i]);
    }

    return 0;
}
