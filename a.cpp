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

void solve() 
	{
	// Read in the number.
	int n;
	cin >> n;

	// Convert number to string
	std::string s = to_string(n);
	
	// If the number is one digit long, just return that
	if(s.length() == 1)
		{ cout << n << " " << n << endl; return; }
	
	
	// Variables 
	int biggest = n;
	int smallest = n;


	// O(N^3) way
	// Try all possible numbers omg fkin noob	
	for(int i = 0; i < s.length()-1; i++)
		{
		for(int j = i+1; j < s.length(); j++)
			{
			// Get this new number as a string
			string news = "";
			for(int k = 0; k < s.length(); k++)
				{
				if(k == i)
					{ news += s[j]; }
				else if(k == j)
					{ news += s[i]; }
				else
					{ news += s[k]; }
				}

			int newn = stoi(news);	

			// Check if this is new biggest
			if(newn > biggest) { biggest = newn; }
			// Check if this is new smallest
			if(newn < smallest) 
				{ 
				// If we're on the first digit and s[j] is 0, do nothing
				if(news[0] != '0')
					{ smallest = newn; }
				}
			}
		}


	// Output answers
	cout << smallest << " " << biggest << endl;
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
