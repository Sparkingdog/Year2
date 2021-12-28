#include <bits/stdc++.h>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX 1000001 //Max element
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, d;
    cin >> n;
    vector<int> left; // negative
    vector<int>::iterator l;
    vector<int> right; //positive
    vector<int>::iterator r;
    vector<int> arr; //ans
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        if (d <= 0)
            left.push_back(d);
        else
            right.push_back(d);
    }
    reverse(left.begin(), left.end());
    l = left.begin(), r = right.begin();
    while (l < left.end() && r < right.end())
    {
        if (abs(*l) <= (*r))
        {
            arr.push_back(*l);
            l++;
        }
        else
        {
            arr.push_back(*r);
            r++;
        }
    }
    if (r != right.end())
        arr.push_back(*r);
    if (l != left.end())
        arr.push_back(*l);
    printArray(arr);
}
