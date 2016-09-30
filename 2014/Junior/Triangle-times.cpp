#include <iostream>

using namespace std;

string answerCompute(int x, int y, int z)
{
	if(x + y + z != 180){
		return "Error";
	}
	if(x == y && y == z){
		return "Equilateral";
	}
	if(x == y || y == z || z == x){
		return "Isosceles";
	}
	return "Scalene";
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << answerCompute(a, b, c) << endl;
}