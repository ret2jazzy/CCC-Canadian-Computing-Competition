#include <iostream>
#include <string>

using namespace std;

int sad = 0;
int happy = 0;

void compute(string &x)
{
	for(int i = 0; i < x.size(); ++i){
		if(x[i] == ':'){
			if(x[i+1] == '-'){
				if(x[i+2] == ')'){
					++happy;
				}
				if(x[i+2] == '('){
					++sad;
				}
			}
		}
	}
}

string ans(int x, int y)
{
	if(x > y){
		return "Happy";
	}
	if(x == y){
		return "none";
	}
	if(x < y){
		return "sad";
	}
}

int main()
{
	string d;
	getline(cin, d);
	compute(d);
	cout << ans(happy, sad) << endl;;
	return 0;
}

