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
// Compile Linux: g++ FightingZombie.cpp -std=c++11 -o main


// Rolling a Y-sided die X times, what's the probability of the rolls adding up to W
void GetStates(int x, int y, int (&states)[20*20+1])
	{
	cout << "Called GetStates for x: " << x << " y: " << y << endl;
	// Fill up the states array
	
	// Find how many states add up to W. AKA...
	// From range 1 to Y, choose X numbers that add up to W.
	
	// We'll do this using 20 for loops, since 20 is the limit of X for the problem.
	int bound[20]; // An array for the limits of our 20 for loops
	// Initialize the first X spots to Y, rest to one.
	int count = 0;
	for(int i = 0; i < 20; i++)
		{
		count += 1;
		if(count <= x) { bound[i] = y; }
		else { bound[i] = 1; }
		}
	
	// So now the bound array looks like [y y y 1 1 1 1 1 1]
	
	// Make another array for the dice states
	int dice[20];
	
	// 20 for loops, for each of the 20 possible rolls we'll do
	for(int a19 = 1; a19 <= bound[19]; a19++) { dice[19] = a19; 
	for(int a18 = 1; a18 <= bound[18]; a18++) { dice[18] = a18;
	for(int a17 = 1; a17 <= bound[17]; a17++) { dice[17] = a17;
	for(int a16 = 1; a16 <= bound[16]; a16++) { dice[16] = a16;
	for(int a15 = 1; a15 <= bound[15]; a15++) { dice[15] = a15;
	for(int a14 = 1; a14 <= bound[14]; a14++) { dice[14] = a14;
	for(int a13 = 1; a13 <= bound[13]; a13++) { dice[13] = a13;
	for(int a12 = 1; a12 <= bound[12]; a12++) { dice[12] = a12;
	for(int a11 = 1; a11 <= bound[11]; a11++) { dice[11] = a11;
	for(int a10 = 1; a10 <= bound[10]; a10++) { dice[10] = a10;
	for(int a9 = 1; a9 <= bound[9]; a9++) { dice[9] = a9;
	for(int a8 = 1; a8 <= bound[8]; a8++) { dice[8] = a8;
	for(int a7 = 1; a7 <= bound[7]; a7++) { dice[7] = a7;
	for(int a6 = 1; a6 <= bound[6]; a6++) { dice[6] = a6;
	for(int a5 = 1; a5 <= bound[5]; a5++) { dice[5] = a5;
	for(int a4 = 1; a4 <= bound[4]; a4++) { dice[4] = a4;
	for(int a3 = 1; a3 <= bound[3]; a3++) { dice[3] = a3;
	for(int a2 = 1; a2 <= bound[2]; a2++) { dice[2] = a2;
	for(int a1 = 1; a1 <= bound[1]; a1++) { dice[1] = a1;
	for(int a0 = 1; a0 <= bound[0]; a0++) { dice[0] = a0;
	
		// Add up the first X indices of dice[].
		int sum = 0;
		for(int j = 0; j < x; j++)
			{
			sum += dice[j];
			}
		
		// Incremenet the states box for this sum
		states[sum] += 1; 
	
	}}}}}}}}}}}}}}}}}}}}
	
	}

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
	
	bool breakout = false; // If we get a 100%, breakout.
	
	// For each spell, read it in and do the calculation.
	for(int i = 0; i < s; i++)
		{
		// Get the spell from input.
		string spell; cin >> spell;
		
		// Breakout if necessary
		if(breakout == true) { continue; }
		
		/// Parse the spell string into ints X, Y, Z.
		int x, y, z = 0;
		ParseSpellString(spell, x, y, z);
		
		// Debug, test parsing.
		//cout << x << " " << y << " " << z << endl;

		// Subtract the Z bonus from the total Hp to get the number we need to roll
		int newh = h - z;
		
		// Check if spell has a 100% kill rate or 0% kill rate
		int high = x * y;
		int low = x;
		
		// Debug		
		//cout << "High: " << high << " Low: " << low << " Hp:" << h << endl;
		
		// 100% if min damage is bigger than hp
		if (low >= newh) { bestSpellProbability = 1; breakout = true; continue; } // No need to continue
		// 0% if max damage is lower than hp
		if (high < newh) { continue; } // Move on to next spell
		
		double prob = 0.0; // The probability this spell OTKs.
		double factor = 1/pow(y,x); // 1 over The number of possible states.
		
		// Make an array for the number of states per probability
		int states[20*20+1] = {0};
		// For example, 12 states if you roll 2 dice
		GetStates(x, y, states);
		
		// The probability of this spell landing is the probability it hits for the range [hp, high]
		// Get the probability in this range from the states array.
		for(int j = newh; j <= high; j++)
			{
			// Get the probability the dice will roll to this number.
			prob += states[j]*factor;
			cout << "Prob for (" << x << ", "<< y<< ", " << j << ") is " <<  prob << endl;
			}
		
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
