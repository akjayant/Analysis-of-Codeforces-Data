#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define K 31

int a, b;
ll dp[K][2][2][2][2];

bool getBit(int x, int pos) { return x&(1<<pos); }

ll cnt(int pos, int sa1, int sb1, int sa2, int sb2)
{
    if(pos == -1) return 1;

    ll &res = dp[pos][sa1][sb1][sa2][sb2];
    if(res != -1) return res;

    res = 0;

    int nsa1, nsb1, nsa2, nsb2;

    if(sa1 == 0 && getBit(a, pos)) goto zeroone;
    if(sa2 == 0 && getBit(a, pos)) goto zeroone;

    nsa1 = sa1, nsa2 = sa2;
    if(getBit(b, pos)) nsb1 = nsb2 = 1;
    else nsb1 = sb1, nsb2 = sb2;

    res += cnt(pos-1, nsa1, nsb1, nsa2, nsb2);

    zeroone:

    if(sa1 == 0 && getBit(a, pos)) goto onezero;
    if(sb2 == 0 && !getBit(b, pos)) goto onezero;

    nsa1 = sa1;
    if(getBit(b, pos)) nsb1 = 1;
    else nsb1 = sb1;

    nsb2 = sb2;
    if(!getBit(a, pos)) nsa2 = 1;
    else nsa2 = sa2;

    res += cnt(pos-1, nsa1, nsb1, nsa2, nsb2);

    onezero:

    if(sa2 == 0 && getBit(a, pos)) return res;
    if(sb1 == 0 && !getBit(b, pos)) return res;

    nsa2 = sa2;
    if(getBit(b, pos)) nsb2 = 1;
    else nsb2 = sb2;

    nsb1 = sb1;
    if(!getBit(a, pos)) nsa1 = 1;
    else nsa1 = sa1;

    res += cnt(pos-1, nsa1, nsb1, nsa2, nsb2);

    return res;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &a, &b);

        memset(dp, -1, sizeof(dp));
        printf("%I64d\n", cnt(K-1, 0, 0, 0, 0));
    }

    return 0;
}
