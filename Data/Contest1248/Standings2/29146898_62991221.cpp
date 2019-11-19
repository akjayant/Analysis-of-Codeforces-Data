/*DennyQi 2019*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 100010;
const int P = 1e9+7;
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
int n,m,lim,f[N],s[N];
int main(){
	// freopen("file.in","r",stdin);
	n = read(), m = read();
	lim = max(n,m)+5;
	f[1] = 2, f[2] = 2;
	for(int i = 3; i <= lim; ++i){
		f[i] = add(f[i-1],f[i-2]);
	}
	s[1] = 2;
	for(int i = 2; i <= lim; ++i){
		s[i] = add(s[i-1],f[i]);
	}
	// printf("%d %d\n",f[n+1],s[m-1]);
	printf("%d\n",add(f[n+1],s[m-1]));
	return 0;
}