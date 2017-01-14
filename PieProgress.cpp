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
// Problem: PieProgress
// URL: https://www.facebook.com/hackercup/problem/1800890323482794/
// Linux command to run this: g++ PieProgress.cpp -o main

/*
Logic:
0. Read input N and M.
1. Keep a vector that stores the minimum price you pay for a pie for each day.
2. Read in each day's pie prices.
	3. Sort the prices for that day.
	4. Adjust the prices to include tax.
	5. Go through the current and each following day and check if today's pies is cheaper.
		6. If it is cheaper...insert it into the current spot, remove the last spot, and move on to the next of today's pies.
*/


// This solve function gets called every test case. 
// Output to cout the answer for just the case, no "Case #1: " stuff. (Include and end line.)
void solve() 
	{
	// Read input N and M.
	int n; cin >> n;
	int m; cin >> m;
	
	// An array holding the min cost of a pie to be eating on the ith day
	vector<int> dailypies;
	// Initialize to a max value
	for(int i = 0; i < n; i++) { dailypies.push_back(INF); }
	
	// Read in each day.
	for(int i = 0; i < n; i++)
		{
		// A vector with the M pies for this day.
		int todayspies[m];
		
		// Read in those M pies.
		for(int j = 0; j < m; j++)
			{
			int temp; cin >> temp;
			todayspies[j] = temp;
			}
			
		// Sort today's pies from cheapest to most expensive.
		sort(todayspies, todayspies + m);
		
		// Go through each pie and adjust the cost by adding p-squared (relavent to it's specific cost)
		for(int p = 1; p <= m; p++)
			{
			todayspies[p-1] += (p*p) - ((p-1)*(p-1));
			}
			
		// Go through each pie and see if it's the cheapest available for the coming days.
		int mcount = 0; // Make sure we don't go past m.
		for(int j = i; j < n && mcount < m; j++) 
			{
			// If today's pie is cheaper than the daily pie of this day
			if(todayspies[mcount] < dailypies[j])
				{ 
				// Insert this pie into our daily lineup.
				dailypies.insert(dailypies.begin() + j, todayspies[mcount]);
				// Remove the pie in the last spot since it got edged out.
				dailypies.erase(dailypies.begin() + n);
				mcount += 1; // Increment mcount to test the next of today's pies
				} 
			}
		}
	
	// Get the minimum price by summing the prices in dailypies.
	long long min = 0;
	for(int i = 0; i < n; i++)
		{ 
		// Debug
		//if(i == 0) { cout << "Min prices for each day: "; } cout << dailypies[i] << " "; if(i == n-1) {cout << endl;}
		min += dailypies[i]; 
		}
	
	// Output the minimum price.
	cout << min << endl;
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
