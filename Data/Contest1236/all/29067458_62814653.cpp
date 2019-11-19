#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<algorithm>
//#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define POP pop_back()
#define LL long long
#define POP pop_back()
#define endl '\n'
#define ls x<<1
#define rs x<<1|1
#define m(x) a[x].l+a[x].r>>1
#define PII pair<int,int>
#define FI first
#define SE second
#define VI vector<int>
#define QI queue<int>
#define SI stack<int>
#define debug cout<<"debug"<<endl;
#define PLL pair<LL,LL>
#define PDD pair<double,double>
#define ULL unsigned long long
#define fo(i,a,b) for (int i=a;i<=b;++i)
#define fd(i,a,b) for (int i=a;i>=b;--i)
#define mem(x,a) memset(x,a,sizeof(x));
const int N=2e5+9,mod=1e9+7,INF=0x3f3f3f3f;
int n,m,k;
vector<int>a[N],b[N];
int cmx,cmn,dmx,dmn;
int x,y;
int main(){
    cin>>n>>m>>k;
    cmx=m,cmn=1,dmx=n,dmn=2;
    for(int i=1;i<=k;i++){
        scanf("%d%d",&x,&y);
        a[x].PB(y);
        b[y].PB(x);
    }
    for(int i=1;i<=n;i++){
    a[i].PB(0),
    a[i].PB(m+1);
    sort(a[i].begin(),a[i].end());
    }

    for(int i=1;i<=m;i++){
     b[i].PB(0),
    b[i].PB(n+1);
    sort(b[i].begin(),b[i].end());
    }

    if(k==0){
        //cout<<"Yes"<<endl;
        //return 0;
    }
    int to=0;
    LL ans=1;
    x=1,y=1;
    LL tot=1ll*n*m;
    while(ans+k<tot){
        //cout<<x<<' '<<y<<endl;
        if(to==0){
            //cout<<amn[x]<<' '<<to<<' '<<cmx<<endl;
            int t=*upper_bound(a[x].begin(),a[x].end(),y);
            cmx=min(cmx,t-1);
            if(cmx-y<=0&&(x!=1||y!=1)){
                break;
            }
            ans+=cmx-y;
            y=cmx;
            cmx--;
        }
        else if(to==1){
            //cout<<bmn[y]<<' '<<to<<' '<<dmx<<endl;

            int t=*upper_bound(b[y].begin(),b[y].end(),x);
            dmx=min(dmx,t-1);
            if(dmx-x<=0){
                break;
            }
            ans+=dmx-x;
            x=dmx;
            dmx--;
        }
        else if(to==2){
            int t=*(upper_bound(a[x].begin(),a[x].end(),y)-1);
                cmn=max(cmn,t+1);
            if(y-cmn<=0){
                break;
            }
            ans+=y-cmn;
            y=cmn++;
        }
        else if(to==3){
            //cout<<bmx[y]<<' '<<to<<' '<<dmn<<endl;
            int t=*(upper_bound(b[y].begin(),b[y].end(),x)-1);
            dmn=max(dmn,t+1);
            if(x-dmn<=0){
                break;
            }
            ans+=x-dmn;
            x=dmn++;
        }
        //cout<<"debug "<<to<<' '<<ans<<endl;
        to=(to+1)%4;
    }
    //cout<<ans<<' '<<ans+k<<endl;
    if(ans+k==tot){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}
