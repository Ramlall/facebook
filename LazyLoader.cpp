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
// Lazy Loading
// https://www.facebook.com/hackercup/problem/169401886867367/


void solve() 
	{
	// Read number of boxes
	int n; cin >> n;
	
	// Declare an array of this size
	int array[n];
	
	// Read in the weights of the boxes
	for(int i = 0; i < n; i++)
		{
		int temp; cin >> temp;
		array[i] = temp;
		}
	
	// Debug - Output Array before
	//for(int i = 0; i < n; i++) { cout << array[i] << " "; } cout << endl;
	
	// Sort the array
	sort(array, array + n);

	// Debug - Output Array after
	//for(int i = 0; i < n; i++) { cout << array[i] << " "; } cout << endl;	
	
	// Go from last to beginning of array
	int maxmoves = 0;
	int beginning = 0;
	for(int i = n-1; i >= 0; i--)
		{
		int weight = array[i];
		
		// If the weight is bigger than 50, add to maxmoves and move on
		if(weight >= 50) { maxmoves += 1; continue; }
		
		// The weight is smaller than 50 so check how many of these boxes we'll need minimum.
		double numerator = 50;
		double denom = weight;
		int minNumOfBoxes = ceil(numerator/denom);
		
		// We'll take this box, and minNumofBoxes-1 from the smallest in the beginning of the array.
		beginning += minNumOfBoxes - 1;
		
		// If the beginning is greater than or equal to i, we don't have enough boxes. Break.
		if(beginning > i) { break; }
		// Otherwise add one to maxmoves and we'll check the next largest box
		maxmoves += 1;
		
		}
	
	// Output answer;
	cout << maxmoves << endl;
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
