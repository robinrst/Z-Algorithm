#include        "algorithm"
#include        "iostream"
#include        "numeric"
#include        "iomanip"
#include        "cstring"
#include        "math.h"
#include        "bitset"
#include        "string"
#include        "vector"
#include        "ctime"
#include        "queue"
#include        "stack"
#include        "map"
#include        "set"
 
#include        "ext/pb_ds/assoc_container.hpp" // Common file
#include        "ext/pb_ds/tree_policy.hpp" // Including tree_order_statistics_node_update
#include        "ext/pb_ds/detail/standard_policies.hpp"
 
using namespace std;
using namespace __gnu_pbds;
 
 
#define          f first
#define          lgn 25
#define          endl '\n'
#define          sc second
#define          N (int)2e5+5
#define          pb push_back
#define          mod 1000000007
#define          ld long double
#define          vi vector<int>
#define          eb emplace_back
#define          vpii vector<pii>
#define          mii map<int,int>
#define          int long long 
#define          pii pair<int,int>
#define          pq priority_queue
#define          BLOCK (int)sqrt(N)
#define          test(x) while(x--)
#define          all(x) begin(x),end(x)
#define          allr(x) rbegin(x),rend(x)
#define          fo(i,a,n) for(int i=a;i<n;i++)
#define          rfo(i,n,a) for(int i=n;i>=a;i--)
#define          FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"
#define          PI acos(-1.0)
#define 		 bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
 
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > 
OS ;
 
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
 
inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}
 
const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
 
int n,m,k,q;
string s,t;
vi adj[N];
int vis[N],par[N],a[N];
 
 
vi Z()  // z[i] btata h ki i se leke aage tk kitne length ki string match kr rhi h prefix se
{
	int l = 0 , r = 0;
	vi z(n,0);
 
	fo(i,1,n)
	{
		if( i <= r ) z[i] = min( z[i - l] , r - i + 1 ); // ya th z[i] jo h vh usi z-box m hoga ya phr or character match kr rhe honge
		while( i + z[i] < n and s[z[i]] == s[i + z[i]] ) z[i]++; // explicit matching krna
 
		if( i + z[i] - 1 > r ) //  agr z[i] ki length r se jada ho jae th r ko update kr do
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}
// for 'aaaaa' -> z[] = { 0 , 4 , 3 , 2 , 1}
 
 
void go()
{
	cin >> t >> s;
	int nn = s.size();
	s = t + '$' + s + s;
 
	m = t.size();
	n = s.size();
 
	auto z = Z();
	int ans = 0;
 
	fo(i,0,nn)
	{
		if( z[i + m + 1] == m ) ans++;
	}
 
	cout << ans << endl;
}
 
int32_t main()
{
	INP(); 
	FAST;     
	int t=1; 
	cin>>t;
	test(t) go();
}