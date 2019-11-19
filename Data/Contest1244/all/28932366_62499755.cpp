#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream fin("AAtest.in.txt");
ll n,a[100005],k,l,r,vah,o;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    l=0;
    while(l<n-1 && a[l+1]==a[l]) l++;
    r=n-1;
    while(r>0 && a[r-1]==a[r]) r--;
    vah=a[r]-a[l];
    while(k && vah){
        if((l+1)<(n-r)){
            o=min(k/(l+1),a[l+1]-a[l]);
            k-=o*(l+1);
            if(o==0) break;
            vah-=o;
            if(o==(a[l+1]-a[l])){
                l++;
                while(l<n-1 && a[l+1]==a[l]) l++;
            }
        }
        else{
            o=min(k/(n-r),a[r]-a[r-1]);
            k-=o*(n-r);
            if(o==0) break;
            vah-=o;
            if(o==(a[r]-a[r-1])){
                r--;
                while(r>=0 && a[r-1]==a[r]) r--;
            }
        }
    }
    cout<<vah;
}
