#include <iostream>
#include <vector>

using namespace std;

int ant = 100;
int david = 100;

void computePrintAns(vector<int>his, vector<int>her)
{
	for(int i = 0; i < his.size(); ++i){
		if(his[i] > her[i]){
			ant -= his[i];
		}else if(her[i] > his[i]){
			david -= her[i];
		}
	}
	cout << ant << endl;
	cout << david << endl;
}

int main()
{
	vector<int>ant;
	vector<int>david;
	int f;
	cin >> f;
	for(int i = 0; i < f; ++i){
		int a, b;
		cin >> a >> b;
		ant.push_back(a);
		david.push_back(b);
	}
	computePrintAns(david, ant);
}