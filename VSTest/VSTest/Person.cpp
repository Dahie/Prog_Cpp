#include "StdAfx.h"
#include "Person.h"

CPerson::CPerson(void)
{
}

CPerson::~CPerson(void)
{
}

CPerson::CPerson( const char* pName, int pAge) {
  mName = pName;
  mAge = mAge;
}

const char* CPerson::getName() const {
  return mName.c_str();
}

int CPerson::getAge() const {
  return mAge;
}