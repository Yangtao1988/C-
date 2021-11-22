#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;

template<class InputIterator, class T>
InputIterator find_1(InputIterator first, InputIterator last, const T& val)
{
  while (first!=last) {
    if (*first==val) return first;
    ++first;
  }
  return last;
}

template<class InputIterator, class UnaryPredicate>
InputIterator find_if_1 (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first!=last) {
    if (pred(*first)) return first;
    ++first;
  }
  return last;
}

bool IsOdd(int i){
	return ((i % 2)==0);
}

template<class InputIterator, class UnaryPredicate>
InputIterator find_if_not (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first!=last) {
    if (!pred(*first)) return first;
    ++first;
  }
  return last;
}

template<class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 find_end (ForwardIterator1 first1, ForwardIterator1 last1,
                             ForwardIterator2 first2, ForwardIterator2 last2)
{
  if (first2==last2) return last1;  // specified in C++11

  ForwardIterator1 ret = last1;

  while (first1!=last1)
  {
    ForwardIterator1 it1 = first1;
    ForwardIterator2 it2 = first2;
    while (*it1==*it2) {    // or: while (pred(*it1,*it2)) for version (2)
        ++it1; ++it2;
        if (it2==last2) { ret=first1; break; }
        if (it1==last1) return ret;
    }
    ++first1;
  }
  return ret;
}

template<class InputIterator, class ForwardIterator>
InputIterator find_first_of_1 ( InputIterator first1, InputIterator last1,
                                ForwardIterator first2, ForwardIterator last2)
{
  while (first1!=last1) {
    for (ForwardIterator it=first2; it!=last2; ++it) {
      if (*it==*first1)          // or: if (pred(*it,*first)) for version (2)
        return first1;
    }
    ++first1;
  }
  return last1;
}

bool comp_case_insensitive (char c1, char c2) {
  return (std::tolower(c1)==std::tolower(c2));
}

template <class ForwardIterator>
ForwardIterator adjacent_find_1 (ForwardIterator first, ForwardIterator last)
{
  if (first != last)
  {
    ForwardIterator next=first; ++next;
    while (next != last) {
      if (*first == *next)     // or: if (pred(*first,*next)), for version (2)
        return first;
      ++first; ++next;
    }
  }
  return last;
}

int main()
{
	system("color 02");

	// int myints[5] = {15, 23, 31, 41, 54};

	// vector<int> myvector(begin(myints), end(myints));

	// if (vector<int>::iterator it = find_1(myvector.begin(), myvector.end(),30);
	// 		it != myvector.end())
	// 	cout << "Element found in myvector: " << *it << '\n';
	// else
	// 	cout << "Element not found in myvector\n";


	// if(vector<int>::iterator it = find_if(myvector.begin(), myvector.end(),IsOdd);
	// 		it != myvector.end())
	// 	cout << "The first even value is " << *it << '\n';

	// if(vector<int>::iterator it = find_if_not
	// 		(myvector.begin(), myvector.end(),[](int i){return i%3;});
	// 		it != myvector.end())
	// 	cout << "The first even value is " << *it << '\n';

	// int mychars[] = {'E', 'G', 'Y', 'C', 'C', 'C'};
	// std::vector<char> haystack(begin(mychars),end(mychars));
	// std::vector<char>::iterator it;

	// int needle[] = {'A', 'B', 'C'};

	// using default comparison:
	// it = find_first_of(haystack.begin(), haystack.end(),
	// 	 begin(needle) ,end(needle),comp_case_insensitive);

	// if (it != haystack.end())
	// 	std::cout << "The first match is: " << *it << '\n';

    
  int myints[] = {5,5,30,30,30,10,10,20};
  vector<int> myvector (myints,myints+8);
  vector<int>::iterator it;

  // using default comparison:
  it = adjacent_find (myvector.begin(), myvector.end());

  if (it!=myvector.end())
    std::cout << "the first pair of repeated elements are: " << *it << '\n';

  it = adjacent_find(++it, myvector.end(), [](int i,int j){return (i == j);});

  if (it!=myvector.end())
    std::cout << "the second pair of repeated elements are: " << *it << '\n';


    return 0;
}
