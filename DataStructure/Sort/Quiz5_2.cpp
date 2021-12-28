#include <bits/stdc++.h>
#include <math.h>
#define MAX 1000000000
#define MAXOBJ 5000
using namespace std;

int DistanceBetween(int x, int y)
{
    return abs(x - y);
}

class Object
{
private:
    int start;
    int end;

public:
    Object(int s, int e)
    {
        start = s;
        end = e;
    }
    Object()
    {
        start = 0;
        end = 0;
    }
    void Display()
    {
        cout << "(" << start << "," << end << ")" << endl;
    }
};
int minD(Object *obj, int end)
{
    int d = 0;

    return d;
}
int main()
{
    Object obj[MAXOBJ];
    int N, M;
    int S, E;
    //int visited[MAX] = {0};
    int minDistance;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> S >> E;
        obj[i] = Object(S, E);
    }
    for (int i = 0; i < N; i++)
    {
        obj[i].Display();
    }
    cout << minDistance << endl;
}