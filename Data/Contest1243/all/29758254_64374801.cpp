#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int a[1005];

int main()
{
    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) scanf("%d", &a[i]);

        sort(a,a+n,greater<int>());
        int ans=0;
        for(int i=0; i<n; i++) {
            int x=a[i];
            int r=i, l=i;
            for(int j=i+1; j<n; j++) {
                if(a[j]<a[i]) break;
                r=j;
            }
            for(int j=i-1; j>=0; j--) {
                if(a[j]<a[i]) break;
                l=j;
            }

            int tot=r-l+1;
            int now=min(a[i],tot);
            ans=max(ans,now);
        }
        cout << ans << endl;
    }
}
