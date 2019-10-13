#pragma once
#include"pch.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;
class myText
{
public:
	myText();
	~myText();
	void getfile(string path);//获得读取的文件
	void frequency();//单词总数和前10个频率最高的单词
	void frequency(int n);//频率最高的前n个单词
	void nWords(int n);//字符为n的单词个数和频率
	void writeToFile(string path);//写到文件
private:
	ifstream ifile;
	string path;

};
