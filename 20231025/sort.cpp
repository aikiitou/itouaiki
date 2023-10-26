#include<iostream>

using namespace std;

// 値の入れ替え用の関数
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int array1[10] = {1,9,3,2,5,7,4,6,8,0};
    int array2[10] = {};
    int array1size = sizeof(array1) / sizeof(array1[0]); // array1のsize
    int array2size = sizeof(array2) / sizeof(array2[0]); // array2のsize
   
    int index = 0;
    int sortedIndex = 0;

    // 乱数が入っている配列の表示
    for(int index = 0; index < array1size; index++)
    {
        cout << array1[index] << endl;       
    }
    
    cout << endl;

    array2[0] = array1[0]; // array2の先頭にarray1の先頭を格納

    // array1[1]からチェックしていく
    for(int index = 1; index < array1size; index++)
    {
        for(int sortedIndex = 0; sortedIndex < array2size; sortedIndex++)
        {
            if(array2[sortedIndex] >= array1[index]) 
            {
                swap(&array2[sortedIndex], &array1[index]);
            }
            else
            {
                array2[index] = array1[index];
            }
        }
    }

    // 整列済みの配列を表示
    for(int i = 0; i < array2size; i++)
    {
        cout << array2[i] << endl;
    }

    return 0;
}