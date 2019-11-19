

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1000000007;
ll a[200005];
int main()
{
    a[1]=2,a[2]=4;
    for(int i=3;i<=200000;i++)
    {
        a[i]=a[i-1]+a[i-2];
        a[i]%=mod;
    }
    for(int i=0;i<10;i++)
    {
        int s;
        s++;
    }
    int n,m;
    scanf("%d%d",&n,&m);
    ll ans=a[n]-2+a[m];
    ans%=mod;
    printf("%lld\n",ans);
    return 0;
}
/*
001100
001101
001001
001010
001011


100100
100101
100110
101001
101010
101011
101100
101101

110011
110010
110101
110110
110100

010101
010011
010010
010100
011001
011010
011011
010110

26

0010
0011
0100
0101
0110

1001
1010
1011
1100
1101

*/

