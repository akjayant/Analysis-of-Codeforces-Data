#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
using namespace std;
const int maxn = 1e5+10;
vector<int> block_row[maxn];
vector<int> block_col[maxn];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int walk(int x,int y,int up,int down,int lft,int rgt,int d,int turn){
    int ret=0;
    for(;;){
        if(d==0){
            up+=1;
            vector<int>& block_list = block_row[x];
            int p = lower_bound(block_list.begin(),block_list.end(),y)-block_list.begin();
            int yy;
            if(p>=block_list.size()){
                yy = rgt;
            }
            else{
                yy = min(block_list[p]-1,rgt);
            }
            if(yy==y){
                if(turn){
                    break;
                }
                else{
                    turn=1;
                    y = yy;
                    rgt = yy;
                    d = (d+1)%4;
                }
            }
            else{
                turn=1;
                ret+=yy-y;
                y = yy;
                rgt = yy;
                d=(d+1)%4;
            }
        }
        else if(d==1){
            rgt-=1;
            vector<int>& block_list = block_col[y];
            int p = lower_bound(block_list.begin(),block_list.end(),x)-block_list.begin();
            int xx;
            if(p>=block_list.size()){
                xx = down;
            }
            else{
                xx = min(block_list[p]-1,down);
            }
            if(xx==x){
                if(turn){
                    break;
                }
                else{
                    turn=1;
                    x = xx;
                    down=xx;
                    d = (d+1)%4;
                }
            }
            else{
                turn=1;
                ret+=xx-x;
                x = xx;
                down = x;
                d = (d+1)%4;
            }
        }
        else if(d==2){
            down-=1;
            vector<int>& block_list = block_row[x];
            int p = lower_bound(block_list.begin(),block_list.end(),y)-block_list.begin();
            int yy;
            p-=1;
            if(p<0){
                yy = lft;
            }
            else{
                yy = max(block_list[p]+1,lft);
            }
            if(yy==y){
                if(turn){
                    break;
                }
                else{
                    turn=1;
                    y=yy;
                    lft = yy;
                    d = (d+1)%4;
                }
            }
            else{
                turn=1;
                ret +=y-yy;
                y=yy;
                lft = yy;
                d = (d+1)%4;
            }
        }
        else{
            lft+=1;
            vector<int>& block_list = block_col[y];
            int p = lower_bound(block_list.begin(),block_list.end(),x)-block_list.begin();
            int xx;
            p-=1;
            if(p<0){
                xx = up;
            }
            else{
                xx = max(block_list[p]+1,up);
            }
            if(xx==x){
                if(turn){
                    break;
                }
                else{
                    turn=1;
                    x = xx;
                    up = xx;
                    d = (d+1)%4;
                }
            }
            else{
                turn=1;
                ret+=x-xx;
                x = xx;
                up = xx;
                d = (d+1)%4;
            }

        }
    }
    return ret;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        block_row[x].push_back(y);
        block_col[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(block_row[i].begin(),block_row[i].end());
    }
    for(int i=1;i<=m;i++){
        sort(block_col[i].begin(),block_col[i].end());
    }
    int cnt = walk(1,0,1,n,1,m,0,0);
    if((cnt+k)!=(n*m)){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    return 0;
}
