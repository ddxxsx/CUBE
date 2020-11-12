#include <opencv2\opencv.hpp>
#include "core/core.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\imgproc\types_c.h>
#include <iostream>
#include <fstream>
#include "Rubic.h"

Rubic CX;
using namespace std;
using namespace cv;

Mat frame, frame2, frame_a, frame_b, frame_c, frame2_a, frame2_b, frame2_c;
long int num = -1;
int rubic[6][6];//[3][3]
int color[36];
int i, j, k, n, H, S, V, m, s;
int F, B, L, R, U, D;




void cout_CWi(int i);
void cout_ACi(int i);
void CW(int i);//顺时针旋转某个面
void AC(int i);//逆时针旋转某个面
void Cross1();//顶层十字1
void First();//一层复原
void Second();//二层复原
void Cross2();//顶层十字2
void Up();//顶层复原
void Third();//三层复原
void Fin();//最终复原
void Print(int i);
int GetCross();
int GetCross2();
int GetUp();
int GetDC();
int GetSE();
bool Get(int y);
/////////////////////////////////
void a1();
void a2();
void a3();
void a4();
void A5();
void jiao1();
void jiao2();
void jiao3();
int check1();
int check2();
void l();
void l_();
void l2();
void d();
void d_();
void d2();
void try1();
void try2();
//角块调整第一招//
void jiao1()
{

	if (((CX.a[1][1][1] == CX.a[5][2][2]) || (CX.a[1][1][1] == CX.a[6][2][2])) && ((CX.a[2][1][3] == CX.a[5][2][2]) || (CX.a[2][1][3] == CX.a[6][2][2])))
	{
		CX.R(); CX.U(); CX.R_(); CX.U(); CX.R(); CX.U2(); CX.R_(); CX.L(); CX.U_(); CX.L_(); CX.U_(); CX.L_(); CX.U2(); CX.L();
	}
	if (((CX.a[1][1][3] == CX.a[5][2][2]) || (CX.a[1][1][3] == CX.a[6][2][2])) && ((CX.a[2][1][1] == CX.a[5][2][2]) || (CX.a[2][1][1] == CX.a[6][2][2])))
	{
		CX.L(); CX.U_(); CX.L_(); CX.U_(); CX.L_(); CX.U2(); CX.L();  CX.R(); CX.U(); CX.R_(); CX.U(); CX.R(); CX.U2(); CX.R_();
	}
}


//角块调整第二招//
void jiao2()
{

	if (((CX.a[3][1][1] == CX.a[5][2][2] || CX.a[3][1][1] == CX.a[6][2][2])) && ((CX.a[3][1][3] == CX.a[5][2][2] || CX.a[3][1][3] == CX.a[6][2][2])))
	{
		CX.L_(); CX.U2(); CX.L(); CX.U(); CX.L_(); CX.U(); CX.L();    CX.R(); CX.U2(); CX.R_(); CX.U_(); CX.R(); CX.U_(); CX.R_();
	}
	if (((CX.a[4][1][1] == CX.a[5][2][2] || CX.a[4][1][1] == CX.a[6][2][2])) && ((CX.a[4][1][3] == CX.a[5][2][2] || CX.a[4][1][3] == CX.a[6][2][2])))
	{
		CX.R(); CX.U2(); CX.R_(); CX.U_(); CX.R(); CX.U_(); CX.R_();  CX.L_(); CX.U2(); CX.L(); CX.U(); CX.L_(); CX.U(); CX.L();
	}
}


//角块调整第三招//
void jiao3()
{
	if ((CX.a[3][1][3] == CX.a[5][2][2] || CX.a[3][1][3] == CX.a[6][2][2]) && (CX.a[2][1][1] == CX.a[5][2][2] || CX.a[2][1][1] == CX.a[6][2][2]))
	{
		CX.z_(); CX.R(); CX.U(); CX.R_(); CX.U_(); CX.R(); CX.U(); CX.R_(); CX.U_(); CX.L2();
		CX.U(); CX.R(); CX.U_(); CX.R_(); CX.U(); CX.R(); CX.U_(); CX.R_(); CX.L2(); CX.z();
	}

	if ((CX.a[1][1][1] == CX.a[5][2][2] || CX.a[1][1][1] == CX.a[6][2][2]) && (CX.a[4][1][3] == CX.a[5][2][2] || CX.a[4][1][3] == CX.a[6][2][2]))
	{
		CX.z_();  CX.U(); CX.R(); CX.U_(); CX.R_(); CX.U(); CX.R(); CX.U_(); CX.R_(); CX.L2();
		CX.R(); CX.U(); CX.R_(); CX.U_(); CX.R(); CX.U(); CX.R_(); CX.U_(); CX.L2(); CX.z();
	}

	if ((CX.a[2][1][1] == CX.a[5][2][2] || CX.a[2][1][1] == CX.a[6][2][2]) && (CX.a[1][1][1] == CX.a[5][2][2] || CX.a[1][1][1] == CX.a[6][2][2]) && (CX.a[3][1][1] == CX.a[5][2][2] || CX.a[3][1][1] == CX.a[6][2][2]))
	{
		CX.z_();    CX.R(); CX.U(); CX.R_(); CX.U_(); CX.R(); CX.U(); CX.R_(); CX.U_(); CX.L();
		CX.R(); CX.U(); CX.R_(); CX.U_(); CX.R(); CX.U(); CX.R_(); CX.U_(); CX.L();
		CX.R(); CX.U(); CX.R_(); CX.U_(); CX.R(); CX.U(); CX.R_(); CX.U_(); CX.L();
		CX.L();     CX.z();
	}

	if ((CX.a[2][1][3] == CX.a[5][2][2] || CX.a[2][1][3] == CX.a[6][2][2]) && (CX.a[3][1][3] == CX.a[5][2][2] || CX.a[3][1][3] == CX.a[6][2][2]) && (CX.a[4][1][3] == CX.a[5][2][2] || CX.a[4][1][3] == CX.a[6][2][2]))
	{
		CX.z_();   CX.U(); CX.R(); CX.U_(); CX.R_(); CX.U(); CX.R(); CX.U_(); CX.R_(); CX.L();
		CX.U(); CX.R(); CX.U_(); CX.R_(); CX.U(); CX.R(); CX.U_(); CX.R_(); CX.L();
		CX.U(); CX.R(); CX.U_(); CX.R_(); CX.U(); CX.R(); CX.U_(); CX.R_(); CX.L();
		CX.L();    CX.z();
	}
}
void l()
{
	CX.M(); CX.L();
	printf("ML");
}
void l_()
{
	CX.M(); CX.L(); CX.M(); CX.L(); CX.M(); CX.L();
	printf("M_L_");
}
void l2()
{
	CX.M(); CX.L(); CX.M(); CX.L();
	printf("M2L2");
}
void d()
{
	CX.E(); CX.D();
	printf("ED");
}
void d2()
{
	CX.E(); CX.D();    CX.E(); CX.D();
	printf("E2D2");
}
void d_()
{
	CX.E(); CX.D();    CX.E(); CX.D();    CX.E(); CX.D();
	printf("E_D_");
}
void a1()
{
	CX.R(); CX.U(); CX.R_(); CX.U_();
	CX.R_(); CX.F();
	CX.R2(); CX.U_(); CX.R_(); CX.U_();
	CX.R(); CX.U(); CX.R_(); CX.F_();
	printf("RUR_U_R_FR2U_R_U_RUR_F_");
}
void a2()
{
	CX.U();
	CX.z();
	CX.U_(); CX.R(); CX.D_();
	CX.R2();
	CX.U();
	CX.R_();
	CX.U_();
	CX.R2();
	CX.U();
	CX.z_(); CX.R(); CX.U_(); CX.U_();
	printf("UzU_RD_R2UR_U_R2Uz_RU_U_");
}
void a3()
{
	CX.R(); CX.U(); CX.R_(); CX.F_();
	CX.R(); CX.U(); CX.R_(); CX.U_();
	CX.R_(); CX.F(); CX.R2(); CX.U_(); CX.R_(); CX.U_();
	printf("RUR_F_RUR_U_R_FR2U_R_U_");

}
void a4()
{
	CX.R2(); CX.U_(); CX.R_(); CX.U_();
	CX.R(); CX.U(); CX.R(); CX.U();
	CX.R(); CX.U_(); CX.R();
	printf("R2U_R_U_RURURU_R");
}
void A5()
{
	CX.R(); CX.U(); CX.R(); CX.U2();
	CX.R_(); CX.L_(); CX.U(); CX.R(); CX.U_(); CX.L();
	CX.U2(); CX.R2();
	printf("RURU2R_L_URU_LU2R2");
}
int check1()
{
	if ((CX.a[1][1][2] == 3 && CX.a[5][3][2] == 1) || (CX.a[1][1][2] == 1 && CX.a[5][3][2] == 3))
		if ((CX.a[4][1][2] == 5 && CX.a[5][2][3] == 1) || (CX.a[4][1][2] == 1 && CX.a[5][2][3] == 5))
			if ((CX.a[2][1][2] == 4 && CX.a[5][1][2] == 1) || (CX.a[2][1][2] == 1 && CX.a[5][1][2] == 4))
				if ((CX.a[3][1][2] == 6 && CX.a[5][2][1] == 1) || (CX.a[3][1][2] == 1 && CX.a[5][2][1] == 6))

					if ((CX.a[1][2][3] == 3 && CX.a[4][2][1] == 5) || (CX.a[1][2][3] == 5 && CX.a[4][2][1] == 3))
						if ((CX.a[4][2][3] == 5 && CX.a[2][2][1] == 4) || (CX.a[4][2][3] == 4 && CX.a[2][2][1] == 5))
							if ((CX.a[2][2][3] == 4 && CX.a[3][2][1] == 6) || (CX.a[2][2][3] == 6 && CX.a[3][2][1] == 4))
								if ((CX.a[3][2][3] == 6 && CX.a[1][2][1] == 3) || (CX.a[3][2][3] == 3 && CX.a[1][2][1] == 6))

									if ((CX.a[6][1][2] == 2 && CX.a[1][3][2] == 3) || (CX.a[6][1][2] == 3 && CX.a[1][3][2] == 2))
										if ((CX.a[6][2][3] == 2 && CX.a[4][3][2] == 5) || (CX.a[6][2][3] == 5 && CX.a[4][3][2] == 2))
											if ((CX.a[6][3][2] == 2 && CX.a[2][3][2] == 4) || (CX.a[6][3][2] == 4 && CX.a[2][3][2] == 2))
												return 1;
	return 0;
}

int check2()
{
	int j, k;
	for (j = 1; j <= 3; j++)
		for (k = 1; k <= 3; k++)
		{
			if (CX.a[1][j][k] != 3) return 0;
			if (CX.a[2][j][k] != 4) return 0;
			if (CX.a[3][j][k] != 6) return 0;
			if (CX.a[4][j][k] != 5) return 0;
			if (CX.a[5][j][k] != 1) return 0;
			if (CX.a[6][j][k] != 2) return 0;
		}
	return 1;
}

