#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
vector<int>edge[100007];
int num[100007];
int a[100007][7];
int anss[100007];
int ppos[100007];
long long mx[100007][7][7],mn[100007][7][7];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    long long ans=2e18;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=3;++j){
            for(int k=1;k<=3;++k){
                mx[i][j][k]=2e18+7;
            }
        }
    }
    for(int i=1;i<=3;++i){
        for(int j=1;j<=n;++j){
            cin>>a[j][i];
        }
    }
    int x,y;
    int flag=0;
    for(int i=1;i<n;++i){
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for(int i=1;i<=n;++i){
        if(edge[i].size()>2){
            cout<<-1;
            return 0;
        }
        if(edge[i].size()==1){
            flag=i;
        }
    }
    for(int i=1;i<n;++i){
        num[i]=flag;
        if(edge[flag][0]!=num[i-1]){
            flag=edge[flag][0];
        }
        else{
            flag=edge[flag][1];
        }
    }
    num[n]=flag;
    for(int i=1;i<=3;++i){
        for(int j=1;j<=3;++j){
            mx[2][i][j]=a[num[2]][j]+a[num[1]][i];
        }
    }
    for(int i=3;i<=n;++i){
        for(int j=1;j<=3;++j){
            for(int k=1;k<=3;++k){
                for(int l=1;l<=3;++l){
                    if(l!=j&&k!=j){
                        if(mx[i][k][l]>a[num[i]][l]+mx[i-1][j][k]){
                            mn[i][k][l]=j;
                            mx[i][k][l]=a[num[i]][l]+mx[i-1][j][k];
                        }
                    }
                }
            }
        }
    }
    int pos1=0,pos2=0;
    for(int i=1;i<=3;++i){
        for(int j=1;j<=3;++j){
            if(ans>mx[n][i][j]&&j!=i){
                pos1=i;
                pos2=j;
                ans=mx[n][i][j];
            }
        }
    }
    for(int i=n;i>=3;--i){
        ppos[i]=pos2;
        int tamp=mn[i][pos1][pos2];
        pos2=pos1;
        pos1=tamp;
    }
    ppos[1]=pos1;
    ppos[2]=pos2;
    for(int i=1;i<=n;++i){
        anss[num[i]]=ppos[i];
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;++i){
        cout<<anss[i]<<" ";
    }
    return 0;
}
