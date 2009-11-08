#include <string>
#include <iostream>
#include <windows.h>

using namespace std;
using namespace System;

//convert String^ in std::string
void MarshalString ( String ^ s, string& os ) {
   using namespace Runtime::InteropServices;
   const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   os = chars;
   Marshal::FreeHGlobal(IntPtr((void*)chars));
}

//convert String^ in std::wstring
void MarshalString ( String ^ s, wstring& os ) {
   using namespace Runtime::InteropServices;
   const wchar_t* chars = (const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
   os = chars;
   Marshal::FreeHGlobal(IntPtr((void*)chars));
}

//convert std::string in std::wstring
std::wstring s2ws(const std::string& s){
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0); 
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

//convert std::wstring in std::string
std::string ws2s(const std::wstring& s){
	int len;
	int slength = (int)s.length() + 1;
	len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, 0, 0, 0, 0);
	char* buf = new char[len];
	WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, buf, len, 0, 0);
	std::string r(buf);
	delete[] buf;
	return r;
}

//scan for files in an directory - NOT COMPLETED - TODO
void scanDir(const std::string& rDirName){
	HANDLE finfo;
	WIN32_FIND_DATA data;

	std::wstring sKey = s2ws(rDirName + "\\*.*");
	finfo = FindFirstFile(sKey.c_str(), &data);
}
