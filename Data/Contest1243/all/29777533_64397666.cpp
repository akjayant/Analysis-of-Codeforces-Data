#include <bits/stdc++.h>
#include <iostream>
 
#define ll long long int
 
#define pb push_back
#define mp make_pair
#define F first
#define S second
 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()
 
using namespace std;
///////////////////////////////////////////////////////
 
#define mod 1000000007

ll gcd(ll a, ll b){
    if(a>b)
        return gcd(b,a);
    if(a==0)
        return b;
    if(a==1)
        return 1;
    return gcd(b%a,a);

}

ll ans = 0;

void bfs(vector<int> a[], bool visited[], map<ll,ll> gcdstore, int x, ll beauty[]){
    // cout<<x<<":";
    // if(gcdstore.size()!=0){
        map<ll,ll>fornext;
        for(auto i:gcdstore){
            // cout<<i.first<<":"<<i.second<<endl;
            ll temp = gcd(i.first,beauty[x]);
            ans=(ans+(temp*i.second)%mod )%mod;
            fornext[temp]+=i.second;
        }
    // }    
    fornext[beauty[x]]++;
    // for(int i=0;i<gcdstore.size())
    // cout<<endl;
    ans = (ans + beauty[x])%mod;
    for(int i=0;i<a[x].size();i++){
        if(!visited[a[x][i]]){
            visited[a[x][i]]=true;
            bfs(a,visited,fornext,a[x][i],beauty);
        }
    }
}

bool csort(const pair<int,int> &a, const pair<int,int> &b){
    return (a.first > b.first);
}

ll modpow(ll m, ll x){
    if(x==0)
        return 1LL;
    if(x%2==0){
        ll temp = modpow(m,x/2);
        return (temp*temp)%mod;
    }else{
        ll temp = modpow(m,x/2);
        return ((temp*temp)%mod * m)%mod;
    }
}

void solve(int a, ll till){
    cout<<"\n",DEBUG(a);DEBUG(till);
    ll ans2=0;
    for(ll i=0;i<=till;i+=a){
        ll temp = i,ans=0;
        while(temp>0){
            ans=ans*10 + temp%10;
            temp/=10;
        }
        if( (ans%a)==0)
            ans2=(ans2+1);
    }
    cout<<ans2;
}

vector<vector<int> >a(500002);
bool visited[500002]={false};
map<ll,ll> qans;
vector<vector<int> >query(500002);//query at time t present or not
vector<map<int,ll> >adding(500002);//adding at time t value k

void traverse(int x, int level){
    // DEBUG(x);
    //add values of adding[k] to adding[0] 
    if(x!=1){
        for(auto i:adding[x])
            adding[1][i.F-level]+=i.S;
    }

    map<int,ll,greater<ll> > tempmap;
    ll temp=0;
    bool isleaf=false;

    // int qsize = query[x].size();
    // int filling_query=0;
    if(a[x].size()==0 || visited[a[x][0]] ){//leaf
        // cout<<"isleaf\n";
        isleaf=true;
        for(auto i:adding[1]){
            temp+=i.S;
            tempmap[i.F]=temp;
            // while(filling_query<qsize && query[x][filling_query]){
            //     qans[query[x][filling_query]]=temp;
            // }
        }
    }

    // if(isleaf)
    //     for(auto i:tempmap)
    //         cout<<i.F<<":"<<i.S<<" ";
    // else   
    //     for(auto i:adding[1])
    //         cout<<i.F<<":"<<i.S<<" ";
    // cout<<endl;     
        

    if(isleaf){
        // int i=0;
        // auto iter = tempmap.begin();
        for(int i=0;i<query[x].size();i++){
            map<int,ll,greater<ll> >::iterator it = tempmap.lower_bound(query[x][i]-level);
            if(it==tempmap.end())
                continue;
            else
                qans[query[x][i]]=tempmap.lower_bound(query[x][i]-level)->second;
        }
        
        // while(i<query[x].size() && iter!=tempmap.end()){
        //     if(iter->first + level <= query[x][i]){
        //         qans[query[x][i]] = iter->second;
        //         iter++;
        //     }else{
        //         i++;
        //         if(i<query[x].size())
        //             qans[query[x][i]] = qans[query[x][i-1]];
        //     }
                
        // }
    }else{
        for(int i=0;i<query[x].size();i++)//answer queries for this node
                qans[query[x][i]]=adding[1][query[x][i]-level];
    }

    for(int i=0;i<a[x].size();i++){
        if(!visited[a[x][i]]){
            visited[a[x][i]]=true;
            traverse(a[x][i],level+1);
        }
    }
    
    //remove values from adding[0];
    if(x!=1){
        for(auto i:adding[x])
            adding[1][i.F-level]-=i.S;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);    
    
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<pair<int,int> >ans;

        int count[26]={0};

        FOR(i,0,n-1){
            count[s[i]-'a']++;
            count[t[i]-'a']++;
        }

        int flag=0;
        FOR(i,0,25){
            if(count[i]%2){
                // DEBUG(i);
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<"NO\n";
            continue;
        }else{
            cout<<"YES\n";

            FOR(i,0,n-1){
                flag=0;
                if(s[i]==t[i])
                    continue;
                FOR(j,i+1,n-1){
                    if(s[i]==s[j]){
                        flag=1;
                        ans.pb(mp(j,i));
                        s[j] = t[i];
                        break;
                    }
                }
                if(flag)
                    continue;

                FOR(j,i+1,n-1){
                    if(s[i]==t[j]){
                        ans.pb(mp(i+1,j));
                        ans.pb(mp(i+1,i));
                        t[j] = s[i+1];
                        s[i+1]=t[i];
                        break;            
                    }
                }
            }

            cout<<ans.size()<<endl;
            FOR(i,0,ans.size()-1)
                cout<<ans[i].F+1<<" "<<ans[i].S+1<<"\n";

        }

    }
    
    return 0;
}