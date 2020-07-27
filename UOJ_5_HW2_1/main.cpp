#include "Student.h"
#include "StudentCollection.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  int n;
  cin >> n;

  StudentCollection sc;
  for(int i = 0; i < 3* n; i++){
    cin >> sc;
  }


  int m;
  cin >> m;
  for(int i = 0; i < m; i++){
    string nameA, nameB;
    cin >> nameA >> nameB;
    Student sA = sc[nameA];
    Student sB = sc[nameB];
    if(sA < sB){
      cout << sB << "\n" << sA << "\n" << endl;
    }else{
      cout << sA << "\n" << sB << "\n" << endl;
    }
  }

  sc.sortByScore();
  cout << sc;

  return 0;
}