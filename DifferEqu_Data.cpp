#include "pch.h"
#include "DifferEqu_Data.h"

int DifferEqu_Data::data_Calculation(int n)
{
	int ret = 0;
	int tmp = 1;
	for (int i = 1; i <= n; i++)
	{
		tmp = tmp * a;
	}
	ret = tmp * y0;

	return ret;
}
