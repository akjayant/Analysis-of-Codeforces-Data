#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
template<class Read>void in(Read &x){
    x=0;
    int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        f|=(ch=='-');
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    x=f?-x:x;
    return;
}
const int M=1000000007;
int n,m;
ll ksm(ll x,int y){
    ll s=1;
    while(y){
        if(y&1)s=(s*x)%M;
        x=(x*x)%M;
        y>>=1;
    }
    return s;
}
int main(){
	in(n);in(m);
    cout<<ksm(ksm(2,m)-1,n)%M<<endl;
	return 0;
}
