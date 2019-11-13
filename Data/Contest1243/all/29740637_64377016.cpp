#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;

const int maxn=1e5+10;
int a[maxn];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int x=0;
        for(int i=0;i<n;i++){
            int xx=a[i];
            int yy=n-i;
            //printf("%d %d\n",xx,yy);
            x=max(x,min(xx,yy));
        }
        printf("%d\n",x);
    }
    return 0;
}