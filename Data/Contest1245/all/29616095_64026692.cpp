///By Stephan Ramirez dsramirezc@unal.edu.co
#include<bits/stdc++.h>
#define ms(a,v) memset(a,v,sizeof a)
#define ll long long
#define N 1000006
using namespace std;
int n;
int cor[N][2];
ll c[N];
ll k[N];
bool vis[N];
vector<pair<int,int> > con;
vector<int> ons;
priority_queue< tuple<ll,int,int >, vector<tuple<ll,int,int>>, greater< tuple<ll,int,int> > >  pq;
int main(){
	#ifdef LOCAL
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++)
        scanf("%d %d",&cor[i][0],&cor[i][1]);
    for(int i=0;i<n;i++){
        scanf("%lld",&c[i]);
        pq.push(make_tuple(c[i],i,i));
    }
    for(int i=0;i<n;i++)
        scanf("%lld",&k[i]);
    int cnt=0;
    ll ans=0;
    while(cnt<n && pq.size()>0){
        tuple<ll,int,int> aux=pq.top();
        int city=get<1> (aux);
        int parent=get<2>(aux);
        ll cost= get<0>(aux);
        pq.pop();
        if(vis[city])
            continue;
        vis[city]=true;
        if(parent==city){
            ons.push_back(city+1);
            ans+=c[city];
        }else{
            con.push_back(make_pair(city+1,parent+1));
            ans+=(k[city]+k[parent])*(abs(cor[city][0]-cor[parent][0])+abs(cor[city][1]-cor[parent][1]));
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ll cost1=(k[city]+k[i])*(abs(cor[city][0]-cor[i][0])+abs(cor[city][1]-cor[i][1]));
                pq.push(make_tuple(cost1,i,city));
            }
        }
    }
    printf("%lld\n",ans);
    printf("%d\n",ons.size());
    for(int i : ons){
        printf("%d ",i);
    }
    printf("\n");
    printf("%d\n",con.size());
    for(pair<int,int> i : con){
        printf("%d %d\n",i.first,i.second);
    }
	return 0;
}

