#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int t;

int main(){
    scanf("%d", &t);
    while (t--)
    {
        ll ev =0 , odd =0 ;
        int n;
        int x;
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &x);
            ev += !(x&1);
            odd += (x&1);
        }
        ll ans = 0;
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &x);
            if (x&1)
                ans += odd ;
            else ans += ev;
        }
        printf("%lld\n", ans);
    }

	return 0;
}
