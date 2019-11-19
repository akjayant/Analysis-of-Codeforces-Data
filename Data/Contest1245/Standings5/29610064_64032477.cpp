#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 4005
typedef long long lld;
const int INF = 2000000000;
class IO {
    const static int IN_LEN = 100000;
    const static int OUT_LEN = 100000;
    const static int goodbit = 0;
    const static int endoffile = EOF;
    char buf[IN_LEN], pbuf[OUT_LEN],*p1, *p2, *pp;
    int state;
public:
    IO(){
        p1 = buf,p2 = buf,pp = pbuf;
        state = goodbit;
    }
    ~IO(){
        finish();
    }
    inline char GetChar() {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, IN_LEN, stdin), p1 == p2) ? (state = endoffile) : *p1++;
    }
    IO& operator >> (char& v){
        v = GetChar();
        return *this;
    }
    IO& operator >> (int& v){
        char ch = GetChar();
        int sum = 0, tag = 1;
        while (ch < '0' || ch > '9') {
            if(ch == EOF) return *this;
            if (ch == '-') tag = -1;
            ch = GetChar();
        }
        while (ch >= '0' && ch <= '9')sum = sum * 10 + ch - 48, ch = GetChar();
        v = sum * tag;
        return *this;
    }
    IO& operator >> (char* buffer){
        char ch = GetChar();
        int k = 0;
        while(ch != '\n' && ch != EOF && ch != ' '){
            buffer[k++] = ch;
            ch = GetChar();
        }
        buffer[k] = 0;
        return *this;
    }
    inline int getline(char* buffer){
        char ch = GetChar();
        int k = 0;
        while(ch != '\n' && ch != EOF){
            buffer[k++] = ch;
            ch = GetChar();
        }
        buffer[k] = 0;
        return k;
    }
    IO& operator << (char c){
        PutChar(c);
        return *this;
    }
    IO& operator << (int x){
        if (x < 0) x = -x, PutChar('-');
        static int sta[35];
        int top = 0;
        do { sta[top++] = x % 10, x /= 10; } while (x);
        while (top) PutChar(sta[--top] + '0');
        return *this;
    }
    IO& operator << (lld x){
        if (x < 0) x = -x, PutChar('-');
        static int sta[65];
        int top = 0;
        do { sta[top++] = x % 10, x /= 10; } while (x);
        while (top) PutChar(sta[--top] + '0');
        return *this;
    }
    IO& operator << (char* s){
        while(*s) PutChar(*s++);
        return *this;
    }
    explicit operator bool() const {
        return state == goodbit;
    }
    void PutChar(const char c) {
        if (pp - pbuf == OUT_LEN) fwrite(pbuf, 1, OUT_LEN, stdout), pp = pbuf;
        *pp++ = c;
    }
    void finish() {
        fwrite(pbuf, 1, pp - pbuf, stdout);
    }
}io;
struct dat{
    int x,y,c,k;
}dts[MAXN];
struct edge{
    int u,v;
}e[MAXN];
int n;
lld dis[MAXN];
int mnu[MAXN];
int vis[MAXN];
int mk[MAXN],pcnt;
int main(){
    //freopen("data.in","r",stdin);
    io >> n;
    for(int i = 1;i <= n;++i){
        io >> dts[i].x >> dts[i].y;
    }
    for(int i = 1;i <= n;++i){
        io >> dts[i].c;
    }
    for(int i = 1;i <= n;++i){
        io >> dts[i].k;
    }
    int ecnt = 0;
    for(int i = 1;i <= n;++i){
        dis[i] = dts[i].c;
        mnu[i] = 0;
        vis[i] = 0;
        mk[i] = 0;
    }
    lld ans = 0;
    for(int i = 1;i <= n;++i){
        int mnid = -1;
        for(int j = 1;j <= n;++j){
            if(!vis[j]){
                if(mnid == -1) mnid = j;
                else if(dis[j] < dis[mnid]) mnid = j;
            }
        }
        e[++ecnt] = {mnu[mnid],mnid};
        if(mnu[mnid] == 0) mk[mnid] = 1,++pcnt;
        ans += dis[mnid];
        vis[mnid] = 1;
        for(int j = 1;j <= n;++j){
            if(!vis[j]){
                lld len = abs(dts[mnid].x - dts[j].x) + (lld)abs(dts[mnid].y - dts[j].y);
                lld nowv = (dts[mnid].k + (lld)dts[j].k) * len;
                if(dis[j] > nowv){
                    dis[j] = nowv;
                    mnu[j] = mnid;
                }
            }
        }
    }
    io << ans << '\n';
    io << pcnt << '\n';
    for(int i = 1;i <= n;++i){
        if(mk[i]) io << i << ' ';
    }
    io << '\n';
    io << ecnt - pcnt << '\n';
    for(int i = 1;i <= ecnt;++i){
        if(e[i].u == 0 || e[i].v == 0) continue;
        io << e[i].u <<' ' << e[i].v << '\n';
    }
    return 0;
}