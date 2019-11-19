#pragma GCC optimize("O3")
#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define INF (ll)1e18


ll N,C[2020],K[2020];
pll XY[2020];
pll cost[2020];
bool mk[2020];
ll i,j,k;
vector<ll> ans1;
vector<pll> ans2;

ll d(pll xy1, pll xy2){
    return abs(xy2.first - xy1.first) + abs(xy2.second - xy1.second);
} 
int main()
{
    scanf("%lld", &N);
    fornum(i,0,N){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        XY[i] = {x, y};
    }
    fornum(i,0,N){
        scanf("%lld", &C[i]);
    }
    fornum(i,0,N){
        scanf("%lld", &K[i]);
    }
    priority_queue<pair<ll,pll>> q;
    fornum(i,0,N){
        q.push({-C[i], {i + 1,0}});
    }
    ll flg = 0;
    ll a = 0;
    while(q.size()){
        auto qa = q.top();
        q.pop();
        ll c = qa.first;
        auto b = qa.second.first;
        if(mk[b]){
            continue;
        }
        flg ++;
        a -= c;
        mk[b] = true;
        if(qa.second.second==0){
            ans1.push_back(b);
        }else{
            ans2.push_back(qa.second);
        }
        if(flg==N){
            break;
        }
        fornum(i,0,N){
            if(!mk[i+1]){
                q.push({-(K[i] + K[b-1]) * d(XY[i], XY[b-1]), {i + 1,b}});
            }
        }
    }

    printf("%lld\n%d\n", a,ans1.size());
    fornum(i,0,ans1.size()){
        printf("%lld " ,ans1[i]);
    }
    printf("\n%lld\n", ans2.size());
    fornum(i,0,ans2.size()){
        printf("%lld %lld\n", ans2[i].first, ans2[i].second);
    }


    return 0;
}