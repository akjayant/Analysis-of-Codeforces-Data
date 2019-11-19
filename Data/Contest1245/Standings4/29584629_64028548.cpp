#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define mod 1000000007

#define ll long long
#define pb push_back
#define vec vector
#define vi vector<long long>
#define vl vector<ll>
#define pi pair<long long,long long>
#define pl pair<ll ,ll>
#define X first
#define Y second
#define vp vector<pi>
vector<long long> sets(2001);
long long find(long long n){
    if(sets[n]==n)return n;
    sets[n]=find(sets[n]);
    return sets[n];
}

void unin(long long x,long long y){
    long long a=find(x),b=find(y);
    if(a>b)sets[a]=b;
    else sets[b]=a;
}
int main(){
    for(long long i=0;i<2001;i++){
        sets[i]=i;
    }
    long long n;
    vector<pair<long long,pi>>e;
    cin>>n;
    vector<long long> c(n),k(n);
    vp x(n);
    for(long long i=0;i<n;i++)cin>>x[i].X>>x[i].Y;
    for(long long i=0;i<n;i++)cin>>c[i];
    for(long long i=0;i<n;i++)cin>>k[i];
    for(long long i=0;i<n;i++){
        
        pi t(i+1,0);
        e.push_back(make_pair(c[i],t));
        for(long long j=0;j<n;j++){
            if(i==j)continue;
            t.X=i+1;
            t.Y=j+1;
            long long temp=(abs(x[i].X-x[j].X)+abs(x[i].Y-x[j].Y))*(k[i]+k[j]);
            e.pb(make_pair(temp,t));
        }

    }
    sort(e.begin(),e.end());
    long long cost=0;
    vp ans;
    long long p=0;
    vi s;
    for(auto ed:e){
        if(find(ed.Y.X)!=find(ed.Y.Y)){
            unin(ed.Y.Y,ed.Y.X);
            cost+=ed.X;
            if(ed.Y.Y==0){
                p++;
                s.pb(ed.Y.X);
            }
            ans.pb(ed.Y);
        }
    }
    cout<<cost<<endl;
    cout<<p<<endl;
    for(long long t:s)cout<<t<<' ';
    cout<<endl;
    cout<<n-p<<endl;
    for(auto t:ans){
        if(t.Y!=0){
            cout<<t.X<<' '<<t.Y<<endl;
        }
    }

}