#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

char sn[110000];
#define ll long long
const int md = 1e9+7;
ll dp[110000];


int main()
{
    gets(sn+1);
    int i,j,k;
    sn[0] = 0;
    int l = strlen(sn+1);
    dp[0] = 1;
    bool bl = 1;
    for(i = 1;i<=l;i++)
    {
        if(sn[i] == 'm'||sn[i] == 'w')
        {
            bl = 0;
            break;
        }
        else
        {
            if((sn[i] == 'u'&&sn[i-1] == 'u')||(sn[i] == 'n'&&sn[i-1] == 'n')) dp[i] = (dp[i-2]+dp[i-1])%md;
            else dp[i] = dp[i-1];
        }
    }
    if(bl)
    {
        cout<<dp[l]<<endl;

    }else cout<<0<<endl;
    return 0;

}
