#include<bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define X first
#define Y second
using namespace std;
const int N=2004;
int n,c[N],k[N],lab[N],f[N][5],vc=1000000000,T[N],up[N][3],cL[N],ans=0;
ii b[N];
vector<int> res1;
vector<ii> res2;
vector<ii> a[N];
vector<ii> vt;

int dis(int x,int y) {
    if(x==y) return c[x];
    return (k[x]+k[y])*(abs(b[x].X-b[y].X)+abs(b[x].Y-b[y].Y));
}

int Findset(int u) {
    return (lab[u]<0?u:lab[u]=Findset(lab[u]));
}

void Union(int x,int y) {
    int w=dis(x,y);
    int r=Findset(x);
    int t=Findset(y);
    if(cL[r]==1&&cL[t]==1) return;
    if(x==y) {
        if(cL[r]==0) {
            cL[r]=1;
            ans+=w;
            res1.push_back(x);
        }
        return;
    }
    if(r!=t) {
        a[x].push_back(ii(w,y));
        a[y].push_back(ii(w,x));
        if(cL[r]==0&&cL[t]==0) {
            if(lab[r]>lab[t]) swap(r,t);
            lab[r]+=lab[t];
            lab[t]=r;
            ans+=w;
            res2.push_back(ii(x,y));
        }
        else {
            if(cL[r]==0) swap(r,t);
            lab[r]+=lab[t];
            lab[t]=r;
            ans+=w;
            res2.push_back(ii(x,y));
        }
    }
}

bool cmp(ii x,ii y) {
    int t1=dis(x.X,x.Y);
    int t2=dis(y.X,y.Y);
    return (t1<t2);
}

void build() {
    memset(lab,255,sizeof(lab));
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            vt.push_back(ii(i,j));
        }
    }
    sort(vt.begin(),vt.end(),cmp);
    for(int i=0;i<vt.size();i++) {
        Union(vt[i].X,vt[i].Y);
    }
    cout<<ans<<endl;
    cout<<res1.size()<<endl;
    for(int i=0;i<res1.size();i++) {
        cout<<res1[i]<<" ";
    }
    if(res1.size()>0)
    cout<<endl;
    cout<<res2.size()<<endl;
    for(int i=0;i<res2.size();i++) {
        cout<<res2[i].X<<" "<<res2[i].Y<<endl;
    }

}

void dfs(int x,int p) {
    bool ok=false;
    for(int i=0;i<a[x].size();i++) {
        int w=a[x][i].X,y=a[x][i].Y;
        if(y!=p) {
            dfs(y,x);
            ok=true;
        }
    }
    if(!ok) {
        f[x][0]=0,f[x][1]=c[x];
        f[x][2]=vc;
    }
    else {
        int res=vc*100,t1;
        for(int i=0;i<a[x].size();i++) {
            int w=a[x][i].X,y=a[x][i].Y;
            if(y!=p) {
                int keep=w+f[y][2];
                keep=min(keep,f[y][1]+w);
                if(keep<res) {
                    t1=y,res=keep;
                }
            }
        }
        f[x][2]=res;
        for(int i=0;i<a[x].size();i++) {
            int w=a[x][i].X,y=a[x][i].Y;
            if(y!=p&&y!=t1) {
                f[x][2]+=min(f[x][2],f[x][1]+w);
            }
        }
        f[x][1]=c[x];
        for(int i=0;i<a[x].size();i++) {
            int w=a[x][i].X,y=a[x][i].Y;
            if(y!=p) {
                f[x][1]+=min(f[y][2],f[y][1]);
            }
        }
    }
}

/*void dfs2(int x,int p) {
    for(int i=0;i<a[x].size();i++) {
        int w=a[x][i].X,y=a[x][i].Y;
        if(y!=p) {
            up[y][0]=min(up[x][1],up[x][0]+w);
            up[y][1]=min(up[x][1],up[x][0])+c[y];
            for(int j=0;j<a[x].size();j++) {
                int cost=a[x][j].X,z=a[x][j].Y;
                if(z!=p&&z!=y) {
                    res+=min(f[z][2]+,f[z][1])+cost+w;
                }
            }
        }
    }
}
*/
main() {
    //freopen("1245D.INP","r",stdin);
    //freopen("1245D.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>b[i].X>>b[i].Y;
    }
    for(int i=1;i<=n;i++) {
        cin>>c[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>k[i];
    }
    build();
    //dfs(1,0);
    //cout<<f[2][2]<<" "<<f[2][1]<<endl;
    //cout<<min(f[1][2],f[1][1]);
}
