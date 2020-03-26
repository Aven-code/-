#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "console.h"
#include <time.h>
#include <stdlib.h>

/*
	ϵͳ������Դ����
*/

/*��궨λ*/
void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);	
	SetConsoleCursorPosition(GetStdHandle(STD_INPUT_HANDLE), pos);
}

/*��ȡ���*/
void getxy(int *x, int *y)
{
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen_buffer_info);
	*x = screen_buffer_info.dwCursorPosition.X;
	*y = screen_buffer_info.dwCursorPosition.Y;
}


/*�������*/
 void cursor_hide(void)
{
	CONSOLE_CURSOR_INFO cci;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}



// ��ȡ����
int get_key(void)
{
	if(_kbhit())	//����м�����
	{
		int ch=_getch();//����һ��ֵ
		if(ch ==0x0 || ch==0xe0)//�Ƿ�Ϊ����ֵ
		{
			ch=_getch();
			switch(ch)
			{
				case 0x48:
					return UP;
				case 0x50:
					return DOWN;
				case 0x4B:
					return LEFT;
				case 0x4D:
					return RIGHT;
				default:
					return NONE;
			}
		}else	//ֻ��һ����ֵ
		{
			switch(ch)
			{
				case 0x50:
					return P_UPPER;
				case 0x70:
					return P_LOWER;
				case 0x51:
					return Q_UPPER;	//��Q�˳�
				case 0x71:
					return Q_LOWER;
				case 0x20:
					return SPACE;
				case 0xd:
					return ENTER;
				default:
					return NONE;
			}
		}
	}
	return NONE;
}


/*
	���ܣ�����ָ����Χ�������
	���������ֵ����Сֵ
	���أ�һ�������
*/
int random(int min,int max)
{
	int val;
	//srand((unsigned int)time(NULL));main��������Ҫ���õ�
	val=rand()%(max-min+1)+min;
	return val;
}