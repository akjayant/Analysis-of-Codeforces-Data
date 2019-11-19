#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#include <cstdio>//sprintf islower isupper
#include <cstdlib>//malloc  exit strcat itoa system("cls")
#include <iostream>//pair
#include <fstream>//freopen("C:\\Users\\13606\\Desktop\\草稿.txt","r",stdin);
#include <bitset>
//#include <map>
//#include<unordered_map>
#include <vector>
#include <stack>
#include <set>
#include <string.h>//strstr substr
#include <string>
#include <time.h>//srand(((unsigned)time(NULL))); Seed n=rand()%10 - 0~9;
#include <cmath>
#include <deque>
#include <queue>//priority_queue<int, vector<int>, greater<int> > q;//less
#include <vector>//emplace_back
//#include <math.h>
//#include <windows.h>//reverse(a,a+len);// ~ ! ~ ! floor
#include <algorithm>//sort + unique : sz=unique(b+1,b+n+1)-(b+1);+nth_element(first, nth, last, compare)
using namespace std;//next_permutation(a+1,a+1+n);//prev_permutation
//******************
int abss(int a);
int lowbit(int n);
int Del_bit_1(int n);
int maxx(int a,int b);
int minn(int a,int b);
double fabss(double a);
void swapp(int &a,int &b);
clock_t __STRAT,__END;
double __TOTALTIME;
void _MS(){__STRAT=clock();}
void _ME(){__END=clock();__TOTALTIME=(double)(__END-__STRAT)/CLOCKS_PER_SEC;cout<<"Time: "<<__TOTALTIME<<" s"<<endl;}
//***********************
#define rint register int
#define fo(a,b,c) for(rint a=b;a<=c;++a)
#define fr(a,b,c) for(rint a=b;a>=c;--a)
#define mem(a,b) memset(a,b,sizeof(a))
#define pr printf
#define sc scanf
#define ls rt<<1
#define rs rt<<1|1
typedef long long ll;
const double E=2.718281828;
const double PI=acos(-1.0);
//const ll INF=(1LL<<60);
const int inf=(1<<30);
const double ESP=1e-9;
const int mod=(int)1e9+7;
const int N=(int)1e6+10;

int a[N];

int main()
{
	int n;
	sc("%d",&n);
	for(int i=1;i<=n;++i)
		sc("%d",&a[i]);
	sort(a+1,a+1+n);
	int temp=n;
	n/=2;
	ll A=0,B=0;
	for(int i=1;i<=n;++i)
		A+=a[i];
	for(int i=n+1;i<=temp;++i)
		B+=a[i];
	pr("%lld\n",A*A+B*B);
	return 0;
}

/**************************************************************************************/

int maxx(int a,int b)
{
	return a>b?a:b;
}

void swapp(int &a,int &b)
{
	a^=b^=a^=b;
}

int lowbit(int n)
{
	return n&(-n);
}

int Del_bit_1(int n)
{
	return n&(n-1);
}

int abss(int a)
{
	return a>0?a:-a;
}

double fabss(double a)
{
	return a>0?a:-a;
}

int minn(int a,int b)
{
	return a<b?a:b;
}