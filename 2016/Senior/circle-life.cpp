#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int>main2;
int y;
int x;
void input()
{
	cin >> x >> y;
	cin.ignore();
	string inp;
	getline(cin, inp);
	for(int l = 0; l < inp.size() ; ++l){
		char s = inp[l];
		int mp = s - '0';
		main2.push_back(mp);
	}
}

void compute()
{
	vector<int>temp(x, 0);
	for(int h = 0; h < x; ++h){
		if(h == 0){
			if((main2[h+1] == 1) && (main2[x-1] == 0)){
				temp[h] = 1; 
			}
			if((main2[h+1] == 0) && (main2[x-1] == 1)){
				temp[h] = 1;
			}
		}
		else if((h == main2.size()-1)){
				if((main2[h-1] == 0) && (main2[0] == 1)){
					temp[h] = 1; 
				}
				if((main2[h-1] == 1) && (main2[0] == 0)){
				temp[h] = 1;
				}
			}
		else if((main2[h-1] == 0) && main2[h+1] == 1){
			temp[h] = 1;
			}
		else if((main2[h-1] == 1) && main2[h+1] == 0){
			temp[h] = 1; 
		}
	}
	for(int o = 0; o < main2.size(); ++o){
		main2[o] = temp[o];
	}
}

void solve()
{
	for(int h = 0; h < y; ++h){
		compute();
	}
}

int main()
{
	input();
	solve();
	for(auto k : main2){
		cout << k;
	}
	cout << endl;
	return 0;
}