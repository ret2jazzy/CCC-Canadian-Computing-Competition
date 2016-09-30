#include <iostream>

using namespace std;

int as = 0;
int bs = 0;

string inputAns()
{
		string c;
		cin >> c;
		for(int i = 0; i < c.size(); ++i){
			if(c[i] == 'A'){
				++as;
			}else if(c[i] == 'B'){
				++bs;
			}
		}
		if(as == bs){
			return "Tie";
		}
	return (as > bs ? "A" : "B");
}

int main()
{
	int a;
	cin >> a;
	cout << inputAns() << endl;
}