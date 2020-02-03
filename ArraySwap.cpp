#include <iostream>

using namespace std;
int A[3] = {1,2,3};
int B[3] = {4,5,6};
int Temp[3];
int main(void)
{
	cout << "=====Before Swapping=====" <<endl;
	for(int i = 0; i < 3; i++)
	{
		cout << A[i];
	}
	cout << endl;
	
	for(int i = 0; i < 3; i++)
	{
		cout << B[i];
	}
	cout << endl;
	cout << endl;
	cout << "=====After Swapping=====";
	for(int i = 0; i < 3; i++)
	{
		Temp[i] = A[i];
		//cout << Temp[i];
	}
	cout << endl;
	
	for(int i = 0; i < 3; i++)
	{
		A[i] = B[i];
		cout << A[i];
	}
	cout << endl;
	
	for(int i = 0; i < 3; i++)
	{
		B[i] = Temp[i];
		cout << B[i];
	}
	cout << endl;
}

