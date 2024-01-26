#include <iostream>
#include <vector>
#include <queue>

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

struct Point{int x,y,num;};

vector<Point> expload_point;

queue<Point> adjacent_point;

vector<Point> route_data;

int dx[ADJACENT_SEARCH_NUM] = {  0, -1,  0,  1};
int dy[ADJACENT_SEARCH_NUM] = { -1,  0,  1,  0};
 

 void adjacentCheck(Point search_point)
 {
    Point check_point;
    for(int i = 0; i < ADJACENT_SEARCH_NUM; i++)
    {
        check_point.x = search_point.x + dx[i];
        check_point.y = search_point.y + dy[i];
        check_point.num = search_point.num + 1;

        if(check_point.x < 0 || check_point.x >= MAP_SIZE ||
        check_point.y < 0 || check_point.y >= MAP_SIZE)
        {
            continue;
        }

        if(map[check_point.y][check_point.x] == 2)
        {
            continue;
        }

        bool is_expload = false;
        for(int j = 0; j < expload_point.size(); j++)
        {
            if(check_point.x == expload_point[j].x && check_point.y == expload_point[j].y)
            {
                is_expload = true;
            }
        }
        if(is_expload)
        {
            continue;
        }

        adjacent_point.push(check_point);

    }
 }

Point breadthFirestSearch(Point start_point)
{
    Point search_point = start_point;

    while(1)
    {
        cout << "SearchPoint:X=" << search_point.x << ",Y=" << search_point.y << "\n";
        cout << "\n";
        expload_point.push_back(search_point);
        if(map[search_point.y][search_point.x] == 9)
        {
            break;
        }
        adjacentCheck(search_point);

        search_point = adjacent_point.front();
        adjacent_point.pop();
    }
    Point goal_point = search_point;
    return goal_point;
}

void routeCheck(Point goal_point)
{
    Point reference_point = goal_point;
    Point check_point;

    while(1)
    {
        if(reference_point.num == 0)
        {
            route_data.push_back(reference_point);
            break;
        }

        int check_num;
        bool is_adjacent = false;
        for(int i = 0; i < ADJACENT_SEARCH_NUM; i++)
        {
            check_point.x = reference_point.x + dx[i];
            check_point.y = reference_point.y + dy[i];

            for(check_num = 0; check_num < expload_point.size(); check_num++)
            {
                if(check_point.x == expload_point[check_num].x && check_point.y == expload_point[check_num].y)
                {
                    is_adjacent = true;
                    break;
                }
            }
            if(reference_point.num -1 == expload_point[check_num].num)
            {
                break;
            }

        }

        route_data.push_back(reference_point);
        reference_point = expload_point[check_num];    
    }
}

void routeDraw()
{
    for(int i = route_data.size() -1; i >= 0; i--)
    {
        cout << "X=" << route_data[i].x << ",Y=" << route_data[i].y << "\n";
    }
}

int main(void)
{
    Point start_point;
    start_point.x = 2;
    start_point.y = 3;
    start_point.num = 0;

    cout << "BreadthFirstSearchStart\n";

    Point goal_point;
    goal_point = breadthFirestSearch(start_point);

    cout << "BreadthFirstSearchEnd\n";

    cout << "routeCheckStart\n";

    routeCheck(goal_point);

    cout << "routeCheckEnd\n";

    cout << "route={\n";

    routeDraw();

    cout << "}\n";

    cout << endl;
    return 0;
}