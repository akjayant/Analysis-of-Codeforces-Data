///+----------------------------------------+\\\
///|   ___  __  __  ____  ____  ____  _  _  |\\\
///|  / __)(  )(  )(_  _)( ___)(_  _)( \( ) |\\\
///| ( (__  )(__)(   )(   )__)   )(   )  (  |\\\
///|  \___)(______) (__) (____) (__) (_)\_) |\\\
///|                                        |\\\
///+-----------------------QUẢN-TIẾN-NGHĨA--+\\\

/// Hạnh đáng iu
/// Hạnh dễ thưn

#include <bits/stdc++.h>
using namespace std;

/// OPTIMIZE SOMETHING I DONT EVEN UNDERSTAND
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/// USEFUL MACROS
#define endl '\n'
#define ff first
#define ss second
#define is ==
#define getMod(x) (x)%= modulo
#define szOf(container_) ((int)container_.size())
#define elif else if
#define RunTestCases int numberOfCases; read(numberOfCases); while(numberOfCases--)
#define forEach(element_, container_) for(auto&element_: container_)
    //forEach can not be used for static array
#define forUp(iterator_, rangeL_, rangeR_) for(ll iterator_ = rangeL_; iterator_ <= rangeR_; iterator_++)
#define forDown(iterator_, rangeR_, rangeL_) for(ll iterator_ = rangeR_; iterator_ >= rangeL_; iterator_--)
#define forTimes(times_) for(ll iterator_ = 1; iterator_ <= times_; iterator_++)
#define readNew(varName, type) type varName; read(varName)


/// FREQUENTLY USED TYPES
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

/// FREQUENTLY USED CONSTS
const ll modulo = ll(1e9 + 7);
const ll oo = (ll)1e18;
const double eps = 1e-6;
const double pi = (atan(1)*4);


/// FAST IO
const char* ELEMENT_SEPARATOR = " ";
const int POSITION_AFTER_DECIMAL = 6;
void print(int a)        { printf("%d"  , a); }
void print(long long a)  { printf("%lld", a); }
void print(char a)       { printf("%c"  , a); }
void print(char*a)       { printf("%s"  , a); }
void print(const char*a) { printf("%s"  , a); }
void print(string a)     { printf("%s"  , a.c_str()); }
void print(float a)      { string format = "%." + to_string(POSITION_AFTER_DECIMAL) + "f"; printf(format.c_str() , a); }
void print(double a)     { string format = "%." + to_string(POSITION_AFTER_DECIMAL) + "f"; printf(format.c_str() , a); }
void print(vector<auto> a)
{
    forEach(element,a)
    {
        print(element);
        print(ELEMENT_SEPARATOR);
    }
}
template<typename Type, typename... Args>
void print(Type a, Args... args)
{
    print(a);
    print(ELEMENT_SEPARATOR);
    print(args...);
}

void read(int&a)        { scanf("%d"   , &a); }
void read(long long&a)  { scanf("%lld" , &a); }
void read(float&a)      { scanf("%f"   , &a); }
void read(double&a)     { scanf("%lf"  , &a); }
void read(char&a)       { scanf("%c"   , &a); }
void read(char*a)       { scanf("%s"   , &a); }
void read(string&a)     { scanf("%s"   , &a); }
void read(vector<auto>&a)
{
    forEach(element, a)
        read(element);
}
template<typename Type, typename... Args>
void read(Type&a, Args&... args)
{
    read(a);
    read(args...);
}


/// INITIALIZE
void onStartMain()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\
/// ALGORITHM TEMPLATE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\


///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\
/// SOLUTION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\\


int main()
{
    onStartMain();

    RunTestCases
    {
        readNew(n, ll);
        ll o1=0, e1=0;
        forTimes(n)
        {
            readNew(x,ll);
            if(x&1)
                o1++;
            else
                e1++;
        }

        readNew(m, ll);
        ll o2=0, e2=0;
        forTimes(m)
        {
            readNew(x,ll);
            if(x&1)
                o2++;
            else
                e2++;
        }

        print(o1*o2 + e1*e2, endl);
    }

    return 0;
}

/// Hạnh đáng iu
/// Hạnh dễ thưn
