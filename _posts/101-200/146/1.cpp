#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
  list<pair<int, int>> q;
  unordered_map<int, list<pair<int, int>>::iterator> m;
  int capacity;

  LRUCache(int capacity) {
    this->capacity = capacity;
    q = list<pair<int, int>>();
    m = unordered_map<int, list<pair<int, int>>::iterator>();
  }

  int get(int key) {
    auto t = m.find(key);
    if (t != m.end() && t->second != q.end()) {
      int val = t->second->second;
      q.erase(t->second);
      q.push_back({key, val});
      t->second = --q.end();
      return val;
    }
    return -1;
  }

  void put(int key, int value) {
    auto t = m.find(key);
    if (t != m.end() && t->second != q.end()) {
      q.erase(t->second);
    }
    if (q.size() == capacity) {
      m[q.front().first] = q.end();
      q.pop_front();
    }
    q.push_back({key, value});
    m[key] = --q.end();
  }
};