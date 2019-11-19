#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream fin("AAtest.in.txt");
ll n,ma[100005][3][3],jad[100005][3],x,y,l,mi,vas[100005],eel[100005];
vector<ll> v[100005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
    cin>>n;
    for(int j=0; j<3; j++) for(int i=1; i<=n; i++) cin>>jad[i][j];
    for(int i=1; i<n; i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        if(v[x].size()>2 || v[y].size()>2){
            cout<<-1;
            return 0;
        }
    }
    for(int i=1; i<=n; i++) if(v[i].size()==1){
        l=i;
        break;
    }
    x=l;
    y=-1;
    while(l!=-1){
        eel[l]=y;
        if(l==x){
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++) if(i!=j)
                    ma[l][i][j]=jad[l][i];
            y=l;
            l=v[l][0];
        }
        else{
            for(int i=0; i<3; i++) for(int j=0; j<3; j++) if(i!=j){
                ma[l][i][j]=jad[l][i]+ma[y][j][3-i-j];
            }
            if(v[l].size()==1) break;
            for(int i=0; i<2; i++) if(v[l][i]!=y){
                y=l;
                l=v[l][i];
                break;
            }
        }
    }
    mi=ma[l][0][1];
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) if(i!=j) mi=min(mi,ma[l][i][j]);
    cout<<mi<<"\n";
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) if(i!=j) if(ma[l][i][j]==mi){
        x=i; y=j;
        while(l!=-1){
            vas[l]=x;
            l=eel[l];
            swap(x,y);
            y=3-x-y;
        }
        for(int o=1; o<=n; o++) cout<<vas[o]+1<<" ";
        return 0;
    }
}
