#include <stdio.h>
#include <random>
#include <time.h>

int main(void)
{
    int data[] = {0,1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(data) / sizeof(data[0]);

    srand(time(NULL));
    // dataのシャッフル
    for(int i = size - 1; i > 0; i--)
    {
        int random = rand() % (i + 1);

        int temp = data[i];
        data[i] = data[random];
        data[random] = temp;
    }

    int result = -1;
    int target = 5;

    for(int i = 0; i < size; ++i)
    {
        if(data[i] == target)
        {
            result = i;
            break;
        }
    }

    printf("target_index = %d\n",result);

    return 0;

}