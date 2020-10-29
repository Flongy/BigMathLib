#ifndef COMPARE_H
#define COMPARE_H

#define SIGN_BIT_MASK 0x80000000
#define SIGN_BIT_SHIFT 31

/************************************************************/
/*	 ������� ��������� ���� �����, �������� ��������� ����	*/
/*															*/
/*	 int Compare(IN p_element valueL,						*/
/*				 IN p_element valueM,						*/
/*				 IN unsigned int sizeL,						*/
/*				 IN unsigned int sizeM);					*/
/*															*/
/*	������� ���������:										*/
/*															*/
/*	p_element valueL 		- ������ �������				*/
/*	p_element valueM		- ������ �������				*/
/*	unsigned int  sizeL		- ����� ������� ��������		*/
/*	unsigned int  sizeM		- ����� ������� ��������		*/
/*															*/
/*	������������ ��������:									*/
/*															*/
/*	-1	- ������ ������� ������ ������� ��������			*/
/*	 0	- ������ � ������ ������� �����						*/
/*	 1	- ������ ������� ������ ������� ��������			*/
/*															*/
/************************************************************/

LIB(int) Compare(p_element valueL, p_element valueM, unsigned int sizeL, unsigned int sizeM);

/************************************************************/
/*	 ������� �������� � ������ �����						*/
/*															*/
/*	 static BOOL CompareAndSwap(IN OUT p_element a,			*/
/*								IN OUT p_element b);		*/
/*															*/
/*	������� ���������:										*/
/*															*/
/*	p_element a		- ������ �����							*/
/*	p_element b		- ������ �����							*/
/*															*/
/*	������������ ��������:									*/
/*															*/
/*	True, ���� ���� ����������� ������, ��� False, ����		*/
/*	������ �� ���� �����������								*/
/*															*/
/*	�������:												*/
/*															*/
/*	- ���� b ������ a, �� a ����� ��������					*/
/*	  � b, � b ����� �������� � a							*/
/*	- ���� a ������ b, �� ������� ��������� �� �����		*/
/*	  �����������											*/
/*															*/
/************************************************************/

LIB(BOOL) CompareAndSwap(IN OUT p_element a,
						 IN OUT p_element b);

/************************************************************/
/*	 ������� ������ �����									*/
/*															*/
/*	 static void Swap(IN OUT p_element a,					*/
/*				      IN OUT p_element b);					*/
/*															*/
/*	������� ���������:										*/
/*															*/
/*	p_element a		- ������ �����							*/
/*	p_element b		- ������ �����							*/
/*															*/
/************************************************************/

LIB(void) Swap(IN OUT p_element a,
			   IN OUT p_element b);

#endif