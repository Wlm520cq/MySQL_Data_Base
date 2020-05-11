#include <stdio.h>
#include "mysql.h"
#pragma comment(lib,"libmysql.lib")

using namespace std;

// ���ݿ�����
MYSQL* data_Init = NULL;

// �����ݿ���صĿ�������

// ���ݿ�ĳ�ʼ��
bool data_Base_Init()
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
		printf("�������ݿ������ʧ�ܣ�\n");
		return false;
	}
	else
	{
		return true;
	}
}

// ���ݵ�ҵ�����
void data_Calculation(int a,int y0)
{
	printf("��ַ���:a = %d\ty0 = %d\n", a, y0);
	int ret = 0;
	int tmp = 1;
	for (int i = 1; i <= 5; i++)
	{
		tmp = tmp * a;
		ret = tmp * y0;
		printf("Y%d = %d\n", i, ret);
	}
	printf("\n");
}

// ������������
void handle_Work()
{
	// 1.1 ׼������
	const char* handle_Command = "select * from qichi";
	// 1.2 ��������
	int work_DataCommand = mysql_query(data_Init, handle_Command);
	// 1.3 �ж��Ƿ�Ϊ��
	if (work_DataCommand)
	{
		printf("���Ͳ�ѯ����ʧ�ܣ�\n");
		return;
	}

	// 2.�����ݿ��������ȡ���
	// ����ֵ��ָ������ָ��
	// �����ô����ݵĻ�ȡ �����ݻ�ȡ���������ʱ����ȡ������
	MYSQL_RES* data_Res_ptr = mysql_store_result(data_Init);
	if (data_Res_ptr == NULL)
	{
		printf("��ȡ��ѯ���ʧ��!\n");
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
		int a = atoi(data_row[0]);  // ��1������
		int y0 = atoi(data_row[1]); // ��2������
		// 3.3 ��������
		data_Calculation(a, y0);
		// 3.4 ������ʾ������
	}
}

int main()
{
	bool judgment_Data = data_Base_Init(); // ��ȡ��ʼ���ķ���ֵ 
	if (judgment_Data == false)
	{
		printf("���ݿ��ʼ��ʧ�ܣ�");
		return 1;
	}
	printf("���ݿ����ӳɹ���\n");

	// ��������
	handle_Work();
	return 0;
}