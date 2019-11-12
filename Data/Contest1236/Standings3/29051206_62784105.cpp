//scnucjh
#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
    int T; scanf("%d",&T);
    while(T--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int ans=0;
        int t1 = min(b,c/2);
        ans += t1*3;
        b -= t1;
        int t2 = min(a,b/2);
        ans += t2*3;
        printf("%d\n",ans);
    }
	return 0;
}

