#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll words, n;
  cin >> words >> n;

  vector<ll> people(n);
  rep(i, 0, n) {
    people[i] = i + 1;
  }

  ll position = 0;
  rep(i, 0, n - 1) {
    position = (position + words - 1) % sz(people);
    people.erase(people.begin() + position);
  }

  cout << people[0] << endl;
}
