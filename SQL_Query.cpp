#include "pch.h"
#include "SQL_Query.h"

bool SQL_Query::init()
{
	
		// 1.��ʼ�����ݿ�����
		data_Init = mysql_init(NULL);

		/*
		MYSQL* STDCALL mysql_real_connect(
			MYSQL * mysql,            // MySQL���ݿ�����
			const char* host,         // MySQL������������������IP��ַ
			const char* user,         // MySQL���������û���
			const char* passwd,       // MySQL������ָ���û���Ӧ������
			const char* db,           // ���ݿ���
			unsigned int port,        // MySQL���ݿ�Ķ˿ںţ�ʹ��0����ʾĬ�϶˿ں�
			const char* unix_socket,  //һ��ʹ��null����ʾ��ʹ��socket��ܵ�����
			unsigned long clientflag);//һ��ʹ��0
		*/
		// 2.�������ݿ�
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
	//������һ���յ�����
	vector<DifferEqu_Data> data_vector;
	DifferEqu_Data data_Block;

	// 1.1 ׼������
	const char* handle_Command = "select * from qichi";
	// 1.2 ��������
	int work_DataCommand = mysql_query(data_Init, handle_Command);
	// 1.3 �ж��Ƿ�Ϊ��
	/*if (work_DataCommand)
	{
		printf("���Ͳ�ѯ����ʧ�ܣ�\n");
		return;
	}*/

	// 2.�����ݿ��������ȡ���
	// ����ֵ��ָ������ָ��
	// �����ô����ݵĻ�ȡ �����ݻ�ȡ���������ʱ����ȡ������
	MYSQL_RES* data_Res_ptr = mysql_store_result(data_Init);
	if (data_Res_ptr == NULL)
	{
		exit(1);
	}

	// 3.�����ؽ��
	int result_rows = mysql_num_rows(data_Res_ptr);

	// �����ý��������
	for (int i = 0; i < result_rows; i++)
	{
		// 3.1 �ӽ��֮��ȡ��һ������
		MYSQL_ROW data_row = mysql_fetch_row(data_Res_ptr);
		// 3.2 ��������
		// ��ȡ��һ�������еĸ��е�����
		data_Block.a = atoi(data_row[0]);  // ��1������
		data_Block.y0 = atoi(data_row[1]); // ��2������
		// 3.3 ��������
		data_vector.push_back(data_Block);
		//data_Calculation(a, y0);
		// 3.4 ������ʾ������
	}

	return data_vector;
}

SQL_Query::~SQL_Query()
{
	vector<DifferEqu_Data> getData();
}