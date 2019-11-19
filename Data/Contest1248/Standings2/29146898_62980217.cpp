/*DennyQi 2019*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define int long long
using namespace std;
const int N = 100010;
const int P = 998244353;
const int INF = 0x3f3f3f3f;
inline int mul(const int& a, const int& b){ return 1ll*a*b%P; }
inline int add(const int& a, const int& b){ return (a+b>=P)?a+b-P:a+b; }
inline int sub(const int& a, const int& b){ return (a-b<0)?a-b+P:a-b; }
inline int read(){
    int x(0),w(1); char c = getchar();
    while(c^'-' && (c<'0' || c>'9')) c = getchar();
    if(c=='-') w = -1, c = getchar();
    while(c>='0' && c<='9') x = (x<<3)+(x<<1)+c-'0', c = getchar(); return x*w;
}
int T,n,m,x,cnt1[2],cnt2[2];
#undef int
int main(){
#define int long long
	// freopen("file.in","r",stdin);
	T = read();
	while(T--){
		n = read();
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for(int i = 1; i <= n; ++i){
			x = read();
			cnt1[x&1]++;
		}
		m = read();
		for(int i = 1; i <= m; ++i){
			x = read();
			cnt2[x&1]++;
		}
		printf("%lld\n",cnt1[0]*cnt2[0]+cnt1[1]*cnt2[1]);
	}
	return 0;
}