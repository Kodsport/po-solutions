#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

vector<vector<ll>> grid;
ll n, k;

// Insikt: vi vill aldrig gå åt vänster, bara upp/ner/höger
ll count(ll r, ll c, ll visited_row, ll visited_count) {
  if (r < 0 || r >= 2 || c >= n) {
    return 0;
  }
  if (visited_count == k) {
    return 0;
  }

  // Vi kan alltid gå åt höger
  ll best_from_here = count(r, c + 1, 0, visited_count + 1);
  // Vi kan inte gå upp, ner och sen upp igen. För att förbjuda
  // detta håller vi koll på om vi besökt den andra på den här raden
  if (visited_row == 0) {
    best_from_here = max(best_from_here, count(1 - r, c, 1, visited_count + 1));
  }

  ll apples = grid[r][c] + best_from_here;
  return apples;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> k;

  grid.resize(2, vector<ll>(n));
  rep(i, 0, n) {
    cin >> grid[0][i];
  }
  rep(i, 0, n) {
    cin >> grid[1][i];
  }

  cout << count(1, 0, 0, 0) << endl;
}
