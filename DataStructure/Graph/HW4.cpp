#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define MAX 2000
int tunnelGraph[MAX][MAX];
int bridgeGraph[MAX][MAX];
int dist[MAX];
bool visited[MAX] = {false};
int st, ex;
int n;
int c = 0;
int shortestpath = INF;
void display()
{
    cout << "tunnel :" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << tunnelGraph[i][j] << " ";
        }
        cout << endl;
    }
    cout << "bridge :" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << bridgeGraph[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Shortest distance from " << st << "->" << ex << endl;
    cout << dist[ex] << endl;
}
void init()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            if (i == j)
            {
                tunnelGraph[i][j] = 0;
                bridgeGraph[i][j] = 0;
            }
            else
            {
                tunnelGraph[i][j] = INF;
                bridgeGraph[i][j] = INF;
            }
        }
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INF;
        dist[st] = 0;
    }
}
int getNearest()
{
    int min = INF;
    int minNode = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minNode = i;
        }
    }
    return minNode;
}
void dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        int nearest = getNearest();
        visited[nearest] = true;
        for (int adj = 1; adj <= n; adj++)
        {
            if (tunnelGraph[nearest][adj] != INF && dist[adj] > dist[nearest] + tunnelGraph[nearest][adj])
            {
                dist[adj] = dist[nearest] + tunnelGraph[nearest][adj];
            }
        }
    }
    if (shortestpath > dist[ex])
        shortestpath = dist[ex];
}

int main()
{
    int T;
    int B;
    int u, v, w;
    cin >> n >> st >> ex;
    cin >> T;
    init();
    while (T--)
    {
        cin >> u >> v >> w;
        tunnelGraph[u][v] = w;
        tunnelGraph[v][u] = w;
    }

    cin >> B;
    while (B--)
    {
        cin >> u >> v >> w;
        bridgeGraph[u][v] = w;
        bridgeGraph[v][u] = w;
        if (tunnelGraph[u][v] == INF || bridgeGraph[u][v] < tunnelGraph[u][v])
        {
            int temp = tunnelGraph[u][v];
            tunnelGraph[u][v] = w;
            tunnelGraph[v][u] = w;
            dijkstra();
            //cout << ++c << "st attempt:"; //debug use
            //cout << shortestpath << endl;
            tunnelGraph[u][v] = temp;
            tunnelGraph[v][u] = temp;
        }
    }
    dijkstra();
    cout << shortestpath << endl;
}
