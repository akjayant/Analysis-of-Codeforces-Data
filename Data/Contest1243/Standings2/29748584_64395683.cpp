#include <bits/stdc++.h>
using namespace std;

int f[100];

int find(int x) {
    if(x==f[x])
        return x;
    return f[x] = find(f[x]);
}

int main() {
    long long n;
    scanf("%lld", &n);
//    for(int i=3; i<=n; i++) {
//        for(int j=1; j<=i; j++)
//            f[j] = j;
//        int cnt = i;
//        for(int j=3; j<=i; j++) {
//            for(int k=j-2; k>=1; k--) {
//                if(i%(j-k)==0) {
//                    int p = find(j);
//                    int q = find(k);
//                    if(p!=q) {
//                        cnt--;
//                        f[p] = q;
//                    }
//                }
//            }
//        }
//        printf("i=%d cnt=%d\n", i, cnt);
//    }
    if(n==1) {
        printf("1\n");
        return 0;
    }
    int k = (int)sqrt(n);
    int cnt = 0;
    int tmp = -1;
    for(int i=2; i<=k; i++) {
        if(n%i==0) {
            cnt++;
            while(n%i==0)
                n /= i;
            tmp = i;
        }
    }
    if(cnt==0)
        printf("%lld\n", n);
    else if(cnt==1 && n==1)
        printf("%d\n", tmp);
    else
        printf("1\n");
    return 0;
}
