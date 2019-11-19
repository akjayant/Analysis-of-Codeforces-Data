#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
#define ll long long
const int N = 3005;


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("c.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b, c, d, k;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        bool ok = false;
        for(int i = 1; i < k; i++) {
            if(i * c >= a && (k - i) * d >= b) {
                ok = true;
                printf("%d %d\n", i, k - i);
                break;
            }
        }
        if(!ok) puts("-1");

    }
    return 0;
}

