#include <iostream>

using namespace std;

int counter = 0;

void TakeInput()
{
	char s;
	for(int i = 0; i < 6; ++i){  //Taken input 6 times
		cin >> s;
		switch (s){
			case 'W':
			++counter;  // counter to count Wins
			break;
		}
	}
}

int Answer()  //Compares
{
	if(counter == 5||counter == 6){
		return 3;
	}
	if(counter == 4||counter == 3){
		return 2;
	}
	if(counter == 1||counter == 2){
		return 1;
	}
	if(counter == 0){
		return -1;
	}
}

int main()
{
	TakeInput();
	cout << Answer() << endl;
	return 0;
}
