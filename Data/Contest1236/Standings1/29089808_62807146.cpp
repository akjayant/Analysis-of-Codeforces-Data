#include<bits/stdc++.h>
using namespace std;

int a[100005],BIT[100005];

void add(int pos,int val){
    for(int i=pos;i<=100000;i+=i&-i)
        BIT[i]+=val;
}

int query(int pos){
    int res=0;
    for(int i=pos;i>0;i-=i&-i)
        res+=BIT[i];
    return res;
}

int main(){
    int n,m;
    long long ans=0;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;i++)
        scanf("%d", &a[i]);
    for(int i=1;i<=n;i++)
        add(i,1);
    for(int i=1;i<=m;i++){
        int l=1,r=n+1,L=1,R=n+1,x=a[i]-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(query(mid)>=x)
                r=mid;
            else
                l=mid+1;
        }
        while(L<R){
            int mid=(L+R)>>1;
            if(query(mid)<=x)
                L=mid+1;
            else
                R=mid;
        }
        add(1,1);
        add(l,-1);
        add(L,1);
        add(n+1,-1);
    }
    add(1,1);
    for(int i=1;i<=n;i++)
        ans+=min(query(i),n)-i;
    for(int i=1;i<=n;i++)
        BIT[i]=0;
    for(int i=1;i<=n;i++)
        add(i,1);
    for(int i=1;i<=m;i++){
        int l=1,r=n+1,L=1,R=n+1,x=a[i]+1;
        while(l<r){
            int mid=(l+r)>>1;
            if(query(mid)>=x)
                r=mid;
            else
                l=mid+1;
        }
        while(L<R){
            int mid=(L+R)>>1;
            if(query(mid)<=x)
                L=mid+1;
            else
                R=mid;
        }
        add(1,-1);
        add(l,1);
        add(L,-1);
        add(n+1,1);
    }
    add(1,-1);
    for(int i=1;i<=n;i++)
        ans+=i-max(query(i),1);
    ans+=n;
    if(n==1)
        ans=0;
    printf("%I64d\n", ans);
}