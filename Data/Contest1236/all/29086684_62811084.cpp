#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,set<ll>> blockx,blocky;
map<ll,map<ll,ll>> turn;
int main()
{
    ll i,j;
    ll n,m,k,dir=1,tk;
    ll curx=1,cury=1;
    ll res=1;
    ll ux=1,vx,uy=1,vy;
    scanf("%lld %lld %lld",&n,&m,&k);
    tk=k;
    vx=n;
    vy=m;
    while(k--){
        scanf("%lld %lld",&i,&j);
        blockx[i].insert(j);
        blocky[j].insert(i);
    }
    while(1){
        if(dir==1){
            auto itr=blockx[curx].upper_bound(cury);

            if(itr!=blockx[curx].end()){
                vy=min(vy,*itr-1);
                //prllf("%d\n",(ll)blockx[curx].size());
            }
            //prllf("%d\n",vy);
            res+=(vy-cury);
            cury=vy;
            ux=curx+1;
            dir=2;
            turn[curx][cury]++;
            if(turn[curx][cury]>1)
                break;
        }
        else if(dir==2){
            auto itr=blocky[cury].upper_bound(curx);
            if(itr!=blocky[cury].end())
                vx=min(vx,*itr-1);
            res+=(vx-curx);
            curx=vx;
            dir=3;
            vy=cury-1;
            turn[curx][cury]++;
            if(turn[curx][cury]>1)
                break;
        }
        else if(dir==3){
            auto itr=blockx[curx].upper_bound(cury);
            if(!blockx[curx].empty()){
                if(itr!=blockx[curx].begin()){
                   itr--;
                   uy=max(uy,*itr+1);
                }
            }
            res+=(cury-uy);
            cury=uy;
            dir=4;
            vx=curx-1;
            turn[curx][cury]++;
            if(turn[curx][cury]>1)
                break;
        }
        else {
            auto itr=blocky[cury].upper_bound(curx);
            if(!blocky[cury].empty()){
                if(itr!=blocky[cury].begin()){
                   itr--;
                   ux=max(ux,*itr+1);
                }
            }
            res+=(curx-ux);
            curx=ux;
            dir=1;
            uy=cury+1;
            turn[curx][cury]++;
            if(turn[curx][cury]>1)
                break;
        }
        //printf("%lld %lld\n",curx,cury);
    }
    if(res+tk==n*m)
        printf("Yes");
    else
        printf("No");
}
