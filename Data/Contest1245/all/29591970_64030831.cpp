#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;
ll INF = (ll)1e10;





int main(){
    ll i,j,ans=0,n,v,to,t=0,s=0;
    cin>>n;
    n++;
    vector < vector<ll> > g(n,vector<ll>(n,INF));
    vector<bool> used (n,0);
    vector<ll> min_e (n, INF), sel_e (n, -1);
    vector <ll> x(n-1);
    vector <ll> y(n-1);
    vector <ll> c(n-1);
    vector <ll> k(n-1);
    for (i=0; i<n-1; i++)
        cin>>x[i]>>y[i];
    for (i=0; i<n-1; i++)
        cin>>c[i];
    for (i=0; i<n-1; i++)
        cin>>k[i];
    for (j=0; j<n-1; j++){
        g[n-1][j]=c[j];
        g[j][n-1]=c[j];
    };
    for (i=0; i<n-1; i++)
        for (j=0; j<n-1; j++){
            g[i][j]=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            g[j][i]=g[i][j];
        }
    vector <ll> Ans1(n);
    vector <pair<ll,ll> > Ans2(n);

    min_e[0] = 0;
    for (i=0; i<n; ++i){
        v = -1;
        for ( j=0; j<n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
			v = j;
        used[v] = 1;
        if (sel_e[v] != -1){
            ans=ans+min_e[v];
            if (v==n-1) {Ans1[t]=sel_e[v]+1; t++; }
            if (sel_e[v]==n-1) {Ans1[t]=v+1;t++;}
            //cout << v << " " << sel_e[v] << endl;
            if (v!=n-1 && sel_e[v]!=n-1){
                Ans2[s].first=v+1;
                Ans2[s].second=sel_e[v]+1;
                s++;
            };
        }
        for (to=0; to<n; ++to)
		if (g[v][to] < min_e[to]) {
			min_e[to] = g[v][to];
			sel_e[to] = v;
		}
    }
    cout<<ans<<endl;
    cout<<t<<endl;
    for (i=0; i<t; i++)
        cout<<Ans1[i]<<" ";
    cout<<endl;
    cout<<s<<endl;
    for (i=0; i<s; i++)
        cout<<Ans2[i].first<<" "<<Ans2[i].second<<endl;
    return 0;
};
