#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#ifndef orewabaka
    #define f first
    #define s second
    #define minna(a) a.begin(), a.end()
    #define ovse(a) a.rbegin(), a.rend()
    #define pb push_back
    #define endl aut '\n'
    #define ar vector
    #define var auto
    #define rand() (((rand()<<15)+rand())&INT32_MAX)
    #define ain cin,
    #define aut cout,
    #define $(a) (i64)a.size()
    #define in insert
    #define fusrodah return
    #define mp make_pair
    #define rep(i, n) for(i64 i=0;i<(n);i++)
    #define rep1(i, n) for(i64 i=1;i<(n);i++)
    #define fro2(i, a, b) for(i64 i=(a);i<(b);i++)
    #define elif else if

    typedef int i32;
    typedef unsigned u32;
    typedef long long i64;
    typedef unsigned long long u64;
    typedef pair<i32, i32> p32;
    typedef pair<i64, i64> p64;
    typedef double lf;
    typedef tree<p64, null_type, less<p64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

    namespace shyutsuryoku{
        const i32 STRSZ=3e6+13;
        char inbufer[STRSZ];
        inline void cscan(string& i){
            i32 c=getc(stdin), cnt=0;while(c<=32)c=getc(stdin);
            while(c>32)*(inbufer+cnt)=c,c=getc(stdin),++cnt;
            *(cnt+inbufer)=0;i=inbufer;
        }
        inline void cprint(string& i){
            char *s=new char[i.size()+1]; 
            strcpy(s, i.c_str());
            while(*s)putchar(*s), s++;
        }
        inline void cprint(const char*& i){
            i32 cnt=0;
            while(*(i+cnt))putc(*(i+cnt), stdout),cnt++;
        }
        inline void cscan(i32&i){
            i=0;i32 c=getc(stdin), b=0;while(c<=32)c=getc(stdin);if(c=='-')b=1, c=getc(stdin);
            while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
            if(b)i=-i;
        }
        inline void cprint(i32 i){
            if(i<0)putc('-',stdout),i=-i;
            i32 sz=0;char ans[13];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
            while(sz--)putc(ans[sz],stdout);
        }
        inline void cscan(i64&i){
            i=0;i32 c=getc(stdin), b=1;while(c<=32)c=getc(stdin);if(c=='-')b=-1,c=getc(stdin);
            while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
            i*=b;
        }
        inline void cprint(i64 i){
            if(i<0)putc('-',stdout),i=-i;
            i32 sz=0;char ans[21];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
            while(sz--)putc(ans[sz],stdout);
        }
        inline void cscan(u32&i){
            i=0;i32 c=getc(stdin);while(c<=32)c=getc(stdin);
            while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
        }
        inline void cprint(u32 i){
            i32 sz=0;char ans[12];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
            while(sz--)putc(ans[sz],stdout);
        }
        inline void cscan(u64&i){
            i=0;i32 c=getc(stdin);while(c<=32)c=getc(stdin);
            while(c>='0'&&c<='9')i*=10,i+=c-'0',c=getc(stdin);
        }
        inline void cprint(u64 i){
            i32 sz=0;char ans[21];while(i||!sz)ans[sz++]=i%10+'0',i/=10;
            while(sz--)putc(ans[sz],stdout);
        }
        inline void cscan(lf&i){
            scanf("%lf", &i);
        }
        inline void cprint(lf i){
            printf("%.20lf", i);
        }
        inline void cprint(char i){
            putc(i, stdout);
        }
        inline void cscan(char&i){
            i32 b=getc(stdin);
            while(b<=32)b=getc(stdin);
            i=b;
        }
        template<class T, class K>inline void cscan(pair<T, K>& i){
            cscan(i.f);cscan(i.s);
        }
        template<class T, class K>inline void cprint(pair<T, K>& i){
            cprint('(');cprint(i.f);cprint(' ');cprint(i.s);cprint(')');
        }
        template<class T>inline void cscan(ar<T>& i){
            for(var& j:i)cscan(j);
        }
        template<class T>inline void cprint(ar<T>& i){
            for(var& j:i)cprint(j), cprint(' ');
        }
        template<class T>inline void cprint(ar<ar<T> >& i){
            for(var& j:i)cprint(j), cprint('\n');
        }
    }
    template<class T>ostream &operator,(ostream &os, T v){
        shyutsuryoku::cprint(v);//cprint(' ');
        return os;
    }
    template<class T>istream &operator,(istream &is, T &v){
        shyutsuryoku::cscan(v);
        return is;
    }
#endif

void exe_cute();

i32 main(){
    #ifdef tavan_sersyv
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        srand(time(0));
        exe_cute();
    #ifdef tavan_sersyv
        aut '\n', (lf)clock()/CLOCKS_PER_SEC, " 秒\n";
    #endif
    fusrodah 0;
}
const i32 N=1e5+77;
i64 cl[N][3], aans[N];
ar<i64> g[N], bk;

void dfs(i64 v, i64 p=-1){
    bk.pb(v);
    for(i64 i:g[v]){
        if(i!=p)
            dfs(i, v);
    }
}

void exe_cute(){
    i64 n;
    ain n;
    rep1(i, n+1)ain cl[i][0];
    rep1(i, n+1)ain cl[i][1];
    rep1(i, n+1)ain cl[i][2];
    rep(i, n-1){
        i32 u, v;
        ain u, v;
        g[u].pb(v);
        g[v].pb(u);
    }
    i64 st=0;
    rep1(i, n+1){
        if($(g[i])>2){
            aut -1;
            return;
        }
        if($(g[i])==1)st=i;
    }
    dfs(st);
    i64 ans=1e18, st1, st2;
    rep(x, 3)rep(y, 3){
        if(x==y)continue;
        i64 p=y, pp=x, sum=cl[bk[0]][x]+cl[bk[1]][y];
        for(i32 i=2;i<n;i++){
            i64 nx;
            if(0!=p&&0!=pp)nx=0;
            if(1!=p&&1!=pp)nx=1;
            if(2!=p&&2!=pp)nx=2;
            sum+=cl[bk[i]][nx];
            pp=p;
            p=nx;
        }
        if(sum<=ans){
            st1=x;
            st2=y;
            ans=sum;
        }
    }
    aut ans, '\n';
    aans[bk[0]]=st1+1;
    aans[bk[1]]=st2+1;
    for(i32 i=2;i<n;i++){
        i64 nx;
        if(0!=st1&&0!=st2)nx=0;
        if(1!=st1&&1!=st2)nx=1;
        if(2!=st1&&2!=st2)nx=2;
        aans[bk[i]]=nx+1;
        st1=st2;
        st2=nx;
    }
    rep1(i, n+1)aut aans[i], ' ';
}