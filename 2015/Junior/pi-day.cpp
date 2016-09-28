#include <iostream>
#include <vector>

using namespace std;

int mainsum;

int sumOfArray(vector<int>lol)
{
	int sum = lol[0];
	for(int i =1; i < lol.size(); ++i){
		sum += lol[i];
	}
	return sum;
}

void arrayCompute(vector<int>&lol, int sum, int lastNumber)
{
	lol[lol.size() - 1] = lastNumber;
	int dif = sum - sumOfArray(lol);
	int increase;
	if(dif < lol.size() - 1){
		increase = 0;
	} else increase = dif/(lol.size() - 1);//The division to see how much will each element increase except the last element
	int increaseLast = dif%(lol.size() - 1);//The rest of the elements element which will be added in order from last
	mainsum = (increase * (lol.size() - 1)) + increaseLast + dif;
}


int compute(int pies, int people)
{
	vector<int>distri(people, 1);
	distri[distri.size() - 1] = pies - people + 1;
	int maxpies;
	if(pies%people == 0){
		maxpies = pies/people;
	}else maxpies = pies/people + 1;
	arrayCompute(distri, pies, maxpies);
	return mainsum - 1;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << compute(a, b) << endl;
}