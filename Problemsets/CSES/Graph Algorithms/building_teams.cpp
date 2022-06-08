#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using str = string;
using db = long double;
 
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;
 
using vi = vector<int>;
using vl = vector<ll>;
using vdb = vector<db>;
using vb = vector<bool>;
using vs = vector<str>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdb = vector<pdb>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
//pairs
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define mp make_pair
#define fi first
#define se second
 
//vectors
#define pb push_back
#define pf push_front
#define low_b lower_bound
#define up_b upper_bound
 
const int MOD = 1e9+7;
//const int MOD = 998244353;
const ll INF = 1e18;

const int MAXN = 1e5+777;
vl adj[MAXN];
ll col[MAXN];
bool visited[MAXN];
bool possible = true;

void dfs(int u){
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++){
        if(col[u] == col[adj[u][i]])
            possible = false;
        if(!visited[adj[u][i]]){
            if(col[u] == 1)
                col[adj[u][i]] = 2;
            else
                col[adj[u][i]] = 1;
            dfs(adj[u][i]);
        }
    }
}

void solve(){
    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 0; i < n; i++){
        col[i] = -1;
        visited[i] = false;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            col[i] = 1;
            dfs(i);
        }
    }
    if(!possible)
        cout << "IMPOSSIBLE" << '\n';
    else{
        for(int i = 0; i < n; i++)
            cout << col[i] << " ";
        cout << '\n';
    }
}
 
int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}