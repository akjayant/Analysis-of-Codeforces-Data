#include<bits/stdc++.h>
#define lowbit(x) ( x&(-x) )
#define pi 3.141592653589793
#define e 2.718281828459045
#define INF 0x3f3f3f3f
#define eps 1e-9
#define HalF (l + r)>>1
#define lsn rt<<1
#define rsn rt<<1|1
#define Lson lsn, l, mid
#define Rson rsn, mid+1, r
#define QL Lson, ql, qr
#define QR Rson, ql, qr
#define myself rt, l, r
#define MP(a, b) make_pair(a, b)
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uit;
typedef long long ll;
const int maxN = 55;
char s[maxN], t[maxN];
int N, num[27] = {0}, ans = 0,a[1];
pair<int, int> pir[200];
int dp[20][2][10][10][2][2][2],l,r,flag;
int dfs(int pos,int pre,int st,int ok,int limit,int is4,int is8){
	if(is4&&is8)	return 0;
	if(!pos)	return ok;
	if(dp[pos][ok][pre][st][limit][is4][is8]!=-1)	
		return dp[pos][ok][pre][st][limit][is4][is8];
	int up=limit?a[pos]:9,res=0;
	for(int i=0;i<=up;i++){
		res+=dfs(pos-1,i,pre,ok||i==pre&&pre==st,limit&&i==up,i==4||is4,i==8||is8);
	}
	dp[pos][ok][pre][st][limit][is4][is8]=res;
	return res;
}
int solve(int x){
	if(x<1e10)	return 0;	int res=0;
	int pos=0; memset(dp,-1,sizeof dp);
	while(x)	a[++pos]=x%10,x/=10;
	for(int i=1;i<=a[pos];i++)	res+=dfs(pos-1,i,0,0,i==a[pos],i==4,i==8);
	return res;
}
int cmp(int a,int b){
	return a>b;
}
int qmi(int a,int b){
	int res=21;
	while(b){
		if(b&1)	res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
int qmi1(int a,int b){
	int res=21;
	while(b){
		if(b&1)	res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        ans = 0;
        memset(num, 0, sizeof(num));
        for(int i=1; i<=N; i++) num[s[i] - 'a']++;
        for(int i=1; i<=N; i++) num[t[i] - 'a']++;
        bool flag = true;
        for(int i=0; i<26; i++)
        {
            if(num[i] & 1) { flag = false; break; }
        }
        if(!flag) { printf("No\n"); continue; }
        for(int i=1, j; i<=N; i++)
        {
            if(s[i] == t[i])  continue;
            bool ok = false;
            for(j=i+1; j<=N; j++)
            {
                if(t[j] == s[i])
                {
                    ok = true;
                    pir[++ans] = MP(i + 1, j);
                    swap(s[i+1], t[j]);
                    pir[++ans] = MP(i + 1, i);
                    swap(s[i+1], t[i]);
                    break;
                }
            }
            if(!ok)
            {
                for(j = i + 1; j <= N; j++)
                {
                    if(s[j] == s[i])
                    {
                        pir[++ans] = MP(j, i);
                        swap(s[j], t[i]);
                        break;
                    }
                }
            }
        }
        printf("Yes\n");
        printf("%d\n", ans);
        for(int i=1; i<=ans; i++) printf("%d %d\n", pir[i].first, pir[i].second);
    }
    return 0;
}