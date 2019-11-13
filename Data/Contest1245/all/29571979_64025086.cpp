#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1E5+6;
const int N=1E5+6;
int x[M],y[M];
struct node{
	int u,v,w;
}t[M];
struct Node{
	int op,x;
}q[N];
struct seg{
	int l,r,s;
}ti[N<<2];
void build(int p,int l,int r){
	ti[p].l=l; ti[p].r=r;
	if(l==r)	return ; int mid=l+r>>1;
	build(p<<1,l,mid);	build(p<<1|1,mid+1,r);
}
int cmp(node a,node b){return a.w<b.w;}
int dis(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
const int maxn=1E5+5;
const int inf=0x3f3f3f3f;
const int m=1E9+7;
string s;
ll arr[maxn];
int main()
{
    cin>>s;
    ll ans=1;
    arr[1]=arr[0]=1;
    for(int i=2;i<=s.size();i++)
        arr[i]=(arr[i-1]+arr[i-2])%m;
    for(int i=0;i<s.size();i++){
        if(s[i]=='m'||s[i]=='w'){
            cout<<0<<'\n'; return 0;
        }
        if(s[i]=='u'){
            int cnt=0,k=i;
            while(s[k]=='u') cnt++,k++;
            if(cnt>=2)
                ans=(arr[cnt]*ans%m)%m;
            i=k-1;
        }
        else if(s[i]=='n'){
            int cnt=0,k=i;
            while(s[k]=='n') cnt++,k++;
            if(cnt>=2) ans=(arr[cnt]*ans%m)%m;
            i=k-1;
        }
    }
    cout<<ans<<'\n';
}
