#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>

#ifdef LOCAL
#define debug(x) cout<<#x<<" "<<(x)<<endl;
#else
#define debug(x)
#endif

struct fast_io{
    fast_io(){
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        cout<<fixed<<setprecision(12);
    }
}____;

vector<ll> er;
vector<vector<ll > > graf((ll)1e5 + 10, er);
ll dp[(ll)1e5 + 10][3];
ll fin[(ll)1e5 + 10][9];
ll sost[(ll)1e5 + 10];
ll mark[(ll)1e5 + 10];
ll stoim[(ll)1e5 + 10][3];


ll dfs(ll v, queue<ll> was, ll t){
    ll sum = 0;
    ll c = was.front();
    sum += stoim[v][c];
    fin[v][t] = c;
    was.pop();
    was.push(c);
    for(ll i = 0; i < graf[v].size(); i++){
        if(!mark[graf[v][i]]){
            mark[graf[v][i]] = 1;
            sum += dfs(graf[v][i], was, t);
        }
    }
    return sum;

}

int main()
{
    ll n;
    cin>>n;
    for(ll i = 0; i < n; i++)cin>>stoim[i][0];
    for(ll i = 0; i < n; i++)cin>>stoim[i][1];
    for(ll i = 0; i < n; i++)cin>>stoim[i][2];
    for(ll i = 0; i < n - 1; i++){
        ll x, t;
        cin>>x>>t;
        x--;
        t--;
        graf[x].pb(t);
        graf[t].pb(x);
    }
    ll nach;
    for(ll i = 0; i < n; i++){
        if(graf[i].size() > 2){
            cout<<-1;
            return 0;
        }
        if(graf[i].size() == 1){
            nach = i;
        }
    }
    ll sum1[9]= {};
    for(ll i = 1; i < 9; i ++)sum1[i] = (ll)1e16;
    for(ll i = 0; i < 3; i++){
        ll second = graf[nach][0];
        ll sum = 1e16;
        for(ll j = 0; j < 3; j++){
            ll tttt = j + 3 * i;
            for(int i = 0; i < n; i++){
                mark[i] = 0;
            }
            if(i != j){
                sum = 0;
                ll q = 0;
                if(i + j == 2)q = 1;
                if(i + j == 1)q = 2;
                queue<ll> was;
                was.push(q);
                was.push(i);
                was.push(j);
                sum += stoim[nach][i];
                sum += stoim[second][j];
                fin[nach][tttt] = i;
                fin[second][tttt] = j;
                mark[second] = 1;
                mark[nach] = 1;
                for(ll rt = 0; rt < graf[second].size(); rt++)
                    if(!mark[graf[second][rt]]){
                        mark[graf[second][rt]] = 1;
                        sum += dfs(graf[second][rt], was, tttt);
                    }
            }
            sum1[tttt] = sum;
        }

    }
    ll minind = 0;
    for(ll i = 1; i < 9; i ++){
        if(sum1[minind] > sum1[i])minind = i;
    }
    cout<<sum1[minind]<<endl;
    for(ll i = 0; i < n; i++){
        cout<<fin[i][minind] + 1<<" ";
    }
    return 0;
}
