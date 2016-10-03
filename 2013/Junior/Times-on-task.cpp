#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool asc(int x, int y){return x < y;}

int maxChores(vector<int>lol, int time)
{
	int counter = 0;
	int timet = 0;
	sort(lol.begin(), lol.end(), asc);
	for(int i = 0; i < lol.size(); ++i){
		if((timet + lol[i]) <= time){
			++counter;
			timet += lol[i];
		}else break;
	}
	return counter;
}

int main()
{
	int t;cin >> t;
	int x;cin>>x;
	vector<int>ans;
	for(int i = 0; i < x; ++i){
		int p;
		cin >> p;
		ans.push_back(p);
	}
	cout << maxChores(ans, t) << endl;
}