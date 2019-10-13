#pragma once
#include"pch.h"
#include<string>
#include<fstream>

class NumEssay { //功能类, 全部是public 无privated
public:
	void read(std::string file_name) {
		this->file_name = file_name;
	}
	int linenum();
	int charnum();
	//输出部分
	void print(int &lnum, int &chnum);//终端展示
	void print(const std::string &out_file, int &lnum, int &chnum);//输入到文件
private:
	std::string file_name; //存储文件名
	std::string buffer; // 存储内存
	std::fstream in, out;//in 用来读入， out用来输出
};


