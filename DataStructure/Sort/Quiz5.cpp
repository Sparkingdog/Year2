#include <bits/stdc++.h>
#include <math.h>
#define MAX 1000000000
#define MAXOBJ 500000
using namespace std;

int DistanceBetween(int x, int y)
{
    return abs(x - y);
}
int minD(int maxS, int minE, int end)
{
    int d = 0;
    d += DistanceBetween(d, maxS);    //go to max Start Posw
    d += DistanceBetween(maxS, minE); //maxS -> minE
    d += DistanceBetween(minE, end);  //minE -> end
    return d;
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
};

int main()
{
    //Object obj[MAXOBJ];
    int N, M;
    int S, E;
    //int visited[MAX] = {0};
    int minDistance;
    int maxS = 0;
    int minE = MAX;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> S >> E;
        if (S > E)
        {
            if (S > maxS)
                maxS = S;
            if (E < minE)
                minE = E;
        }
    }
    //cout << "Max Start : " << maxS << endl;
    //cout << "Min End : " << minE << endl;
    minDistance = minD(maxS, minE, M);
    cout << minDistance << endl;
}