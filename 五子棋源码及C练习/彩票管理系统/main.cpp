#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <algorithm>
#include <fstream>

using namespace std;

vector<int> select_red(const vector<int>& rvec)		//ѡ����򲢷���
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

vector<int> select_blue(const vector<int>& bvec, vector<int> r_vec)			//ѡ����򲢷���
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
	srand(static_cast<unsigned int>(time(0)));		//���������
	const vector<int>rvec = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
				17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33 };	//����1-33

	const vector<int>bvec = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};	//����1-16
	
	vector<int> one;			//�н�����
	vector<int> chance;			//ѡ���Ʊ
	set<vector<int>> rb_set;	//�ܺ����

	one = select_blue(bvec, select_red(rvec));			//ѡ���н�����
	sort(one.begin(), one.end() - 1);					//�����н�����

	//ofstream out("buy_ticket.txt");
	cout << "һ�Ƚ�������Ϊ��";
	//out << "һ�Ƚ�������Ϊ��";
	show_vec(one);

	bool not_get_it = true;
	int total_guess= 1;

	while (not_get_it)
	{
		chance = select_blue(bvec, select_red(rvec));		//ѡ����Ʊ
		sort(chance.begin(), chance.end() - 1);				//�����Ʊ

		//cout << "�� " << total_guess << " �ι���ĺ���Ϊ��";
		//out  << "�� " << total_guess << " �ι���ĺ���Ϊ��";
		show_vec(chance);
		if (one == chance)
		{
			cout << "\t�н���!�н���!�н���!" << endl;
			cout << "\t����10000��Ԫ!" << endl;
			cout << "\t����10000��Ԫ!" << endl;
			cout << "\t����10000��Ԫ!" << endl;
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
		//	rb_set.insert(chance);								//������������Ʊ��
		//}
	}
	return 0;
}