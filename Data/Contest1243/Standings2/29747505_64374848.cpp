#include<bits/stdc++.h>
#define ll long long
#define mod (ll)1000000007
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++)  cin>>a[i];

        int ans = 0;
        sort(a,a+n);
        for(int k = 1001; k >= 0; k--){
            int c=0;
            for(int i =n-1; i >= 0; i--){
                if(a[i] >= k) c++;
                else
                    break;
            }

            if(c >= k)
                ans = max(ans, k);
        }

        cout<<ans<<"\n";
    }
    return 0;
}
