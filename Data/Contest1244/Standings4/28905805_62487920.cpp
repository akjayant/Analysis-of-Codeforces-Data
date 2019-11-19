#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a,b,c,d,k,pn,pc,n,i,j,x,y;
    cin>>n;

    ll cp[4][n+1];

    for(i=1;i<=3;i++){
        for(j=1;j<=n;j++)   cin>>cp[i][j];
    }

    vector<vector<ll> > edges(n+1);

    for(i=0;i<n-1;i++){
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    ll head=1;

    for(i=1;i<=n;i++){
        if(edges[i].size()>2)   break;
        if(edges[i].size()==1)  head=i;
    }

    if(i<=n){
        cout<<-1;
        return 0;
    }

    vector<ll> order(n+1);
    order[1]=head;
    ll prev=head;
    order[2]=edges[prev][0];

    for(i=2;i<n;i++){
        ll cur = order[i];
        for(j=0;j<edges[cur].size();j++){
            k = edges[cur][j];
            if(k!=prev)  order[i+1]=k;
        }
        prev=cur;
    }

    //for(i=1;i<=n;i++)   cout<<order[i]<<" ";
    //cout<<endl;

    ll ans[3];
    ll mincost = 1e15;

    for(ll c=1;c<=3;c++){
        for(ll d=1;d<=3;d++){
            if(c==d)    continue;
            ll t;
            if(c+d==4)  t=2;
            else if(c+d==3)  t=3;
            else t=1;

            ll arr[] = {c,d,t};

            ll cost=0;
            for(i=1;i<=n;i++){
                ll col = arr[(i-1)%3];
                cost += cp[col][order[i]];
            }

            if(cost<mincost){
                mincost=cost;
                for(i=0;i<3;i++)    ans[i]=arr[i];
            }
        }
    }

    cout<<mincost<<endl;
    ll paint[n+1];

    for(i=1;i<=n;i++){
        ll col = ans[(i-1)%3];
        //cout<<order[i]<<"H";
        paint[order[i]]=col;
    }

    for(i=1;i<=n;i++)   cout<<paint[i]<<" ";
}

