#if !defined(UTILS_H)
#define UTILS_H

#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;
using namespace System;

//convert String^ in std::string
void MarshalString ( String ^ s, string& os );

//convert String^ in std::wstring
void MarshalString ( String ^ s, wstring& os );

//convert std::string in std::wstring
std::wstring s2ws(const std::string& s);

//convert std::wstring in std::string
std::string ws2s(const std::wstring& s);

//create std::string with an ending converted from int
void createStdString(std::string& name, const int count);

//scan for files in an directory - NOT COMPLETED - TODO
void scanDir(const std::string& rDirName);

#endif //UTILS_H
