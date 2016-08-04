#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;
void TakeInput()
{
	string ab;
	string ac;
	string ad;
	string ae;
	getline(cin, ab);
	getline(cin, ac);
	getline(cin, ad);
	getline(cin, ae);
	istringstream iss(ab);
	for (int b; iss >> b;){
		A.push_back(b);
	}
	istringstream iss1(ac);
	for (int b; iss1 >> b;){
		B.push_back(b);
	}
	istringstream iss2(ad);
	for (int b; iss2 >> b;){
		C.push_back(b);
	}
	istringstream iss3(ae);
	for (int b; iss3 >> b;){
		D.push_back(b);
	}
}

int vectorsum(vector<int> &a)
{
	int allsum = 0;
	for (auto m : a){
		allsum += m;
	}
	return allsum;
}

int vectorcolumnsum(vector<int> &a,vector<int> &b,vector<int> &c,vector<int> &d, int x)
{
	long allsum2 = 0;
	allsum2 = a[x] + b[x] + c[x] + d[x];
	return allsum2;
}

bool ComputeInputRow()
{
	if(vectorsum(A) == vectorsum(B) && vectorsum(B) == vectorsum(C) && vectorsum(C) == vectorsum(D) && vectorsum(D) == vectorsum(A)){
		return true;
	}
	else{
		return false;
	}
}
bool ComputColumnInput()
{
	if(vectorcolumnsum(A, B, C, D, 0) == vectorcolumnsum(A, B, C, D, 1) && vectorcolumnsum(A, B, C, D, 1) == vectorcolumnsum(A, B, C, D, 2) && vectorcolumnsum(A, B, C, D, 2) == vectorcolumnsum(A, B, C, D, 3) && vectorcolumnsum(A, B, C, D, 3) == vectorcolumnsum(A, B, C, D, 0)){
		return true;
	}
	else{
		return false;
	}
}
bool columnrow()
{
	if(vectorcolumnsum(A, B, C, D, 0) == vectorsum(A)){
		return true;
	}
	else{
		return false;
	}
}

int main()
{
	TakeInput();
	if (ComputeInputRow() && ComputColumnInput() && columnrow()){
		cout << "magic" <<endl;
	}
	else{
		cout << "not magic" << endl;
	}
	return 0;
}