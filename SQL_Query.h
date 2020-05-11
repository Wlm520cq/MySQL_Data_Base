#pragma once
#include <vector>
#include "DifferEqu_Data.h"
#include "mysql.h"
#pragma comment(lib,"libmysql.lib")

using namespace std;

class SQL_Query // ���ݴ����   �ӿ���
{
public:
	bool init();    // ���ݿ�ĳ�ʼ��

	vector<DifferEqu_Data> getData(); // ��������    �����ݿ��ȡ����
	
	~SQL_Query();
private:
	MYSQL* data_Init = NULL;
};