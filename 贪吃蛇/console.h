#ifndef CONSOLE_H_
#define CONSOLE_H_
#include <Windows.h>

// ����Ƶ�ָ��λ��
void gotoxy(int x, int y);

//��ȡ���λ��
void getxy(int *x, int *y);

//���ع��
 void cursor_hide(void);


 // ��ȡ����
int get_key(void);

// �������õ��İ���ö��ֵ
enum key
{
	NONE    = 0x0000,  // û�м�����
	P_UPPER = 0x0050,  // ��д��ĸ P
	P_LOWER = 0x0070,  // Сд��ĸ p
	Q_UPPER = 0x0051,  // ��д��ĸ Q
	Q_LOWER = 0x0071,  // Сд��ĸ q
	UP      = 0xE048,  // �ϼ�ͷ
	DOWN    = 0xE050,  // �¼�ͷ
	LEFT    = 0xE04B,  // ���ͷ
	RIGHT   = 0xE04D,  // �Ҽ�ͷ
	SPACE	= 0x0020,   //�ո��
	ENTER	= 0x00d  //�س�
};


/*
	���ܣ�����ָ����Χ�������
	���������ֵ����Сֵ
	���أ�һ�������
*/
int random(int min,int max);
#endif