#pragma GCC optimize ("2")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef pair<int,int> pr;
const int mxn = 1;
const int mxm = 1;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;
const double pii = 3.1415926535898;
#define mpr make_pair
int gcd(int x,int y){if(y==0) return x; else return gcd(y,x%y);}
int qpow(int a,int b){int ans=1; while(b){ if(b&1) ans=ans*a%mod; b>>=1; a=a*a%mod; } return ans;}
int lowbit(int x){return (x&(-x));}
int qmul(int a,int b){int ans=0; while(b){ if(b&1) ans=(ans+a)%mod; b>>=1; a=(a+a)%mod; } return ans; }
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string s;

signed main(void){
    int t;
    FAST_IO
    cin>>t;
    while(t--){
        int a,b,c,n;
        cin>>n;
        cin>>a>>b>>c;
        cin>>s;
        int tar = n%2?n/2+1:n/2;
        int aa=0,bb=0,cc=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R')aa++;
            else if(s[i]=='P')bb++;
            else cc++;
        }
        int ans = 0;
        ans = min(a,cc) + min(b,aa) + min(c,bb);

//        cout<<ans<<endl;
//        cout<<tar<<endl;
        if(ans>=tar){
            cout<<"YES"<<endl;
            int res1 = a-cc,res2=b-aa,res3=c-bb;
            for(int i=0;i<s.size();i++){
//                                printf("a=%lld,b=%lld,c=%lld,res1=%lld,res2=%lld,res3=%lld\n",a,b,c,res1,res2,res3);

                if(s[i]=='R'){
                    if(b>0){
                        cout<<"P";
                        b--;
//                        res2--;
                    }
                    else{
                        if(res1>0){
                            cout<<"R";
                            res1--;
                            a--;
                        }
                        else if(res3>0){
                            cout<<"S";
                            res3--;
                            c--;
                        }
                    }
                }
                else if(s[i]=='P'){
                    if(c>0){
                        cout<<"S";
                        c--;
//                        res3--;
                    }
                    else{
                        if(res1>0){
                            cout<<"R";
                            res1--;
                            a--;
                        }
                        else if(res2>0){
                            cout<<"P";
                            res2--;
                            b--;
                        }
                    }
                }
                else{
                    if(a>0){
                        cout<<"R";
                        a--;
//                        res1--;
                    }
                    else{
                        if(res2>0){
                            cout<<"P";
                            res2--;
                            b--;
                        }
                        else if(res3>0){
                            cout<<"S";
                            res3--;
                            c--;
                        }
                    }
                }
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
