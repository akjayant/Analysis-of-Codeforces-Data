#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
 
#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define deb4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define deb5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define deb6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
 
#define MAXN 100010
#define MOD 1000000007
using namespace std;
 
int main(){
    
    ll k;
    cin>>k;
    while(k--){
        
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        bool f=0;
        ll a[26]={0};
        vector<ll> g[26];
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
            a[t[i]-'a']++;
            g[t[i]-'a'].pb(i);
        }
        for(int i=0;i<26;i++){
            if(a[i]%2==1){
                f=1;
                break;
            }
        }
        if(f==1){
            cout<<"No"<<endl;
            continue;
        }
 
        vector< pair <ll,ll> > v;
        for(int i=0;i<n-1;i++){
            if(s[i]==t[i]){
                continue;
            }
            
            ll ind= -1;
            for(int j=i+1;j<n;j++){
                if(s[j]==s[i]){
                    ind=j;
                    break;
                }
            }
            
            char temp;
            if(ind != -1){
                temp = s[ind];
                s[ind] = t[i];
                t[i] = temp;
                v.pb({ind,i});
                continue;
            }
            
            for(int j=i;j<n;j++){
                if(s[i]==t[j]){
                    ind=j;
                    break;
                }
            }
 
            temp = s[i+1];
            s[i+1]=t[ind];
            t[ind]=temp;
 
            temp = s[i+1];
            s[i+1] = t[i];
            t[i]=temp;
 
            v.pb({i+1,ind});
            v.pb({i+1,i});
 
        }
 
        cout<<"Yes"<<endl;
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i].ff+1<<" "<<v[i].ss+1<<endl;
        }
    }
    return 0;
}