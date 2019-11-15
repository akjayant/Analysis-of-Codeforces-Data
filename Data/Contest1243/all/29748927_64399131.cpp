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
        bool flag=true;
        int a1[26]={0},a2[26]={0},a[26]={0};
        rep(i,0,n){
            a[s[i]-'a']++;a[t[i]-'a']++;
        }
        rep(i,0,26){
            if(a[i]&1)flag=false;
        }
        /*bool visited[n];
        rep(i,0,n)visited[i]=false;*/
        vector<pair<int,int> >res;
        rep(i,0,n){
            if(s[i]!=t[i]){ll id=-1;
                rep(j,i+1,n){
                    if(s[j]==s[i]){id=j;break;}
                }
                if(id!=-1){
                    res.pb({id+1,i+1});
                    //cout<<id+1<<" "<<i+1<<endl;
                    swap(s[id],t[i]);

                    continue;
                }else{
                    rep(j,i+1,n){
                        if(t[j]==s[i]){id=j;break;}
                    }
                }
                if(id!=-1){
                    res.pb({id+1,id+1});
                    res.pb({id+1,i+1});
                    //cout<<id+1<<" "<<id+1<<endl;
                    swap(s[id],t[id]);
                    //cout<<id+1<<" "<<i+1<<endl;
                    swap(s[id],t[i]);
                }else{
                    flag=false;break;
                }
            }
            if(flag==false)break;
        }
        if(flag&&s==t){
            cout<<"Yes"<<endl;
            cout<<res.size()<<endl;
            for(auto elem:res){
                cout<<elem.F<<" "<<elem.S<<endl;
            }
        }else{
            cout<<"No"<<endl;
        }
    }




    return 0;
}

