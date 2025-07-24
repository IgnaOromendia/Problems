#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > mat;
typedef pair<int,int> pi;
typedef pair<double,double> pd;

#define pb push_back
#define mp make_pair

#define forn(i,from,to) for (int i = from; i < to; i++)

constexpr int INF  = 1e9;
constexpr int MAXN = 1e6;
constexpr int mod  = 1e9 + 7;
constexpr double PI = 3.14159265359;

ll memo[MAXN][2];
int visited[MAXN][2]; // No hace falta reiniciar el visited ya que siempre es el mismo problema pero más alto
 
// Basicamente vemos cuantas formas tenemos de ir de un 
// casillero dividido en 2 a otro dividido en 2 + ir a uno entero y viceversa
// state = 0 -> entero 
// state = 1 -> dividido
ll amount_of_ways(int i, int state) {
    if (i == 1) return 1;

    if (visited[i][state]) return memo[i][state];
    visited[i][state] = true;

    // Entero puedo llegar de 2 formas desde un entero o de 1 forma desde un dividido
    // Dividido puedo llegar de 1 forma desde un enetero o de 4 formas desde un dividio

    ll prev_entire  = (state == 0 ? 2 : 1) * amount_of_ways(i-1, 0);
    ll prev_divided = (state == 1 ? 4 : 1) * amount_of_ways(i-1, 1);

    return memo[i][state] = (prev_entire + prev_divided) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,t; cin >> t;
 
    memset(visited, 0, sizeof(visited));
 
    while (t--) {
        cin >> n;
        ll res = amount_of_ways(n, 0) + amount_of_ways(n, 1);
        res %= mod;
        cout << res << "\n";
    }
    
}