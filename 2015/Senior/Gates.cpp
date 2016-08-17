#include <iostream>
#include <vector>

using namespace std;

int x;
int y;
void input()
{
	cin >> x;
	cin >> y;
}

int compute()
{
	vector<int>gates(y, 0);
	int inp;
	int cnt = 0;
	bool notclosed = true;
	for(int i = 0; i < y; ++i){
		cin >> inp;
		if(notclosed){
			for(int g = inp; g > 0; --g){
				if(gates[g] == 0){
					gates[g] = 1;
					++cnt;
					break;
				}
				if(g == 1){
					notclosed = false;
				}
			}
		}
	}
	return cnt;
}

int main()
{
	input();
	cout << compute() << endl;
	return 0;
}