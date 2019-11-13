#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<time.h>
#include<set>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

int tu[305][305];
int main()
{
    int n;
    cin>>n;
    int cur=1;
    for(int i=1;i<=n;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=n;j++)
            {
                tu[j][i]=cur++;
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                tu[j][i]=cur++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<tu[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
