#include <stdio.h>
#include <set>
using namespace std;
set<int> Raw[100000],Column[100000];
int main(){
    int n,m;
    long long k;
    scanf("%i%i%lli",&n,&m,&k);
    for(long long i=0;i<k;i++){
        int x,y;
        scanf("%i%i",&x,&y);
        x--,y--;
        Raw[x].insert(y);
        Column[y].insert(x);
    }

    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            auto it1=Raw[i].lower_bound(j);
            if(it1==lowe)
            it1--;
            auto it2=Raw[i].upper_bound(j);
            printf("(%i,%i) ",*it1,*it2);
        }
        printf("\n");
    }*/

    int x=0,y=0,l_bound=0,r_bound=m-1,u_bound=0,d_bound=n-1;
    char direction='r';
    bool turned=0;
    while(1){
        //printf("%i %i\n",x,y);
        ///right
        if(direction=='r'){
            auto y1=Raw[x].upper_bound(y);
            if(y1==Raw[x].end() || (*y1)>r_bound){
                if(y==r_bound) {
                    if(turned==1) break;
                    turned=1;
                }
                else {
                    if(turned==1) k--;
                    turned=0;
                }
                k+=1ll*(r_bound-y+1);
                y=r_bound;
                direction='d';
                u_bound=x+1;
                turned=1;
                continue;
            }

            if(y==(*y1)-1) {
                if(turned==1) break;
                turned=1;
            }
            else {
                if(turned==1) k--;
                turned=0;
            }
            k+=1ll*((*y1)-y);
            y=(*y1)-1;
            direction='d';
            u_bound=x+1;
            turned=1;
            continue;
        }

        ///down
        if(direction=='d'){
            auto x1=Column[y].upper_bound(x);
            if(x1==Column[y].end() || (*x1)>d_bound){
                if(x==d_bound) {
                    if(turned==1) break;
                    turned=1;
                }
                else {
                    if(turned==1) k--;
                    turned=0;
                }
                k+=1ll*(d_bound-x+1);
                x=d_bound;
                direction='l';
                r_bound=y-1;
                turned=1;
                continue;
            }

            if(x==(*x1)-1) {
                if(turned==1) break;
                turned=1;
            }
            else {
                if(turned==1) k--;
                turned=0;
            }
            k+=1ll*((*x1)-x);
            x=(*x1)-1;
            direction='l';
            r_bound=y-1;
            turned=1;
            continue;
        }

        ///left
        if(direction=='l'){
            auto y1=Raw[x].lower_bound(y);
            bool outOfBounds=0;
            if(y1==Raw[x].begin())
                outOfBounds=1;
            else y1--;
            if(outOfBounds || (*y1)<l_bound){
                if(y==l_bound) {
                    if(turned==1) break;
                    turned=1;
                }
                else {
                    if(turned==1) k--;
                    turned=0;
                }
                k+=1ll*(y-l_bound+1);
                y=l_bound;
                direction='u';
                d_bound=x-1;
                turned=1;
                continue;
            }

            if(y==(*y1)+1) {
                if(turned==1) break;
                turned=1;
            }
            else {
                if(turned==1) k--;
                turned=0;
            }
            k+=1ll*(y-(*y1));
            y=(*y1)+1;
            direction='u';
            d_bound=x-1;
            turned=1;
            continue;
        }

        ///up
        if(direction=='u'){
            auto x1=Column[y].lower_bound(x);
            bool outOfBounds=0;
            if(x1==Column[y].begin())
                outOfBounds=1;
            else x1--;
            if(outOfBounds || (*x1)<u_bound){
                if(x==u_bound) {
                    if(turned==1) break;
                    turned=1;
                }
                else {
                    if(turned==1) k--;
                    turned=0;
                }
                k+=1ll*(x-u_bound+1);
                x=u_bound;
                direction='r';
                l_bound=y+1;
                turned=1;
                continue;
            }

            if(x==(*x1)+1) {
                if(turned==1) break;
                turned=1;
            }
            else {
                if(turned==1) k--;
                turned=0;
            }
            k+=1ll*(x-(*x1));
            x=(*x1)+1;
            direction='r';
            l_bound=y+1;
            turned=1;
            continue;
        }
    }
    if(k==n*1ll*m) printf("Yes");
    else printf("No");
}