void try1()
{
	int c, o, q;
	c = 0; o = 0; q = 0;
	if (!(CX.a[1][1][2] == 3 && CX.a[5][3][2] == 1)) { c = 3; o = 1; }
	if (!(CX.a[4][1][2] == 5 && CX.a[5][2][3] == 1)) { c = 5; o = 1; }
	if (!(CX.a[2][1][2] == 4 && CX.a[5][1][2] == 1)) { c = 4; o = 1; }
	if (!(CX.a[3][1][2] == 6 && CX.a[5][2][1] == 1)) { c = 6; o = 1; }

	if (!(CX.a[1][2][3] == 3 && CX.a[4][2][1] == 5)) { c = 3; o = 5; }
	if (!(CX.a[4][2][3] == 5 && CX.a[2][2][1] == 4)) { c = 5; o = 4; }
	if (!(CX.a[2][2][3] == 4 && CX.a[3][2][1] == 6)) { c = 4; o = 6; }
	if (!(CX.a[3][2][3] == 6 && CX.a[1][2][1] == 3)) { c = 6; o = 3; }

	if (!((CX.a[6][1][2] == 2 && CX.a[1][3][2] == 3) || (CX.a[6][1][2] == 3 && CX.a[1][3][2] == 2))) { c = 2; o = 3; }
	if (!((CX.a[6][2][3] == 2 && CX.a[4][3][2] == 5) || (CX.a[6][2][3] == 5 && CX.a[4][3][2] == 2))) { c = 2; o = 5; }
	if (!((CX.a[6][3][2] == 2 && CX.a[2][3][2] == 4) || (CX.a[6][3][2] == 4 && CX.a[2][3][2] == 2))) { c = 2; o = 4; }



	for (q = 1; q < 2; q++)
	{
		if ((c == 1) && (o == 3)) { a3(); continue; }
		if ((c == 3) && (o == 1)) { l_(); a2(); l(); continue; }
		if ((c == 2) && (o == 3)) { l2(); a2(); l2(); continue; }
		//ÒÑ¹éÎ»Á½¸ö//
		if ((c == 2) && (o == 5)) { d_(); l2(); a2(); l2(); d(); continue; }
		if ((c == 1) && (o == 4)) { a2(); continue; }
		if ((c == 4) && (o == 1)) { l(); a3(); l_(); continue; }
		if ((c == 2) && (o == 4)) { l2(); a3(); l2(); continue; }
		if ((c == 1) && (o == 6)) { a1(); continue; }
		if ((c == 6) && (o == 1)) { l(); d_(); l(); a1(); l_(); d(); l_(); continue; }
		if ((c == 2) && (o == 6)) { l2(); a1(); l2(); continue; }
		if ((c == 3) && (o == 5)) { d2(); l(); a1(); l_(); d2(); continue; }
		if ((c == 5) && (o == 3)) { d_(); l_(); a1(); l(); d(); continue; }
		if ((c == 3) && (o == 2)) { l_(); a3(); l(); continue; }
		if ((c == 5) && (o == 4)) { d(); l(); a1(); l_(); d_(); continue; }
		if ((c == 4) && (o == 5)) { d2(); l_(); a1(); l(); d2(); continue; }
		if ((c == 5) && (o == 2)) { d(); l(); a2; l_(); d_(); continue; }
		if ((c == 4) && (o == 6)) { l(); a1(); l_(); continue; }
		if ((c == 6) && (o == 4)) { d(); l_(); a1(); l(); d_(); continue; }
		if ((c == 4) && (o == 2)) { l(); a2(); l_(); continue; }
		if ((c == 6) && (o == 3)) { d_(); l(); a1(); l_(); d(); continue; }
		if ((c == 3) && (o == 6)) { l_(); a1(); l(); continue; }
		if ((c == 6) && (o == 2)) { d_(); l(); a2(); l_(); d(); continue; }
	}
}

void try2()
{
	int q, w, e;
	if (!(CX.a[5][3][3] == 1 && CX.a[1][1][3] == 3 && CX.a[4][1][1] == 5)) { q = 1; w = 3; e = 5; }
	if (!(CX.a[5][1][3] == 1 && CX.a[2][1][1] == 4 && CX.a[3][1][3] == 5)) { q = 1; w = 5; e = 4; }
	if (!(CX.a[5][3][1] == 1 && CX.a[3][1][3] == 6 && CX.a[1][1][1] == 3)) { q = 1; w = 6; e = 3; }
	if (!(CX.a[1][3][1] == 3 && CX.a[3][3][3] == 6 && CX.a[6][1][1] == 2)) { q = 3; w = 6; e = 2; }
	if (!(CX.a[1][3][3] == 3 && CX.a[4][3][1] == 5 && CX.a[6][1][3] == 2)) { q = 3; w = 2; e = 5; }
	if (!(CX.a[2][3][1] == 4 && CX.a[4][3][3] == 5 && CX.a[6][3][3] == 2)) { q = 4; w = 5; e = 2; }
	if (!(CX.a[2][3][3] == 4 && CX.a[3][3][1] == 6 && CX.a[6][3][1] == 2)) { q = 4; w = 2; e = 6; }





	if ((q == 5) && (w == 3) && (e == 2)) { A5(); }
	if ((q == 2) && (w == 3) && (e == 6)) { CX.F_(); printf("F_"); A5(); CX.F(); printf("F"); }
	if ((q == 2) && (w == 5) && (e == 3)) { CX.F_(); CX.R_(); printf("F_R_"); A5(); CX.R(); CX.F(); printf("RF"); }
	if ((q == 2) && (w == 4) && (e == 5)) { CX.R2(); CX.F(); printf("R2F"); A5(); CX.F_(); CX.R2(); printf("F_R2"); }
	if ((q == 2) && (w == 6) && (e == 4)) { CX.D2(); CX.R_(); CX.D_(); printf("D2R_D_"); A5(); CX.D(); CX.R(); CX.D2(); printf("DRD2"); }/////5.13
	if ((q == 3) && (w == 6) && (e == 2)) { CX.D(); printf("D"); A5(); CX.D_(); printf("D_"); }
	//已归位//
	if ((q == 4) && (w == 5) && (e == 2)) { CX.D_(); printf("D_"); A5(); CX.D(); printf("D"); }
	if ((q == 6) && (w == 4) && (e == 2)) { CX.D2(); printf("D2"); A5(); CX.D2(); printf("D2"); }
	if ((q == 6) && (w == 2) && (e == 3)) { CX.F2(); CX.R_(); printf("F2R_"); A5(); CX.R(); CX.F2(); printf("RF2"); }
	if ((q == 3) && (w == 2) && (e == 5)) { CX.D(); CX.R(); printf("DR"); A5(); CX.R_(); CX.D_(); printf("R_D_"); }
	if ((q == 5) && (w == 2) && (e == 4)) { CX.R(); printf("R"); A5(); CX.R_(); printf("R_"); }
	if ((q == 4) && (w == 2) && (e == 6)) { CX.D_(); CX.R(); printf("D_R"); A5(); CX.R_(); CX.D(); printf("R_D"); }
	if ((q == 1) && (w == 3) && (e == 5)) { CX.F(); printf("F"); A5(); CX.F_(); printf("F_"); }
	if ((q == 1) && (w == 5) && (e == 4)) { CX.R(); CX.D_(); printf("RD_"); A5(); CX.D(); CX.R_(); printf("DR_"); }
	if ((q == 1) && (w == 6) && (e == 3)) { CX.F(); CX.R_(); printf("FR_"); A5(); CX.R(); CX.F_(); printf("RF_"); }
	if ((q == 3) && (w == 5) && (e == 1)) { CX.F2(); CX.D(); printf("F2D"); A5(); CX.D_(); CX.F2(); printf("D_F2"); }
	if ((q == 5) && (w == 4) && (e == 1)) { CX.R2(); printf("R2"); A5(); CX.R2(); printf("R2"); }
	if ((q == 6) && (w == 3) && (e == 1)) { CX.F2(); printf("F2"); A5(); CX.F2(); printf("F2"); }
	if ((q == 5) && (w == 1) && (e == 3)) { CX.R_(); printf("R_"); A5(); CX.R(); printf("R"); }
	if ((q == 4) && (w == 1) && (e == 5)) { CX.R_(); CX.F(); printf("R_F"); A5(); CX.F_(); CX.R(); printf("F_R"); }
	if ((q == 3) && (w == 1) && (e == 6)) { CX.F_(); CX.D(); printf("F_D"); A5(); CX.D_(); CX.F(); printf("D_F"); }

}
/////////////////////////////////////////

