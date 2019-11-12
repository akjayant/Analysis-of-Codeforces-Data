#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int a[N];
int main() {
    int k,n;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        sort(a,a+n);
        int ans=0;
        for(int i=n-1;i>=0;--i)
        {
            if(a[i]>=ans+1)
                ++ans;
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
