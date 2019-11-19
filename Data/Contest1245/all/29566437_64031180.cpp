#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> tri;
int n;
int ck[2000];
ll x[2000],y[2000],c[2000],k[2000];
vector <tri> V;
int p[2000];
vector <pii> AA; 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0 ; i<n ; i++)p[i]=i;
    for(int i=0 ; i<n ; i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0 ; i<n ; i++){
        cin>>c[i];
    }
    for(int i=0 ; i<n ; i++){
        cin>>k[i];
    }
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            V.push_back(make_pair((abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]),make_pair(i,j)));
        }
        V.push_back(make_pair(c[i],make_pair(i,i)));
    }
    sort(V.begin(),V.end());
    ll ans = 0;
    for(int i=0 ; i<V.size() ; i++){
        int a = V[i].second.first;
        int b = V[i].second.second;
        if(ck[a]==1&&ck[b]==1)continue;
        if(a!=b){
            if(p[a]==p[b]){
                continue;
            }
            else{
                AA.push_back(make_pair(a,b));
                ans+=V[i].first;
                int cc = max(ck[a],ck[b]);
                int pp = p[b];
                for(int j=0 ; j<n ; j++){
                    if(p[j]==pp){
                        p[j]=p[a];
                    }
                    if(p[j]==p[a]||p[j]==pp){
                        ck[j]=cc;
                    }
                }
            }
        }
        else{
            ans+=V[i].first;
            AA.push_back(make_pair(a,-1));
            for(int j=0 ; j<n ; j++){
                if(p[j]==p[a]){
                    ck[j]=1;
                }
            }
        }
    }
    cout<<ans<<"\n";
    int cnt = 0;
    for(int i=0 ; i<AA.size() ; i++){
        if(AA[i].second==-1){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    for(int i=0 ;i<AA.size() ; i++){
        if(AA[i].second==-1){
            cout<<AA[i].first+1<<" ";
        }
    }
    cout<<"\n";
    cout<<AA.size()-cnt<<"\n";
    for(int i=0 ; i<AA.size() ; i++){
        if(AA[i].second!=-1){
            cout<<AA[i].first+1<<" "<<AA[i].second+1<<"\n";
        }
    }

}