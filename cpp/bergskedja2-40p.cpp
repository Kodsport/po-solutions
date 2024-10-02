#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define per(i, high) for (int i = high - 1; i >= 0; i--)
#define perr(i, high, low) for (int i = high - 1, i >= low; i++)
#define sz(container) ((int)container.size())
#define all(x) begin(x), end(x)

void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

vector<vector<ll>> grid, neighbours;
ll n, m;
ll mi = 1e5, ma = -1e5;

void rec(ll r, ll c, set<ll> used) {
  if (c == n) {
    c = 0;
    r += 1;
  }

  if (r == m) {
    bool allowed = true;
    for (ll a = 0; a < n; a++) {
      for (ll b = 0; b < m; b++) {
        ll smaller = 0;
        if (a != 0 && grid[a - 1][b] < grid[a][b])
          smaller += 1;
        if (b != 0 && grid[a][b - 1] < grid[a][b])
          smaller += 1;
        if (a != n - 1 && grid[a + 1][b] < grid[a][b])
          smaller += 1;
        if (b != m - 1 && grid[a][b + 1] < grid[a][b])
          smaller += 1;

        if (smaller != neighbours[a][b]) {
          allowed = false;
          break;
        }
      }
    }

    if (allowed) {
      mi = min(mi, grid[0][0]);
      ma = max(ma, grid[0][0]);
    }

    return;
  }

  for (ll i = 1; i < n * m + 1; i++) {
    if (0 < used.count(i))
      continue;
    grid[c][r] = i;
    used.insert(i);
    rec(r, c + 1, used);
    used.erase(i);
  }
}

int main() {
  fast();

  cin >> n >> m;

  neighbours.resize(n, vector<ll>(m));
  grid.resize(n, vector<ll>(m));
  for (ll i = 0; i < n; i++) {
    string line;
    cin >> line;
    for (ll j = 0; j < m; j++) {
      neighbours[i][j] = line[j] - '0';
    }
  }

  rec(0, 0, {});
  cout << mi << " " << ma << endl;

  return 0;
}
