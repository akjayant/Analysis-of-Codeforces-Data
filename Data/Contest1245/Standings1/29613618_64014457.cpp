#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 4e6+100;
#define fr(i,a,b) for(register int i = a;i <= b; ++i)
#define pb push_back

struct point{
   int id,x,y;
   ll val;
   point(int id=0,int x=0,int y=0,ll val=0):
      id(id),x(x),y(y),val(val){}
   bool operator < (const point &b) const {
      return val < b.val;
   }
}p[N];

int lt[N];
int f[N];
inline int find(int x){
   return f[x] == x ? x : f[x] = find(f[x]);
}

int n;
int x[N],y[N],c[N],k[N];

vector<pii>anse;
vector<int>ansc;

ll dis(int a,int b){
   return 1LL*(k[a]+k[b])*(abs(x[a]-x[b])+abs(y[a]-y[b]));
}

ll ans;
int main(){
   scanf("%d",&n);
   fr(i,1,n)f[i] = i,lt[i] = 0;

   fr(i,1,n) scanf("%d%d",x+i,y+i); 
   fr(i,1,n) scanf("%d",c+i);
   fr(i,1,n) scanf("%d",k+i);

   int cnt = 0;
   fr(i,1,n){
      fr(j,i+1,n){
         p[++cnt] = point(0,i,j,dis(i,j));
      }
   }
   fr(i,1,n)p[++cnt] = point(1,i,0,c[i]);
   
   sort(p+1,p+cnt+1);

   int j = 0;
   fr(i,1,cnt){
      if(j >= n)break;
      if(p[i].id == 0){
         int cx = p[i].x,cy = p[i].y;
         if(find(cx) == find(cy) || (lt[find(cx)] && lt[find(cy)]))continue ;
         else {
            ans += p[i].val; anse.pb(pii(cx,cy));
            ++j;
            int wx = find(cx),wy = find(cy);
            f[wx] = wy;
            lt[wy] |= lt[wx];
         }
      } else {
         int cx = p[i].x;
         if(lt[find(cx)])continue ;
         else {
            ans += p[i].val; ansc.pb(cx);
            ++j;
            int wx = find(cx);
            lt[wx] = 1;
         }
      }
   }
   printf("%lld\n",ans);
   printf("%d\n",ansc.size());
   fr(i,0,(int)ansc.size()-1){
      printf("%d ",ansc[i]);
   }
   puts("");
   printf("%d\n",anse.size());
   fr(i,0,(int)anse.size()-1){
      printf("%d %d\n",anse[i].first,anse[i].second);
   }
}
