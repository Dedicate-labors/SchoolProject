#include"pch.h"
#include"NumEssay.h"
#include"myText.h"
#include<string>
#include<cstring>
#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;
int flag[4] = { 0 }, sum=0;
vector<string> pd(4);


int CheckArgs()
{
	if(sum <=0 || sum > 4) { 
		cout << "请输入正确的参数格式" << endl;
		exit(-1);
	} 
	if(!flag[0] || pd[0] != "input.txt") 
	{
		cout << "请输入正确文件名" << endl;
		exit(-1);
	}
	if(!flag[3])
	{     
		cout << "请输入正确输出文件" << endl;
		exit(-1);
	}
} 

int main(int argv, char *args[])
{
	char str[][3] = { "-i", "-m", "-n", "-o" };
	//参数操作
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < argv; j++)
		{
			if (!strcmp(str[i], args[j]))
			{
				flag[i] += 1;
				sum++;
				try {
					j++;
					if (j >= argv)
						throw -1;
					pd[i] = args[j]; //后面下标越界或者是一个错误值
				}
				catch (int e)
				{
					cout << "输入的参数有误或者有为空的" << endl;
					exit(e);
				}
				break;
			}
		}
	}
	//检查参数是否正确
	CheckArgs();
	
	NumEssay Essay;//功能类名
	myText T;
	int NChar=0, NLin=0;//存储字符数 行数

	cout << "======================" << endl;
	
	if (flag[0]) //-i 0 写的多一些 输入文件名， 打印基本信息
	{
		Essay.read(pd[0]);
		NChar = Essay.charnum();
		NLin = Essay.linenum();
		Essay.print(NLin, NChar);
		T.getfile(pd[0]);
		T.frequency();
	}
	if (flag[1]) //-m 1
	{
		//cout << pd[1] << endl;
		//cout << stoi(pd[1]) << endl;
		T.nWords(stoi(pd[1]));
	}
	if (flag[2]) //-n 2
	{
		//cout << pd[2] << endl;
		//cout << stoi(pd[2]) << endl;
		T.frequency(stoi(pd[2]));
	}
	if (flag[3]) //-o 3 打印进文件中
	{
		Essay.print(pd[3], NLin, NChar);
		T.writeToFile(pd[3]);
	}
	return 0;
}
