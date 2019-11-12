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
char a[maxn];
char b[maxn];

int num[maxn];
int len;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        getchar();
        scanf("%s%s",a,b);
        len=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                num[len++]=i;
            }
        }
        if(len==2&&a[num[0]]==a[num[1]]&&b[num[0]]==b[num[1]]){
            printf("Yes\n");
        }else printf("No\n");
    }
    return 0;
}