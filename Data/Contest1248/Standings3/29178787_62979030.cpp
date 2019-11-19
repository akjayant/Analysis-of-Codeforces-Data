#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <ctime>
#include <map>
#define ll long long
using namespace std;
int main(){
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        int x,p1,q1,p2,q2;
        p1=q1=p2=q2=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&x),p1+=(x&1),q1+=!(x&1);
        scanf("%d",&m);
        for(int i=0;i<m;i++) scanf("%d",&x),p2+=(x&1),q2+=!(x&1);
        ll ans=1LL*p1*p2+1LL*q2*q1;
        printf("%I64d\n",ans);
    }
	
	return 0;
}
