#include <iostream>
#include <vector>

using namespace std;

vector<int> lol;

void takeinput()
{
	int x;
	cin >> x;
	int m;
	for(int i = 0, k = 0; i < x; ++i){
		cin >> m;
		if(m == 0){
			lol.erase(lol.begin() + k - 1);
			--k;
		}
		else{
			lol.push_back(m);
			++k;
		}
	}
}

int main()
{
	takeinput();
	int sum = 0;
	for(auto k : lol){
		sum += k;
	}
	cout << sum << endl;
	return 0;
}
