#include <bits/stdc++.h>
#include "rectangle.h"
using namespace std;
int main()
{
    Rectangle r, s;
    Rectangle *t = &s;
    if (r.GetHeight() * r.GetWeight() > t->GetHeight() * t->GetWeight())
        cout << "r";
    else
        cout << "s";
    cout << "has the greater area" << endl;
}