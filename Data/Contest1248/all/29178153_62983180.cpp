#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
int a[100007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+1+n);
    long long x=0,y=0;
    for(int i=1;i<=n/2;++i)
        x+=a[i];
    for(int i=n/2+1;i<=n;++i)
        y+=a[i];
    long long ans=x*x+y*y;
    cout<<ans;
    return 0;
}
