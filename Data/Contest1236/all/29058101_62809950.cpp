#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
vector <int> mp[100010], mp1[100010];
int px1[100010], px2[100010], py1[100010], py2[100010];
int main(){
    ll n, m, k;
    while(cin>>n>>m>>k){
        ll sm=1;
        int x, y;
        for(int i=0; i<k; ++i){
            scanf("%d %d",&x, &y);
            mp[x].push_back(y);
            mp1[y].push_back(x);
        }
        int lx1, lx2, ly1, ly2;
            lx1=0;
            lx2=n+1;
        for(int i=1; i<=n; ++i){
            mp[i].push_back(0);
            mp[i].push_back(m+1);
            sort(mp[i].begin(), mp[i].end());
            px2[i]=mp[i].size();
            --px2[i];
            px1[i]=0;
        }
            ly1=0;
            ly2=m+1;
        for(int i=1; i<=m; ++i){
            mp1[i].push_back(0);
            mp1[i].push_back(n+1);
            sort(mp1[i].begin(), mp1[i].end());
            py2[i]=mp1[i].size();
            --py2[i];
            py1[i]=0;
        }
        int dir=1, tmpx, tmpy, tmp, cnt=0;
        x=1; y=1;
        int cnt1=0;
        while(1){
            tmpx=x;tmpy=y;
            if(dir==1){
                while(mp[x][px2[x]-1]>y){
                    --px2[x];
                }
                tmp=mp[x][px2[x]];
                tmp=min(tmp, ly2);
                sm+=tmp-y-1;
                y=tmp-1;
                ly2=tmp;
                lx1=max(lx1, x);
            }
            else if(dir==2){
                while(mp1[y][py2[y]-1]>x){
                    --py2[y];
                }
                tmp=mp1[y][py2[y]];
                tmp=min(tmp, lx2);
                sm+=tmp-x-1;
                x=tmp-1;
                lx2=tmp;
                ly2=min(ly2, y);
            }
            else if(dir==3){
                while(mp[x][px1[x]+1]<y){
                    ++px1[x];
                }
                tmp=mp[x][px1[x]];
                tmp=max(tmp, ly1);
                sm+=y-tmp-1;
                y=tmp+1;
                ly1=tmp;
                lx2=min(lx2, x);
            }
            else if(dir==4){
                while(mp1[y][py1[y]+1]<x){
                    ++py1[y];
                }
                tmp=mp1[y][py1[y]];
                tmp=max(tmp, lx1);
                sm+=x-tmp-1;
                x=tmp+1;
                lx1=tmp;
                ly1=max(ly1, y);
            }
            ++dir;
            if(dir==5)
                dir=1;
            if(tmpx==x&&tmpy==y){
                ++cnt;
            }
            else{
                cnt=0;
            }
            if(x==1&&y==1){
                if(cnt>=2){
                    break;
                }
            }
            else{
                if(cnt>=1)
                    break;
            }
            ++cnt1;
            assert(cnt1<3*(n+m));
//            cout<<x<<" "<<y<<" "<<sm<<endl;
        }
//        cout<<sm<<endl;
        if(n*m-sm==k){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
  return 0;
}


