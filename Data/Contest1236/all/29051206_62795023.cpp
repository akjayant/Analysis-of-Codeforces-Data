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

int a[400][400];
int n;
int cal(int a[],int b[]) {
    int res=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(a[i]>b[j]) res++;
        }
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif

    scanf("%d",&n);
    int m=n*n;
    for(int j=1;j<=n;j++) {
        if(j%2) {
            for(int i=1;i<=n;i++) {
                a[i][j] = m--;
            }
        }else {
            for(int i=n;i;i--) {
                a[i][j] = m--;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    //for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) cout<<cal(a[i],a[j])<<endl;

	return 0;
}

