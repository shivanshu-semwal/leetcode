// https://leetcode.com/problems/lru-cache

#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  deque<int> d;
  d.push_back(10);
  d.push_back(11);

  auto t = d.end();
  d.pop_back();
  d.push_back(15);
  d.push_back(16);
  cout << *t;
  return 0;
}