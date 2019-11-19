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

ll n;
ll a[DIM];
ll sx,sy;

int main()
{
    fast;
    //ll x1,y1,x2,y2;

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=(n/2);i++)sx+=a[i];
    for(int i=n;i>(n/2);i--)sy+=a[i];
    cout<<sx*sx+sy*sy<<endl;
    return 0;
}


