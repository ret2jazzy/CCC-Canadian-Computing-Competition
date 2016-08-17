#include <iostream>
#include <vector>
using namespace std;

vector<char>jerseys(1, '#');
int a;
void input()
{
	int j;
	cin >> j >> a;
	for(int i = 0; i < j; ++i){
		char f;
		cin >> f;
		jerseys.push_back(f);
	}
}

int computing()
{
	int cnter = 0;
	for(int i = 0; i < a; ++i){
		char k;
		cin >> k;
		if(k == 'S'){
			int m;
			cin >> m;
			if(jerseys[m] == 'S' ||jerseys[m] == 'M' || jerseys[m] == 'L'){
				++cnter;
				jerseys[m] = '#';
			}
		}
		if(k == 'M'){
			int m;
			cin >> m;
			if(jerseys[m] == 'M' || jerseys[m] == 'L'){
				++cnter;
				jerseys[m] = '#';
			}
		}
		if(k == 'L'){
			int m;
			cin >> m;
			if(jerseys[m] == 'L'){
				++cnter;
				jerseys[m] = '#';
			}
		}
	}
	return cnter;
}

int main()
{
	input();
	cout << computing() << endl;
	return 0;
}