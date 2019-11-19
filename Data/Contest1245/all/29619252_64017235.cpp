#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;
pair<int,int>a[N];
pair<int,int>best[N];
int n,k[N],x[N],y[N];
ll totcost;
vector<int>cities;
vector<pair<int,int>>roads;
ll manhattan(int i,int j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
        best[i]={0,i};
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
    }
    for(int pos=1;pos<=n;pos++){
        sort(a+pos,a+n+1);
        totcost+=a[pos].first;
        int og=a[pos].second;
        if(best[og].first==0){
            cities.push_back(og);
        }
        else{
            roads.push_back({og,best[og].second});
        }
        for(int i=pos+1;i<=n;i++){
            int ogi=a[i].second;
            ll newcost=manhattan(ogi,og)*(k[og]+k[ogi]);
            if(newcost<a[i].first){
                a[i].first=newcost;
                best[ogi]={1,og};
            }
        }
    }
    printf("%lld\n",totcost);
    printf("%d\n",cities.size());
    for(auto&x:cities){
        printf("%d ",x);
    }
    printf("\n");
    printf("%d\n",roads.size());
    for(auto&x:roads){
        printf("%d %d\n",x.first,x.second);
    }
    return 0;
}
