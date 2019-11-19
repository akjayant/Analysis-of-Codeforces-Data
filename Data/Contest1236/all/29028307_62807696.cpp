#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5+100;
typedef long long ll;
typedef vector<int>::iterator iter;
int n,m,k;
vector<int> r[N],c[N];
ll ps,tot,nw; iter it;
bool check(){
    int x=1,y=1,d=1,a,b; ps=1; int up=1,down=n+1,left=0,right=m+1;
    while(ps+k<tot){
        //printf("%d %d %d %d\n",x,y,d,ps);
        if(d==1){
            a=x; it=upper_bound(r[x].begin(),r[x].end(),y);
            b=*it; b=min(right,b); b--; nw=b-y; right=b;
            if(nw<=0&&(x!=1||y!=1)) return false;
        }
        else if(d==2){
            b=y; it=upper_bound(c[y].begin(),c[y].end(),x);
            a=*it; a=min(down,a); a--; nw=a-x; down=a;
            if(nw<=0) return false;
        }
        else if(d==3){
            a=x; it=upper_bound(r[x].begin(),r[x].end(),y); it--;
            b=*it; b=max(left,b); b++; nw=y-b; left=b;
            if(nw<=0) return false;
            
        }
        else if(d==4){
            b=y; it=upper_bound(c[y].begin(),c[y].end(),x); it--;
            a=*it; a=max(up,a); a++; nw=x-a; up=a;
            if(nw<=0) return false;
        }
        //printf("%d %d -> %d %d d:%d\n",x,y,a,b,d);
        d++; if(d>4) d-=4;
        x=a; y=b; ps+=nw;
        
    }
    return ps+k==tot;
}

int main(){
    scanf("%d %d %d",&n,&m,&k); tot=1LL*n*m;
    for(int i=1,x,y;i<=k;++i){
        scanf("%d %d",&x,&y);
        r[x].push_back(y);
        c[y].push_back(x);
    }
    for(int i=1;i<=n;++i){
        r[i].push_back(0); r[i].push_back(m+1);
        sort(r[i].begin(),r[i].end());
    }
    for(int j=1;j<=m;++j){
        c[j].push_back(0); c[j].push_back(n+1);
        sort(c[j].begin(),c[j].end());
    }
    if(check()) printf("Yes\n");
    else printf("No\n");
}