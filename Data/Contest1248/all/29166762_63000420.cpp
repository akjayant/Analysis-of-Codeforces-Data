/*

Nasha rozpovid pro yizhachka
Pro malenkogo necluhnanogo
Yak spitkala malogo bida
Vzhe ne zhvavogo ne rumanogo
� ����� �� ������ ������
�����, �������, ������, ����
�� ������ ��������� ����
�� ��������� ������������

������! ϳ������, ��������!
������! ����� � ���� ���������!
������! �������� ��������!
������! ������!

��� �� ������������� � ����
� ������� ���� ��� �����
�� ������� ����, �� �����
��� �� ���� � ��� ������

*/

#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio();cin.tie();cout.tie();
#define ops cout<<"ops"<<endl;

#define DIM 100007
#define DIMM 10007
#define INF 100000000000000007.0
#define X 10000
#define MODULO 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pllll;
typedef string str;
typedef char cr;

ll n,m;
ll z;
ll a[DIM],p[DIM];

int main()
{
    fast;
    //ll x1,y1,x2,y2;

    cin>>n>>m;
    z=max(n,m)+1;
    a[1]=2;a[2]=2;
    p[1]=2;p[2]=4;
    for(int i=3;i<=z;i++){
     a[i]=(a[i-1]+a[i-2])%MODULO;
     p[i]=(p[i-1]+a[i])%MODULO;
    }
    cout<<(p[n-1]+a[m+1])%MODULO<<endl;
    return 0;
}


