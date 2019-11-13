#include<bits/stdc++.h>
#define MOD 1000000007
#define INF LLONG_MAX
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound
#define vc vector
#define vll vector<long long>
#define pll pair<long long,long long> 
#define pb push_back
#define all(v) v.begin(),v.end()
#define T ll test;cin>>test; while(test--)
#define rep(i,a,n) for(ll i=a;i<(long long)n;++i)
#define repr(i,n,a) for(ll i=n;i>(long long)a;--i)
#define endl '\n'
#define MAX 100005
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    T{
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        ll cnt=0,x=-1,y=-1;bool flag=true;
        vector<int> v;
        rep(i,0,n){
            if(s[i]!=t[i]){++cnt;
                if(cnt>2){flag=false;break;}
                v.pb(i);
            }
        }
        if(flag){
            if(cnt==0){
                cout<<"Yes"<<endl;
            }else if(cnt==1){
                cout<<"No"<<endl;
            }else{
                swap(s[v[0]],t[v[1]]);
                if(s==t){
                    cout<<"Yes"<<endl;
                }else{
                    cout<<"No"<<endl;
                }
            }

        }else{
            cout<<"No"<<endl;
        }
    }




    return 0;
}

