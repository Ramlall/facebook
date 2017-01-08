#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const int INF = (int)1e9;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

// Hacker Cup 2017 Round: Q
// Progress Pie
// https://www.facebook.com/hackercup/problem/1254819954559001/


void solve() 
	{
	// Read input.
	int p; cin >> p;
	int x; cin >> x;
	int y; cin >> y;
	
	/// Preliminary cases 
	// If the p is zero, just output white
	if(p == 0) { cout << "white" << endl; return; }
	
	// (50, 50) is valid
	if(x == 50 && y == 50) { cout << "black" << endl; return; }
	
	// Calculate the distance between (x,y) and the center (50,50)
	double distance = sqrt( pow(x-50, 2) + pow(y-50, 2) );
	
	// If the distance is bigger than 50, the point is never inside circle range
	if(distance > 50) { cout << "white" << endl; return; }
	
	// Otherwise, this point is inside the circle's range.
	
	// Determine which quadrant the point is in. 
	int quadrant = 0;
	
	if(x < 50 && y >= 50) { quadrant = 2; }
	if(x < 50 && y < 50) { quadrant = 3; }
	if(x >= 50 && y < 50) { quadrant = 4; }
	if(x >= 50 && y >= 50) { quadrant = 1; }
	
	// Depending on the quadrant, calculate the degrees the point would be at if the circle
	// were formed around it
	double xydegrees = -1;
	double a, b; // The adjusted point of (x,y) compared to the center for our triangle
	double alpha; // The angle of our triangle in the quadrant, for height b, width a
	
	// Calculate the degrees.
	// Quadrant one is top right.
	if(quadrant == 1)
		{
		a = x - 50;
		b = y - 50;
		alpha = atan(b/a) * 180/pi;
		xydegrees = 90-alpha;
		}
	// Quadrant 2 is top left.
	if(quadrant == 2)
		{
		a = 50 - x;
		b = y - 50;
		alpha = atan(b/a) * 180/pi;
		xydegrees = 270 + alpha;
		}
	// Quadrant 3 is bottom left.
	if(quadrant == 3)
		{
		a = 50 - x;
		b = 50 - y;
		alpha = atan(b/a) * 180/pi;
		xydegrees = 180 + (90 - alpha);
		}
	// Quadrant 4 is bottom right.		
	if(quadrant == 4)
		{
		a = x - 50;
		b = 50 - y;
		alpha = atan(b/a) * 180/pi;
		xydegrees = 90 + alpha;
		}
		
	// Get the degrees our P suggests
	double pAsDouble = p;
	double pdegrees = (pAsDouble/100) * 360; // The relative percent * 360 degrees
	
	// Debug - output both degrees
	//cout << "xydegrees: " << xydegrees << " pdegrees: " << pdegrees << endl;
	
	// If the point's degrees is bigger or equal to xydegrees, then it's in the circle
	if(pdegrees >= xydegrees) { cout << "black" << endl; }
	else { cout << "white" << endl; }
		
	}

int main() 
	{
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);

	freopen("input.txt", "r", stdin);
	freopen("answer.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) 
		{
		printf("Case #%d: ",tt);
		solve();
		
		}
	return 0;
	}
