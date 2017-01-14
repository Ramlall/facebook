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

// Hacker Cup 2017 Round: 1
// Problem: Fighting The Zombies
// URL: https://www.facebook.com/hackercup/problem/235709883547573/
// Linux command to run this: g++ FightingTheZombies.cpp -o main


// This solve function gets called every test case. 
// Output to cout the answer for just the case, no "Case #1: " stuff. (Include and end line.)
void solve() 
	{
	// Read input N and R
	int n; cin >> n;
	long r; cin >> r;
	
	// Read each coordinate of the zombies.
	long xs[n]; 
	long ys[n];
	for(int i = 0; i < n; i++)
		{
		long x; cin >> x;
		long y; cin >> y;
		xs[i] = x;
		ys[i] = y;
		}
	
	// The max number of zombies we can kill.	
	int n = 0;
	
	// Output the number of zombies we can kill.
	cout << n << endl;
	}

// Main. Program starts here.
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
