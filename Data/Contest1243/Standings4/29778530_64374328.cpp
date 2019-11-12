//
// Created by StupidTurtle on 2019/11/6.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1005;
int a[maxn];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i>a[i]){
                break;
            }
            ans=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}