#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
  size_t n;
  cin >> n;

  vector<size_t> data(n);
  copy(istream_iterator<size_t>(cin), istream_iterator<size_t>(), back_inserter(data));

  cout << *max_element(data.begin(), data.end()) << '\n';
}
