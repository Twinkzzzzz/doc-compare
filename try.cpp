#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <windows.h>
#include <CommCtrl.h>
#include <commdlg.h>
#include <comdef.h>
#include <gdiplus.h>
using namespace std;

int main()
{
	string filename;
	OPENFILENAME ofn = { 0 };
	char strFileName[999] = { 0 };	//���ڽ����ļ���
	ofn.lStructSize = sizeof(OPENFILENAME);	//�ṹ���С
	ofn.hwndOwner = NULL;					//ӵ���Ŵ��ھ��
	ofn.lpstrFilter = TEXT("All\0*.*\0jpg\0*.jpg\0bmp\0*.bmp\0\0");	//���ù���
	ofn.nFilterIndex = 1;	//����������
	ofn.lpstrFile = strFileName;	//���շ��ص��ļ�����ע���һ���ַ���ҪΪNULL
	ofn.nMaxFile = sizeof(strFileName);	//����������
	ofn.lpstrInitialDir = NULL;			//��ʼĿ¼ΪĬ��
	ofn.lpstrTitle = TEXT("��"); //���ڱ���
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY; //�ļ���Ŀ¼������ڣ�����ֻ��ѡ��
	//���ļ��Ի���
	if (GetOpenFileName(&ofn)) 
	{
		cout<<"�򿪳ɹ�"<<endl;
		//filename = TCHAR2STRING(strFileName);//charתString
		cout << strFileName << endl;
	}
	else 
	{
		MessageBox(NULL, TEXT("��ѡ��һ�ļ�"), NULL, MB_ICONERROR);
	}
}
