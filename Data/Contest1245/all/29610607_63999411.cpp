//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define si(x) scanf("%d",&x)
#define sii(a,b) scanf("%d%d",&a,&b)
#define siii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define siiii(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define sl(x) scanf("%I64d",&x)
#define sll(a,b) scanf("%I64d%I64d",&a,&b)
#define slll(a,b,c) scanf("%I64d%I64d%I64d",&a,&b,&c)
#define sllll(a,b,c,d) scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)
#define ss(x) scanf("%s",x+1)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(a,b,c) printf("%d %d %d",a,b,c)
#define piiii(a,b,c,d) printf("%d %d %d %d",a,b,c,d)
#define Pi(x) printf("%d\n",x)
#define Pii(x,y) printf("%d %d\n",x,y)
#define Piii(a,b,c) printf("%d %d %d\n",a,b,c)
#define Piiii(a,b,c,d) printf("%d %d %d %d\n",a,b,c,d)
#define pl(x) printf("%I64d",x)
#define pll(x,y) printf("%I64d %I64d",x,y)
#define plll(a,b,c) printf("%I64d %I64d %I64d",a,b,c)
#define pllll(a,b,c,d) printf("%I64d %I64d %I64d %I64d",a,b,c,d)
#define Pl(x) printf("%I64d\n",x)
#define Pll(x,y) printf("%I64d %I64d\n",x,y)
#define Plll(a,b,c) printf("%I64d %I64d %I64d\n",a,b,c)
#define Pllll(a,b,c,d) printf("%I64d %I64d %I64d %I64d\n",a,b,c,d)
#define ps(x) printf("%s",x+1)
#define space putchar(' ')
#define enter putchar('\n')
using namespace std;typedef long long LL;typedef long double LD;const LL pp=1e9+7;const LD eps=1e-8;
inline LL ksm(LL x,LL y=pp-2){x=(x%pp+pp)%pp;LL ans=1;while (y){if (y&1) ans=ans*x%pp;x=x*x%pp;y>>=1;}return ans;}
inline LL gcd(LL x,LL y){return y?gcd(y,x%y):x;}
inline void reads(char s[],int &n){n=0;char ch=getchar();while (ch==' ' || ch=='\n' || ch=='\r') ch=getchar();
while (ch!=' ' && ch!='\n' && ch!='\r') s[++n]=ch,ch=getchar();}
 
// HEAP Attention : Int + Array_Size + Stores In key[] + Top.id/v = Min
// init() empty() top() push(id,value) pop()
/*
struct HEAP
{
    int sz;
    struct HEAP_Pair{int id,v;}T[100009];
    inline int ls(int x){return x<<1;}
    inline int rs(int x){return ((x<<1)|1);}
    inline int f(int x){return x>>1;} 
    inline void init(){sz=0;}
    inline bool empty(){return sz==0;}
    inline HEAP_Pair top(){return T[1];}
    inline void push(int x,int v)
    {
        T[++sz].id=x;
        T[sz].v=v;
        pushup(sz);
    }
    inline void pop()
    {
        T[1]=T[sz--];
        pushdown(1);
    }
    void pushup(int x)
    {
        if (x==1) return;
        if (T[x].v<T[f(x)].v)    //
        {
            HEAP_Pair tmp=T[f(x)];
            T[f(x)]=T[x];
            T[x]=tmp;
            pushup(f(x));
        }
    }
    void pushdown(int x)
    {
        if (ls(x)>sz) return;
        int t=ls(x);
        if (rs(x)<=sz)
            if (T[rs(x)].v<T[t].v) t=rs(x);   //
        if (T[t].v<T[x].v)   //
        {
            HEAP_Pair tmp=T[t];
            T[t]=T[x];
            T[x]=tmp;
            pushdown(t);
        }
    }
};*/

 
// BIT Attention : Bit.init(Size) + Int + Array_Size + [ add1(x,v) sum(l,r) ] Or [ add(l,r,v) get(x) ]
// init(Size) [ add1(x,v) sum(l,r) ] Or [ add(l,r,v) get(x) ]
/*
struct BIT
{
	int T[100009],sz;
	inline int lowbit(int x){return x&(-x);}
	inline void init(int x){sz=x;}
	inline void Badd(int x,int v)
	{
		while (x<=sz)
		{
			T[x]+=v;
			x+=lowbit(x);
		}
	}
	inline int Bsum(int x)
	{
		int ans=0;
		while (x>=1)
		{
			ans+=T[x];
			x-=lowbit(x);
		}
		return ans;
	}
	inline void add1(int x,int v){Badd(x,v);}
	inline int sum(int l,int r){if (l>r) return 0;return Bsum(r)-Bsum(l-1);}
	inline void add(int l,int r,int v){Badd(l,v);Badd(r+1,-v);}
	inline int get(int x){return Bsum(x);}
};
*/
 
//Min/Max Pri Que Attention : MPQ.init(Size,Type [0=Min;1=Max] ) + get().id/v/t + Int + Array_Size
//get().id/v/t push(id,value,time) init(Size,Type) upd(L,R) empty()
/*
struct MPQ
{
	int sz,l,r,type;
	struct MPQ_Pair{int id,v,t;}q[1000009];
	inline void init(int thesz,int thetype){sz=thesz;l=r=0;type=thetype;}
	inline bool empty(){return l==r;}
	inline int pre(int x){if (x-1<0) return sz;return x-1;}
	inline int suc(int x){if (x+1>sz) return 1;return x+1;}
	inline void push(int id,int v,int t)
	{
		if (!type)
			while (q[pre(r)].v>=v && !empty()) r=pre(r);
		else
			while (q[pre(r)].v<=v && !empty()) r=pre(r);
		q[r].id=id,q[r].v=v,q[r].t=t;
		r=suc(r);
	}
	inline MPQ_Pair get(){return q[l];}
	inline void upd(int tL,int tR){while ((q[l].t<tL || q[l].t>tR) && !empty()) l=suc(l);}
};
*/
//========================    C    ========================    F    ==================================
int n,a,b,c,needed,A,B,C,aa,bb,cc;
char S[109];
int main()
{
	//freopen("r.txt","r",stdin);
	//freopen("w1.txt","w",stdout);
	int Tt;
	si(Tt);
	while (Tt--)
	{
		si(n);
		needed=(n+1)>>1;
		siii(a,b,c);
		ss(S);
		A=B=C=0;
		for (int i=1;i<=n;i++)
			if (S[i]=='R')
				A++;
			else if (S[i]=='P')
				B++;
			else
				C++;
		aa=min(a,C);
		bb=min(b,A);
		cc=min(c,B);
		A=a-aa,B=b-bb,C=c-cc;
		if (aa+bb+cc>=needed)
		{
			puts("YES");
			for (int i=1;i<=n;i++)
				if (S[i]=='S')
				{
					if (aa) aa--,printf("R");
					else
					{
						if (A) A--,printf("R"); else if (B) B--,printf("P"); else C--,printf("S");
					}
				}
				else if (S[i]=='R')
				{
					if (bb) bb--,printf("P");
					else
					{
						if (A) A--,printf("R"); else if (B) B--,printf("P"); else C--,printf("S");
					}
				}
				else
				{
					if (cc) cc--,printf("S");
					else
					{
						if (A) A--,printf("R"); else if (B) B--,printf("P"); else C--,printf("S");
					}
				}
			enter;
		}
		else
			puts("NO");
	}
	return 0;
}