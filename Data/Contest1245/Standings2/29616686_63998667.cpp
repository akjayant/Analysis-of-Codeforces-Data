#include <bits/stdc++.h>
#define copy(x,y) memcpy(x,y,sizeof x)
#define fill(x,y) memset(x,y,sizeof x)
// #define int long long
using namespace std;
template<class t> inline void read(t &x){
    x=0;char c=getchar();
    bool f=0;
    while(c<'0'||c>'9') f|=c=='-',c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;
}
template<class t> inline void write(t x){
    if(x<0) putchar('-'),write(-x);
    else{
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
template<class t> inline void Write(t x,char c){
	write(x);putchar(c);
}

void doit(){
    int x,y;
    read(x);read(y);
    if(__gcd(x,y)==1) puts("Finite");
    else puts("Infinite");
}
signed main(){
    int t;
    read(t);
    while(t--) doit();
}
