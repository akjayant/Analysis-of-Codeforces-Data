#define _CRT_SECURE_NO_WARNINGS  
#include<bits/stdc++.h>
using namespace std;
//^[ \t]*//[^\n]*\n
#define inc(i, a, b) for (register int i = (a); i <= (b); ++i)
#define dec(i, a, b) for (register int i = (a); i >= (b); --i)
#define ll long long
#define ri register int
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define M(x) (((x) + mod) % mod)
#define pii pair<int, int>
#define mii map<int, int>
inline int gint()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
inline ll gll()
{
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
inline void pint(int x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	int y = 10, len = 1;
	while (y <= x)
	{
		y = (y << 3) + (y << 1);
		len++;
	}
	while (len--)
	{
		y /= 10;
		putchar(x / y + 48);
		x %= y;
	}
}
inline void pll(ll x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	ll y = 10, len = 1;
	while (y <= x)
	{
		y = (y << 3) + (y << 1);
		len++;
	}
	while (len--)
	{
		y /= 10;
		putchar(x / y + 48);
		x %= y;
	}
}
inline void pintln(int x)
{
	pint(x);
	putchar('\n');
}
inline void pllln(ll x)
{
	pll(x);
	putchar('\n');
}
const double pi = acos(-1.0);  //�߾���Բ����
const double eps = 1e-8;       //ƫ��ֵ
const int maxp = 1010;         //�������
int sgn(double x)
{            //�ж�x�Ƿ����0
	if (fabs(x) < eps)
		return 0;
	else
		return x < 0 ? -1 : 1;
}
int Dcmp(double x, double y)
{  //�Ƚ�������������0 ��ȣ�-1 С�ڣ�1 ����
	if (fabs(x - y) < eps)
		return 0;
	else
		return x < y ? -1 : 1;
}
//---------------ƽ�漸�Σ������--------
struct Point
{  //�����ͻ�������
	double x, y;
	Point()
	{
	}
	Point(double x, double y) : x(x), y(y)
	{
	}
	Point operator+(Point B)
	{
		return Point(x + B.x, y + B.y);
	}
	Point operator-(Point B)
	{
		return Point(x - B.x, y - B.y);
	}
	Point operator*(double k)
	{
		return Point(x * k, y * k);
	}  //��������k��
	Point operator/(double k)
	{
		return Point(x / k, y / k);
	}  //������Сk��
	bool operator==(Point B)
	{
		return sgn(x - B.x) == 0 && sgn(y - B.y) == 0;
	}
	bool operator<(Point B)
	{
		return sgn(x - B.x) < 0 || (sgn(x - B.x) == 0 && sgn(y - B.y) < 0);
	}  //����͹��
};
typedef Point Vector;                                             //��������
double Dot(Vector A, Vector B)
{
	return A.x * B.x + A.y * B.y;
}  //���
double Len(Vector A)
{
	return sqrt(Dot(A, A));
}  //�����ĳ���
double Len2(Vector A)
{
	return Dot(A, A);
}       //�������ȵ�ƽ��
double Angle(Vector A, Vector B)
{
	return acos(Dot(A, B) / Len(A) / Len(B));
}  // A��B�ļн�
double Cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}  //���
double Area2(Point A, Point B, Point C)
{
	return Cross(B - A, C - A);
}  //������ABC�����2��
double Distance(Point A, Point B)
{
	return hypot(A.x - B.x, A.y - B.y);
}  //����ľ���
double Dist(Point A, Point B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
Vector Normal(Vector A)
{
	return Vector(-A.y / Len(A), A.x / Len(A));
}  //����A�ĵ�λ������

bool Parallel(Vector A, Vector B)
{
	return sgn(Cross(A, B)) == 0;
}  //����ƽ�л��غ�)

Vector Rotate(Vector A, double rad)
{  //����A��ʱ����תrad��
	return Vector(A.x * cos(rad) - A.y * sin(rad),
		A.x * sin(rad) + A.y * cos(rad));
}

struct Line
{
	Point p1, p2;  //���ϵ�������
	Line()
	{
	}
	Line(Point p1, Point p2) : p1(p1), p2(p2)
	{
	}
	// Line(Point x,Point y){p1 = x;p2 = y;}
	//  Point(double x,double y):x(x),y(y){}
	//����һ�������б�� angle ȷ��ֱ��,0<=angle<pi
	Line(Point p, double angle)
	{
		p1 = p;
		if (sgn(angle - pi / 2) == 0)
		{
			p2 = (p1 + Point(0, 1));
		}
		else
		{
			p2 = (p1 + Point(1, tan(angle)));
		}
	}
	// ax+by+c=0
	Line(double a, double b, double c)
	{
		if (sgn(a) == 0)
		{
			p1 = Point(0, -c / b);
			p2 = Point(1, -c / b);
		}
		else if (sgn(b) == 0)
		{
			p1 = Point(-c / a, 0);
			p2 = Point(-c / a, 1);
		}
		else
		{
			p1 = Point(0, -c / b);
			p2 = Point(1, (-c - a) / b);
		}
	}
};

typedef Line Segment;  //�����߶Σ����˵���Point p1,p2

//����ֱ����б�� 0<=angle<pi
double Line_angle(Line v)
{
	double k = atan2(v.p2.y - v.p1.y, v.p2.x - v.p1.x);
	if (sgn(k) < 0) k += pi;
	if (sgn(k - pi) == 0) k -= pi;
	return k;
}
//���ֱ�߹�ϵ:1 �����;2 ���Ҳ�;0 ��ֱ����
int Point_line_relation(Point p, Line v)
{
	int c = sgn(Cross(p - v.p1, v.p2 - v.p1));
	if (c < 0) return 1;  // 1��p��v�����
	if (c > 0) return 2;  // 2��p��v���ұ�
	return 0;             // 0��p��v��
}
// ����߶εĹ�ϵ��0 ��p�����߶�v�ϣ�1 ��p���߶�v�ϡ�
bool Point_on_seg(Point p, Line v)
{
	return sgn(Cross(p - v.p1, v.p2 - v.p1)) == 0 &&
		sgn(Dot(p - v.p1, p - v.p2)) <= 0;
}

//��ֱ�߹�ϵ:0 ƽ��,1 �غ�,2 �ཻ
int Line_relation(Line v1, Line v2)
{
	if (sgn(Cross(v1.p2 - v1.p1, v2.p2 - v2.p1)) == 0)
	{
		if (Point_line_relation(v1.p1, v2) == 0)
			return 1;  // 1 �غ�
		else
			return 0;  // 0 ƽ��
	}
	return 2;  // 2 �ཻ
}

//�㵽ֱ�ߵľ���
double Dis_point_line(Point p, Line v)
{
	return fabs(Cross(p - v.p1, v.p2 - v.p1)) / Distance(v.p1, v.p2);
}

//����ֱ���ϵ�ͶӰ
Point Point_line_proj(Point p, Line v)
{
	double k = Dot(v.p2 - v.p1, p - v.p1) / Len2(v.p2 - v.p1);
	return v.p1 + (v.p2 - v.p1) * k;
}

//��p��ֱ��v�ĶԳƵ�
Point Point_line_symmetry(Point p, Line v)
{
	Point q = Point_line_proj(p, v);
	return Point(2 * q.x - p.x, 2 * q.y - p.y);
}

//�㵽�߶εľ���
double Dis_point_seg(Point p, Segment v)
{
	if (sgn(Dot(p - v.p1, v.p2 - v.p1)) < 0 ||
		sgn(Dot(p - v.p2, v.p1 - v.p2)) < 0)  //���ͶӰ�����߶���
		return min(Distance(p, v.p1), Distance(p, v.p2));
	return Dis_point_line(p, v);  //���ͶӰ���߶���
}

//����ֱ��ab��cd�Ľ���
//����ǰҪ��֤��ֱ�߲�ƽ�л��غ�
Point Cross_point(Point a, Point b, Point c, Point d)
{  // Line1:ab,  Line2:cd
	double s1 = Cross(b - a, c - a);
	double s2 = Cross(b - a, d - a);  //���������
	return Point(c.x * s2 - d.x * s1, c.y * s2 - d.y * s1) / (s2 - s1);
}
//���߶��Ƿ��ཻ��1 �ཻ��0���ཻ
bool Cross_segment(Point a, Point b, Point c, Point d)
{  // Line1:ab,  Line2:cd
	double c1 = Cross(b - a, c - a), c2 = Cross(b - a, d - a);
	double d1 = Cross(d - c, a - c), d2 = Cross(d - c, b - c);
	return sgn(c1) * sgn(c2) < 0 &&
		sgn(d1) * sgn(d2) < 0;  //ע�⽻���Ƕ˵�������������
}
//---------------ƽ�漸�Σ������----------------
struct Polygon
{
	int n;          //����εĶ�����
	Point p[maxp];  //����εĵ�
	Line v[maxp];   //����εı�
};
//�жϵ���������εĹ�ϵ: 3 ����; 2 ����; 1 �ڲ�; 0 �ⲿ
int Point_in_polygon(Point pt, Point* p, int n)
{  //��pt�������Point *p
	for (int i = 0; i < n; i++)
	{                    //���ڶ���εĶ�����
		if (p[i] == pt) return 3;
	}
	for (int i = 0; i < n; i++)
	{  //���ڶ���εı���
		Line v = Line(p[i], p[(i + 1) % n]);
		if (Point_on_seg(pt, v)) return 2;
	}
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		int j = (i + 1) % n;
		int c = sgn(Cross(pt - p[j], p[i] - p[j]));
		int u = sgn(p[i].y - pt.y);
		int v = sgn(p[j].y - pt.y);
		if (c > 0 && u < 0 && v >= 0) num++;
		if (c < 0 && u >= 0 && v < 0) num--;
	}
	return num != 0;  // 1 �ڲ�; 0 �ⲿ
}

