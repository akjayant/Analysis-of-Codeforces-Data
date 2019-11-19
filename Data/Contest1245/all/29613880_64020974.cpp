#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
typedef pair<ll,P> san;

int n;
int x[100050];
int y[100050];
int c[100050];
int k[100050];
vector<P> G[100050];
vector<san> v;

int pre[100050];
int ra[100050];

vector<int> ans1;
vector<P> ans2;


int Find(int x)
{
	return pre[x]==0?x:Find(pre[x]);
}

void jo(int a,int b){
    int x=Find(a);
    int y=Find(b);
    if(x==y)
        return ;
    if(ra[x]<ra[y]){
        pre[x]=y;
 //       e[x]=c;//e数组记录路径上的大小
    }
    else{
        pre[y]=x;
  //      e[y]=c;
        if(ra[x]==ra[y])
            ra[x]++;//ra数组就是记录树的高度，也就是所谓的秩
    }
}

void f(){

    sort(v.begin(),v.end());


    ll sum = 0;
    for(auto t : v){
        ll w = t.first;
        int u = t.second.first;
        int v = t.second.second;

        if(Find(u) == Find(v)){
            continue;
        }
        else{
            sum += w;
            if(v == n+1){
                ans1.push_back(u);
            }
            else{
                ans2.push_back(P(u,v));
            }

            jo(u,v);
        }
    }

    cout << sum <<"\n";
    cout << ans1.size() << "\n";
    for(auto t:ans1){
        printf("%d ",t);
    }
    cout << "\n";
    cout << ans2.size() << "\n";
    for(auto t:ans2){
        printf("%d %d\n",t.first,t.second);
    }


    return;

}


int main()
{
    cin >> n;
    for(int i =1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(int i =1 ;i<=n;i++){
        scanf("%d",&c[i]);
    }
    for(int i =1 ;i<=n;i++){
        scanf("%d",&k[i]);
    }


    for(int i = 1;i<=n;i++){
        for(int j =i+1;j<=n;j++){
            ll w = 1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            G[i].push_back(P(j,w));
            G[j].push_back(P(i,w));
            v.push_back(san(w,P(i,j)));
        }
    }

    for(int i =1;i<=n;i++){
        G[i].push_back(P(n+1,c[i]));
        G[n+1].push_back(P(i,c[i]));
        v.push_back(san(c[i],P(i,n+1)));
    }


    f();


    return 0;
}
