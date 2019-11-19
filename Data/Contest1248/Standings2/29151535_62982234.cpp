#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#define pi 3.14159265
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll mod = 1000000000 + 7;
const double kd = 1.41421356237;

ll n,a[100500],x,y;
int main()
{
    //freopen("ladder.in ","r",stdin);
    //freopen("ladder.out","w",stdout);
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n/2;i++)
        x += a[i];
    for(int i=n/2;i<n;i++)
        y += a[i];
    cout<<x*x+y*y;
}
