#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inarr(a,k,n) for(int i=k;i<n;i++){cin>>a[i];}
#define outarr(a,k,n) for(int i=k;i<n;i++){cout<<a[i]<<" ";}
#define inpair(a) cin>>a.first>>a.second
#define outpair(a) cout<<a.ff<<" "<<a.ss<<endl
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c
#define fastio ios_base::sync_with_stdio(false)
ll gcd(ll a,ll b){
    if(a==0)return b;
    b%=a;
    return gcd(b,a);
}
int main(){
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        ll n,p,w,d;in2(n,p);in2(w,d);
        if(w==d){
            if(p%w == 0){
                p=p/w;
                if(p<=n){
                    cout<<p<<" 0 "<<n-p<<endl;
                }
                else cout<<-1<<endl;
            }
            else cout<<-1<<endl;
            return 0;
        }
        ll g = gcd(w,d);
        ll l = w*d;l/=g;// l =lcm;
        ll a = l/w;ll b = l/d;
        ll as,bs;

        if(b<a){
            as=0;bs=-1;
            while(as<a){
                g = p-(as*w);
                if(g%d == 0){
                    bs=g/d;break;
                }
                as++;
            }
            if(bs>=0 && as+bs<=n){
                cout<<as<<" "<<bs<<" "<<n-(as+bs)<<endl;
            }
            else cout<<-1<<endl;
        }
        else{
            bs=0;as=-1;
            while(bs<b){
                g=p-(bs*d);
                if(g%w == 0){as=g/w;break;}
                bs++;
            }
            if(as>=0 && as+bs<=n){
                cout<<as<<" "<<bs<<" "<<n-(as+bs)<<endl;
            }
            else cout<<-1<<endl;
        }
    }
    return 0;
}
