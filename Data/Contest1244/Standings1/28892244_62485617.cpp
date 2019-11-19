#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF=1e18+1;
const int N=1e5+1;
int n,col[N][3],a,b,In[N],resi[3],resenje[N];
vector<int> V[N];
vector<int> v;
void Dfs(int x){
    v.push_back(x);
    In[x]=1;
    for(int i=0;i<V[x].size();i++){
        if(!In[V[x][i]]){
            Dfs(V[x][i]);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=2;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&col[j][i]);
        }
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    int ok=0;
    for(int i=1;i<=n;i++){
        if(V[i].size()>2){
            printf("-1");
            return 0;
        }
        else{
            if(V[i].size()==1){
                ok=i;
            }
        }
    }
    Dfs(ok);
    int c[]={0,1,2};
    LL sol=INF;
    do{
        LL tmp=0;
        for(int i=0;i<v.size();i++){
            tmp+=(LL)col[v[i]][c[i%3]];
        }
        if(sol>tmp){
            sol=tmp;
            resi[0]=c[0],resi[1]=c[1],resi[2]=c[2];
        }
    }while(next_permutation(c,c+3));
    cout<<sol<<endl;
    for(int i=0;i<v.size();i++){
        resenje[v[i]]=resi[i%3]+1;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",resenje[i]);
    }
    return 0;
}
//mora biti lanac
//probaj svaku permutaciju
