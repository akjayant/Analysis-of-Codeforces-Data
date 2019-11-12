#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rint register int
typedef long long ll;
typedef long long unsigned llu;
using namespace std;
const int N=2e5+5;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const int bs=31;
const double eps=1e-8;
const ll zzz=1e9;
struct iiios{
    inline char gc(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }
    template<typename _Tp> inline ios&operator>>(_Tp&x){
        static char ch,sgn;ch=gc(),sgn=0;
        for(;!isdigit(ch);ch=gc()){if(ch==-1)return *this;sgn|=ch=='-';}
        for(x=0;isdigit(ch);ch=gc()) x=x*10+(ch^'0');
        sgn&&(x=-x);
    }
}io;
struct sgmt
{
    int l,r;
    ll add,sum;
}t[N<<2];
void update(int p)
{
    if(t[p].add)
    {
        t[p*2].sum+=(t[p*2].r-t[p*2].l+1)*t[p].add;
        t[p*2+1].sum+=(t[p*2+1].r-t[p*2+1].l+1)*t[p].add;
        t[p*2].add+=t[p].add;
        t[p*2+1].add+=t[p].add;
        t[p].add=0;
    }
}
void change(int p,int l,int r,int d)
{
    if(l<=t[p].l&&r>=t[p].r)
    {
        t[p].sum+=(t[p].r-t[p].l+1)*d;
        t[p].add+=d;
        return;
    }
    update(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid) change(p*2,l,r,d);
    if(r>mid) change(p*2+1,l,r,d);
    t[p].sum=t[p*2].sum+t[p*2+1].sum;
}
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r;t[p].sum=0,t[p].add=0;
    if(l==r)
    {
        t[p].sum=t[p].add=0;
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].sum=t[p*2].sum+t[p*2+1].sum;
}
ll ask(int p,int l,int r)
{
    if(l<=t[p].l&&r>=t[p].r) return t[p].sum;
    update(p);
    int mid=(t[p].l+t[p].r)/2;
    ll val=0;
    if(l<=mid) val+=ask(p*2,l,r);
    if(r>mid) val+=ask(p*2+1,l,r);
    return val;
}
int a[2000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while(_--)
    {
        memset(a,0,sizeof a);
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            a[x]++;
        }
        for(int i=n;i>=1;i--)
            a[i]+=a[i+1];
        for(int i=n;i>=1;i--)
            if(a[i]>=i)
            {
                cout<<i<<endl;
                break;
            }
    }
}
