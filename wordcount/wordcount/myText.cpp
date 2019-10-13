#include "pch.h"
#include"myText.h"
// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的
typedef pair<string, int> PAIR;

struct cmp
{
	bool operator()(const pair<string, int> &p1, const pair<string, int> &p2)
	{
		return p1.second > p2.second;
	}
};
//打开文件
void myText::getfile(string path)
{
	this->path = path;
}

//统计频率最高的前n个单词
void myText::frequency(int n)
{
	ifile.open(path);
	string str;
	string sss;
	while (getline(ifile, sss))
	{
		str += sss;
	}
	stringstream ss(str);
	string s;
	vector<string>vt;
	map<string, int>m1;
	while (getline(ss, s, ' '))
	{
		int flag = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < s.size())
		{
			if (s[i] <= 'z'&& s[i] >= 'a' || s[i] <= 'Z'&& s[i] >= 'A')
			{
				j++;
				if (s[i] <= 'Z'&& s[i] >= 'A')
				{
					s[i] += 32;
				}
			}
			else
			{
				k++;
			}

			if (j < 4 && k>0)
			{
				i++;
				flag = 0;
				break;
			}
			else if (j >= 4)
			{
				i++;
				flag = 1;
			}
			else
			{
				i++;
				flag = 0;
			}
		}
		if (flag == 1)
			vt.push_back(s);
	}
	for (int i = 0; i < vt.size(); i++)
	{
		m1[vt[i]] += 1;
	}

	//cout << "字符串单词总个数 : " << vt.size() << endl;
	//cout << "不同单词的个数 : " << m1.size() << endl;
	cout << "前" << n << "个不同单词出现的频率 :" << endl;

	vector<pair<string, int>>vt2(m1.begin(), m1.end());
	sort(vt2.begin(), vt2.end(), cmp());
	int k = 0;
	for (vector<pair<string, int>>::iterator it = vt2.begin(); it != vt2.end(); it++)
	{
		k++;
		cout << it->first << " ：" << it->second << endl;
		if (k > n)
		{
			break;
		}
	}
	ifile.close();
}
//普通统计频率和单词
void myText::frequency()
{
	ifile.open(path);
	string str;
	string sss;
	while (getline(ifile, sss))
	{
		str += sss;
	}
	stringstream ss(str);
	string s;
	vector<string>vt;
	map<string, int>m1;
	while (getline(ss, s, ' '))
	{
		int flag = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < s.size())
		{
			if (s[i] <= 'z'&& s[i] >= 'a' || s[i] <= 'Z'&& s[i] >= 'A')
			{
				j++;
				if (s[i] <= 'Z'&& s[i] >= 'A')
				{
					s[i] += 32;
				}
			}
			else
			{
				k++;
			}

			if (j < 4 && k>0)
			{
				i++;
				flag = 0;
				break;
			}
			else if (j >= 4)
			{
				i++;
				flag = 1;
			}
			else
			{
				i++;
				flag = 0;
			}
		}
		if (flag == 1)
			vt.push_back(s);
	}
	for (int i = 0; i < vt.size(); i++)
	{
		m1[vt[i]] += 1;
	}

	cout << "总的单词个数：" << vt.size() << endl;
	cout << "不同单词的个数 : " << m1.size() << endl;
	cout << "不同单词出现的频率 :" << endl;

	vector<pair<string, int>>vt2(m1.begin(), m1.end());
	sort(vt2.begin(), vt2.end(), cmp());
	int k = 0;
	for (vector<pair<string, int>>::iterator it = vt2.begin(); it != vt2.end(); it++)
	{
		k++;
		cout << it->first << " ：" << it->second << endl;
		if (k > 10)
		{
			break;
		}
	}
	ifile.close();
}
//字符长度为n的单词
void myText::nWords(int n)
{
	ifile.open(path);
	string str;
	string sss;
	while (getline(ifile, sss))
	{
		str += sss;
	}
	stringstream ss(str);
	string s;
	vector<string>vt;
	map<string, int>m1;
	while (getline(ss, s, ' '))
	{
		int flag = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < s.size())
		{
			if (s[i] <= 'z'&& s[i] >= 'a' || s[i] <= 'Z'&& s[i] >= 'A')
			{
				j++;
				if (s[i] <= 'Z'&& s[i] >= 'A')
				{
					s[i] += 32;
				}
			}
			else
			{
				k++;
			}

			if (j < 1 && k>0)
			{
				i++;
				flag = 0;
				break;
			}
			else if (j + k == n)
			{
				i++;
				flag = 1;
			}
			else
			{
				i++;
				flag = 0;
			}
		}
		if (flag == 1)
			vt.push_back(s);
	}
	for (int i = 0; i < vt.size(); i++)
	{
		m1[vt[i]] += 1;
	}

	cout << "字符长度为 " << n << "的单词个数：" << vt.size() << endl;
	cout << "不同单词的个数 : " << m1.size() << endl;
	cout << "不同单词出现的频率 :" << endl;

	vector<pair<string, int>>vt2(m1.begin(), m1.end());
	sort(vt2.begin(), vt2.end(), cmp());
	int k = 0;
	for (vector<pair<string, int>>::iterator it = vt2.begin(); it != vt2.end(); it++)
	{
		k++;
		cout << it->first << " ：" << it->second << endl;
		if (k > 10)
		{
			break;
		}
	}
	ifile.close();
}
//写到文件中
void myText::writeToFile(string path)
{
	ifile.open(this->path);
	ofstream outfile(path, ios::app);
	string str;
	string sss;
	while (getline(ifile, sss))
	{
		str += sss;
	}
	stringstream ss(str);
	string s;
	vector<string>vt;
	map<string, int>m1;
	while (getline(ss, s, ' '))
	{
		int flag = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < s.size())
		{
			if (s[i] <= 'z'&& s[i] >= 'a' || s[i] <= 'Z'&& s[i] >= 'A')
			{
				j++;
				if (s[i] <= 'Z'&& s[i] >= 'A')
				{
					s[i] += 32;
				}
			}
			else
			{
				k++;
			}

			if (j < 4 && k>0)
			{
				i++;
				flag = 0;
				break;
			}
			else if (j >= 4)
			{
				i++;
				flag = 1;
			}
			else
			{
				i++;
				flag = 0;
			}
		}
		if (flag == 1)
			vt.push_back(s);
	}
	for (int i = 0; i < vt.size(); i++)
	{
		m1[vt[i]] += 1;
	}
	outfile << "字符串单词总个数 : " << vt.size() << endl;
	outfile << "不同单词的个数 : " << m1.size() << endl;
	outfile << "不同单词出现的频率 :" << endl;

	map<string, int>::iterator it;

	for (it = m1.begin(); it != m1.end(); it++)
	{
		outfile << "<" << it->first << ">" << ":" << it->second << endl;
	}

	outfile.close();
	ifile.close();
}

myText::myText()
{
}

myText::~myText()
{
	ifile.close();
}
// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。
