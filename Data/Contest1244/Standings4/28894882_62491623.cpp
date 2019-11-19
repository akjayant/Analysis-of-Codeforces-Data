#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long k,a[N],n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("1244E.inp","r",stdin);
//    freopen("1244E.out","w",stdout);
    cin>>n>>k;
    for (long long i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long i=1;
    long long j=n;
    while(i<=j&&k>0){
        if (a[i]==a[i+1]){
            while(a[i]==a[i+1]) i++;
        }
        if (a[j]==a[j-1]){
            while(a[j]==a[j-1]) j--;
        }
        if (i>=j) break;
        if (i<n-j+1){
            long long m=a[i+1]-a[i];
            if (m*i<=k){
                k-=m*i;
                a[i]+=m;
            }
            else{
                a[i]+=k/i;
                k=0;
            }
        }
        else {
            long long d=n-j+1;
            long long m=a[j]-a[j-1];
            if (d*m<=k){
                k-=m*d;
                a[j]-=m;
            }
            else {
                a[j]-=k/d;
                k=0;
            }
        }
    }
    cout<<a[j]-a[i];
}
