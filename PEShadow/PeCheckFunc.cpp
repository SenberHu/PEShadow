
#include "stdafx.h"
#include "PeCheckFunc.h"



BOOL LoadFileData(WCHAR* wzFilePath,CHAR** szFileData,ULONG* ulLow)
{

	HANDLE hFile;
	ULONG ulHigh = 0;
	ULONG ulReturn = 0;

	if (wzFilePath==NULL)
	{
		return FALSE;
	}

	//打开文件对象
	hFile = CreateFileW(wzFilePath,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);

	if (hFile==INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	*ulLow = GetFileSize(hFile,&ulHigh);//获取指定文件的大小 

	*szFileData = new char[*ulLow + 20];

	if (ReadFile(hFile,*szFileData,*ulLow,&ulReturn,NULL)==0)
	{
		CloseHandle(hFile);
		delete *szFileData;
		return FALSE;
	}

	return TRUE;
}

BOOL	IsPEFile(CHAR* szFileData,PETYPE* PeType)
{
	PIMAGE_DOS_HEADER	DosHead =NULL;
	PIMAGE_NT_HEADERS	NtHead = NULL;
	IMAGE_FILE_HEADER	FileHead = {0};

	//判断是否是PE文件
	DosHead = (PIMAGE_DOS_HEADER)szFileData;
	if (DosHead->e_magic!=IMAGE_DOS_SIGNATURE)
	{
		return FALSE;
	}

	NtHead = (PIMAGE_NT_HEADERS)((ULONG)szFileData+DosHead->e_lfanew);

	if (NtHead->Signature!=IMAGE_NT_SIGNATURE)
	{
		return FALSE;
	}
	//判断32or64PE文件
	FileHead = NtHead->FileHeader;
	switch(FileHead.Machine)   //根据NT头中的FileHeader.Machine判断是哪种32or64PE文件
	{
	case IMAGE_FILE_MACHINE_IA64:
	case IMAGE_FILE_MACHINE_AMD64:
		{
			*PeType = Bit64;
			break;
		}
	case IMAGE_FILE_MACHINE_I386:
		{
			*PeType = Bit32;
			break;
		}


	default: *PeType = Unkonw;
	}

	return TRUE;


}

/*
HANDLE hFile = CreateFile(L"D:\\Demo.txt",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_WRITE|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);    //创建文件从文件中获得数据


DWORD dwHigh = 0;
DWORD dwLow = 0;
dwLow = GetFileSize(hFile,&dwHigh);   

dwLow = ((dwLow + 4095)/4096)*4096;


if (hFile==INVALID_HANDLE_VALUE)
{

return -1;
}


HANDLE hMapping = CreateFileMapping(hFile,NULL,PAGE_READWRITE,dwHigh,dwLow,NULL);


if (hMapping==NULL)
{
CloseHandle(hFile);
}

char* szBuffer = NULL;

szBuffer = (char*)MapViewOfFile(hMapping,FILE_MAP_ALL_ACCESS,0,0,0);
*/