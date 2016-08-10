#include <iostream>

using namespace std;

int x, y;
void input()
{
	cin >> x >> y;
}

string work()
{
	if(x < 2){
		return "Before";
	}
	if(x == 2){
		if(y < 18){
			return "Before";
		}
		if(y == 18){
			return "Special";
		}
		if(y > 18){
			return "After";
		}
	}
	if(x > 2){
		return "After";
	}
}

int main()
{
	input();
	cout << work() << endl;
	return 0;
}