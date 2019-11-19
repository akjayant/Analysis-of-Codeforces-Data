#include <iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
#include<stack>

using namespace std;
#define ULL long long

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        ULL x, y, x1 = 0, x2 = 0, y1 = 0, y2 = 0, z;
        int i;
        cin >>x;
        for(i = 0;i < x;i++)
        {
            cin >>z;
            if(z%2)x1++;
            else x2++;
        }
        cin >>y;
        for(i = 0;i < y;i++)
        {
            cin >>z;
            if(z % 2)y1++;
            else y2++;
        }
        cout<<x1*y1+x2*y2<<endl;
    }
    return 0;
}