double Polygon_area(Point* p,
	int n)
{  // Point *p��ʾ����Ρ���ԭ�㿪ʼ����������
	double area = 0;
	for (int i = 0; i < n; i++) area += Cross(p[i], p[(i + 1) % n]);
	return area / 2;  //��������������ܼ򵥵�ȡ����ֵ
}

Point Polygon_center(Point* p, int n)
{  //���������ġ�Point *p��ʾ����Ρ�
	Point ans(0, 0);
	if (Polygon_area(p, n) == 0) return ans;
	for (int i = 0; i < n; i++)
		ans = ans +
		(p[i] + p[(i + 1) % n]) * Cross(p[i], p[(i + 1) % n]);  //���������
	return ans / Polygon_area(p, n) / 6.;
}

// Convex_hull()��͹����͹���������ch�У�����ֵ��͹���Ķ�����
int Convex_hull(Point* p, int n, Point* ch)
{
	sort(p, p + n);  //�Ե����򣺰�x��С�����������x��ͬ����y����
	n = unique(p, p + n) - p;  //ȥ���ظ���
	int v = 0;
	//����͹�������p[i]���ҹ���ģ�����㲻��͹���ϣ�������
	for (int i = 0; i < n; i++)
	{
		while (v > 1 && sgn(Cross(ch[v - 1] - ch[v - 2], p[i] - ch[v - 2])) <= 0)
			v--;
		ch[v++] = p[i];
	}
	int j = v;
	//����͹��
	for (int i = n - 2; i >= 0; i--)
	{
		while (v > j&& sgn(Cross(ch[v - 1] - ch[v - 2], p[i] - ch[v - 2])) <= 0)
			v--;
		ch[v++] = p[i];
	}
	if (n > 1) v--;
	return v;  //����ֵv��͹���Ķ�����
}

