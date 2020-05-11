#pragma once
#include <vector>
#include "DifferEqu_Data.h"
#include "mysql.h"
#pragma comment(lib,"libmysql.lib")

using namespace std;

class SQL_Query // 数据处理层   接口类
{
public:
	bool init();    // 数据库的初始化

	vector<DifferEqu_Data> getData(); // 设置数据    从数据库获取数据
	
	~SQL_Query();
private:
	MYSQL* data_Init = NULL;
};