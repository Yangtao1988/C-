#include <iostream>
#include <string>
#include <vector>
using namespace std;
int fact()
{
	static int My_number = 0;
	My_number++;
	return My_number;
}
void main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << fact() << endl;
	}
	cout << fact() << endl;
}