void cout_CWi(int i)
{
	switch (i)
	{
	case 1: {
		cout << "F";
		break;
	}
	case 2: {
		cout << "B";
		break;
	}
	case 3: {
		cout << "L";
		break;
	}
	case 4: {
		cout << "R";
		break;
	}
	case 5: {
		cout << "U";
		break;
	}
	case 6: {
		cout << "D";
		break;
	}
	}
}
void cout_ACi(int i)
{
	switch (i)
	{
	case 1: {
		cout << "F_";
		break;
	}
	case 2: {
		cout << "B_";
		break;
	}
	case 3: {
		cout << "L_";
		break;
	}
	case 4: {
		cout << "R_";
		break;
	}
	case 5: {
		cout << "U_";
		break;
	}
	case 6: {
		cout << "D_";
		break;
	}
	}
}
void Print(int i)
{
	cout << CX.a[i][1][1];
	cout << CX.a[i][1][2];
	cout << CX.a[i][1][3] << endl;
	cout << CX.a[i][2][1];
	cout << CX.a[i][2][2];
	cout << CX.a[i][2][3] << endl;
	cout << CX.a[i][3][1];
	cout << CX.a[i][3][2];
	cout << CX.a[i][3][3] << endl;
}
void CW(int i)
{
	switch (i)
	{
	case 1: {
		CX.F();
		break;
	}
	case 2: {
		CX.B();
		break;
	}
	case 3: {
		CX.L();
		break;
	}
	case 4: {
		CX.R();
		break;
	}
	case 5: {
		CX.U();
		break;
	}
	case 6: {
		CX.D();
		break;
	}
	}
}
void AC(int i)
{
	switch (i)
	{
	case 1: {
		CX.F_();
		break;
	}
	case 2: {
		CX.B_();
		break;
	}
	case 3: {
		CX.L_();
		break;
	}
	case 4: {
		CX.R_();
		break;
	}
	case 5: {
		CX.U_();
		break;
	}
	case 6: {
		CX.D_();
		break;
	}
	}
}
int GetCross()
{
	int x = 0;
	if (CX.a[5][1][2] == m)  x++;
	if (CX.a[5][2][1] == m)  x++;
	if (CX.a[5][3][2] == m)  x++;
	if (CX.a[5][2][3] == m)  x++;
	return x;
}
int GetCross2()
{
	int x = 0;
	if (CX.a[5][1][2] == n)  x++;
	if (CX.a[5][2][1] == n)  x++;
	if (CX.a[5][3][2] == n)  x++;
	if (CX.a[5][2][3] == n)  x++;
	return x;
}
int GetUp()
{
	int x = 0; int i, j;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			if (CX.a[5][i][j] == n) 	x++;
		}
	}
	return x;
}
int GetDC()
{
	int x = 0;
	if ((CX.a[1][3][3] == CX.a[1][2][2]) && ((CX.a[4][3][1] == CX.a[4][2][2]) && (CX.a[6][1][3] == m))) x++;
	if ((CX.a[1][3][1] == CX.a[1][2][2]) && ((CX.a[3][3][3] == CX.a[3][2][2]) && (CX.a[6][1][1] == m))) x++;
	if ((CX.a[3][3][1] == CX.a[3][2][2]) && ((CX.a[2][3][3] == CX.a[2][2][2]) && (CX.a[6][3][1] == m))) x++;
	if ((CX.a[4][3][3] == CX.a[4][2][2]) && ((CX.a[2][3][1] == CX.a[2][2][2]) && (CX.a[6][3][3] == m))) x++;
	return x;
}
int GetSE()
{
	int x = 0;
	if ((CX.a[1][2][1] == CX.a[1][2][2]) && (CX.a[3][2][3] == CX.a[3][2][2])) x++;
	if ((CX.a[1][2][3] == CX.a[1][2][2]) && (CX.a[4][2][1] == CX.a[4][2][2])) x++;
	if ((CX.a[3][2][1] == CX.a[3][2][2]) && (CX.a[2][2][3] == CX.a[2][2][2])) x++;
	if ((CX.a[4][2][3] == CX.a[4][2][2]) && (CX.a[2][2][1] == CX.a[2][2][2])) x++;
	return x;
}
bool Get(int y)
{
	bool x = true;
	int i, j, k;
	k = CX.a[y][2][2];
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
			if (CX.a[y][i][j] != k)  x = false;
		if (x == false) break;
	}
	return x;
}
void Cross1()
{
	int i, x;
	do
	{
		for (i = 1; i <= 4; i++)
			if (CX.a[i][1][2] == m) { CW(i);  CX.E_();  CW(i); cout_CWi(i); cout << "E_"; cout_CWi(i); }

		for (i = 1; i <= 4; i++)
			if (CX.a[i][2][1] == m)
			{
				x = GetCross();
				CX.E(); AC(i);
				if (GetCross() == x) { CW(i); cout << "E"; }
				else { x = GetCross(); cout << "E"; cout_ACi(i); }
			}
		for (i = 1; i <= 4; i++)
			if (CX.a[i][2][3] == m)
			{
				x = GetCross();
				CX.E_(); CW(i);
				if (GetCross() == x) { AC(i); cout << "E_"; }
				else { x = GetCross(); cout << "E_"; cout_CWi(i); }
			}

		for (i = 1; i <= 4; i++)
			if (CX.a[i][3][2] == m)
			{
				x = GetCross();
				CW(i); CX.E(); AC(i);
				if (GetCross() == x)
				{
					CW(i); CX.E_(); AC(i); CX.D(); cout << "D";
				}
				else { x = GetCross(); cout_CWi(i); cout << "E"; cout_ACi(i); }
			}

		if (CX.a[6][1][2] == m)
		{
			x = GetCross();
			CX.F2();
			if (GetCross() == x) { CX.F2(); CX.D(); cout << "D"; }
			else { x = GetCross(); cout << "F2"; }
		}

		if (CX.a[6][2][3] == m)
		{
			x = GetCross();
			CX.R2();
			if (GetCross() == x) { CX.R2(); CX.D(); cout << "D"; }
			else { x = GetCross(); cout << "R2"; }
		}

		if (CX.a[6][3][2] == m)
		{
			x = GetCross();
			CX.B2();
			if (GetCross() == x) { CX.B2(); CX.D(); cout << "D"; }
			else { x = GetCross(); cout << "B2"; }
		}

		if (CX.a[6][2][1] == m)
		{
			x = GetCross();
			CX.L2();
			if (GetCross() == x) { CX.L2(); CX.D();  cout << "D"; }
			else { x = GetCross(); cout << "L2"; }
		}

	} while (GetCross() <= 3);
	//cout << endl;
	//cout << "**************************************" << endl; //顶层十字第一步
	do
	{

		for (i = 1; i <= 4; i++)
		{
			x = GetCross();
			if (CX.a[i][1][2] == CX.a[i][2][2])
			{
				CW(i); CW(i);
				if (GetCross() == x - 1) { cout_CWi(i); cout_CWi(i); }
				else { AC(i); AC(i); }
			}
		}
		CW(5); cout << "U";
	} while (GetCross() > 0);
	//cout << endl;
	//cout << "**************************************" << endl; //顶层十字第二步
}
void First()
{
	int i;
	do
	{
		if (CX.a[1][1][1] == m)
		{
			if (CX.a[3][1][3] == CX.a[1][2][2]) { AC(5); AC(5); AC(1); CW(5); CW(1); cout << "U_U_F_UF"; }
			else
				if (CX.a[3][1][3] == CX.a[3][2][2]) { AC(5); AC(3); CW(5); CW(3); cout << "U_L_UL"; }
				else
					if (CX.a[3][1][3] == CX.a[2][2][2]) { AC(2); CW(5); CW(2); cout << "B_UB"; }
					else
						if (CX.a[3][1][3] == CX.a[4][2][2]) { CW(5); AC(4); CW(5); CW(4); cout << "UR_UR"; }
		}
		if (CX.a[3][1][1] == m)
		{
			if (CX.a[2][1][3] == CX.a[1][2][2]) { CW(5); AC(1); CW(5); CW(1); cout << "UF_UF"; }
			else
				if (CX.a[2][1][3] == CX.a[3][2][2]) { AC(5); AC(5); AC(3); CW(5); CW(3); cout << "U_U_L_UL"; }
				else
					if (CX.a[2][1][3] == CX.a[2][2][2]) { AC(5);  AC(2); CW(5); CW(2); cout << "U_B_UB"; }
					else
						if (CX.a[2][1][3] == CX.a[4][2][2]) { AC(4); CW(5); CW(4); cout << "R_UR"; }
		}
		if (CX.a[2][1][1] == m)
		{
			if (CX.a[4][1][3] == CX.a[1][2][2]) { AC(1); CW(5); CW(1); cout << "F_UF"; }
			else
				if (CX.a[4][1][3] == CX.a[3][2][2]) { CW(5); AC(3); CW(5); CW(3); cout << "UL_UL"; }
				else
					if (CX.a[4][1][3] == CX.a[2][2][2]) { AC(5);  AC(5); AC(2); CW(5); CW(2); cout << "U_U_B_UB"; }
					else
						if (CX.a[4][1][3] == CX.a[4][2][2]) { AC(5);  AC(4); CW(5); CW(4); cout << "U_R_UR"; }
		}
		if (CX.a[4][1][1] == m)
		{
			if (CX.a[1][1][3] == CX.a[1][2][2]) { AC(5); AC(1); CW(5); CW(1); cout << "U_F_UF"; }
			else
				if (CX.a[1][1][3] == CX.a[3][2][2]) { AC(3); CW(5); CW(3); cout << "L_UL"; }
				else
					if (CX.a[1][1][3] == CX.a[2][2][2]) { CW(5); AC(2); CW(5); CW(2); cout << "UB_UB"; }
					else
						if (CX.a[1][1][3] == CX.a[4][2][2]) { AC(5);  AC(5);  AC(4); CW(5); CW(4); cout << "U_U_R_UR"; }
		}

		if (CX.a[1][1][3] == m)
		{
			if (CX.a[4][1][1] == CX.a[1][2][2]) { CW(5); CW(5); CW(1); AC(5); AC(1); cout << "UUFU_F_"; }
			else
				if (CX.a[4][1][1] == CX.a[3][2][2]) { AC(5); CW(3); AC(5); AC(3); cout << "U_LU_L_"; }
				else
					if (CX.a[4][1][1] == CX.a[2][2][2]) { CW(2); AC(5); AC(2); cout << "BU_B_"; }
					else
						if (CX.a[4][1][1] == CX.a[4][2][2]) { CW(5); CW(4); AC(5); AC(4); cout << "URU_R_"; }
		}
		if (CX.a[2][1][3] == m)
		{
			if (CX.a[3][1][1] == CX.a[1][2][2]) { CW(1); AC(5); AC(1); cout << "FU_F_"; }
			else
				if (CX.a[3][1][1] == CX.a[3][2][2]) { CW(5); CW(3); AC(5); AC(3); cout << "ULU_L_"; }
				else
					if (CX.a[3][1][1] == CX.a[2][2][2]) { CW(5); CW(5); CW(2); AC(5); AC(2); cout << "UUBU_B_"; }
					else
						if (CX.a[3][1][1] == CX.a[4][2][2]) { AC(5); CW(4); AC(5); AC(4); cout << "U_RU_R_"; }
		}
		if (CX.a[3][1][3] == m)
		{
			if (CX.a[1][1][1] == CX.a[1][2][2]) { CW(5); CW(1); AC(5); AC(1); cout << "UFU_F_"; }
			else
				if (CX.a[1][1][1] == CX.a[3][2][2]) { CW(5); CW(5); CW(3); AC(5); AC(3); cout << "UULU_L_"; }
				else
					if (CX.a[1][1][1] == CX.a[2][2][2]) { AC(5); CW(2); AC(5); AC(2); cout << "U_BU_B_"; }
					else
						if (CX.a[1][1][1] == CX.a[4][2][2]) { CW(4); AC(5); AC(4); cout << "RU_R_"; }
		}
		if (CX.a[4][1][3] == m)
		{
			if (CX.a[2][1][1] == CX.a[1][2][2]) { AC(5); CW(1); AC(5); AC(1); cout << "U_FU_F_"; }
			else
				if (CX.a[2][1][1] == CX.a[3][2][2]) { CW(3); AC(5); AC(3); cout << "LU_L_"; }
				else
					if (CX.a[2][1][1] == CX.a[2][2][2]) { CW(5); CW(2); AC(5); AC(2); cout << "UBU_B_"; }
					else
						if (CX.a[2][1][1] == CX.a[4][2][2]) { CW(5); CW(5); CW(4); AC(5); AC(4); cout << "UURU_R_"; }
		}

		for (i = 1; i <= 4; i++)
			if (CX.a[i][3][1] == m) { CW(i); CW(5); AC(i); cout_CWi(i); cout << "U"; cout_ACi(i); }

		for (i = 1; i <= 4; i++)
			if (CX.a[i][3][3] == m) { AC(i); AC(5); CW(i); cout_ACi(i); cout << "U_"; cout_CWi(i); }

		if (CX.a[5][1][1] == m)
			if ((CX.a[3][3][1] == CX.a[3][2][2]) && ((CX.a[2][3][3] == CX.a[2][2][2]) && (CX.a[6][3][1] == m))) { CW(5); cout << "U"; }
			else { AC(2); CW(5); CW(2); cout << "B_UB"; }

		if (CX.a[5][1][3] == m)
			if ((CX.a[2][3][1] == CX.a[2][2][2]) && ((CX.a[4][3][3] == CX.a[4][2][2]) && (CX.a[6][3][3] == m))) { CW(5); cout << "U"; }
			else { CW(2); AC(5); AC(2); cout << "BU_B_"; }

		if (CX.a[5][3][3] == m)
			if ((CX.a[4][3][1] == CX.a[4][2][2]) && ((CX.a[1][3][3] == CX.a[1][2][2]) && (CX.a[6][1][3] == m))) { CW(5); cout << "U"; }
			else { AC(1); CW(5); CW(1); cout << "F_UF"; }

		if (CX.a[5][3][1] == m)
			if ((CX.a[1][3][1] == CX.a[1][2][2]) && ((CX.a[3][3][3] == CX.a[3][2][2]) && (CX.a[6][1][1] == m))) { CW(5); cout << "U"; }
			else { CW(1); AC(5); AC(1); cout << "FU_F_"; }

		if ((CX.a[6][1][1] == m) && ((CX.a[3][3][3] != CX.a[3][2][2]) || (CX.a[1][3][1] != CX.a[1][2][2]))) { CW(1); CW(5); AC(1); cout << "FUF_"; }
		if ((CX.a[6][1][3] == m) && ((CX.a[4][3][1] != CX.a[4][2][2]) || (CX.a[1][3][3] != CX.a[1][2][2]))) { AC(1); AC(5); CW(1); cout << "F_U_F"; }
		if ((CX.a[6][3][1] == m) && ((CX.a[3][3][1] != CX.a[3][2][2]) || (CX.a[2][3][3] != CX.a[2][2][2]))) { AC(2); AC(5); CW(2); cout << "B_U_B"; }
		if ((CX.a[6][3][3] == m) && ((CX.a[2][3][1] != CX.a[2][2][2]) || (CX.a[4][3][3] != CX.a[4][2][2]))) { CW(2); CW(5); AC(2); cout << "BUB_"; }
	} while (GetDC() < 4);
	//cout << endl;
	//cout <<  "**************************************" << endl; //一层
}
void Second()
{
	do
	{
		if (CX.a[1][1][2] == CX.a[1][2][2])
		{
			if (CX.a[5][3][2] == CX.a[3][2][2])
			{
				AC(5); AC(3); CW(5); CW(3); CW(5); CW(1); AC(5); AC(1);
				cout << "U_L_ULUFU_F_";
				continue;
			}
			else if (CX.a[5][3][2] == CX.a[4][2][2])
			{
				CW(5); CW(4); AC(5); AC(4); AC(5); AC(1); CW(5); CW(1);
				cout << "URU_R_U_F_UF";
				continue;
			}
		}
		if (CX.a[2][1][2] == CX.a[2][2][2])
		{
			if (CX.a[5][1][2] == CX.a[3][2][2])
			{
				CW(5); CW(3); AC(5); AC(3); AC(5); AC(2); CW(5); CW(2);
				cout << "ULU_L_U_B_UB";
				continue;
			}
			else if (CX.a[5][1][2] == CX.a[4][2][2])
			{
				AC(5); AC(4); CW(5); CW(4); CW(5); CW(2); AC(5); AC(2);
				cout << "U_R_URUBU_B_";
				continue;
			}
		}
		if (CX.a[3][1][2] == CX.a[3][2][2])
		{
			if (CX.a[5][2][1] == CX.a[2][2][2])
			{
				AC(5); AC(2); CW(5); CW(2); CW(5); CW(3); AC(5); AC(3);
				cout << "U_B_UBULU_L_";
				continue;
			}
			else if (CX.a[5][2][1] == CX.a[1][2][2])
			{
				CW(5); CW(1); AC(5); AC(1); AC(5); AC(3); CW(5); CW(3);
				cout << "UFU_F_U_L_UL";
				continue;
			}
		}
		if (CX.a[4][1][2] == CX.a[4][2][2])
		{
			if (CX.a[5][2][3] == CX.a[1][2][2])
			{
				AC(5); AC(1); CW(5); CW(1); CW(5); CW(4); AC(5); AC(4);
				cout << "U_F_UFURU_R_";
				continue;
			}
			else if (CX.a[5][2][3] == CX.a[2][2][2])
			{
				CW(5); CW(2); AC(5); AC(2); AC(5); AC(4); CW(5); CW(4);
				cout << "UBU_B_U_R_UR";
				continue;
			}
		}

		if ((CX.a[1][2][1] == CX.a[3][2][2]) && (CX.a[3][2][3] == CX.a[1][2][2]))
		{
			CW(1); AC(5); AC(5); AC(1); CW(5); CW(1); AC(5); AC(5); AC(1); CW(5); AC(3); AC(5); CW(3);
			cout << "FU_U_F_UFU_U_F_UL_U_L";
			continue;
		}
		if ((CX.a[3][2][1] == CX.a[2][2][2]) && (CX.a[2][2][3] == CX.a[3][2][2]))
		{
			CW(3); AC(5); AC(5); AC(3); CW(5); CW(3); AC(5); AC(5); AC(3); CW(5); AC(2); AC(5); CW(2);
			cout << "LU_U_L_ULU_U_L_UB_U_B";
			continue;
		}
		if ((CX.a[2][2][1] == CX.a[4][2][2]) && (CX.a[4][2][3] == CX.a[2][2][2]))
		{
			CW(2); AC(5); AC(5); AC(2); CW(5); CW(2); AC(5); AC(5); AC(2); CW(5); AC(4); AC(5); CW(4);
			cout << "BU_U_B_UBU_U_B_UR_U_R";
			continue;
		}
		if ((CX.a[4][2][1] == CX.a[1][2][2]) && (CX.a[1][2][3] == CX.a[4][2][2]))
		{
			CW(4); AC(5); AC(5); AC(4); CW(5); CW(4); AC(5); AC(5); AC(4); CW(5); AC(1); AC(5); CW(1);
			cout << "RU_U_R_URU_U_R_UF_U_F";
			continue;
		}

		if ((CX.a[1][2][1] == CX.a[3][2][2]) && (CX.a[3][2][3] != CX.a[5][2][2]) && (CX.a[3][2][3] != CX.a[1][2][2]))
		{
			AC(5); AC(3); CW(5); CW(3); CW(5); CW(1); AC(5); AC(1);
			cout << "U_L_ULUFU_F_";
		}
		if ((CX.a[3][2][3] == CX.a[1][2][2]) && (CX.a[1][2][1] != CX.a[5][2][2]) && (CX.a[1][2][1] != CX.a[3][2][2]))
		{
			AC(5); AC(3); CW(5); CW(3); CW(5); CW(1); AC(5); AC(1);
			cout << "U_L_ULUFU_F_";
		}
		if ((CX.a[1][2][3] == CX.a[4][2][2]) && (CX.a[4][2][1] != CX.a[5][2][2]) && (CX.a[4][2][1] != CX.a[1][2][2]))
		{
			CW(5); CW(4); AC(5); AC(4); AC(5); AC(1); CW(5); CW(1);
			cout << "URU_R_U_F_UF";
		}
		if ((CX.a[4][2][1] == CX.a[1][2][2]) && (CX.a[1][2][3] != CX.a[5][2][2]) && (CX.a[1][2][3] != CX.a[4][2][2]))
		{
			CW(5); CW(4); AC(5); AC(4); AC(5); AC(1); CW(5); CW(1);
			cout << "URU_R_U_F_UF";
		}
		if ((CX.a[4][2][3] == CX.a[2][2][2]) && (CX.a[2][2][1] != CX.a[5][2][2]) && (CX.a[2][2][1] != CX.a[4][2][2]))
		{
			AC(5); AC(4); CW(5); CW(4); CW(5); CW(2); AC(5); AC(2);
			cout << "U_R_URUBU_B_";
		}
		if ((CX.a[2][2][1] == CX.a[4][2][2]) && (CX.a[4][2][3] != CX.a[5][2][2]) && (CX.a[4][2][3] != CX.a[2][2][2]))
		{
			AC(5); AC(4); CW(5); CW(4); CW(5); CW(2); AC(5); AC(2);
			cout << "U_R_URUBU_B_";
		}
		if ((CX.a[2][2][3] == CX.a[3][2][2]) && (CX.a[3][2][1] != CX.a[5][2][2]) && (CX.a[3][2][1] != CX.a[2][2][2]))
		{
			CW(5); CW(3); AC(5); AC(3); AC(5); AC(2); CW(5); CW(2);
			cout << "ULU_L_U_B_UB";
		}
		if ((CX.a[3][2][1] == CX.a[2][2][2]) && (CX.a[2][2][3] != CX.a[5][2][2]) && (CX.a[2][2][3] != CX.a[3][2][2]))
		{
			CW(5); CW(3); AC(5); AC(3); AC(5); AC(2); CW(5); CW(2);
			cout << "ULU_L_U_B_UB";
		}
		/*
		if ((CX.a[1][2][1] != CX.a[3][2][2]) && (CX.a[1][2][1] != CX.a[5][2][2]) && (CX.a[3][2][3] != CX.a[5][2][2]) && (CX.a[3][2][3] != CX.a[1][2][2]))
		{
			AC(5); AC(3); CW(5); CW(3); CW(5); CW(1); AC(5); AC(1);
			cout << "U_L_ULUFU_F_";
		}
		if ((CX.a[1][2][3] != CX.a[4][2][2]) && (CX.a[1][2][3] != CX.a[5][2][2]) && (CX.a[4][2][1] != CX.a[5][2][2]) && (CX.a[4][2][1] != CX.a[1][2][2]))
		{
			CW(5); CW(4); AC(5); AC(4); AC(5); AC(1); CW(5); CW(1);
			cout << "URU_R_U_F_UF";
		}
		if ((CX.a[4][2][3] != CX.a[2][2][2]) && (CX.a[4][2][3] != CX.a[5][2][2]) && (CX.a[2][2][1] != CX.a[5][2][2]) && (CX.a[2][2][1] != CX.a[4][2][2]))
		{
			AC(5); AC(4); CW(5); CW(4); CW(5); CW(2); AC(5); AC(2);
			cout << "U_R_URUBU_B_";
		}
		if ((CX.a[2][2][3] != CX.a[3][2][2]) && (CX.a[2][2][3] != CX.a[5][2][2]) && (CX.a[3][2][1] != CX.a[5][2][2]) && (CX.a[3][2][1] != CX.a[2][2][2]))
		{
			CW(5); CW(3); AC(5); AC(3); AC(5); AC(2); CW(5); CW(2);
			cout << "ULU_L_U_B_UB";
		}
		*/

		if (GetSE() != 4) { CW(5); cout << "U"; }
	} while (GetSE()< 4);
	//cout << endl;
	//cout << "**************************************" << endl;//二层
}
void Cross2()
{
	do
	{
		if (GetCross2() == 0)
		{
			CW(3); CW(1); CW(5); AC(1); AC(5); AC(3);
			cout << "LFUF_U_L_";
		}
		if (GetCross2() == 2)
		{
			if ((CX.a[5][2][1] == n) && (CX.a[5][2][3] == n)) { CW(5); cout << "U"; }
			if ((CX.a[5][1][2] == n) && (CX.a[5][2][1] == n)) { AC(5); cout << "U_"; }
			if ((CX.a[5][1][2] == n) && (CX.a[5][2][3] == n)) { CW(5); CW(5); cout << "UU"; }
			if ((CX.a[5][2][3] == n) && (CX.a[5][3][2] == n)) { CW(5); cout << "U"; }
			CW(3); CW(1); CW(5); AC(1); AC(5); AC(3);
			cout << "LFUF_U_L_";
		}
	} while (GetCross2() < 4);
	//cout << endl;
	//cout << "**************************************" << endl;//顶层十字2
}
void Up()
{
	do
	{
		if (GetUp() == 6)
		{
			while (CX.a[5][1][1] != n) { CW(5); cout << "U"; }
			if (CX.a[1][1][1] == n)
			{
				AC(4); AC(5); CW(4); AC(5); AC(4); AC(5); AC(5); CW(4);
				cout << "R_U_RU_R_U_U_R";
			}
			else if (CX.a[1][1][3] == n)
			{
				CW(1); CW(5); AC(1); CW(5); CW(1); CW(5); CW(5); AC(1);
				cout << "FUF_UFUUF_";
			}
		}
		if (GetUp() == 7)
		{
			while (CX.a[2][1][3] != n)
			{
				CW(5);
				cout << "U";
			}
			AC(4); AC(5); CW(4); AC(5); AC(4); AC(5); AC(5); CW(4);
			cout << "R_U_RU_R_U_U_R";
		}
		if (GetUp() == 5)
		{
			while ((CX.a[3][1][1] != n) || (CX.a[3][1][3] != n)) { CW(5); cout << "U"; }
			AC(4); AC(5); CW(4); AC(5); AC(4); AC(5); AC(5); CW(4);
			cout << "R_U_RU_R_U_U_R";
		}
	} while (GetUp() < 9);
	//cout << endl;
	//cout << "**************************************" << endl;//顶层复原
}
void Third()
{
	bool x = false; int j = 0;
	if ((CX.a[1][1][1] == CX.a[1][1][3]) && (CX.a[2][1][1] == CX.a[2][1][3]) && (CX.a[3][1][1] == CX.a[3][1][3]) && (CX.a[4][1][1] == CX.a[4][1][3])) { x = true; j = 1; }

	if (j != 0)
		while (CX.a[1][1][1] != CX.a[1][2][2]) { CW(5); cout << "U"; }
	else
	{
		if (CX.a[1][1][1] == CX.a[1][1][3]) { AC(5); cout << "U_"; }
		else
			if (CX.a[3][1][1] == CX.a[3][1][3]) { CW(5); CW(5); cout << "UU"; }
			else
				if (CX.a[2][1][1] == CX.a[2][1][3]) { CW(5); cout << "U"; }
				else
					if (CX.a[4][1][1]!=CX.a[4][1][3])
					{
						CW(4); CW(4); CW(1); CW(1); AC(4); AC(2); CW(4); CW(1); CW(1); AC(4); CW(2); AC(4);
						cout << "RRFFR_B_RFFR_BR_";

						if (CX.a[1][1][1] == CX.a[1][1][3]) { AC(5); cout << "U_"; }
						else
							if (CX.a[3][1][1] == CX.a[3][1][3]) { CW(5); CW(5); cout << "UU"; }
							else
								if (CX.a[2][1][1] == CX.a[2][1][3]) { CW(5); cout << "U"; }
					}

		CW(4); CW(4); CW(1); CW(1); AC(4); AC(2); CW(4); CW(1); CW(1); AC(4); CW(2); AC(4);
		cout << "RRFFR_B_RFFR_BR_";
		while (CX.a[1][1][1] != CX.a[1][2][2]) { CW(5); cout << "U"; }

	}
	//cout << endl;
	//cout << "**************************************" << endl;//三层复原
}
void Fin()
{
	if ((CX.a[1][1][2] == CX.a[2][2][2]) && (CX.a[3][1][2] == CX.a[4][2][2]))
	{
		CX.M2(); CW(5); CX.M2(); CW(5); CW(5); CX.M2(); CW(5); CX.M2();
		cout << "M2UM2UUM2UM2";

	}
	if ((CX.a[1][1][2] == CX.a[3][2][2]) && (CX.a[2][1][2] == CX.a[4][2][2]))
	{
		CX.y_();
		cout << "y_";
	}
	if ((CX.a[1][1][2] == CX.a[4][2][2]) && (CX.a[2][1][2] == CX.a[3][2][2]))
	{
		CX.M2(); CW(5); CX.M2(); CW(5); CX.M_(); CW(5); CW(5); CX.M2(); CW(5); CW(5); CX.M_(); CW(5); CW(5);
		cout << "M2UM2UM_UUM2UUM_UU";

	}
	if (Get(1) == true)
	{
		if (CX.a[3][1][2] == CX.a[4][2][2])
		{
			CW(3); AC(5); CW(3); CW(5); CW(3); CW(5); CW(3); AC(5); AC(3); AC(5); CW(3); CW(3);
			cout << "LU_LULULU_L_U_LL";
		}
		if (CX.a[4][1][2] == CX.a[3][2][2])
		{
			AC(3); AC(3); CW(5); CW(3); CW(5); AC(3); AC(5); AC(3); AC(5); AC(3); CW(5); AC(3);
			cout << "L_L_ULUL_U_L_U_L_UL_";
		}
	}
	if (Get(2) == true)
	{
		if (CX.a[3][1][2] == CX.a[1][2][2])
		{
			CW(4); AC(5); CW(4); CW(5); CW(4); CW(5); CW(4); AC(5); AC(4); AC(5); CW(4); CW(4);
			cout << "RU_RURURU_R_U_RR";
		}
		if (CX.a[1][1][2] == CX.a[3][2][2])
		{
			AC(4); AC(4); CW(5); CW(4); CW(5); AC(4); AC(5); AC(4); AC(5); AC(4); CW(5); AC(4);
			cout << "R_R_URUR_U_R_U_R_UR_";
		}
	}
	if (Get(3) == true)
	{
		if (CX.a[2][1][2] == CX.a[1][2][2])
		{
			CW(2); AC(5); CW(2); CW(5); CW(2); CW(5); CW(2); AC(5); AC(2); AC(5); CW(2); CW(2);
			cout << "BU_BUBUBU_B_U_BB";
		}
		if (CX.a[1][1][2] == CX.a[2][2][2])
		{
			AC(2); AC(2); CW(5); CW(2); CW(5); AC(2); AC(5); AC(2); AC(5); AC(2); CW(5); AC(2);
			cout << "B_B_UBUB_U_B_U_B_UB_";
		}
	}
	if (Get(4) == true)
	{
		if (CX.a[1][1][2] == CX.a[2][2][2])
		{
			CW(1); AC(5); CW(1); CW(5); CW(1); CW(5); CW(1); AC(5); AC(1); AC(5); CW(1); CW(1);
			cout << "FU_FUFUFU_F_U_FF";
		}
		if (CX.a[2][1][2] == CX.a[1][2][2])
		{
			AC(1); AC(1); CW(5); CW(1); CW(5); AC(1); AC(5); AC(1); AC(5); AC(1); CW(5); AC(1);
			cout << "F_F_UFUF_U_F_U_F_UF_";
		}
	}
	//cout << endl;
	//cout << "**************************************" << endl;//最终复原
}

