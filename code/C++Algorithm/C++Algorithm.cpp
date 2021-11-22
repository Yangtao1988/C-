#include <iostream>
#include <cassert>
using namespace std;

void printArray(int (&arr)[10]){
	int len = sizeof(arr)/sizeof(arr[0]);
	cout << "len: " << len << endl;
	if(len < 20){
		cerr <<"Error: "<<__FILE__
		<<"\nfunction: " << __func__
		<<"\nat line: " << __LINE__
		<<"\non:"<<__DATE__
		<<"\nat:"<<__TIME__<<endl;
	}
	for(auto elem : arr)
		cout << elem <<" ";
}

int main()
{
	system("color 02");

	int arr[10] = {1,2,3,4,5};
	int len = sizeof(arr)/sizeof(arr[0]);
	printArray(arr);
	
	return 0;
}