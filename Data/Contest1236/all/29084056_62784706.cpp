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
int n,x,y,c;
int main(){
	in(n);
    while(n--){
        int ans=0;
        in(x);in(y);in(c);
        int sum=min(c/2,y);
        y-=sum;
        c-=sum*2;
        ans+=sum*3;
        sum=min(y/2,x);
        x-=sum;
        y-=sum*2;
        ans+=sum*3;
        printf("%d\n",ans);
    }
	return 0;
}
