#include <string>
#include <vector>
#include "ed.h"

using namespace std;

// constructor, creates table of distances between successive substrings of a and b
ed::ed(string a, string b) {
  //set variables
  ed::a_length = a.length();
  ed::b_length = b.length();
  if(a_length == 0 || b_length == 0) {
      cout << "Error: one or more strings of size 0" << endl;
      return;
      } 
  
  ed::a = a;
  ed::b = b;
  
  vector<int> row;
  // pushes top line to table
  for(int i = 0; i <= b_length + 1; i++) {
      row.push_back(i);
  }

  ed::distances.push_back(row);
  //clear row to re-use
  row.clear();
    
  // pushes leftmost column to table
  for(int i = 1; i <= a_length + 1; i++) {
    row.push_back(i);
    ed::distances.push_back(row);
    //clear row to re-use
    row.clear();
  }

  
  
  for(int i = 1; i <= a_length; i++) {
    for(int j = 1; j <= b_length; j++) {
      //calculates distances according to Levenshtein formula
      int cost = swap(a[i - 1], b[j - 1]);
      int deletion = ed::distances[i - 1][j] + 1;
      int insertion = ed::distances[i][j - 1] + 1;
      int match_swap = ed::distances[i - 1][j - 1] + cost;

      //push back min value
      ed::distances[i].push_back(min(deletion, insertion, match_swap));
    }
  }
  
}

//basic min function
int ed::min(int x, int y, int z) {
  if(x < y && x < z)
    return x;
  else if(y < z)
    return y;
  else
    return z; 
}

// swap(x, y) = 1 if x != y and 0 otherwise
int ed::swap(char a, char b) {
  if(a != b)
    return 1;
  else
    return 0;
}

// prints
void ed::print() {
  
  //same error test as in ed::ed
  if(a_length == 0 || b_length == 0)
      return;
  
  
  cout << "      ";
  for(int i = 0; i < ed::b_length; i++) {
    cout << b[i];
    cout << "  ";
  }

  cout << endl << "   ";
  
  for(int i = 0; i < ed::a_length + 1; i++) {
    for(int j = 0; j < ed::b_length + 1; j++) {
      //prints out current value
      if(distances[i][j] < 10) {
 	 cout << distances[i][j];
	 cout << "  ";
      }
      //for locations where val >= 10, we need to alter spacing
      //for aesthetic purposes
      else {
	  cout << distances[i][j];
	  cout << " ";
      }
    }
    cout << endl;
    //print out current character of string a
    if(i < a_length)
      cout << a[i];
    cout << "  ";
  }

  cout << endl;
  cout << "The Levenshtein distance between " << a << " and " << b << " is " << distances[a_length][b_length] << endl;
}