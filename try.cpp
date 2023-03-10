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
	char strFileName[999] = { 0 };	//用于接收文件名
	ofn.lStructSize = sizeof(OPENFILENAME);	//结构体大小
	ofn.hwndOwner = NULL;					//拥有着窗口句柄
	ofn.lpstrFilter = TEXT("All\0*.*\0jpg\0*.jpg\0bmp\0*.bmp\0\0");	//设置过滤
	ofn.nFilterIndex = 1;	//过滤器索引
	ofn.lpstrFile = strFileName;	//接收返回的文件名，注意第一个字符需要为NULL
	ofn.nMaxFile = sizeof(strFileName);	//缓冲区长度
	ofn.lpstrInitialDir = NULL;			//初始目录为默认
	ofn.lpstrTitle = TEXT("打开"); //窗口标题
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY; //文件、目录必须存在，隐藏只读选项
	//打开文件对话框
	if (GetOpenFileName(&ofn)) 
	{
		cout<<"打开成功"<<endl;
		//filename = TCHAR2STRING(strFileName);//char转String
		cout << strFileName << endl;
	}
	else 
	{
		MessageBox(NULL, TEXT("请选择一文件"), NULL, MB_ICONERROR);
	}
}
