#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ed
{
 public:
  string a, b;
  int a_length, b_length;
  vector<vector<int> > distances;
  ed(string a, string b);
  int distance(string a, string b, int aIndex, int bIndex);
  int swap(char a, char b);
  void print(void);
  int min(int x, int y, int z);
};