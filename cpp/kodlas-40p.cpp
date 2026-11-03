#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

vector<string> plates;
ll n, m;

ll count(ll plate_nr, string mask) {
  if (plate_nr == n) {
    return mask.find('.') != string::npos;
  }

  ll total_count = 0;
  rep(offset, 0, m) {
    string new_mask;
    rep(i, 0, m) {
      if (mask[i] == '.' && plates[plate_nr][(i + offset) % m] == '.') {
        new_mask.push_back('.');
      } else {
        new_mask.push_back('#');
      }
    }
    total_count += count(plate_nr + 1, new_mask);
  }

  return total_count;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;

  plates.resize(n);
  rep(i, 0, n) {
    cin >> plates[i];
  }

  cout << count(0, string(m, '.')) << endl;
}
