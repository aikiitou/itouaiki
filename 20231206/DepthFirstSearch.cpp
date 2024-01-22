#include <iostream>
#include <vector>

using namespace std;

#define MAP_SIZE 8

#define ADJACENT_SEARCH_NUM 4

int map[MAP_SIZE][MAP_SIZE]
{
    {1,1,2,1,1,1,1,1},
    {1,2,2,1,2,1,2,1},
    {1,2,2,1,2,1,2,1},
    {1,1,0,1,2,1,2,1},
    {1,2,1,2,2,2,1,1},
    {1,2,1,2,2,1,1,2},
    {1,1,1,2,2,2,9,2},
    {1,2,1,1,1,2,1,2}
};
typedef struct {int x,y;}index; 


vector<index> explored_data;

vector<index> adjacent_data;

vector<index> branch_data;

vector<index> route_data;

vector<index> check_data;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int test_arr[] = {0};
void modifyArray(int* arr)
{
    for(int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }
}

int adjacentCheck(index reference_point)
{
    int adjacent_count = 0;

    for(int i = 0; i < ADJACENT_SEARCH_NUM; i++)
    {
    
        index adjacent_point;
        adjacent_point.x = reference_point.x + dx[i];
        adjacent_point.y = reference_point.y + dy[i];


        if(adjacent_point.x == -1 || adjacent_point.x >= MAP_SIZE ||
           adjacent_point.y == -1 || adjacent_point.y >= MAP_SIZE)
        {
            continue;
        }

        bool is_explored = false;
        for(int j = 0; j < explored_data.size(); j++)
        {
            if(explored_data[j].x == adjacent_point.x && explored_data[j].y == adjacent_point.y)
            {
                is_explored = true;
            }
        }

        if(is_explored)
        {
            continue;
        }

        if(map[adjacent_point.y][adjacent_point.x] == 2)
        {
            continue;
        }

        adjacent_data.push_back(adjacent_point);
        adjacent_count++;
    }

    return adjacent_count;
}

bool is_finish = false;

void depthFirstSearch(index search_index)
{    
    while(1)
    {
        route_data.push_back(search_index);

        explored_data.push_back(search_index);

        cout << "\n";
        cout << "search_index:X=" << search_index.x << ",Y=" << search_index.y << "\n";

        if(map[search_index.y][search_index.x] == 9)
        {
            cout << "Finish" << "\n";
            break;
        }

        int adjacent_count = adjacentCheck(search_index);

        if(adjacent_count == 0)
        {
            index return_point = branch_data[branch_data.size() - 1];

            branch_data.pop_back();
            while(1)
            {
                if(route_data[route_data.size() - 1].x == return_point.x && route_data[route_data.size() - 1].y == return_point.y)
                {
                    break;
                }
                route_data.pop_back();
            }

            index next_serach_point = adjacent_data.back();
            adjacent_data.pop_back();
            search_index = next_serach_point;
            continue;
        }
        else if(adjacent_count >= 2)
        {
            branch_data.push_back(search_index);
        }

        index next_serach_point;
        next_serach_point = adjacent_data[adjacent_data.size() - 1];
        adjacent_data.pop_back();
        search_index = next_serach_point;
    }
}

int main(void)
{
    index start_index;
    start_index.x = 2;
    start_index.y = 3;
    //bool is_gool = 
    depthFirstSearch(start_index);

    cout << "\n";
    for(int i = 0; i < route_data.size(); i++)
    {
        cout << "X=" << route_data[i].x << ",Y=" << route_data[i].y << "\n"; 
    }
    
    cout << endl;

    return 0;
}
