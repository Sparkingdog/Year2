#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define INF 99999
#define MAX 501
int n, m;
int a, b;
double p;
int r;
int s, e;
double graph[MAX][MAX];
double probability[MAX];
bool visited[MAX] = {false};
void init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                graph[i][j] = 1;
            }
            else
            {
                graph[i][j] = INF;
            }
        }
    for (int i = 0; i < n; i++)
    {
        probability[i] = INF;
    }
}
int getNearest()
{
    int min = INF;
    int minNode = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && probability[i] < min)
        {
            min = probability[i];
            minNode = i;
        }
    }
    return minNode;
}
double dijkstra(int s, int e)
{
    if (s == e)
        return 1;
    for (int i = 0; i < n; i++)
    {
        int nearest = getNearest();
        visited[nearest] = true;
        for (int adj = 0; adj < n; adj++)
        {
            if (graph[nearest][adj] != INF && probability[adj] > probability[nearest] * graph[nearest][adj])
            {
                probability[adj] = probability[nearest] * graph[nearest][adj];
            }
        }
    }
    return probability[e];
}
void display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    cin >> n;
    cin >> m;
    cin >> r;
    init();
    while (m--)
    {
        cin >> a >> b >> p;
        graph[a][b] = -p;
        graph[b][a] = -p;
    }
    display();
    while (r--)
    {
        cin >> s >> e;
        probability[s] = 1;
        double ans = dijkstra(s, e);
        cout << fixed << setprecision(5) << ans << endl;
    }
}
