/***********************************************
 *                   _ooOoo_                   *
 *                  o8888888o                  *
 *                  88" . "88                  *
 *                  (| -_- |)                  *
 *                  O\  =  /O                  *
 *               ____/`---'\____               *
 *             .'  \\|     |//  `.             *
 *            /  \\|||  :  |||//  \            *
 *           /  _||||| -:- |||||-  \           *
 *           |   | \\\  -   * |    |           *
 *           | \_|  ''\---/''  |   |           *
 *           \  .-\__  `-`  ___/-. /           *
 *         ___`. .'  /--.--\  `. . __          *
 *      ."" '<  `.___\_<|>_/___.'  >'"".       *
 *     | | :  `- \`.;`\ _ /`;.`/ - ` : | |     *
 *     \  \ `-.   \_ __\ /__ _/   .-` /  /     *
 *======`-.____`-.___\_____/___.-`____.-'======*
 *                   `=---='                   *
 *^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

             佛祖保佑       永无BUG

   本程序已经经过开光处理，绝无可能再产生bug
 **********************************************/
#include<algorithm>
#include <iostream>
#include  <cstdlib>
#include  <cstring>
#include   <string>
#include   <vector>
#include   <cstdio>
#include    <queue>
#include    <stack>
#include    <ctime>
#include    <cmath>
#include      <map>
#include      <set>
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
#define mkp(a,b) make_pair(a,b)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define db1(x) cout<<#x<<"="<<(x)<<endl
#define db2(x,y) cout<<#x<<"="<<(x)<<", "<<#y<<"="<<(y)<<endl
#define db3(x,y,z) cout<<#x<<"="<<(x)<<", "<<#y<<"="<<(y)<<", "<<#z<<"="<<(z)<<endl
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[(1<<22)],*p1=buf,*p2=buf;
inline ll read(){
    char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
const int maxn=4005;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main(){
    #ifdef DanDan
    freopen("in.txt","r",stdin);
    //freopen("in.txt","w",stdout);
    clock_t start=clock();
    #endif //DanDan
    int t=read();
    while(t--){
        int a=read(),b=read();
        if(a==1){printf("Finite\n");continue;}
        if(a==b){printf("Infinite\n");continue;}
        if(gcd(a,b)==1){printf("Finite\n");}
        else {printf("Infinite\n");}
    }

    #ifdef DanDan
    clockid_t end=clock();
    double endtime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n\n\n\n\n");
    cout<<"Total time:"<<endtime<<"s"<<endl;        //s为单位
    cout<<"Total time:"<<endtime*1000<<"ms"<<endl;    //ms为单位
    #endif //DanDan
    return 0;
}


// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ????━????   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

