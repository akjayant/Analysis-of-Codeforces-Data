#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define L long long
typedef pair<L,L> P;
inline L read(){
	L sum(0);char ch(getchar());
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum;
}
#define get_size(x) (x?x->size:0)
#define get_sp(x) (x?x->sp:0)
struct node{
	node *lch,*rch;
	int key,fix,size,cnt,sp;
	node(int x=0,int y=1):lch(NULL),rch(NULL),key(x),fix(rand()),size(y),cnt(y),sp(1){}
	inline void pushup(){
		this->size=get_size(this->lch)+get_size(this->rch)+this->cnt;
		this->sp=get_sp(this->lch)+get_sp(this->rch)+1;
	}
}*root;
inline void left_rotate(node *&x){
	node *tmp(x->rch);
	x->rch=tmp->lch;
	tmp->lch=x;
	x->pushup();
	tmp->pushup();
	x=tmp;
}
inline void right_rotate(node *&x){
	node *tmp(x->lch);
	x->lch=tmp->rch;
	tmp->rch=x;
	x->pushup();
	tmp->pushup();
	x=tmp;
}
inline void insert(node *&x,int k,int cnt){
	if(!x){
		x=new node(k,cnt);
		return;
	}
	if(k==x->key){
		x->cnt+=cnt;
		x->pushup();
		return;
	}
	if(k<x->key){
		insert(x->lch,k,cnt);
		x->pushup();
		if(x->lch->fix<x->fix)right_rotate(x);
	}
	else{
		insert(x->rch,k,cnt);
		x->pushup();
		if(x->rch->fix<x->fix)left_rotate(x);
	}
}
inline int del(node *&x,int k){
	int ret;
	if(x->key==k){
		ret=x->cnt;
		if(!x->lch||!x->rch){
			node *tmp(NULL);
			if(x->lch)tmp=x->lch;
			if(x->rch)tmp=x->rch;
			delete x;
			x=tmp;
		}
		else{
			if(x->lch->fix<x->rch->fix){
				right_rotate(x);
				del(x->rch,k);
			}
			else{
				left_rotate(x);
				del(x->lch,k);
			}
		}
	}
	else{
		if(k<x->key)ret=del(x->lch,k);
		else ret=del(x->rch,k);
	}
	if(x)x->pushup();
	return ret;
}
inline P kth(int k){
	node *tmp(root);
	while(tmp){
		if(k==get_sp(tmp->lch)+1)return P(tmp->key,tmp->cnt);
		if(k<get_sp(tmp->lch)+1)tmp=tmp->lch;
		else{
			k-=get_sp(tmp->lch)+1;
			tmp=tmp->rch;
		}
	}
	return P(tmp->key,tmp->cnt);
}
int n,a[100005],bl[100005],id(1),l,r,ans;
L k,st[100005],cnt[100005];
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	int now(a[1]);bl[1]=cnt[1]=1;st[1]=a[1];
	for(int i=2;i<=n;++i){
		if(a[i]^now){now=a[i];++id;st[id]=a[i];cnt[id]=1;bl[i]=id;}
		else{bl[i]=id;++cnt[id];}
	}
	l=1,r=id;ans=a[n]-a[1];
	while(k>=0&&l<r){
		L tp1(cnt[l]),all1(cnt[l]*(st[l+1]-st[l]));
		L tp2(cnt[r]),all2(cnt[r]*(st[r]-st[r-1]));
		if(k<min(tp1,tp2))break;
		if(tp1<tp2){
			L flg(k/tp1*tp1);
			if(flg>=all1){
				cnt[l+1]+=cnt[l];
				k-=all1;
				ans=st[r]-st[l+1];
				l++;
			}
			else{
				st[l]=st[l]+(k/tp1);
				k-=flg;
				ans=st[r]-st[l];
			}
		}
		else{
			if(tp1>tp2){
				L flg(k/tp2*tp2);
				if(flg>=all2){
					cnt[r-1]+=cnt[r];
					k-=all2;
					ans=st[r-1]-st[l];
					r--;
				}
				else{
					st[r]=st[r]-(k/tp2);
					k-=flg;
					ans=st[r]-st[l];
				}
			}
			else{
				if(all1<all2){
					L flg(k/tp1*tp1);
					if(flg>=all1){
						cnt[l+1]+=cnt[l];
						k-=all1;
						ans=st[r]-st[l+1];
						l++;
					}
					else{
						st[l]=st[l]+(k/tp1);
						k-=flg;
						ans=st[r]-st[l];
					}
				}
				else{
					L flg(k/tp2*tp2);
					if(flg>=all2){
						cnt[r-1]+=cnt[r];
						k-=all2;
						ans=st[r-1]-st[l];
						r--;
					}
					else{
						st[r]=st[r]-(k/tp2);
						k-=flg;
						ans=st[r]-st[l];
					}
				}
			}
		}
	}
	printf("%d",ans);
}