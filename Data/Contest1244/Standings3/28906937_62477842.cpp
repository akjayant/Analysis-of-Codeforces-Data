#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define dd double
#define oo 1001007000
#define ff float
#define ooo 1000000100000000000
#define iii pair<int,int>
#define vii vector<ll>
#define viii vector<iii>
#define sss pair<str,str>
#define str string
#define sii set<ll>
#define siii set<iii>
#define sz size
#define st size_t
#define r0 return 0
#define pb push_back
#define quickcin cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

const char E='\n';
const int N=200151;

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int n;
    ll k;
    cin >> n >> k;
    ll a[N]={0};
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n;

    while (k>0 && l<r){
        while (a[l]==a[l+1] && l<r)l++;
        while (a[r]==a[r-1] && l<r)r--;
        if(l>=r)break;
        bool q=0;
        if (l<=(n-r+1)){
            if ((a[l+1]-a[l])*l<=k){
                k-=(a[l+1]-a[l])*l;
                l++;
                q=1;
            }else if (k/l>=1){
                a[l]+=k/(l);
                k-=k/l*l;
                q=1;
            }


        }else {
            if ((a[r]-a[r-1])*(n-r+1)<=k){
                k-=(a[r]-a[r-1])*(n-r+1);
                r--;
                q=1;
            }
            else if (k/(n-r+1)>=1){
                a[r]-=k/(n-r+1);
                k-=k/(n-r+1)*(n-r+1);
                q=1;
            }
        }
        if (!q)break;
    }
    cout << a[r]-a[l] << E;

    //cout << l << " " << r << E;
//cout << a[l] << " " << a[r] << E;
    r0;
}
