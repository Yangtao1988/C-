#include <iostream>
#include <array>
#include <vector>
using namespace std;

// all_of 全部满足
template<class InputIterator, class UnaryPredicate>
bool all_of (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first != last) {
    if (!pred(*first)) return false;
    ++first;
  }
  return true;
}

// any_of 至少有一个满足
template<class InputIterator, class UnaryPredicate>
bool any_of (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first!=last) {
    if (pred(*first)) return true;
    ++first;
  }
  return false;
}

//none_of 所有都不满足
template<class InputIterator, class UnaryPredicate>
bool none_of (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first!=last) {
    if (pred(*first)) return false;
    ++first;
  }
  return true;
}

//应用函数到集合，可以是函数或者函数对象
template<class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function fn)
{
  while (first!=last) {
    fn (*first);
    ++first;
  }
  return fn;
}

//函数
void myfunction (int i) { 
	cout << ' ' << i*100;
}

//函数对象
struct myclass {           
void operator() (int i) {
	  i *= 10;
	  cout << ' ' << i;}
} myobject;


int main()
{
	system("color 02");
	vector<int>foo = {100,200,300,400,500,600,700,800,900,1000};
	if (all_of( foo.begin(), foo.end(), [](int i){return i>0 && i<100;}))
				cout << "all_of: (1-100)\n";
	else		cout << "all_of: no(1-100)\n";

	if (any_of( foo.begin(), foo.end(), [](int i){return i<0;}) )
    			cout << "any_of: There are negative elements in the range.\n";
	else 		cout << "any_of: There are no negative elements in the range.\n";

	if (none_of(foo.begin(), foo.end(), [](int i){return i<0;}) )
   				cout << "none_of: There no negative elements in the range.\n";
	else		cout << "none_of: There have negative elements in the range.\n";

	vector<int> myvector(10);
	for (size_t i = 0; i < 10; i++)
	{
		myvector[i] = i;
	}
	
	cout << "myvector contains:";
	for_each(myvector.begin(), myvector.end(), myfunction);
	cout << '\n';
	// or:
	cout << "myvector contains:";
	for_each(myvector.begin(), myvector.end(), myobject);
	cout << '\n';
	cout << "myvector contains:";
	for_each(myvector.begin(), myvector.end(), myclass());
	cout << '\n';

	return 0;
}