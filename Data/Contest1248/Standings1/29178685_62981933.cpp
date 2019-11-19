#include<bits/stdc++.h>
#include <iterator>
using namespace std;
#define ll long long
#define M 1000000007LL
#define M1 1000000009LL
#define sz(a) (ll)a.size()
#define rep(i,a,b) for( i=a;i<b;i++)
#define sep(i,a,b) for((ll) i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define vl vector<ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pii pair<ll,ll>
#define MAXN 1000002
#define ppi pair<ll,pair<ll,ll> >
#define INF 1e7
#define mp make_pair
#define trace1(x)                cerr << #x << ": " << x << "\n";
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
bool prime[100001];
vector<int> pr;
void build(){
    memset(prime,false,sizeof(pr));
    for(ll i=2;i<=100000;i++){
        if(!prime[i]){
            pr.pb(i);
            for(ll j=i*i;j<=100000;j+=i)prime[j]=true;
        }
    }
}
int bit[100001];
void upd(int x){
    for(;x<=100000;x+=x&(-x)){
        bit[x]++;
    }
}
int sum(int x){
    int k=0;
    for(;x>0;x-=x&(-x)){
        k+=bit[x];
    }
    return k;
}
int merge(vector<int>&A,int st,int mid,int en){
    vector<int> a(en-st+1);
    int ans=0;
    int i=st,j=mid,k=0;
    while(i<=mid-1 && j<=en){
        if(A[i]<=A[j]){
            a[k++]=A[i++];
        }
        else{
            ans=(ans+mid-i)%1000000007;
            a[k++]=A[j++];
        }
    }
    while(i<=mid-1){
      //  ans=(ans)%1000000007;
        a[k++]=A[i++];
    }
    while(j<=en){
        a[k++]=A[j++];
    }
    for(i=st,k=0;i<=en;i++){
        A[i]=a[k++];
    }
    return ans;
}
int mergesort(vector<int> &A,int st,int en){
    int cnt=0;
    if(st<en){
        int mid=(st+en)/2;
        cnt+=mergesort(A,st,mid)%1000000007;
        cnt+=mergesort(A,mid+1,en)%1000000007;
        cnt+=merge(A,st,mid+1,en)%1000000007;
    }
    return cnt%1000000007;
}
void solve(){
    ll n;
    cin>>n;
    ll sum=0,ans=0;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll h=0,v=0;
    int i=0,j=n-1;
    while(i<=j){
        if(i==j){
            v+=a[i];
            i++;j--;
        }
        else{
            v+=a[j];
            h+=a[i];
            i++;
            j--;
        }
    }
    cout<<v*v+h*h;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
