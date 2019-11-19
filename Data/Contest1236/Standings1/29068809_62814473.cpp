#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set< pair<int,int> > obs;
set< pair<int,int> >::iterator it;

int flagx[100010],flagy[100010];
long long tot=0;
int del(int x1,int y1,int x2,int y2)
{
    for (int i=x1;i<=x2;++i)
    for (int j=y1;j<=y2;++j)
    {
        it = obs.find(make_pair(i,j));
        if (it==obs.end())
            return 0;
        --flagx[i];
        --flagy[j];
        obs.erase(it);
    }
    return 1;
}


int main()
{

    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<k;++i)
    {
        int x,y;scanf("%d%d",&x,&y);
        ++flagx[x];++flagy[y];
        obs.insert(make_pair(x,y));
    }

    int uu=1,dd=n,ll=1,rr=m;int tmp=0;
    while (uu<=dd && ll<=rr)
    {
        tmp=tmp+1;if (tmp==5) tmp=1;
        if (tmp==1){
            if (flagx[uu]){
                int x=uu,y=ll;
                for (;y<=rr;++y){
                    it=obs.find(make_pair(x,y));
                    if (it!=obs.end())
                        break;
                }
                int flag= del(x,y,dd,rr);
                if (!flag){printf("No\n");return 0;}
                rr=y-1;
            }
            tot+=(rr-ll+1);
            ++uu;
        }
        if (tmp==2){
            if (flagy[rr]){
                int x=uu,y=rr;
                for (;x<=dd;++x){
                    it=obs.find(make_pair(x,y));
                    if (it!=obs.end())
                        break;
                }
                int flag= del(x,ll,dd,y);
                if (!flag){printf("No\n");return 0;}
                dd=x-1;
            }
            tot+=(dd-uu+1);
            --rr;
        }
        if (tmp==3){
            if (flagx[dd]){
                int x=dd,y=rr;
                for (;y>=ll;--y){
                    it=obs.find(make_pair(x,y));
                    if (it!=obs.end())
                        break;
                }
                int flag= del(uu,ll,x,y);
                if (!flag){printf("No\n");return 0;}
                ll=y+1;
            }
            tot+=(rr-ll+1);
            --dd;
        }
        if (tmp==4){
            if (flagy[ll]){
                int x=dd,y=ll;
                for (;x>=uu;--x){
                    it=obs.find(make_pair(x,y));
                    if (it!=obs.end())
                        break;
                }
                int flag= del(uu,y,x,rr);
                if (!flag){printf("No\n");return 0;}
                uu=x+1;
            }
            tot+=(dd-uu+1);
            ++ll;
        }
        //printf("%d %d %d %d\n",uu,dd,ll,rr);
    }
    if (tot+k==1LL*n*m && obs.empty()){
        printf("Yes\n");return 0;
    }
    printf("No\n");
}




