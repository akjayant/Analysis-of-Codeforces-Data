#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <stack>
#include <climits>
#include <ctime>
#include <iomanip>

using namespace std;

typedef long long LL;
typedef double db;
#define lowbit(x) ((x)&(-x))
#define gcd(a,b) __gcd(a,b)
#define sqre(x) (x)*(x)
#define mem(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define lson l,m,rt<<1
#define rson m+1,r,(rt<<1)|1
#define PII pair<int,int>
const int MaxN = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const LL mod = 1000000007;
int go[8][2] = {{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1},{-2,-1},{-2,1}};


void OPEN(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
inline int read(){
	int x=0,k=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') k=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return k*x;
}
long long qpow(long long a ,long long b){
	long long res = 1LL;
	while(b){
		if(b & 1)res = (res * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return res % mod;
}
long long arr[MaxN];
int main(){
	int n ; scanf("%d",&n);
	for(int i = 1; i <= n ; i++)scanf("%lld",&arr[i]);
	sort(arr + 1 , arr + 1 + n);
	long long a = 0 , b = 0;
	for(int i = 1; i <= n / 2 ; i++)a += arr[i];
	for(int i = n / 2 + 1; i <=n ; i++)b += arr[i];
	a *= a;
	b *= b;
	printf("%lld\n",a + b);
	return 0;
}