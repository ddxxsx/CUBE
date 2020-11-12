#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#define RU RUBIC 
using namespace std;
typedef long long (LL);
class Rubic
{
public:
	/*
	Rubic()
	{
		memset(a,0,sizeof(a));
	}
	*/
	
	void Rotate();//旋转魔方至上黄下白前红 
	 
	void RotateCW(int S);//0顺时针旋转某个平面
	void RotateAC(int S);//逆时针旋转某个平面
	
	void F();
	void R();
	void U();
	void B();
	void L();
	void D();
	void M();
	void E();

	void F_();
	void R_();
	void U_();
	void B_();
	void L_();
	void D_();
	void M_();
	void E_();
	
	void F2();
	void R2();
	void U2();
	void B2();
	void L2();
	void D2();
	void M2();
	void E2();

	//void f();
	//void r();
	void u();
	void d();

	void x();//整个魔方的R 
	void y();//整个魔方的U 
	void z();//整个魔方的F 
	void x_();
	void y_();
	void z_();
	void x2();
	void y2();
	void z2();
	
	
	int a[10][5][5];	
	/*
	12前后 34左右 56上下
	1白2黄3红4橙5蓝6绿 
	对面条件为差绝对值为1且较小数为奇数 
	*/
}; 
bool Opp(int X,int Y); //判读两个方块的颜色是否是对色
void Rubic::Rotate()
{
	if(a[6][2][2]!=1)//把白转到下面 
		{
			if(a[3][2][2]==1 || a[4][2][2]==1)
				for(;a[6][2][2]!=1;z())
					;
			if(a[1][2][2]==1 || a[2][2][2]==1 || a[5][2][2]==1)
				for(;a[6][2][2]!=1;x())
					;		
		}
	for(;a[1][2][2]!=3;y())
		; 
}
void Rubic::RotateCW(int S)
{
	int i,j,temp[5][5];
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			temp[j][4-i]=a[S][i][j];
	for(i=1;i<=3;i++)
		 for(j=1;j<=3;j++)
		 	a[S][i][j]=temp[i][j];
}
void Rubic::RotateAC(int S)
{
	RotateCW(S);RotateCW(S);RotateCW(S);
} 
void Rubic::F()
{
	int i,temp[5];
	RotateCW(1);
	for(i=1;i<=3;i++)
		{
			temp[i]=a[3][4-i][3];
			a[3][4 - i][3] = a[6][1][4 - i];
			a[6][1][4 - i] = a[4][i][1];
			a[4][i][1]=a[5][3][i];
			a[5][3][i]=temp[i];
		}
}
void Rubic::R()
{
	y();F();y_();
} 
void Rubic::U()
{
	x_();F();x();	
}
void Rubic::B()
{
	y(); y(); F(); y_(); y_();
}
void Rubic::L()
{
	y_(); F(); y();
}
void Rubic::D()
{
	x(); F(); x_();
}
void Rubic::M()
{
	R();L_();x_();
}
void Rubic::E()
{
	U();D_();y_();
}
void Rubic::F_()
{
	F();F();F();
}
void Rubic::R_()
{
	R();R();R();
}
void Rubic::U_()
{
	U();U();U();
}
void Rubic::B_()
{
	B();B();B();
}
void Rubic::L_()
{
	L();L();L();
}
void Rubic::D_()
{
	D();D();D();	
}
void Rubic::M_()
{
	M();M();M();
}
void Rubic::E_()
{
	E(); E(); E();
}
void Rubic::F2()
{
	F();F();
}
void Rubic::R2()
{
	R();R();
}
void Rubic::U2()
{
	U();U();
}
void Rubic::B2()
{
	B();B();
}
void Rubic::L2()
{
	L();L();
}
void Rubic::D2()
{
	D();D();
}
void Rubic::M2()
{
	M();M();
}
void Rubic::E2()
{
	E(); E();
}
void Rubic::u()
{
	D();y();
}
void Rubic::d()
{
	U();y_();
}
void Rubic::x()
{
	int i,j,temp[5][5];
	RotateCW(4);
	RotateAC(3);
	RotateCW(2);
	RotateCW(2);
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			{
				temp[i][j]=a[1][i][j];
				a[1][i][j]=a[6][i][j];
				a[6][i][j]=a[2][i][j];
				a[2][i][j]=a[5][i][j];
				a[5][i][j]=temp[i][j];
			}
	RotateCW(2);
	RotateCW(2);
}
void Rubic::y()
{
	int i,j,temp[5][5];
	RotateCW(5);
	RotateAC(6);
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			{
				temp[i][j]=a[1][i][j];
				a[1][i][j]=a[4][i][j];
				a[4][i][j]=a[2][i][j];
				a[2][i][j]=a[3][i][j];
				a[3][i][j]=temp[i][j];
			}
}
void Rubic::z()
{
	int i,j,temp[5][5];
	RotateCW(1);
	RotateAC(2); 
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			{
				temp[i][j]=a[5][i][j];
				a[5][i][j]=a[3][i][j];
				a[3][i][j]=a[6][i][j];
				a[6][i][j]=a[4][i][j];
				a[4][i][j]=temp[i][j];
			}
	RotateCW(4);
	RotateCW(6);
	RotateCW(3);
	RotateCW(5);
}
void Rubic::x_()
{
	x();x();x();
}
void Rubic::y_()
{
	y();y();y();
}
void Rubic::z_()
{
	z();z();z();	
}
void Rubic::x2()
{
	x();x();
}
void Rubic::y2()
{
	y();y();
}
void Rubic::z2()
{
	z();z();
}
bool Opp(int X,int Y)
{
	if(abs(X-Y)==1 && min(X,Y)%2) return true;
	return false; 
}