//---------------ƽ�漸�Σ�Բ----------------
struct Circle
{
	Point c;   //Բ��
	double r;  //�뾶
	Circle()
	{
	}
	Circle(Point c, double r) : c(c), r(r)
	{
	}
	Circle(double x, double y, double _r)
	{
		c = Point(x, y);
		r = _r;
	}
};

//���Բ�Ĺ�ϵ: 0 ����Բ��, 1 Բ��, 2 Բ��.
int Point_circle_relation(Point p, Circle C)
{
	double dst = Distance(p, C.c);
	if (sgn(dst - C.r) < 0) return 0;   //����Բ��
	if (sgn(dst - C.r) == 0) return 1;  //Բ��
	return 2;                           //Բ��
}

//ֱ�ߺ�Բ�Ĺ�ϵ��0 ֱ����Բ��, 1 ֱ�ߺ�Բ����, 2 ֱ����Բ��
int Line_circle_relation(Line v, Circle C)
{
	double dst = Dis_point_line(C.c, v);
	if (sgn(dst - C.r) < 0) return 0;   //ֱ����Բ��
	if (sgn(dst - C.r) == 0) return 1;  //ֱ�ߺ�Բ����
	return 2;                           //ֱ����Բ��
}

//�߶κ�Բ�Ĺ�ϵ��0 �߶���Բ��, 1 �߶κ�Բ����, 2 �߶���Բ��
int Seg_circle_relation(Segment v, Circle C)
{
	double dst = Dis_point_seg(C.c, v);
	if (sgn(dst - C.r) < 0) return 0;   //�߶���Բ��
	if (sgn(dst - C.r) == 0) return 1;  //�߶κ�Բ����
	return 2;                           //�߶���Բ��
}

