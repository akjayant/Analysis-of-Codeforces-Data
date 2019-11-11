#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sz() size()
#define fr first
#define sc second
#define pb push_back
#define er erase
#define in insert
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
#define mp make_pair
#define int long long
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
///#define cin fin
///#define cout fout
using namespace std;

const int mod=1e9+7;
const int mod1=998244353;
const double eps=1e-12;


double cross(pair<double,double>O,pair<double,double>A,pair<double,double>B){
    return (A.fr-O.fr)*(B.sc-O.sc)-(A.sc-O.sc)*(B.fr-O.fr);
    //pozitiv stanga
    //negativ dreapta
}

int t,n,a,b,c;
string s;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> a >> b >> c;
        cin >> s;
        int ans=0;
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R') cnt1++;
            else if(s[i]=='P') cnt2++;
            else cnt3++;
        }
        int g=min(cnt1,b)+min(cnt2,c)+min(cnt3,a);
        if(g<(n+1)/2){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
            char rs[105];
            for(int i=1;i<=n;i++) rs[i]='0';
            for(int i=0;i<s.size();i++){
                if(s[i]=='R' && b>=1) rs[i+1]='P',b--;
                else if (s[i]=='P' && c>=1) rs[i+1]='S',c--;
                else if(s[i]=='S' && a>=1) rs[i+1]='R',a--;
            }
            for(int i=0;i<s.size();i++){
                if(rs[i+1]=='0'){
                    if(a){
                        rs[i+1]='R';
                        a--;
                    }
                    else if(b){
                        rs[i+1]='P';
                        b--;
                    }
                    else {
                        rs[i+1]='S';
                        c--;
                    }
                }
            }
            for(int i=1;i<=n;i++) cout << rs[i];
            cout << '\n';
        }
    }


}

