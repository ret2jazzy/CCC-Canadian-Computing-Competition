#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> lol;
int s;
bool ans = true;

void takeinput()
{
	cin >> s;
	for (int i = 0; i < s; ++i){
		int inp;
		cin >> inp;
		lol.push_back(inp);
	}
}

bool desc(int y, int z){return y > z;}

void compute()
{
	ans = false;
	for(int i = 0; i < lol.size();++i){

		if((i+2 < lol.size()) && (lol[i] == lol[i+2])){
			lol[i] = lol[i] + lol[i+1] + lol[i+2];
			lol.erase(lol.begin() + i + 1);
			lol.erase(lol.begin() + i + 1);
			ans = true;
		}
		
		else if((i+1 < lol.size()) && (lol[i] == lol[i+1])){
			lol[i] = lol[i] + lol[i+1];
			lol.erase(lol.begin() + i + 1);
			ans = true;
		}
	}
}

void finalans()
{
	while (ans){
		compute();
	}
	ans = true;
	sort(lol.begin(), lol.end(), desc);
}

int main()
{
	takeinput();
	finalans();
	cout << lol[0] << endl;
	return 0;
}

