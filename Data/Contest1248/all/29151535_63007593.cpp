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


int main()
{
    //freopen("ladder.in ","r",stdin);
    //freopen("ladder.out","w",stdout);
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,a[505],sum = 0,o[505],z[505],an = 0,l=0,r=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char qq;
        cin>>qq;
        if(qq == '(')
            a[i] = 1;
        else a[i] = -1;
        sum += a[i];
    }
    if(sum != 0)
    {
        cout<<0<<'\n'<<1<<' '<<1;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sumo = 0,sumz = 0,oo = 0,zz = 0;
            for(int k=0;k<n;k++)
            {
                int pos1 = k, pos2 = n-k-1;
                int ch1 = a[pos1], ch2 = a[pos2];
                if(pos1 == i)
                    ch1 = a[j];
                if(pos1 == j)
                    ch1 = a[i];
                if(pos2 == i)
                    ch2 = a[j];
                if(pos2 == j)
                    ch2 = a[i];
                sumo += ch1;
                sumz += ch2;
                if(sumo < 0)
                    sumo = 0;
                if(sumz > 0)
                    sumz = 0;
                if(ch1 == 1)
                    o[pos1] = 0;
                else
                {
                    if(sumo == 0)
                        o[pos1] = 1;
                    else o[pos1] = 0;
                }
                if(ch2 == -1)
                    z[pos2] = 0;
                else
                {
                    if(sumz == 0)
                        z[pos2] = 1;
                    else z[pos2] = 0;
                }
            }
            int kk = 0;
            for(int i=0;i<n-1;i++)
            {
                if(o[i] == 1 && z[i+1] == 1)
                    kk++;
            }
            if(o[n-1] == 1)
                kk++;
            if(kk > an)
            {
                an = kk;
                l = i;
                r = j;
            }
        }
    }
    cout<<an<<'\n'<<l+1<<' '<<r+1;
}

