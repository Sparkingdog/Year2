#include <bits/stdc++.h>
using namespace std;
#define INF 99999

int TunnelGraph[20][20] = {999};
int BridgeGraph[20][20] = {INF};
int dist[20];
bool visited[20] = {false};
int st, ex;
int n;

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                TunnelGraph[i][j] = 0;
                BridgeGraph[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        dist[st] = 0;
    }
}

// get the nearest val adj
int getNearest()
{
    int minValue = INF;
    int minNode = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] < minValue)
        {
            minValue = dist[i];
            minNode = i;
        }
    }
    return minNode;
}

// find all Shortest path from starting point
void dijkstra()
{
    for (int i = 0; i < n; i++)
    {
        int nearest = getNearest();
        visited[nearest] = true;
        for (int adj = 0; adj < n; adj++)
        {
            // update
            if (TunnelGraph[nearest][adj] != INF && dist[adj] > dist[nearest] + TunnelGraph[nearest][adj])
            {
                dist[adj] = dist[nearest] + TunnelGraph[nearest][adj];
                cout << "New dist = " << adj << ":" << dist[adj] << endl;
            }
        }
    }
    cout << dist[ex] << endl;
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << TunnelGraph[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int T;                // Tunnel
    int B;                // Bridge #will break
    int u, v, w;          // from,to,length
    cin >> n >> st >> ex; // n*n matrix,Start,Exit
    cin >> T;
    while (T--) // update Tunnel
    {
        cin >> u >> v >> w;
        TunnelGraph[u][v] = w;
        TunnelGraph[v][u] = w;
    }
    cin >> B;
    while (B--) // update Bridge
    {
        cin >> u >> v >> w;
        BridgeGraph[u][v] = w;
        BridgeGraph[v][u] = w;
    }
    init();
    display();
    // dijkstra();
}
/*
4 1 2
4
1 2 6
1 3 3
2 4 4
3 4 5
3
2 4 1
1 3 2
1 4 1
*/
