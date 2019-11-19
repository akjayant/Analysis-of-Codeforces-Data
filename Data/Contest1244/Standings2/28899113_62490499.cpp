#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define int long long

using namespace std;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int l=1,r=n-2;
    int maxx=a[n-1],minn=a[0];
    int nl=1,nr=1;
    while(k>0 && maxx>minn){
        int res=0;
        if(nl<nr){
            res=1;
            int ress=0;
            if((a[l]-minn)*nl<=k){
                ress=1;
                k-=(a[l]-minn)*nl;
                minn=a[l];
                nl++;
                l++;
            }
            if(ress==0){
                minn+=k/nl;
                k=0;
                cout<<maxx-minn;
                return 0;
            }
        }
        if(res==0){
            int ress=0;
            if((maxx-a[r])*nr<=k){
                ress=1;
                k-=(maxx-a[r])*nr;
                maxx=a[r];
                nr++;
                r--;
            }
            if(ress==0){
                maxx-=k/nr;
                k=0;
                cout<<maxx-minn;
                return 0;
            }
        }
   //     cout<<minn<<" "<<maxx<<'\t'<<l<<" "<<r<<endl;
    }
    long long sefr=0;
    cout<<max(maxx-minn,sefr);
    return 0;
}
