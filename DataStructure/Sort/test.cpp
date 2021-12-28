#include <bits/stdc++.h>
#include <vector>
#include <math.h>
#define MAX 1000001 //Max element
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    vector<int> a;
    for (int i = 1; i <= 5; i++)
    {
        a.push_back(i);
    }
    vector<int>::iterator ptr = a.begin();
    a.insert(a.begin(), 9);
    a.insert(ptr + 1, 8);
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); ++it)
    {
        cout << *it;
    }
}