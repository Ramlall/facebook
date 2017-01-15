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
// Problem: ManicMoving
// URL: https://www.facebook.com/hackercup/problem/300438463685411/
// Linux command to run this: g++ ManicMoving.cpp -o main

/*
Logic:
0. Read input N, M, K.
1. Read the edges into an adjacency matrix.
2. Read the deliveries into two arrays.
*/

/*
// Thanks to Steven Hao for Dijkstra
// Source: https://www.quora.com/What-is-the-most-simple-efficient-C++-code-for-Dijkstras-shortest-path-algorithm

// given adjacency matrix adj, finds shortest path from A to B
int dijk(int A, int B, vector< vector<int> > &adj) 
	{
	int n = adj.size();
 	vector<int> dist(n);
  	vector<bool> vis(n);

  	for(int i = 0; i < n; ++i) 
  		{ dist[i] = INF; }
  	dist[A] = 0;

  	for(int i = 0; i < n; ++i) 
  		{
	    	int cur = -1;
    		for(int j = 0; j < n; ++j) 
    			{
		      	if (vis[j]) continue;
			if (cur == -1 || dist[j] < dist[cur]) { cur = j; }
    			}

	    	vis[cur] = true;
    		for(int j = 0; j < n; ++j) 
    			{
		      	int path = dist[cur] + adj[cur][j];
		      	if (path < dist[j]) { dist[j] = path; }
    			}
  		}

	return dist[B];
	}
*/
// Global so it's not annoying
int k = 0;

int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INF, min_index;
  
   for (int v = 0; v < k; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}

int dijk(int src, int b, const vector< vector<int> > (&graph))
	{
	int V = k;
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
     	{
        dist[i] = INF, sptSet[i] = false;
        }
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INF 
                                       && dist[u]+graph[u][v] < dist[v])
          {  dist[v] = dist[u] + graph[u][v]; }
     }
  
	// Return distance
	return dist[b];
	}


// Recursive function to get minimum cost of gas for a destination D
vector<int> MinDStorage;
//int MinD(int (&adj)[][], vector<int> (&s), vector<int> (&d), int i)
int MinD(const vector< vector<int> > &adj, vector<int> (&s), vector<int> (&d), int i)
	{
	// Base cases
	// First delivery min is town 1 to start 1, and start 1 to delivery 1
	if(i == 0) 
		{ 
		cout << "i: 0 min: " << dijk(0, s[0], adj) + dijk(s[0], d[0], adj) << endl;
		return dijk(0, s[0], adj) + dijk(s[0], d[0], adj); 
		}
	if(i == 1) 
		{ 
		cout << "i: 0 min: " << min(dijk(0, s[0], adj) + dijk(s[0], d[0], adj) + dijk(d[0], s[1], adj) + dijk(s[1], d[1], adj), dijk(0, s[0], adj) + dijk(s[0], s[1], adj) + dijk(s[1], d[0], adj) + dijk(d[0], d[1], adj)) << endl;
		return min(dijk(0, s[0], adj) + dijk(s[0], d[0], adj) + dijk(d[0], s[1], adj) + dijk(s[1], d[1], adj), dijk(0, s[0], adj) + dijk(s[0], s[1], adj) + dijk(s[1], d[0], adj) + dijk(d[0], d[1], adj)); 
		}
	
	
	int dim1_si = dijk(d[i-1], s[i], adj);
	int si_di = dijk(s[i], d[i], adj);
	int MinDim1 = MinD(adj, s, d, i-1);
	
	int way1 = dim1_si + si_di + MinDim1;
	
	int dim2_sim1 = dijk(d[i-2], s[i-1], adj);
	int sim1_si = dijk(s[i-1], s[i], adj);
	int si_dim1 = dijk(s[i], d[i-1], adj);
	int dim1_di = dijk(d[i-1], d[i], adj);
	int MinDim2 = MinD(adj, s, d, i-2);
	
	int way2 = dim2_sim1 + sim1_si + si_dim1 + dim1_di + MinDim2;
	int way3 = INF;
	if(i != k) { way3 = dijk(d[i-1], s[i], adj) + dijk(s[i], s[i+1], adj) + dijk(s[i+1], d[i], adj) + MinD(adj, s, d, i-1); }
	
	// The int we return
	int re = min(min(way1, way2), way3);
	
	// If all 3 ways are 0 or something, return -1.
	if(way1 == 0 && way2 == 0) { re = 0; }	
	
	// Add this to MinDStorage if it's smaller.
	//if(re < MinDStorage[i]) { MinDStorage[i] = re; }
	
	cout << "k: " << i << " min" <<  ": " << re << endl;
		
	// Return it.
	return re;
	}

// This solve function gets called every test case. 
// Output to cout the answer for just the case, no "Case #1: " stuff. (Include and end line.)
void solve() 
	{
	// Read input N M K
	int n; cin >> n;
	int m; cin >> m;
	cin >> k;
	
	// Initialize an adjacency list to infinite
	//int adj[V][V];
	vector< vector<int> > adj(n);//(n, vector<int>(n));
	for(int i = 0; i < n; i++) 
		{
		adj.push_back(vector<int>(n));
		//adj[i] = vector<int>(n);
	    	for(int j = 0; j < n; j++) 
	    		{ adj[i].push_back(0); }
		}
	
	// Read input for roads in and add to adjacency list.
	for(int i = 0; i < m; i++)
		{
		int a, b, g;
		cin >> a >> b >> g;
		adj[a-1][b-1] = g;
		adj[b-1][a-1] = g;
		}
	
	// Debug - output adj matrix
	cout << endl; for(int i = 0; i < n; i++) { for(int j = 0; j < n; j++) { cout << adj[i][j] << " "; } cout << endl; }
	
	// Read input for deliveries into two vectors
	vector<int> s(k);
	vector<int> d(k);
	for(int i = 0; i < k; i++)
		{
		int ss, dd;
		cin >> ss >> dd;
		s.push_back(ss);
		d.push_back(dd);
		}
	
	// Initialize MinDStorage
	for(int i = 0; i < n; i++)
		{ MinDStorage.push_back(INF); }
	
	// The minimum we spend on gas.
	int totalmin = INF;
	
	// Debug - Test Dijkstra
	//totalmin = dijk(0, 1, adj);
	
	// Find the total min by dynamic programming.
	totalmin = MinD(adj, s, d, k);
	
	// Output Elements
	//for(int i = 0; i < n; i++) { cout << MinDStorage[i] << endl; }
	
	// Output the min
	cout << totalmin << endl;
	
	// Empty MinDStorage
	MinDStorage.clear();
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
