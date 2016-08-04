#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> lol;
int s;

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
	for(int i = 0; i < lol.size();++i){
		while((i+1 < lol.size()) && (lol[i] == lol[i+1])){
			lol[i] = lol[i] + lol[i+1];
			lol.erase(lol.begin() + i + 1);
		}
		while((i+2 < lol.size()) && (lol[i] == lol[i+2])){
			lol[i] = lol[i] + lol[i+1] + lol[i+2];
			lol.erase(lol.begin() + i + 1);
			lol.erase(lol.begin() + i + 1);
		}
	}
}

void finalans()
{
	int sd = 0;
	while (sd < 100){
		compute();
		++sd;
	}
	sort(lol.begin(), lol.end(), desc);
}

int main()
{
	takeinput();
	finalans();
	cout << lol[0] << endl;
	return 0;
}