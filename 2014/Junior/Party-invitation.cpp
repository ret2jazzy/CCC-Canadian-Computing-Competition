#include <iostream>
#include <vector>

using namespace std;

void removeNegative(vector<int>&lol2)
{
    for(int i = 0; i < lol2.size();++i){
        if(lol2[i] == -1){
            lol2.erase(lol2.begin() + i);
        }
    }
}

void changeMultiples(vector<int>&lol, int q)
{
    for(int i = q-1; i < lol.size(); i += q){
        lol[i] = -1;
    }
    removeNegative(lol);
}

int main()
{
  int n;
  cin >>n;
  vector<int>ans;
  for(int i =  1; i < n; ++i){
      ans.push_back(i);
  }
  int h;
  cin >> h;
  for(int i = 0; i < h; ++i){
      int g;
      cin >> g;
      changeMultiples(ans, g);
  }
  for(auto x : ans){
      cout << x << endl;
  }
}
