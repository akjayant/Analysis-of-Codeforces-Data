#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define vll vector<long long>
#define pll pair<long long, long long>
#define pt complex<double>
#define ft first
#define sc second
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b,c,aa,bb,cc,w1;
        string s;
        cin>>n;
        cin>>a>>b>>c;
        cin>>s;
        aa = bb = cc = 0;
        vector<char> v;
        for(int i = 0; i<s.length();i++){
            if(s[i]=='S')aa++;
            if(s[i]=='R')bb++;
            if(s[i]=='P')cc++;
            v.pb('A');
        }
        int res = min(a, aa) + min(b, bb) + min(c, cc);
        if(2 * res >= n){
            cout<<"YES\n";
            for(int i = 0; i<s.length();i++){
                if(s[i]=='S'){
                    if(a > 0){
                        v[i] = 'R';
                        a--;
                    }
                }
                if(s[i]=='R'){
                    if(b > 0){
                        v[i] = 'P';
                        b--;
                    }
                }
                if(s[i]=='P'){
                    if(c > 0){
                        v[i] = 'S';
                        c--;
                    }
                }
            }
            for(int i = 0; i<s.length();i++){
                if(v[i] == 'A'){
                    if(a>0){
                        v[i] = 'R';
                        a--;
                        continue;
                    }
                    if(b>0){
                        v[i] = 'P';
                        b--;
                        continue;
                    }
                    if(c>0){
                        v[i] = 'S';
                        c--;
                        continue;
                    }
                }
            }
            string res;
            for(int i=0;i<s.length();i++){
                res+=v[i];
            }
            cout<<res<<endl;
        }
        else{
            cout<<"NO\n";
        }
    }
}