/*void rec(Mat c)
{

	Point p1, p2;
	p1.x = 0; p1.y = 0; p2.x = 100; p2.y = 100;
	rectangle(c, p1, p2, Scalar(0, 255, 0), 1, 8, 0);

	Point p3, p4;
	p3.x = 100; p3.y = 0; p4.x = 200; p4.y = 100;
	rectangle(c, p3, p4, Scalar(0, 255, 0), 1, 8, 0);

	Point p5, p6;
	p5.x = 200; p5.y = 0; p6.x = 300; p6.y = 100;
	rectangle(c, p5, p6, Scalar(0, 255, 0), 1, 8, 0);

	Point p7, p8;
	p7.x = 0; p7.y = 100; p8.x = 100; p8.y = 200;
	rectangle(c, p7, p8, Scalar(0, 255, 0), 1, 8, 0);

	Point p9, p10;
	p9.x = 100; p9.y = 100; p10.x = 200; p10.y = 200;
	rectangle(c, p9, p10, Scalar(0, 255, 0), 1, 8, 0);

	Point p11, p12;
	p11.x = 200; p11.y = 100; p12.x = 300; p12.y = 200;
	rectangle(c, p11, p12, Scalar(0, 255, 0), 1, 8, 0);

	Point p13, p14;
	p13.x = 0; p13.y = 200; p14.x = 100; p14.y = 300;
	rectangle(c, p13, p14, Scalar(0, 255, 0), 1, 8, 0);

	Point p15, p16;
	p15.x = 100; p15.y = 200; p16.x = 200; p16.y = 300;
	rectangle(c, p15, p16, Scalar(0, 255, 0), 1, 8, 0);

	Point p17, p18;
	p17.x = 200; p17.y = 200; p18.x = 300; p18.y = 300;
	rectangle(c, p17, p18, Scalar(0, 255, 0), 1, 8, 0);

}*/
void on_mouse(int EVENT, int x, int y, int flags, void* userdata)
{
  Mat hh;
  hh = *(Mat*)userdata;
  Point p(x, y);
  switch (EVENT)
  {
	case EVENT_LBUTTONDOWN:
    {
		cout << x << ' ' << y << endl;
		printf("h=%d\t", hh.at<Vec3b>(p)[0]);
		printf("s=%d\t", hh.at<Vec3b>(p)[1]);
		printf("v=%d\n", hh.at<Vec3b>(p)[2]);
		cv::circle(hh, p, 2, Scalar(255), 3);
    }
    break;
  }
}

