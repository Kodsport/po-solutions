#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

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
    rep(a, 0, n) {
      rep(b, 0, m) {
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

  rep(i, 1, n * m + 1) {
    if (0 < used.count(i))
      continue;
    grid[c][r] = i;
    used.insert(i);
    rec(r, c + 1, used);
    used.erase(i);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;

  neighbours.resize(n, vector<ll>(m));
  grid.resize(n, vector<ll>(m));
  rep(i, 0, n) {
    string line;
    cin >> line;
    rep(j, 0, m) {
      neighbours[i][j] = line[j] - '0';
    }
  }

  rec(0, 0, {});
  cout << mi << " " << ma << endl;
}
