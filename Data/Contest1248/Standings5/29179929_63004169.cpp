#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
#define INF 0x7f7f7f7f

using namespace std;
int ax[100005]={0,2,4},bx[100005]={0,0,2},cx[100005]={0,0,2};

void chuli()
{
    for(int i=3;i<100005;i++)
    {
        ax[i]=ax[i-1]+ax[i-2];
        bx[i]=bx[i-1]+bx[i-2];
        ax[i]=ax[i]%1000000007;
        bx[i]=bx[i]%1000000007;
        cx[i]=(cx[i-1]+bx[i])%1000000007;
    }
    return;
}

int main()
{
    int n,m;
    cin>>n>>m;
    chuli();
    cout<<(ax[n]+cx[m])%1000000007<<endl;
    return 0;
}
