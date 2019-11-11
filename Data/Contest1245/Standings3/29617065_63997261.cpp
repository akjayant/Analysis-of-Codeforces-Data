#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        if(gcd(a,b)==1)puts("Finite\n");
        else puts("Infinite\n");
    }
    return 0;
}
