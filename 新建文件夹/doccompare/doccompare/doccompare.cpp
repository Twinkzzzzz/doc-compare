// doccompare.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <windows.h>
#include <ShlObj.h>
#include <stdio.h>
#include <stdlib.h>
#include <atlstr.h>
using namespace std;

int main()
{
	CString path;
	OPENFILENAME open;// 公共对话框结构。
	char file[MAX_PATH];// 用来保存获取文件名称的缓冲区。 
	ZeroMemory(&open, sizeof(OPENFILENAME)); // 初始化选择文件对话框
	open.lStructSize = sizeof(OPENFILENAME);//指定这个结构的大小，以字节为单位。
	open.lpstrFile = file;//打开的文件的全路径
	open.lpstrFile[0] = '\0'; //第一个字符串是过滤器描述的显示字符串
	open.nMaxFile = MAX_PATH;  //指定lpstrFile缓冲的大小，以TCHARs为单位
	open.lpstrFilter = "文本文件(*.txt)\0*.txt\0所有文件(*.*)\0*.*\0\0";  //打开文件类型
	open.nFilterIndex = 1;  //指定在文件类型控件中当前选择的过滤器的索引
	open.lpstrFileTitle = NULL; // 指向接收选择的文件的文件名和扩展名的缓冲（不带路径信息）。这个成员可以是NULL。
	open.nMaxFileTitle = 0;  //指定lpstrFileTitle缓冲的大小，以TCHARs为单位
	open.lpstrInitialDir = NULL;  //指向以空字符结束的字符串，可以在这个字符串中指定初始目录。
	open.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;//位标记的设置，你可以使用来初始化对话框
	//GetOpenFileName (&open) ;//打开文件对话框
	//GetSaveFileName(&open);//保存文件对话框
	if (GetOpenFileName(&open))  // 显示打开选择文件对话框。  
	{
		path = file;
		printf(path + "\n");
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
