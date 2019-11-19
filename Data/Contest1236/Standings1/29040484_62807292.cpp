#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
set<int>A[100010],B[100010];
set<int>::iterator it;
map<int,int>ma[100010];
int main(){
    int a,b,i,n,m,kk;
    cin>>n>>m>>kk;
    for(i=1;i<=kk;i++){
        cin>>a>>b;
        B[a].insert(b);
        A[b].insert(a);
    }
    for(i=1;i<=1e5;i++){
        A[i].insert(0);
        A[i].insert(n+1);

        B[i].insert(0);
        B[i].insert(m+1);
    }


    int l=1,r=m,u=1,d=n,x,y,k;
    x=y=k=a=b=1;

    long long sum=n,cnt=1;
    sum*=m;
    while(1){
        if(k==1){
            it=B[y].upper_bound(x);
            a=min(r,(*it)-1);

            u=max(b+1,u);
        }
        else if(k==2){
            it=A[x].upper_bound(y);
            b=min(d,(*it)-1);

            r=min(a-1,r);
        }
        else if(k==3){
            it=B[y].upper_bound(x);
            it--;
            a=max(l,(*it)+1);

            d=min(b-1,d);
        }
        else{
            it=A[x].upper_bound(y);
            it--;
            b=max(u,(*it)+1);

            l=max(a+1,l);
        }

        k=k%4+1;
        cnt+=abs(a-x)+abs(b-y);

        x=a;
        y=b;

        if(ma[a].find(b)==ma[a].end()) ma[a][b]=1;
        else ma[a][b]++;
        if(ma[a][b]==2) break;
    }

    if(cnt+kk==sum) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
