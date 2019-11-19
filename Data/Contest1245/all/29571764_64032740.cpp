
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<algorithm>

#define inc(i, a, b) for (register int i = (a); i <= (b); ++i)
#define dec(i, a, b) for (register int i = (a); i >= (b); --i)
#define ll long long
#define ri register int
#define PB push_back
#define MP(A, B) make_pair(A, B)

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
const double pi = acos(-1.0);  //高精度圆周率
const double eps = 1e-8;       //偏差值
const int maxp = 1010;         //点的数量
int sgn(double x)
{            //判断x是否等于0
	if (fabs(x) < eps)
		return 0;
	else
		return x < 0 ? -1 : 1;
}
int Dcmp(double x, double y)
{  //比较两个浮点数：0 相等；-1 小于；1 大于
	if (fabs(x - y) < eps)
		return 0;
	else
		return x < y ? -1 : 1;
}
//---------------平面几何：点和线--------
struct Point
{  //定义点和基本运算
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
	}  //长度增大k倍
	Point operator/(double k)
	{
		return Point(x / k, y / k);
	}  //长度缩小k倍
	bool operator==(Point B)
	{
		return sgn(x - B.x) == 0 && sgn(y - B.y) == 0;
	}
	bool operator<(Point B)
	{
		return sgn(x - B.x) < 0 || (sgn(x - B.x) == 0 && sgn(y - B.y) < 0);
	}  //用于凸包
};
typedef Point Vector;                                             //定义向量
double Dot(Vector A, Vector B)
{
	return A.x * B.x + A.y * B.y;
}  //点积
double Len(Vector A)
{
	return sqrt(Dot(A, A));
}  //向量的长度
double Len2(Vector A)
{
	return Dot(A, A);
}       //向量长度的平方
double Angle(Vector A, Vector B)
{
	return acos(Dot(A, B) / Len(A) / Len(B));
}  // A与B的夹角
double Cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}  //叉积
double Area2(Point A, Point B, Point C)
{
	return Cross(B - A, C - A);
}  //三角形ABC面积的2倍
double Distance(Point A, Point B)
{
	return hypot(A.x - B.x, A.y - B.y);
}  //两点的距离
double Dist(Point A, Point B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
Vector Normal(Vector A)
{
	return Vector(-A.y / Len(A), A.x / Len(A));
}  //向量A的单位法向量

bool Parallel(Vector A, Vector B)
{
	return sgn(Cross(A, B)) == 0;
}  //向量平行或重合)

Vector Rotate(Vector A, double rad)
{  //向量A逆时针旋转rad度
	return Vector(A.x * cos(rad) - A.y * sin(rad),
		A.x * sin(rad) + A.y * cos(rad));
}

struct Line
{
	Point p1, p2;  //线上的两个点
	Line()
	{
	}
	Line(Point p1, Point p2) : p1(p1), p2(p2)
	{
	}
	// Line(Point x,Point y){p1 = x;p2 = y;}
	//  Point(double x,double y):x(x),y(y){}
	//根据一个点和倾斜角 angle 确定直线,0<=angle<pi
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

typedef Line Segment;  //定义线段，两端点是Point p1,p2

//返回直线倾斜角 0<=angle<pi
double Line_angle(Line v)
{
	double k = atan2(v.p2.y - v.p1.y, v.p2.x - v.p1.x);
	if (sgn(k) < 0) k += pi;
	if (sgn(k - pi) == 0) k -= pi;
	return k;
}
//点和直线关系:1 在左侧;2 在右侧;0 在直线上
int Point_line_relation(Point p, Line v)
{
	int c = sgn(Cross(p - v.p1, v.p2 - v.p1));
	if (c < 0) return 1;  // 1：p在v的左边
	if (c > 0) return 2;  // 2：p在v的右边
	return 0;             // 0：p在v上
}
// 点和线段的关系：0 点p不在线段v上；1 点p在线段v上。
bool Point_on_seg(Point p, Line v)
{
	return sgn(Cross(p - v.p1, v.p2 - v.p1)) == 0 &&
		sgn(Dot(p - v.p1, p - v.p2)) <= 0;
}

//两直线关系:0 平行,1 重合,2 相交
int Line_relation(Line v1, Line v2)
{
	if (sgn(Cross(v1.p2 - v1.p1, v2.p2 - v2.p1)) == 0)
	{
		if (Point_line_relation(v1.p1, v2) == 0)
			return 1;  // 1 重合
		else
			return 0;  // 0 平行
	}
	return 2;  // 2 相交
}

//点到直线的距离
double Dis_point_line(Point p, Line v)
{
	return fabs(Cross(p - v.p1, v.p2 - v.p1)) / Distance(v.p1, v.p2);
}

//点在直线上的投影
Point Point_line_proj(Point p, Line v)
{
	double k = Dot(v.p2 - v.p1, p - v.p1) / Len2(v.p2 - v.p1);
	return v.p1 + (v.p2 - v.p1) * k;
}

//点p对直线v的对称点
Point Point_line_symmetry(Point p, Line v)
{
	Point q = Point_line_proj(p, v);
	return Point(2 * q.x - p.x, 2 * q.y - p.y);
}


//求两直线ab和cd的交点
//调用前要保证两直线不平行或重合
Point Cross_point(Point a, Point b, Point c, Point d)
{  // Line1:ab,  Line2:cd
	double s1 = Cross(b - a, c - a);
	double s2 = Cross(b - a, d - a);  //叉积有正负
	return Point(c.x * s2 - d.x * s1, c.y * s2 - d.y * s1) / (s2 - s1);
}
//两线段是否相交：1 相交，0不相交
bool Cross_segment(Point a, Point b, Point c, Point d)
{  // Line1:ab,  Line2:cd
	double c1 = Cross(b - a, c - a), c2 = Cross(b - a, d - a);
	double d1 = Cross(d - c, a - c), d2 = Cross(d - c, b - c);
	return sgn(c1) * sgn(c2) < 0 &&
		sgn(d1) * sgn(d2) < 0;  //注意交点是端点的情况不算在内
}
//---------------平面几何：多边形----------------
struct Polygon
{
	int n;          //多边形的顶点数
	Point p[maxp];  //多边形的点
	Line v[maxp];   //多边形的边
};
//判断点和任意多边形的关系: 3 点上; 2 边上; 1 内部; 0 外部
int Point_in_polygon(Point pt, Point* p, int n)
{  //点pt，多边形Point *p
	for (int i = 0; i < n; i++)
	{                    //点在多边形的顶点上
		if (p[i] == pt) return 3;
	}
	for (int i = 0; i < n; i++)
	{  //点在多边形的边上
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
	return num != 0;  // 1 内部; 0 外部
}

double Polygon_area(Point* p,
	int n)
{  // Point *p表示多边形。从原点开始划分三角形
	double area = 0;
	for (int i = 0; i < n; i++) area += Cross(p[i], p[(i + 1) % n]);
	return area / 2;  //面积有正负，不能简单地取绝对值
}

Point Polygon_center(Point* p, int n)
{  //求多边形重心。Point *p表示多边形。
	Point ans(0, 0);
	if (Polygon_area(p, n) == 0) return ans;
	for (int i = 0; i < n; i++)
		ans = ans +
		(p[i] + p[(i + 1) % n]) * Cross(p[i], p[(i + 1) % n]);  //面积有正负
	return ans / Polygon_area(p, n) / 6.;
}


//---------------平面几何：圆----------------
struct Circle
{
	Point c;   //圆心
	double r;  //半径
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

//点和圆的关系: 0 点在圆内, 1 圆上, 2 圆外.
int Point_circle_relation(Point p, Circle C)
{
	double dst = Distance(p, C.c);
	if (sgn(dst - C.r) < 0) return 0;   //点在圆内
	if (sgn(dst - C.r) == 0) return 1;  //圆上
	return 2;                           //圆外
}

//直线和圆的关系：0 直线在圆内, 1 直线和圆相切, 2 直线在圆外
int Line_circle_relation(Line v, Circle C)
{
	double dst = Dis_point_line(C.c, v);
	if (sgn(dst - C.r) < 0) return 0;   //直线在圆内
	if (sgn(dst - C.r) == 0) return 1;  //直线和圆相切
	return 2;                           //直线在圆外
}



//直线和圆的交点   hdu 5572
int Line_cross_circle(Line v, Circle C, Point& pa,
	Point& pb)
{  // pa, pb是交点。返回值是交点个数
	if (Line_circle_relation(v, C) == 2) return 0;  //无交点
	Point q = Point_line_proj(C.c, v);   //圆心在直线上的投影点
	double d = Dis_point_line(C.c, v);   //圆心到直线的距离
	double k = sqrt(C.r * C.r - d * d);  //
	if (sgn(k) == 0)
	{                   // 1个交点，直线和圆相切
		pa = q;
		pb = q;
		return 1;
	}
	Point n = (v.p2 - v.p1) / Len(v.p2 - v.p1);  //单位向量
	pa = q + n * k;
	pb = q - n * k;
	return 2;  // 2个交点
}

//-------------------三维几何----------------
//三维：点
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
//点积。和二维点积函数同名。C++允许函数同名。
double Dot(Vector3 A, Vector3 B)
{
	return A.x * B.x + A.y * B.y + A.z * B.z;
}
//叉积
Vector3 Cross(Vector3 A, Vector3 B)
{
	return Point3(A.y * B.z - A.z * B.y, A.z * B.x - A.x * B.z,
		A.x * B.y - A.y * B.x);
}
double Len(Vector3 A)
{
	return sqrt(Dot(A, A));
}  //向量的长度
double Len2(Vector3 A)
{
	return Dot(A, A);
}       //向量长度的平方
double Distance(Point3 A, Point3 B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) +
		(A.z - B.z) * (A.z - B.z));
}
double Angle(Vector3 A, Vector3 B)
{
	return acos(Dot(A, B) / Len(A) / Len(B));
}  // A与B的夹角
//三维：线
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
typedef Line3 Segment3;  //定义线段，两端点是Point p1,p2

//三角形面积的2倍
double Area2(Point3 A, Point3 B, Point3 C)
{
	return Len(Cross(B - A, C - A));
}

//三维：点到直线距离
double Dis_point_line(Point3 p, Line3 v)
{
	return Len(Cross(v.p2 - v.p1, p - v.p1)) / Distance(v.p1, v.p2);
}

//三维：点在直线上
bool Point_line_relation(Point3 p, Line3 v)
{
	return sgn(Len(Cross(v.p1 - p, v.p2 - p))) == 0 &&
		sgn(Dot(v.p1 - p, v.p2 - p)) == 0;
}

//三维：点 p 在直线上的投影
Point3 Point_line_proj(Point3 p, Line3 v)
{
	double k = Dot(v.p2 - v.p1, p - v.p1) / Len2(v.p2 - v.p1);
	return v.p1 + (v.p2 - v.p1) * k;
}
//三维：平面
struct Plane
{
	Point3 p1, p2, p3;  //平面上的三个点
	Plane()
	{
	}
	Plane(Point3 p1, Point3 p2, Point3 p3) : p1(p1), p2(p2), p3(p3)
	{
	}
};
//平面法向量
Point3 Pvec(Point3 A, Point3 B, Point3 C)
{
	return Cross(B - A, C - A);
}
Point3 Pvec(Plane f)
{
	return Cross(f.p2 - f.p1, f.p3 - f.p1);
}
//四点共平面
bool Point_on_plane(Point3 A, Point3 B, Point3 C, Point3 D)
{
	return sgn(Dot(Pvec(A, B, C), D - A)) == 0;
}
//两平面平行
int Parallel(Plane f1, Plane f2)
{
	return Len(Cross(Pvec(f1), Pvec(f2))) < eps;
}
//两平面垂直
int Vertical(Plane f1, Plane f2)
{
	return sgn(Dot(Pvec(f1), Pvec(f2))) == 0;
}
//直线与平面的交点p，返回值是交点个数  ???
int Line_cross_plane(Line3 u, Plane f, Point3& p)
{
	Point3 v = Pvec(f);
	double x = Dot(v, u.p2 - f.p1);
	double y = Dot(v, u.p1 - f.p1);
	double d = x - y;
	if (sgn(x) == 0 && sgn(y) == 0) return -1;  //-1：v在f上
	if (sgn(d) == 0) return 0;                  // 0：v与f平行
	p = ((u.p1 * x) - (u.p2 * y)) / d;          // v与f相交
	return 1;
}

//四面体有向体积*6
double volume4(Point3 A, Point3 B, Point3 C, Point3 D)
{
	return Dot(Cross(B - A, C - A), D - A);
}
typedef long long LL;
using namespace std;
#define MAXN 500666
#define eps (1e-11)
#define pp 1000000007
#define pRR pair<int,int>
#define int LL

int c[MAXN];
int n;
int k[MAXN];
pRR psssi[MAXN];
int mmmkans[MAXN][2];
int oopans[MAXN];
int vis[MAXN];
int cntt1 ;
int cntt2;
int tmpp[MAXN];

struct cmp
{
	bool operator ()(int& a, int& b)
	{
		return c[a] > c[b];
	}
};

priority_queue<int, vector<int>, cmp> q;

int zdzdd()
{
	int minn = LLONG_MAX;
	int ind = 0;
	inc(i,1,n)
	{
		if (!vis[i])
		{
			if (minn >= c[i])
			{
				ind = i;
				minn = c[i];
			}
		}
	}
	return ind;
}

int hffff(int i, int j)
{
	int dis = abs(psssi[i].first - psssi[j].first) + abs(psssi[i].second - psssi[j].second);
	return dis * (k[i] + k[j]);
}

void NewFunction()
{
	n = gll();

	inc(i, 1, n)
	{
		int x, y;
		x = gll(), y = gll();
		psssi[i].first = x; psssi[i].second = y;
	}
	inc(i, 1, n) scanf("%I64d", &c[i]);
	inc(i, 1, n) scanf("%I64d", &k[i]);
	inc(i, 1, n) q.push(i);
}

void NewFunction(LL& sanasn, LL& cnttttq)
{
	int now = zdzdd();
	int tmp = c[now];
	bool flag = false;
	int tmpind = 0;
	inc(i, 1, n)
	{
		if (vis[i])
		{
			if (tmp > hffff(i, now))
			{
				flag = true;
				tmp = hffff(i, now);
				tmpind = i;
			}
		}
	}
	if ((!flag) && tmpp[now] == 0)
	{
		oopans[cntt1++] = now;
	}
	else
	{
		if (!flag)
		{
			mmmkans[cntt2][0] = now;
			mmmkans[cntt2][1] = tmpp[now];
			cntt2 += 1;
		}
		else
		{
			mmmkans[cntt2][0] = now;
			mmmkans[cntt2][1] = tmpind;
			cntt2 += 1;
		}
	}
	inc(i, 1, n)
	{
		if (!vis[i])
		{
			if (c[i] > hffff(i, now))tmpp[i] = now;
			c[i] = min(c[i], hffff(i, now));
		}
	}
	vis[now] = true;
	sanasn += tmp;
	cnttttq += 1;
}

void NewFunction222(const LL& sanasn)
{
	pllln(sanasn);
	pllln(cntt1);
	inc(i, 0, cntt1 - 1)
	{
		printf("%I64d ", oopans[i]);
	}
	printf("\n");
	printf("%I64d\n", cntt2);
	inc(i, 0, cntt2 - 1)
	{
		printf("%I64d %I64d\n", mmmkans[i][0], mmmkans[i][1]);
	}
}
int sanasn , cnttttq ;
signed main()
{
	
	NewFunction();
	
	for(;cnttttq < n;)
	{
		NewFunction(sanasn, cnttttq);
	}

	NewFunction222(sanasn);
}