int main()
{

	VideoCapture cap(0);
	VideoCapture capcap(1);
	 if (!cap.isOpened())
	 {
	   return -1;
	 }
	 if (!capcap.isOpened())
	 {
		 return -1;
	 }


	 F = 3; B = 4; L = 6; R = 5; U = 1; D = 2;
	 while (1)
	 {
		 cap >> frame;
		 if (frame.empty())
			 break;
		 capcap >> frame2;
		 if (frame2.empty())
			 break;
		 imshow("摄像头", frame);
		 imshow("摄像头2", frame2);
		 setMouseCallback("摄像头", on_mouse, &frame);
		 setMouseCallback("摄像头2", on_mouse, &frame2);

		 Point2f dst_coners[4];
		 dst_coners[0] = Point2f(2, 0);
		 dst_coners[1] = Point2f(300, 0);
		 dst_coners[2] = Point2f(0, 300);
		 dst_coners[3] = Point2f(300, 300);

		 if (1)
		 {
			 Point2f src_coners[4];
			 src_coners[0] = Point2f(187, 156);
			 src_coners[1] = Point2f(305, 49);
			 src_coners[2] = Point2f(137, 322);
			 src_coners[3] = Point2f(298, 195);
			 circle(frame, src_coners[0], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame, src_coners[1], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame, src_coners[2], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame, src_coners[3], 3, Scalar(0, 0, 255), 3, 8);

			 //Get_1(frame, src_coners, dst_coners, num);
			 //Get_1(frame, src_coners2, dst_coners, num);


			 Mat warpMatrix = getPerspectiveTransform(src_coners, dst_coners);
			 warpPerspective(frame, frame_a, warpMatrix, Size(400, 400), INTER_LINEAR, BORDER_CONSTANT);
			 //透视变换
			 //rec(frame_a);
			 cvtColor(frame_a, frame_a, COLOR_BGR2HSV);//RGB转HSV
			// imshow("frame_a", frame_a);
			 //setMouseCallback("frame_a", on_mouse, &frame_a);


			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 60; i <= 80; i++)
			 {
				 for (j = 0; j <= 20; j++)
				 {
					 H = frame_a.at<Vec3b>(i, j)[0];
					 S = frame_a.at<Vec3b>(i, j)[1];
					 V = frame_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 46) && (V >= 170)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第一格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////////第一格

			 for (i = 1; i <= 6; i++) color[i] = 0;

			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame_a.at<Vec3b>(i, j)[0];
					 S = frame_a.at<Vec3b>(i, j)[1];
					 V = frame_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 46) && (V >= 170)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第二格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第二格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame_a.at<Vec3b>(i, j)[0];
					 S = frame_a.at<Vec3b>(i, j)[1];
					 V = frame_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 46) && (V >= 170)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第三格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////////第三格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {

					 H = frame_a.at<Vec3b>(i, j)[0];
					 S = frame_a.at<Vec3b>(i, j)[1];
					 V = frame_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 46) && (V >= 170)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第四格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////第四格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame_a.at<Vec3b>(i, j)[0];
					 S = frame_a.at<Vec3b>(i, j)[1];
					 V = frame_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 46) && (V >= 170)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第五格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第五格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame_a.at<Vec3b>(i, j)[0];
					 S = frame_a.at<Vec3b>(i, j)[1];
					 V = frame_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 46) && (V >= 170)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第六格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第六格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {
					 H = frame_a.at<Vec3b>(i, j)[0];
					 S = frame_a.at<Vec3b>(i, j)[1];
					 V = frame_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 46) && (V >= 170)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第七格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第七格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame_a.at<Vec3b>(i, j)[0];
					 S = frame_a.at<Vec3b>(i, j)[1];
					 V = frame_a.at<Vec3b>(i, j)[2];
					 //cout << i << ' ' << j << ' ' << H << ' ' << S << ' ' << V << endl;
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 46) && (V >= 170)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第八格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第八格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame_a.at<Vec3b>(i, j)[0];
					 S = frame_a.at<Vec3b>(i, j)[1];
					 V = frame_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 46) && (V >= 170)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第九格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第九格

			 if (num == 2)
			 {

				 for (i = 1; i <= 3; i++)
				 {
					 for (j = 1; j <= 3; j++)
						 cout << rubic[i][j] << ' ';
					 cout << endl;
				 }

				 CX.a[4][1][1] = rubic[1][1];  CX.a[4][1][2] = rubic[1][2]; CX.a[4][1][3] = rubic[1][3];
				 CX.a[4][2][1] = rubic[2][1]; CX.a[4][2][2] = R; CX.a[4][2][3] = rubic[2][3];
				 CX.a[4][3][1] = rubic[3][1]; CX.a[4][3][2] = rubic[3][2]; CX.a[4][3][3] = rubic[3][3];
			 }


		 }
		 ///////////////////////////////////////////////////R 4
		 if (1)
		 {
			 Point2f src_coners2[4];
			 src_coners2[0] = Point2f(323, 47);
			 src_coners2[1] = Point2f(445, 156);
			 src_coners2[2] = Point2f(316, 192);
			 src_coners2[3] = Point2f(493, 314);
			 circle(frame, src_coners2[0], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame, src_coners2[1], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame, src_coners2[2], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame, src_coners2[3], 3, Scalar(0, 0, 255), 3, 8);
			 Mat warpMatrix2 = getPerspectiveTransform(src_coners2, dst_coners);
			 warpPerspective(frame, frame_b, warpMatrix2, Size(400, 400), INTER_LINEAR, BORDER_CONSTANT);
			 //透视变换
			 //rec(frame_b);
			 //imshow("frame", frame);
			 cvtColor(frame_b, frame_b, COLOR_BGR2HSV);//RGB转HSV
			 //setMouseCallback("frame_b", on_mouse, &frame_b);
			 //imshow("frame_b", frame_b);


			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {
					 H = frame_b.at<Vec3b>(i, j)[0];
					 S = frame_b.at<Vec3b>(i, j)[1];
					 V = frame_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 175)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43)  && (V >= 175)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第一格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////////第一格

			 for (i = 1; i <= 6; i++) color[i] = 0;

			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame_b.at<Vec3b>(i, j)[0];
					 S = frame_b.at<Vec3b>(i, j)[1];
					 V = frame_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 175)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 175)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第二格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第二格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 70; i <= 80; i++)
			 {
				 for (j = 280; j <= 290; j++)
				 {

					 H = frame_b.at<Vec3b>(i, j)[0];
					 S = frame_b.at<Vec3b>(i, j)[1];
					 V = frame_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 175)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 175)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第三格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////////第三格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {

					 H = frame_b.at<Vec3b>(i, j)[0];
					 S = frame_b.at<Vec3b>(i, j)[1];
					 V = frame_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 175)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 175)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第四格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////第四格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame_b.at<Vec3b>(i, j)[0];
					 S = frame_b.at<Vec3b>(i, j)[1];
					 V = frame_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 175)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 175)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第五格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第五格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame_b.at<Vec3b>(i, j)[0];
					 S = frame_b.at<Vec3b>(i, j)[1];
					 V = frame_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 175)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 175)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第六格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第六格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {
					 H = frame_b.at<Vec3b>(i, j)[0];
					 S = frame_b.at<Vec3b>(i, j)[1];
					 V = frame_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 175)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 175)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第七格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第七格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame_b.at<Vec3b>(i, j)[0];
					 S = frame_b.at<Vec3b>(i, j)[1];
					 V = frame_b.at<Vec3b>(i, j)[2];
					 //cout << i << ' ' << j << ' ' << H << ' ' << S << ' ' << V << endl;
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 175)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 175)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第八格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第八格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 230; j <= 300; j++)
				 {

					 H = frame_b.at<Vec3b>(i, j)[0];
					 S = frame_b.at<Vec3b>(i, j)[1];
					 V = frame_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 100)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 175)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 175)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第九格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第九格
			 if (num == 2)
			 {

				 for (i = 1; i <= 3; i++)
				 {
					 for (j = 1; j <= 3; j++)
						 cout << rubic[i][j] << ' ';
					 cout << endl;
				 }

				 CX.a[2][1][1] = rubic[1][1];  CX.a[2][1][2] = rubic[1][2]; CX.a[2][1][3] = rubic[1][3];
				 CX.a[2][2][1] = rubic[2][1]; CX.a[2][2][2] = B; CX.a[2][2][3] = rubic[2][3];
				 CX.a[2][3][1] = rubic[3][1]; CX.a[2][3][2] = rubic[3][2]; CX.a[2][3][3] = rubic[3][3];
			 }


		 }
		 ///////////////////////////////////////////////////B 2
		 if (1)
		 {
			 Point2f src_coners3[4];
			 src_coners3[0] = Point2f(151, 335);
			 src_coners3[1] = Point2f(322, 221);
			 src_coners3[2] = Point2f(320, 405);
			 src_coners3[3] = Point2f(483, 331);
			 circle(frame, src_coners3[0], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame, src_coners3[1], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame, src_coners3[2], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame, src_coners3[3], 3, Scalar(0, 0, 255), 3, 8);
			 Mat warpMatrix3 = getPerspectiveTransform(src_coners3, dst_coners);
			 warpPerspective(frame, frame_c, warpMatrix3, Size(400, 400), INTER_LINEAR, BORDER_CONSTANT);
			 //透视变换
//			 rec(frame_c);
			 //imshow("frame", frame);
			 cvtColor(frame_c, frame_c, COLOR_BGR2HSV);//RGB转HSV
			 setMouseCallback("frame_c", on_mouse, &frame_c);
			 imshow("frame_c", frame_c);


			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {
					 H = frame_c.at<Vec3b>(i, j)[0];
					 S = frame_c.at<Vec3b>(i, j)[1];
					 V = frame_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <=60) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 60) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 60) && (V >= 43) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 60) && (V >= 46) && (V >= 150)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 60) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 60) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第一格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////////第一格

			 for (i = 1; i <= 6; i++) color[i] = 0;

			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame_c.at<Vec3b>(i, j)[0];
					 S = frame_c.at<Vec3b>(i, j)[1];
					 V = frame_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 60) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 60) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 60) && (V >= 43) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 60) && (V >= 46) && (V >= 150)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 60) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 60) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第二格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第二格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame_c.at<Vec3b>(i, j)[0];
					 S = frame_c.at<Vec3b>(i, j)[1];
					 V = frame_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 60) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 60) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 60) && (V >= 43) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 60) && (V >= 46) && (V >= 150)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 60) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 60) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第三格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////////第三格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {

					 H = frame_c.at<Vec3b>(i, j)[0];
					 S = frame_c.at<Vec3b>(i, j)[1];
					 V = frame_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 60) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 60) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 60) && (V >= 43) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 60) && (V >= 46) && (V >= 150)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 60) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 60) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第四格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////第四格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame_c.at<Vec3b>(i, j)[0];
					 S = frame_c.at<Vec3b>(i, j)[1];
					 V = frame_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 60) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 60) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 60) && (V >= 43) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 60) && (V >= 46) && (V >= 150)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 60) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 60) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第五格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第五格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame_c.at<Vec3b>(i, j)[0];
					 S = frame_c.at<Vec3b>(i, j)[1];
					 V = frame_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 60) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 60) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 60) && (V >= 43) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 60) && (V >= 46) && (V >= 150)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 60) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 60) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第六格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第六格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 285; i <= 290; i++)
			 {
				 for (j = 70; j <= 75; j++)
				 {
					 H = frame_c.at<Vec3b>(i, j)[0];
					 S = frame_c.at<Vec3b>(i, j)[1];
					 V = frame_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 60) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 60) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 60) && (V >= 43) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 60) && (V >= 46) && (V >= 150)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 60) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 60) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第七格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第七格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame_c.at<Vec3b>(i, j)[0];
					 S = frame_c.at<Vec3b>(i, j)[1];
					 V = frame_c.at<Vec3b>(i, j)[2];
					 //cout << i << ' ' << j << ' ' << H << ' ' << S << ' ' << V << endl;
					 if ((H >= 0) && (H <= 180) && (S <= 60) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 60) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 60) && (V >= 43) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 60) && (V >= 46) && (V >= 150)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 60) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 60) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第八格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第八格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame_c.at<Vec3b>(i, j)[0];
					 S = frame_c.at<Vec3b>(i, j)[1];
					 V = frame_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 60) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 60) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 60) && (V >= 43) && (V <= 170)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 60) && (V >= 46) && (V >= 150)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 60) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 60) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第九格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第九格
			 if (num == 2)
			 {

				 for (i = 1; i <= 3; i++)
				 {
					 for (j = 1; j <= 3; j++)
						 cout << rubic[i][j] << ' ';
					 cout << endl;
				 }

				 CX.a[6][1][1] = rubic[3][1];  CX.a[6][1][2] = rubic[2][1]; CX.a[6][1][3] = rubic[1][1];
				 CX.a[6][2][1] = rubic[3][2]; CX.a[6][2][2] = D; CX.a[6][2][3] = rubic[1][2];
				 CX.a[6][3][1] = rubic[3][3]; CX.a[6][3][2] = rubic[2][3]; CX.a[6][3][3] = rubic[1][3];
			 }
		 }
		 ///////////////////////////////////////////////////D 6
		 if (1)
		 {
			 Point2f src_coners4[4];
			 src_coners4[0] = Point2f(180, 116);
			 src_coners4[1] = Point2f(343, 242);
			 src_coners4[2] = Point2f(214,253);
			 src_coners4[3] = Point2f(335, 364);
			 circle(frame2, src_coners4[0], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame2, src_coners4[1], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame2, src_coners4[2], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame2, src_coners4[3], 3, Scalar(0, 0, 255), 3, 8);
			 Mat warpMatrix4 = getPerspectiveTransform(src_coners4, dst_coners);
			 warpPerspective(frame2, frame2_a, warpMatrix4, Size(400, 400), INTER_LINEAR, BORDER_CONSTANT);
			 //透视变换
		     //rec(frame2_a);
			 //imshow("frame2", frame2);
			 cvtColor(frame2_a, frame2_a, COLOR_BGR2HSV);//RGB转HSV
			 //imshow("frame2_a", frame2_a);
			 //setMouseCallback("frame2_a", on_mouse, &frame2_a);



			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 0; i <= 90; i++)
			 {
				 for (j = 0; j <= 70; j++)
				 {
					 H = frame2_a.at<Vec3b>(i, j)[0];
					 S = frame2_a.at<Vec3b>(i, j)[1];
					 V = frame2_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) ) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 40) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S >=43 ) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第一格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////////第一格

			 for (i = 1; i <= 6; i++) color[i] = 0;

			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame2_a.at<Vec3b>(i, j)[0];
					 S = frame2_a.at<Vec3b>(i, j)[1];
					 V = frame2_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 40) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第二格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第二格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame2_a.at<Vec3b>(i, j)[0];
					 S = frame2_a.at<Vec3b>(i, j)[1];
					 V = frame2_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 40) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第三格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////////第三格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {

					 H = frame2_a.at<Vec3b>(i, j)[0];
					 S = frame2_a.at<Vec3b>(i, j)[1];
					 V = frame2_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 40) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第四格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////第四格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame2_a.at<Vec3b>(i, j)[0];
					 S = frame2_a.at<Vec3b>(i, j)[1];
					 V = frame2_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 40) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第五格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第五格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame2_a.at<Vec3b>(i, j)[0];
					 S = frame2_a.at<Vec3b>(i, j)[1];
					 V = frame2_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 40) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第六格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第六格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 210; i <= 240; i++)
			 {
				 for (j = 10; j <= 40; j++)
				 {
					 H = frame2_a.at<Vec3b>(i, j)[0];
					 S = frame2_a.at<Vec3b>(i, j)[1];
					 V = frame2_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 40) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第七格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第七格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame2_a.at<Vec3b>(i, j)[0];
					 S = frame2_a.at<Vec3b>(i, j)[1];
					 V = frame2_a.at<Vec3b>(i, j)[2];
					 //cout << i << ' ' << j << ' ' << H << ' ' << S << ' ' << V << endl;
					 if ((H >= 0) && (H <= 180) && (S <= 43)) color[1]++;
					 if ((H >= 26) && (H <= 55) && (S >= 35) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第八格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第八格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame2_a.at<Vec3b>(i, j)[0];
					 S = frame2_a.at<Vec3b>(i, j)[1];
					 V = frame2_a.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43)) color[1]++;
					 if ((H >= 26) && (H <= 55) && (S >= 35) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第九格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第九格
			 if (num == 2)
			 {

				 for (i = 1; i <= 3; i++)
				 {
					 for (j = 1; j <= 3; j++)
						 cout << rubic[i][j] << ' ';
					 cout << endl;
				 }

				 CX.a[3][1][1] = rubic[1][1];  CX.a[3][1][2] = rubic[1][2]; CX.a[3][1][3] = rubic[1][3];
				 CX.a[3][2][1] = rubic[2][1]; CX.a[3][2][2] =L; CX.a[3][2][3] = rubic[2][3];
				 CX.a[3][3][1] = rubic[3][1]; CX.a[3][3][2] = rubic[3][2]; CX.a[3][3][3] = rubic[3][3];
			 }

		 }
		 ///////////////////////////////////////////////////L 3
		 if (1)
		 {
			 Point2f src_coners5[4];
			 src_coners5[0] = Point2f(341, 246);
			 src_coners5[1] = Point2f(500, 121);
			 src_coners5[2] = Point2f(339, 365);
			 src_coners5[3] = Point2f(460, 255);
			 circle(frame2, src_coners5[0], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame2, src_coners5[1], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame2, src_coners5[2], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame2, src_coners5[3], 3, Scalar(0, 0, 255), 3, 8);
			 Mat warpMatrix5 = getPerspectiveTransform(src_coners5, dst_coners);
			 warpPerspective(frame2, frame2_b, warpMatrix5, Size(400, 400), INTER_LINEAR, BORDER_CONSTANT);
			 //透视变换
//			 rec(frame2_b);
			 imshow("frame2", frame2);
			 cvtColor(frame2_b, frame2_b, COLOR_BGR2HSV);//RGB转HSV
			 imshow("frame2_b", frame2_b);
			 setMouseCallback("frame2_b", on_mouse, &frame2_b);



			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {
					 H = frame2_b.at<Vec3b>(i, j)[0];
					 S = frame2_b.at<Vec3b>(i, j)[1];
					 V = frame2_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 40) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 150)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43)&& (V >= 160)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第一格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////////第一格

			 for (i = 1; i <= 6; i++) color[i] = 0;

			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {
					 H = frame2_b.at<Vec3b>(i, j)[0];
					 S = frame2_b.at<Vec3b>(i, j)[1];
					 V = frame2_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 40) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 150)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 160)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第二格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第二格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 0; i <= 75; i++)
			 {
				 for (j = 225; j <= 300; j++)
				 {
					 H = frame2_b.at<Vec3b>(i, j)[0];
					 S = frame2_b.at<Vec3b>(i, j)[1];
					 V = frame2_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 40) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 150)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 160)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第三格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////////第三格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {

					 H = frame2_b.at<Vec3b>(i, j)[0];
					 S = frame2_b.at<Vec3b>(i, j)[1];
					 V = frame2_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 40) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 150)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 160)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第四格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////第四格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame2_b.at<Vec3b>(i, j)[0];
					 S = frame2_b.at<Vec3b>(i, j)[1];
					 V = frame2_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 40) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 150)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 160)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第五格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第五格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame2_b.at<Vec3b>(i, j)[0];
					 S = frame2_b.at<Vec3b>(i, j)[1];
					 V = frame2_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 40) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 150)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 160)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第六格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第六格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {
					 H = frame2_b.at<Vec3b>(i, j)[0];
					 S = frame2_b.at<Vec3b>(i, j)[1];
					 V = frame2_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 40) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 150)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 160)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第七格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第七格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame2_b.at<Vec3b>(i, j)[0];
					 S = frame2_b.at<Vec3b>(i, j)[1];
					 V = frame2_b.at<Vec3b>(i, j)[2];
					 //cout << i << ' ' << j << ' ' << H << ' ' << S << ' ' << V << endl;
					 if ((H >= 0) && (H <= 180) && (S <= 40) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 150)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 160)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第八格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第八格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 210; i <= 240; i++)
			 {
				 for (j = 260; j <= 290; j++)
				 {

					 H = frame2_b.at<Vec3b>(i, j)[0];
					 S = frame2_b.at<Vec3b>(i, j)[1];
					 V = frame2_b.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 40) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 10) || ((H >= 156) && (H <= 180))) && (S >= 43) && (V >= 46) && (V <= 150)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 160)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 50) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第九格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第九格
			 if (num == 2)
			 {

				 for (i = 1; i <= 3; i++)
				 {
					 for (j = 1; j <= 3; j++)
						 cout << rubic[i][j] << ' ';
					 cout << endl;
				 }

				 CX.a[1][1][1] = rubic[1][1];  CX.a[1][1][2] = rubic[1][2]; CX.a[1][1][3] = rubic[1][3];
				 CX.a[1][2][1] = rubic[2][1]; CX.a[1][2][2] = F; CX.a[1][2][3] = rubic[2][3];
				 CX.a[1][3][1] = rubic[3][1]; CX.a[1][3][2] = rubic[3][2]; CX.a[1][3][3] = rubic[3][3];
			 }

		 }
		 ///////////////////////////////////////////////////F 1
		 if (1)
		 {
			 Point2f src_coners6[4];
			 src_coners6[0] = Point2f(182, 106);
			 src_coners6[1] = Point2f(334, 23);
			 src_coners6[2] = Point2f(338, 216);
			 src_coners6[3] = Point2f(493, 105);
			 circle(frame2, src_coners6[0], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame2, src_coners6[1], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame2, src_coners6[2], 3, Scalar(0, 0, 255), 3, 8);
			 circle(frame2, src_coners6[3], 3, Scalar(0, 0, 255), 3, 8);
			 Mat warpMatrix6 = getPerspectiveTransform(src_coners6, dst_coners);
			 warpPerspective(frame2, frame2_c, warpMatrix6, Size(400, 400), INTER_LINEAR, BORDER_CONSTANT);
			 //透视变换
			 //rec(frame2_c);
			 //imshow("frame2", frame2);
			 cvtColor(frame2_c, frame2_c, COLOR_BGR2HSV);//RGB转HSV
			 //imshow("frame2_c", frame2_c);
			 //setMouseCallback("frame2_c", on_mouse, &frame2_c);



			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {
					 H = frame2_c.at<Vec3b>(i, j)[0];
					 S = frame2_c.at<Vec3b>(i, j)[1];
					 V = frame2_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S >43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第一格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////////第一格

			 for (i = 1; i <= 6; i++) color[i] = 0;

			 for (i = 0; i <= 100; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {
					 H = frame2_c.at<Vec3b>(i, j)[0];
					 S = frame2_c.at<Vec3b>(i, j)[1];
					 V = frame2_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S > 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第二格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第二格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 10; i <= 20; i++)
			 {
				 for (j = 230; j <= 240; j++)
				 {
					 H = frame2_c.at<Vec3b>(i, j)[0];
					 S = frame2_c.at<Vec3b>(i, j)[1];
					 V = frame2_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S > 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[1][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[1][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第三格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////////第三格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 0; j <= 100; j++)
				 {

					 H = frame2_c.at<Vec3b>(i, j)[0];
					 S = frame2_c.at<Vec3b>(i, j)[1];
					 V = frame2_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S > 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第四格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////第四格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame2_c.at<Vec3b>(i, j)[0];
					 S = frame2_c.at<Vec3b>(i, j)[1];
					 V = frame2_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S > 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第五格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第五格
			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 100; i <= 200; i++)
			 {
				 for (j = 200; j <= 300; j++)
				 {

					 H = frame2_c.at<Vec3b>(i, j)[0];
					 S = frame2_c.at<Vec3b>(i, j)[1];
					 V = frame2_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S > 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[2][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[2][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第六格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第六格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 230; i++)
			 {
				 for (j = 0; j <= 30; j++)
				 {
					 H = frame2_c.at<Vec3b>(i, j)[0];
					 S = frame2_c.at<Vec3b>(i, j)[1];
					 V = frame2_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S > 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][1] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][1] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第七格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ////////////////////////////第七格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 200; i <= 300; i++)
			 {
				 for (j = 100; j <= 200; j++)
				 {

					 H = frame2_c.at<Vec3b>(i, j)[0];
					 S = frame2_c.at<Vec3b>(i, j)[1];
					 V = frame2_c.at<Vec3b>(i, j)[2];
					 //cout << i << ' ' << j << ' ' << H << ' ' << S << ' ' << V << endl;
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S > 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][2] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][2] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第八格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 ///////////////////////////////第八格

			 for (i = 1; i <= 6; i++) color[i] = 0;
			 for (i = 270; i <= 300; i++)
			 {
				 for (j = 270; j <= 300; j++)
				 {

					 H = frame2_c.at<Vec3b>(i, j)[0];
					 S = frame2_c.at<Vec3b>(i, j)[1];
					 V = frame2_c.at<Vec3b>(i, j)[2];
					 if ((H >= 0) && (H <= 180) && (S <= 43) && (V >= 140)) color[1]++;
					 if ((H >= 26) && (H <= 50) && (S >= 43) && (V >= 46)) color[2]++;
					 if (((H <= 15) || ((H >= 156) && (H <= 180))) && (S > 43) && (V >= 46) && (V <= 180)) color[3]++;
					 if ((H >= 0) && (H <= 25) && (S >= 43) && (V >= 180)) color[4]++;
					 if ((H >= 100) && (H <= 124) && (S >= 43) && (V >= 46)) color[5]++;
					 if ((H >= 60) && (H <= 99) && (S >= 43) && (V >= 46)) color[6]++;
				 }
			 }
			 n = color[1]; rubic[3][3] = 1;
			 for (i = 1; i <= 5; i++)
			 {
				 if (n < color[i + 1]) { rubic[3][3] = i + 1; n = color[i + 1]; }
			 }
			 //cout << "第九格" << endl;
			 //for (i = 1; i <= 6; i++) cout << color[i] << endl;
			 //////////////////////////////第九格
			 if (num == 2)
			 {

				 for (i = 1; i <= 3; i++)
				 {
					 for (j = 1; j <= 3; j++)
						 cout << rubic[i][j] << ' ';
					 cout << endl;
				 }

				 CX.a[5][1][1] = rubic[1][1];  CX.a[5][1][2] = rubic[1][2]; CX.a[5][1][3] = rubic[1][3];
				 CX.a[5][2][1] = rubic[2][1]; CX.a[5][2][2] = U; CX.a[5][2][3] = rubic[2][3];
				 CX.a[5][3][1] = rubic[3][1]; CX.a[5][3][2] = rubic[3][2]; CX.a[5][3][3] = rubic[3][3];
			 }

		 }
		 ///////////////////////////////////////////////////U 5

		 if (num == 2)
		 {
			 s =0;
			 for (i = 1; i <= 6; i++)
			 {
				 Print(i);
				 cout << "                             " << endl;
			 }
			 if (s == 0)
			 {
				 i = 0;
				 n = CX.a[5][2][2];
				 m = CX.a[6][2][2];
				 //12前后 34左右 56上下
				 //1白2黄3红4橙5蓝6绿
			   	Cross1();//顶层十字
				 First();//一层复原
				Second();//二层复原
				 Cross2();//顶层十字2
				 Up();//顶层复原;
				 Third();//三层复原
				 Fin();//最终复原

				 				 for (i = 1; i <= 6; i++)
				 {
					 Print(i);
					 cout << "                             " << endl;
				 }
			 }
			 else if (s==1)
			 {
				 i = 0; j = 0; k = 0;
				 while (check1() == 0)
				 {
					 i++;
					 if (((CX.a[5][2][3] == 1) && (CX.a[4][1][2] == 5)) || ((CX.a[5][2][3] == 5) && (CX.a[4][1][2] == 1))) { i++; try1(); continue; }
					 if ((CX.a[5][2][3] == 1) && (CX.a[4][1][2] == 3)) { a3(); continue; }
					 if ((CX.a[5][2][3] == 3) && (CX.a[4][1][2] == 1)) { l_(); a2(); l(); continue; }
					 if ((CX.a[5][2][3] == 2) && (CX.a[4][1][2] == 3)) { l2(); a2(); l2(); continue; }
					 if ((CX.a[5][2][3] == 2) && (CX.a[4][1][2] == 5)) { d_(); l2(); a2(); l2(); d(); continue; }
					 if ((CX.a[5][2][3] == 1) && (CX.a[4][1][2] == 4)) { a2(); continue; }
					 if ((CX.a[5][2][3] == 4) && (CX.a[4][1][2] == 1)) { l(); a3(); l_(); continue; }
					 if ((CX.a[5][2][3] == 2) && (CX.a[4][1][2] == 4)) { l2(); a3(); l2(); continue; }
					 if ((CX.a[5][2][3] == 1) && (CX.a[4][1][2] == 6)) { a1(); continue; }
					 if ((CX.a[5][2][3] == 6) && (CX.a[4][1][2] == 1)) { l(); d_(); l(); a1(); l_(); d(); l_(); continue; }
					 if ((CX.a[5][2][3] == 2) && (CX.a[4][1][2] == 6)) { l2(); a1(); l2(); continue; }
					 if ((CX.a[5][2][3] == 3) && (CX.a[4][1][2] == 5)) { d2(); l(); a1(); l_(); d2(); continue; }
					 if ((CX.a[5][2][3] == 5) && (CX.a[4][1][2] == 3)) { d_(); l_(); a1(); l(); d(); continue; }
					 if ((CX.a[5][2][3] == 3) && (CX.a[4][1][2] == 2)) { l_(); a3(); l(); continue; }
					 if ((CX.a[5][2][3] == 5) && (CX.a[4][1][2] == 4)) { d(); l(); a1(); l_(); d_(); continue; }
					 if ((CX.a[5][2][3] == 4) && (CX.a[4][1][2] == 5)) { d2(); l_(); a1(); l(); d2(); continue; }
					 if ((CX.a[5][2][3] == 5) && (CX.a[4][1][2] == 2)) { d(); l(); a2(); l_(); d_(); continue; }
					 if ((CX.a[5][2][3] == 4) && (CX.a[4][1][2] == 6)) { l(); a1(); l_(); continue; }
					 if ((CX.a[5][2][3] == 6) && (CX.a[4][1][2] == 4)) { d(); l_(); a1(); l(); d_(); continue; }
					 if ((CX.a[5][2][3] == 4) && (CX.a[4][1][2] == 2)) { l(); a2(); l_(); continue; }
					 if ((CX.a[5][2][3] == 6) && (CX.a[4][1][2] == 3)) { d_(); l(); a1(); l_(); d(); continue; }
					 if ((CX.a[5][2][3] == 3) && (CX.a[4][1][2] == 6)) { l_(); a1(); l(); continue; }
					 if ((CX.a[5][2][3] == 6) && (CX.a[4][1][2] == 2)) { d_(); l(); a2(); l_(); d(); continue; }

				 }
				 if (i % 2 == 1) { a1(); a4(); }

				 //角块//
				 while (check2() == 0)
				 {
					 if (((CX.a[5][1][1] == 1) && (CX.a[2][1][3] == 4) && (CX.a[3][1][1] == 6)) || ((CX.a[5][1][1] == 4) && (CX.a[2][1][3] == 6) && (CX.a[3][1][1] == 1)) || ((CX.a[5][1][1] == 6) && (CX.a[2][1][3] == 1) && (CX.a[3][1][1] == 4))) { try2(); }
					 if ((CX.a[5][1][1] == 5) && (CX.a[2][1][3] == 3) && (CX.a[3][1][1] == 2)) { A5(); }
					 if ((CX.a[5][1][1] == 2) && (CX.a[2][1][3] == 3) && (CX.a[3][1][1] == 6)) { CX.F_(); printf("F_"); A5(); CX.F(); printf("F"); }
					 if ((CX.a[5][1][1] == 2) && (CX.a[2][1][3] == 5) && (CX.a[3][1][1] == 3)) { CX.F_(); CX.R_(); printf("F_R_"); A5(); CX.R(); CX.F(); printf("RF"); }
					 if ((CX.a[5][1][1] == 2) && (CX.a[2][1][3] == 4) && (CX.a[3][1][1] == 5)) { CX.R2(); CX.F(); printf("R2F"); A5(); CX.F_(); CX.R2(); printf("F_R2"); }
					 if ((CX.a[5][1][1] == 2) && (CX.a[2][1][3] == 6) && (CX.a[3][1][1] == 4)) { CX.D2(); CX.R_(); CX.D_(); printf("D2R_D_"); A5(); CX.D(); CX.R(); CX.D2(); printf("DRD2"); }//////////
					 if ((CX.a[5][1][1] == 3) && (CX.a[2][1][3] == 6) && (CX.a[3][1][1] == 2)) { CX.D(); printf("D"); A5(); CX.D_(); printf("D_"); };
					 //已归位//
					 if ((CX.a[5][1][1] == 4) && (CX.a[2][1][3] == 5) && (CX.a[3][1][1] == 2)) { CX.D_(); printf("D_"); A5(); CX.D(); printf("D"); }
					 if ((CX.a[5][1][1] == 6) && (CX.a[2][1][3] == 4) && (CX.a[3][1][1] == 2)) { CX.D2(); printf("D2"); A5(); CX.D2(); printf("D2"); }
					 if ((CX.a[5][1][1] == 6) && (CX.a[2][1][3] == 2) && (CX.a[3][1][1] == 3)) { CX.F2(); CX.R_(); printf("F2R_"); A5(); CX.R(); CX.F2(); printf("RF2"); }
					 if ((CX.a[5][1][1] == 3) && (CX.a[2][1][3] == 2) && (CX.a[3][1][1] == 5)) { CX.D(); CX.R(); printf("DR"); A5(); CX.R_(); CX.D_(); printf("R_D_"); }
					 if ((CX.a[5][1][1] == 5) && (CX.a[2][1][3] == 2) && (CX.a[3][1][1] == 4)) { CX.R(); printf("R"); A5(); CX.R_(); printf("R_"); }
					 if ((CX.a[5][1][1] == 4) && (CX.a[2][1][3] == 2) && (CX.a[3][1][1] == 6)) { CX.D_(); CX.R(); printf("D_R"); A5(); CX.R_(); CX.D(); printf("R_D"); }
					 if ((CX.a[5][1][1] == 1) && (CX.a[2][1][3] == 3) && (CX.a[3][1][1] == 5)) { CX.F(); printf("F"); A5(); CX.F_(); printf("F_"); }
					 if ((CX.a[5][1][1] == 1) && (CX.a[2][1][3] == 5) && (CX.a[3][1][1] == 4)) { CX.R(); CX.D_(); printf("RD_"); A5(); CX.D(); CX.R_(); printf("DR_"); }
					 if ((CX.a[5][1][1] == 1) && (CX.a[2][1][3] == 6) && (CX.a[3][1][1] == 3)) { CX.F(); CX.R_(); printf("FR_"); A5(); CX.R(); CX.F_(); printf("RF_"); }
					 if ((CX.a[5][1][1] == 3) && (CX.a[2][1][3] == 5) && (CX.a[3][1][1] == 1)) { CX.F2(); CX.D(); printf("F2D"); A5(); CX.D_(); CX.F2(); printf("D_F2"); }
					 if ((CX.a[5][1][1] == 5) && (CX.a[2][1][3] == 4) && (CX.a[3][1][1] == 1)) { CX.R2(); printf("R2"); A5(); CX.R2(); printf("R2"); }
					 if ((CX.a[5][1][1] == 6) && (CX.a[2][1][3] == 3) && (CX.a[3][1][1] == 1)) { CX.F2(); printf("F2"); A5(); CX.F2(); printf("F2"); }
					 if ((CX.a[5][1][1] == 5) && (CX.a[2][1][3] == 1) && (CX.a[3][1][1] == 3)) { CX.R_(); printf("R_"); A5(); CX.R(); printf("R"); }
					 if ((CX.a[5][1][1] == 4) && (CX.a[2][1][3] == 1) && (CX.a[3][1][1] == 5)) { CX.R_(); CX.F(); printf("R_F"); A5(); CX.F_(); CX.R(); printf("F_R"); }
					 if ((CX.a[5][1][1] == 3) && (CX.a[2][1][3] == 1) && (CX.a[3][1][1] == 6)) { CX.F_(); CX.D(); printf("F_D"); A5(); CX.D_(); CX.F(); printf("D_F"); }
				 }
			 }

		 }
		 num++;
		 waitKey(30);
	  }
	  return 0;
}
