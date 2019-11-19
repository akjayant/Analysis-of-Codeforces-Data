#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;
const int N=1e5+10, base=1e9+123;
int n,arr[N],a[N];
long long k;
bool check(int x){
    long long cur=0;
    for(int i=0;i<n;i++) a[i]=arr[i];
    int l=0;
    for(int i=n-1;i>=l;i--){
        while(a[i]-a[l]<=x&&l<i){
            l++;
        }
        if(a[i]-a[l]>x){
            cur+=(a[i]-a[l]-x);
            a[l]+=(a[i]-a[l]-x);
        }
    }
    return cur<=k;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int st=0, en=(int)1e9, mid;
    while(1){
        mid=(st+en)/2;
        if(st==mid) break;
        if(check(mid)) en=mid;
        else st=mid;
    }
    if(!check(st)) mid=en;
    cout<<mid<<'\n';
    return 0;
}
