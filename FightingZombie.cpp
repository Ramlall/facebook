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
// Fighting the Zombie
// https://www.facebook.com/hackercup/problem/326053454264498/


// Parse a spell (1d10+2) into the x, y, z and zmodifier referenced variables
void ParseSpellString(string &spell, int &x, int &y, int &z)
	{
	int zmodifier = 0; // -1 for -, 0 for no z, 1 for +z
	string xstring, ystring, zstring = "";
	bool foundd = false;
	bool foundz = false;
	for(int k = 0; k < spell.length(); k++)
		{
		// The current character in the spell string.
		char currentchar = spell[k];
		
		// Mark whether we're at a D, +, or - to check for X, Y, or Z
		if(currentchar == 'd')
			{ foundd = true; continue; }
		// Mark whether Z is found and if it's a + or -
		if(currentchar == '+' || currentchar == '-')
			{ 
			// Z modifier
			if (currentchar == '+') { zmodifier = 1; }
			if (currentchar == '-') { zmodifier = -1; }
			// Mark z as found and move to next char.
			foundz = true; continue; 
			}
		
		// Add char to X.
		if(foundd == false)
			{ xstring += currentchar; continue; }
		// Add char to Y.
		if(foundz == false)
			{ ystring += currentchar; continue; }
		// Add char to Z.
		zstring += currentchar;
		}
	
	// Convert the strings to ints.
	x = stoi(xstring);
	y = stoi(ystring);
	if(zstring != "") { z = zmodifier * stoi(zstring); }
	}

void solve() 
	{
	// Get the two integers H and S.
	int h; cin >> h;
	int s; cin >> s;
	double bestSpellProbability = 0.00; // The probability that the best spell has to OTK the zombie.
	
	// For each spell, read it in and do the calculation.
	for(int i = 0; i < s; i++)
		{
		// Get the spell from input.
		string spell; cin >> spell;
		
		/// Parse the spell string into ints X, Y, Z.
		int x, y, z = 0;
		ParseSpellString(spell, x, y, z);
		
		// Debug, test parsing.
		//cout << x << " " << y << " " << z << endl;
		
		/// For the X, Y, and Z determine the range the spells will be in.
		int high = x*y + z;
		int low = x + z;
		
		// Debug
		cout << "High: " << high << " Low: " << low << endl;
		
		/// For that range and our H, determine the probability of OTKing the zombie.
		double numerator = high - h + 1; // Number of OTK numbers in the range
		double range = high - low + 1; // The range
		double prob = numerator/range;
		
		// Debug
		//cout << "Prob: " << prob << " Numerator: " << numerator << " Range: " << range << endl;
		
		/// If that probability is better than our current bestSpellProbability, update it.
		if(prob > bestSpellProbability)
			{ bestSpellProbability = prob; }
		}
	
	/// Output the best spell probability.
	cout << fixed << setprecision(10) << bestSpellProbability << endl;
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
