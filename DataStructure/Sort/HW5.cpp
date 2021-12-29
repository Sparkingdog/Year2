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
            left.insert(left.begin(), d);
        else
            right.push_back(d);
    }
    //printArray(right);
    //printArray(left);
    l = left.begin(), r = right.begin();
    for (int i = 0; i < n; i++)
    {
        if (abs(*l) <= (*r) && l != left.end() && !right.empty())
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
    printArray(arr);
}
