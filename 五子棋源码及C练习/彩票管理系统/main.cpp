#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <algorithm>
#include <fstream>

using namespace std;

vector<int> select_red(const vector<int>& rvec)		//选择红球并放入
{
	vector<int> r_vec;
	for (auto i =0 ; r_vec.size() < 6; i++)
	{
		int r_index = rand() % 33;
		if (find(r_vec.cbegin(),r_vec.cend(),rvec[r_index]) == r_vec.cend())
		{
			r_vec.push_back(rvec[r_index]);
		}
	}
	return r_vec;
}

vector<int> select_blue(const vector<int>& bvec, vector<int> r_vec)			//选择红球并放入
{
	int b_index = rand() % 16;
	r_vec.push_back(bvec[b_index]);
	return r_vec;
}

void show_vec(vector<int>& vec)
{
	for (size_t i = 0; i < 7; i++)
	{
		if (i == 6)
		{
			cout << "+ ";
		}
		cout << vec[i] << " ";
	}
	//cout << endl;
}

//void show_set(set<vector<int>>& rb_set)
//{
//	for (set<vector<int>>::const_iterator it = rb_set.cbegin(); it != rb_set.cend(); it++)
//	{
//		show_vec((*it));
//	}
//}

int main()
{
	system("color 0A");
	srand(static_cast<unsigned int>(time(0)));		//随机数种子
	const vector<int>rvec = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
				17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33 };	//红球1-33

	const vector<int>bvec = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};	//篮球1-16
	
	vector<int> one;			//中奖号码
	vector<int> chance;			//选择彩票
	set<vector<int>> rb_set;	//总号码池

	one = select_blue(bvec, select_red(rvec));			//选出中奖号码
	sort(one.begin(), one.end() - 1);					//排序中奖号码

	//ofstream out("buy_ticket.txt");
	cout << "一等奖奖号码为：";
	//out << "一等奖奖号码为：";
	show_vec(one);

	bool not_get_it = true;
	int total_guess= 1;

	while (not_get_it)
	{
		chance = select_blue(bvec, select_red(rvec));		//选出彩票
		sort(chance.begin(), chance.end() - 1);				//排序彩票

		//cout << "第 " << total_guess << " 次购买的号码为：";
		//out  << "第 " << total_guess << " 次购买的号码为：";
		show_vec(chance);
		if (one == chance)
		{
			cout << "\t中奖了!中奖了!中奖了!" << endl;
			cout << "\t奖金10000万元!" << endl;
			cout << "\t奖金10000万元!" << endl;
			cout << "\t奖金10000万元!" << endl;
			not_get_it = false;
		}
		if (total_guess == 1000000 || total_guess == 10000000||total_guess==100000000)
		{
			cout << total_guess << " ";
		}
		total_guess++;
		//auto it = rb_set.find(chance);
		//if (it == rb_set.end())
		//{
		//	rb_set.insert(chance);								//排序后的球插入彩票池
		//}
	}
	return 0;
}