//ֱ�ߺ�Բ�Ľ���   hdu 5572
int Line_cross_circle(Line v, Circle C, Point& pa,
	Point& pb)
{  // pa, pb�ǽ��㡣����ֵ�ǽ������
	if (Line_circle_relation(v, C) == 2) return 0;  //�޽���
	Point q = Point_line_proj(C.c, v);   //Բ����ֱ���ϵ�ͶӰ��
	double d = Dis_point_line(C.c, v);   //Բ�ĵ�ֱ�ߵľ���
	double k = sqrt(C.r * C.r - d * d);  //
	if (sgn(k) == 0)
	{                   // 1�����㣬ֱ�ߺ�Բ����
		pa = q;
		pb = q;
		return 1;
	}
	Point n = (v.p2 - v.p1) / Len(v.p2 - v.p1);  //��λ����
	pa = q + n * k;
	pb = q - n * k;
	return 2;  // 2������
}

//-------------------��ά����----------------
//��ά����
struct Point3
{
	double x, y, z;
	Point3()
	{
	}
	Point3(double x, double y, double z) : x(x), y(y), z(z)
	{
	}
	Point3 operator+(Point3 B)
	{
		return Point3(x + B.x, y + B.y, z + B.z);
	}
	Point3 operator-(Point3 B)
	{
		return Point3(x - B.x, y - B.y, z - B.z);
	}
	Point3 operator*(double k)
	{
		return Point3(x * k, y * k, z * k);
	}
	Point3 operator/(double k)
	{
		return Point3(x / k, y / k, z / k);
	}
	bool operator==(Point3 B)
	{
		return sgn(x - B.x) == 0 && sgn(y - B.y) == 0 && sgn(z - B.z) == 0;
	}
};
typedef Point3 Vector3;
//������Ͷ�ά�������ͬ����C++������ͬ����
double Dot(Vector3 A, Vector3 B)
{
	return A.x * B.x + A.y * B.y + A.z * B.z;
}
//���
Vector3 Cross(Vector3 A, Vector3 B)
{
	return Point3(A.y * B.z - A.z * B.y, A.z * B.x - A.x * B.z,
		A.x * B.y - A.y * B.x);
}
double Len(Vector3 A)
{
	return sqrt(Dot(A, A));
}  //�����ĳ���
double Len2(Vector3 A)
{
	return Dot(A, A);
}       //�������ȵ�ƽ��
double Distance(Point3 A, Point3 B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) +
		(A.z - B.z) * (A.z - B.z));
}
double Angle(Vector3 A, Vector3 B)
{
	return acos(Dot(A, B) / Len(A) / Len(B));
}  // A��B�ļн�
//��ά����
struct Line3
{
	Point3 p1, p2;
	Line3()
	{
	}
	Line3(Point3 p1, Point3 p2) : p1(p1), p2(p2)
	{
	}
};
typedef Line3 Segment3;  //�����߶Σ����˵���Point p1,p2

//�����������2��
double Area2(Point3 A, Point3 B, Point3 C)
{
	return Len(Cross(B - A, C - A));
}

//��ά���㵽ֱ�߾���
double Dis_point_line(Point3 p, Line3 v)
{
	return Len(Cross(v.p2 - v.p1, p - v.p1)) / Distance(v.p1, v.p2);
}

