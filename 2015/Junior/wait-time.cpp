#include <iostream>
#include <vector>

using namespace std;

vector<int>lol(100, -1);
vector<int>fag(100, 0);
vector<char>lmao;
void calculae(int x)
{
	char l;
	int t = 0;
	int inp;
	for(int j = 0; j < x; ++j){
		cin >> l >> inp;
		if(l == 'R'){
			if((j-1 >= 0) && (lmao[j-1] != 'W') || (j == 1)){
				++t;
				cout << "t " << t << endl;
			}
			lol[inp] = t;
		}
		if(l == 'S'){
			if((j-1 >= 0) && (lmao[j-1] != 'W')){
				++t;
				cout << "t " << t << endl;
			}
			fag[inp] = t - lol[inp] + fag[inp];
			lol[inp] = -1;
		}
		if(l == 'W'){
			t += inp;
			cout << "t " << t << endl;
		}
		lmao.push_back(l);
	}
}

void printq()
{
	for(int i = 0; i < fag.size(); ++i){
		if((fag[i] != 0) && (lol[i] == -1)){
			cout << i << " " << fag[i] << endl;
		}
		else{
			if (lol[i] != -1){
				cout << i << " " << "-1" << endl;
			}
		}
	}
}

int main()
{
	int fg;
	cin >> fg;
	calculae(fg);
	printq();
	return 0;
}