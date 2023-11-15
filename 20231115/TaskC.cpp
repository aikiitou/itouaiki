#include <stdio.h>
#include <random>
#include <time.h>

int main(void)
{
    const int RANDOM_MAX = 100;
    const int RANDOM_MIN = 0;
    int data[100];
    int size = sizeof(data) / sizeof(data[0]);

    srand(time(NULL));
    
    // 0~100までの乱数が入った配列を作成
    for(int i = 0; i < size; ++i)
    {
        data[i] = (rand() % (RANDOM_MAX - RANDOM_MIN +1)) + RANDOM_MIN;
        printf("%d\n",data[i]);
    }

    
    // 作成した配列をソートする
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

    int target = 50;
    int result = -1;
    int left = 0;
    int right = size -1;

    while(left < right)
    {
        int mid = (left + right) / 2;
        if(data[mid] == target)
        {
            result = mid;
            break;
        }
        else 
        {
            if(data[mid] < target)
            {
                left = mid +1;
            }
            else{
                right = mid;
            }
        }
    }

    if(result >= 0)
    {
        printf("target_index = %d\n", result);
    }
    else
    {
        printf("target = none\n");
    }

    return 0;

}