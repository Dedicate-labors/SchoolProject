#include"pch.h"
#include"NumEssay.h"
#include<ios>
#include<cstdio>
#include<string>
#include<iostream>


int NumEssay::linenum() // 输出行数
{
	in.open(file_name, std::ios::in);
	int count = 0;
	if (in.is_open()) //检查文件是否打开
	{
		while (!in.eof())
		{
			if (in.good()) ///如果文件流对，就继续运行
			{
				getline(in, buffer);
				if (buffer != "")
					++count;
			}
			else
			{
				std::cout << "Error:读取的文件可能过大内存无法存储" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Open " << file_name << "failing!!!" << std::endl;
	}
	in.close();
	return count;
}

int NumEssay::charnum()
{
	in.open(file_name, std::ios::in);
	int count = 0;
	if (in.is_open())//检查文件是否打开
	{
		while (!in.eof())
		{
			if (in.good())//如果文件流对，就继续运行
			{
				getline(in, buffer);
				if (buffer != "")
				{
					count += buffer.size();
					if (!in.eof())
						count += 1; //加上换行符
				}
				else if (!in.eof())//buffer为空，但是为换行符, 
				{
					count += 1;
				}
			}
			else
			{
				std::cout << "Error:读取的文件有错误" << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Open " << file_name << "failing!!!" << std::endl;
	}
	in.close();
	return count;
}

void  NumEssay::print(int &lnum, int &chnum)//进行打印
{
	std::cout << "行数：" << lnum << std::endl;
	std::cout << "字符数：" << chnum << std::endl;
}

void NumEssay::print(const std::string &out_file, int &lnum, int &chnum)//打印到文件中
{
	out.open(out_file, std::ios::out);
	out << "行数：" << lnum << "\n";
	out << "字符数：" << chnum << "\n";
	out.close();
	std::cout << "保存成功!" << std::endl;
}