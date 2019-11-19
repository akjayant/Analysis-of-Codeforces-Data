#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
int n,m;
int sq=350;
int f[400];
bool ok[100100];
vector<int> v[100100];
vector<int> y[360];
vector<pair<int,int> > g;
void take(int cr){
    queue<int> q;
    q.push(cr);
    ok[cr]=1;

    while(q.size()){
        int mk=q.front();
        q.pop();
        int c=0;
        for(int i=0;i<350;i++)
        {
            if(i*sq>n)
                break;
           //cout<<i<<endl;
            for(int k=0;k<y[i].size();k++){
                int j=y[i][k];

                if(i*sq+j>n)
                    break;
                if(ok[i*350+j])continue;
                while(c<v[mk].size()&&v[mk][c]<i*sq+j)c++;
                int p=-1;
                if(c<v[mk].size())
                    p=v[mk][c];
                if(p!=i*sq+j){

                    ok[i*sq+j]=1;
                    q.push(i*sq+j);
                    y[i].erase(y[i].begin()+k);
                    k--;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<=350;i++)
    {
        for(int j=1;j<=350;j++)y[i].pb(j);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int sum=0;
    for(int i=1;i<=n;i++){sort(v[i].begin(),v[i].end());g.pb(mp(v[i].size(),i));}
    sort(g.begin(),g.end());
    for(int i=0;i<n;i++)
    {   int h=g[i].ss;
        if(!ok[h]){
            take(h);
            sum++;
        }
    }
    cout<<sum-1;
    return 0;
    }
