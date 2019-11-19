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
    ULL n, i, a[100004], x = 0, y = 0;
    cin >>n;
    for(i = 0;i < n;i++)cin >>a[i];
    sort(a,a+n);
    for(i = 0;i < n/2;i++)x += a[i];
    for(i = n/2;i < n;i++)y += a[i];
    cout<<x*x+y*y<<endl;
    return 0;
}
