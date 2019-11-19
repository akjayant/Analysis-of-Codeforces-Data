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
int n,a[N],x,y;
#undef int
int main(){
#define int long long
	// freopen("file.in","r",stdin);
	n = read();
	for(int i = 1; i <= n; ++i){
		a[i] = read();
	}
	sort(a+1,a+n+1);
	for(int i = 1; i <= (n>>1); ++i){
        x += a[i];
    }
    for(int i = (n>>1)+1; i <= n; ++i){
        y += a[i];
    }
	printf("%lld\n",x*x+y*y);
	return 0;
}