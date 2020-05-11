#pragma once
struct DifferEqu_Data  // 差分方程数据
{
	int a;
	int y0;

	// 用来计算对应的差分值，n 表示计算 Yn
	int data_Calculation(int n);
};

