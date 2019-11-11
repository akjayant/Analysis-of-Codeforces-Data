/* LittleFall : Hello! */
#include <bits/stdc++.h>
using namespace std; using ll = long long; inline int read();
const int M = 100016, MOD = 1000000007;

ll F[M];
char save[M];
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
    #endif

	F[0] = F[1] = 1;
	for(int i=2; i<M; ++i)
		F[i] = ( F[i-1] + F[i-2] ) % MOD;
	scanf("%s",save);

	for(int i=0; save[i]; ++i)
	{
		if(save[i]=='m'||save[i]=='w')
			return !printf("0\n");
	}
	ll ans = 1;
	for(int i=0, cntu=0, cntn=0; save[i]; ++i)
	{
		if(save[i]=='u' )
		{
			++cntu;
			if(save[i+1]!='u')
			{
				ans = (ans * F[cntu])%MOD;
				cntu = 0;
			}
		}
		if(save[i]=='n' )
		{
			++cntn;
			if(save[i+1]!='n')
			{
				ans = (ans * F[cntn])%MOD;
				cntn = 0;
			}
		}
	}
	cout << ans << endl;

    return 0;
}


inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}