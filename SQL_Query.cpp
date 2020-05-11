#include "pch.h"
#include "SQL_Query.h"

bool SQL_Query::init()
{
	
		// 1.初始化数据库链接
		data_Init = mysql_init(NULL);

		/*
		MYSQL* STDCALL mysql_real_connect(
			MYSQL * mysql,            // MySQL数据库链接
			const char* host,         // MySQL服务器的主机名或者IP地址
			const char* user,         // MySQL服务器的用户名
			const char* passwd,       // MySQL服务器指定用户对应的密码
			const char* db,           // 数据库名
			unsigned int port,        // MySQL数据库的端口号，使用0，表示默认端口号
			const char* unix_socket,  //一般使用null，表示不使用socket或管道机制
			unsigned long clientflag);//一般使用0
		*/
		// 2.链接数据库
		if (mysql_real_connect(data_Init, "118.126.117.125", "root",
			"linuxpzj", "chafen", 0, NULL, 0) == NULL)
			//if (mysql_real_connect(data_Init, "118.126.122.255", "dawn_centos",
			//	"dawn", "equation", 0, NULL, 0) == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}


vector<DifferEqu_Data> SQL_Query::getData()
{
	//定义了一个空的容器
	vector<DifferEqu_Data> data_vector;
	DifferEqu_Data data_Block;

	// 1.1 准备命令
	const char* handle_Command = "select * from qichi";
	// 1.2 发送命令
	int work_DataCommand = mysql_query(data_Init, handle_Command);
	// 1.3 判断是否为空
	/*if (work_DataCommand)
	{
		printf("发送查询命令失败！\n");
		return;
	}*/

	// 2.从数据库服务器获取结果
	// 返回值：指向结果的指针
	// 不适用大数据的获取 大数据获取容易造成延时，获取数据慢
	MYSQL_RES* data_Res_ptr = mysql_store_result(data_Init);
	if (data_Res_ptr == NULL)
	{
		exit(1);
	}

	// 3.处理返回结果
	int result_rows = mysql_num_rows(data_Res_ptr);

	// 便利该结果的数据
	for (int i = 0; i < result_rows; i++)
	{
		// 3.1 从结果之中取出一行数据
		MYSQL_ROW data_row = mysql_fetch_row(data_Res_ptr);
		// 3.2 解析数据
		// 获取这一行数据中的各列的数据
		data_Block.a = atoi(data_row[0]);  // 第1列数据
		data_Block.y0 = atoi(data_row[1]); // 第2列数据
		// 3.3 处理数据
		data_vector.push_back(data_Block);
		//data_Calculation(a, y0);
		// 3.4 数据显示到界面
	}

	return data_vector;
}

SQL_Query::~SQL_Query()
{
	vector<DifferEqu_Data> getData();
}