//��ά������ֱ����
bool Point_line_relation(Point3 p, Line3 v)
{
	return sgn(Len(Cross(v.p1 - p, v.p2 - p))) == 0 &&
		sgn(Dot(v.p1 - p, v.p2 - p)) == 0;
}
//��ά���㵽�߶ξ��롣
double Dis_point_seg(Point3 p, Segment3 v)
{
	if (sgn(Dot(p - v.p1, v.p2 - v.p1)) < 0 ||
		sgn(Dot(p - v.p2, v.p1 - v.p2)) < 0)
		return min(Distance(p, v.p1), Distance(p, v.p2));
	return Dis_point_line(p, v);
}
//��ά���� p ��ֱ���ϵ�ͶӰ
Point3 Point_line_proj(Point3 p, Line3 v)
{
	double k = Dot(v.p2 - v.p1, p - v.p1) / Len2(v.p2 - v.p1);
	return v.p1 + (v.p2 - v.p1) * k;
}
//��ά��ƽ��
struct Plane
{
	Point3 p1, p2, p3;  //ƽ���ϵ�������
	Plane()
	{
	}
	Plane(Point3 p1, Point3 p2, Point3 p3) : p1(p1), p2(p2), p3(p3)
	{
	}
};
//ƽ�淨����
Point3 Pvec(Point3 A, Point3 B, Point3 C)
{
	return Cross(B - A, C - A);
}
Point3 Pvec(Plane f)
{
	return Cross(f.p2 - f.p1, f.p3 - f.p1);
}
//�ĵ㹲ƽ��
bool Point_on_plane(Point3 A, Point3 B, Point3 C, Point3 D)
{
	return sgn(Dot(Pvec(A, B, C), D - A)) == 0;
}
//��ƽ��ƽ��
int Parallel(Plane f1, Plane f2)
{
	return Len(Cross(Pvec(f1), Pvec(f2))) < eps;
}
//��ƽ�洹ֱ
int Vertical(Plane f1, Plane f2)
{
	return sgn(Dot(Pvec(f1), Pvec(f2))) == 0;
}
//ֱ����ƽ��Ľ���p������ֵ�ǽ������  ???
int Line_cross_plane(Line3 u, Plane f, Point3& p)
{
	Point3 v = Pvec(f);
	double x = Dot(v, u.p2 - f.p1);
	double y = Dot(v, u.p1 - f.p1);
	double d = x - y;
	if (sgn(x) == 0 && sgn(y) == 0) return -1;  //-1��v��f��
	if (sgn(d) == 0) return 0;                  // 0��v��fƽ��
	p = ((u.p1 * x) - (u.p2 * y)) / d;          // v��f�ཻ
	return 1;
}

//�������������*6
double volume4(Point3 A, Point3 B, Point3 C, Point3 D)
{
	return Dot(Cross(B - A, C - A), D - A);
}
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
const int MAXN = 300000;

char s[MAXN];
char ans[MAXN];
int a, b, c;

void fk(int i)
{
	if (a != 0)
	{
		printf("R");
		a-=1;
	}
	else if (b != 0)
	{
		printf("P");
		b-=1;
	}
	else if (c != 0)
	{
		printf("S");
		c-=1;
	}
}

void NewFunction()
{
	int n = gint();
	a = gint(), b = gint(), c = gint();
	scanf("%s", s);
	int count = 0;
	inc(i,0,n-1)
	{
		if (s[i] == 'R')
		{
			if (b)
			{
				b-=1;
				count+=1;
				ans[i] = 'P';
			}
			else
			{
				ans[i] = '*';
			}
		}
		else if (s[i] == 'P')
		{
			if (c)
			{
				c-=1;
				count+=1;
				ans[i] = 'S';
			}
			else
			{
				ans[i] = '*';
			}
		}
		else if (s[i] == 'S')
		{
			if (a)
			{
				a-=1;
				count+=1;
				ans[i] = 'R';
			}
			else ans[i] = '*';
		}
	}
	ans[n] = '\0';
	if (count < (n + 1) / 2)
	{
		puts("NO");
	}
	else
	{
		puts("YES");
		inc(i,0,n-1)
		{
			if (ans[i] != '*')printf("%c", ans[i]);
			else
			{
				fk(i);
			}
		}
		printf("\n");
	}
}

int  main()
{
	int t=gint();
	while (t--)
	{
		NewFunction();
	}
	return 0;
}