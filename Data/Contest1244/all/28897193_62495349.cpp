#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 1e5+23;
map<int,int> m;
int a[maxn];
int n;
ll k;
int main()
{
    cin >>n>> k ;
    for(int i=0;i<n;i++) scanf("%d",a+i),m[a[i]]++;
    int cnt=0;
    while(k>0&&m.size()>=2){
        auto it=m.begin(),ite=m.end();ite--;
        if(it->second<=ite->second){
            int x=it->first,y=it->second;
            it++;
            int x2=it->first;
            int dif=abs(x2-x);
            m.erase(x);
            if(1ll*dif*y<=k) k-=1ll*dif*y,m[x2]+=y;
            else x+=(k/y),m[x]=(y),k=0;
        }
        else{
            int x=ite->first,y=ite->second;
            ite--;
            int x2=ite->first;
            int dif=abs(x-x2);
            m.erase(x);
            if(1ll*dif*y<=k) k-=1ll*dif*y,m[x2]+=y;
            else x-=(k/y),m[x]=y,k=0;
        }
    }
    if(m.size()==1) printf("0");
    else{
        auto it=m.begin(),ite=m.end();ite--;
        printf("%d",ite->first-it->first);
    }
}
