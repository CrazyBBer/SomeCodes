// SafeArryGUID.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <objbase.h>
#include <string>
#include<atlsafe.h>
#include<iostream>
using namespace std;

string GuidToString(const GUID &guid)
{
	char buf[64] = { 0 };
	sprintf_s(buf, sizeof(buf), "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
		guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1],
		guid.Data4[2], guid.Data4[3],
		guid.Data4[4], guid.Data4[5],
		guid.Data4[6], guid.Data4[7]);
	return string(buf);
}

void Put1GuidInSafeArry()
{
	GUID guid;
	CoCreateGuid(&guid);

	auto guidStri = GuidToString(guid);

	cout << guidStri << endl;

	//TODO... put the guid into safearry..
	SAFEARRAY* p_safe_arry;
	SAFEARRAYBOUND safe_arry_bound[2] = { 0 };
	auto guidsize = sizeof(GUID);
	safe_arry_bound[0].cElements = guidsize;
	safe_arry_bound[0].lLbound = 0;
	safe_arry_bound[1].cElements = guidsize;
	safe_arry_bound[1].lLbound = 0;

	p_safe_arry = SafeArrayCreate(VT_ARRAY, 1, safe_arry_bound);
	auto pnData = reinterpret_cast<char*>(p_safe_arry->pvData);
	memcpy_s(pnData, guidsize, guidStri.c_str(), guidsize);
	//TODO...
	//do something..
	SafeArrayDestroy(p_safe_arry);
}

void Put2GuidInSafeArry()
{
	GUID guid, guid2;
	CoCreateGuid(&guid);
	CoCreateGuid(&guid2);

	//TODO... put the guid into safearry..
	SAFEARRAY* p_safe_arry;
	SAFEARRAYBOUND safe_arry_bound[1] = { 0 };
	safe_arry_bound[0].cElements = 5;
	safe_arry_bound[0].lLbound = 0;

	p_safe_arry = SafeArrayCreate(VT_VARIANT, 1, safe_arry_bound);

	long Low(0), High(0);
	SafeArrayGetLBound(p_safe_arry, 1, &Low);
	SafeArrayGetUBound(p_safe_arry, 1, &High);

	////p_safe_arry->cbElements = sizeof(GUID);
	//long lDimension;
	//lDimension = 0;
	//SafeArrayPutElement(p_safe_arry, &lDimension, &guid);
	//lDimension = 1;

	//SafeArrayPutElement(p_safe_arry, &lDimension, &guid2);
	////TODO...
	//GUID guidout = { 0 };
	//SafeArrayGetElement(p_safe_arry, &lDimension, &guidout);

	GUID* pData = NULL;
	HRESULT hr = SafeArrayAccessData(p_safe_arry, (void**)&pData);
	pData[0] = guid;
	pData[1] = guid2;
	//TODO...
	SafeArrayUnaccessData(p_safe_arry);
	SafeArrayDestroy(p_safe_arry);
}

void Put1GuidInSafeArryByStack()
{
	GUID guid;

	//TODO... put the guid into safearry..
	SAFEARRAY* pArray = nullptr;
	auto hr = SafeArrayAllocDescriptorEx(VT_CLSID, 1, &pArray);
	pArray->cbElements = sizeof(GUID);
	pArray->rgsabound[0].cElements = 1;
	pArray->rgsabound[0].lLbound = 16;
	pArray->pvData = &guid;
	pArray->fFeatures = FADF_AUTO;
	//_bstr_t bstr;
}

void CComSafeArrayGUID()
{
	//CComSafeArray<GUID> comsafeguid(10);
}

void LearnSafeArray()
{
	SAFEARRAY *pArray = nullptr;
	HRESULT hr = SafeArrayAllocDescriptor(1, &pArray);//创建SAFEARRAY结构的对象
	pArray->cbElements = sizeof(GUID);
	pArray->rgsabound[0].cElements = 10;
	pArray->rgsabound[0].lLbound = 0;

	GUID guid, guid2;
	CoCreateGuid(&guid);
	CoCreateGuid(&guid2);
	GUID _guidarr[] = { guid,guid2 };
	pArray->pvData = _guidarr;
	pArray->fFeatures = FADF_AUTO | FADF_FIXEDSIZE;

	//CComSafeArray<VARIANT> saguid;
//	saguid.Attach(pArray);

	//auto count = saguid.GetCount();

	//auto t = saguid.GetType();

	GUID* p_GUIDArry = nullptr;
	SafeArrayAccessData(pArray, (PVOID*)&p_GUIDArry);

	auto retv = p_GUIDArry[0];
	auto retv1 = p_GUIDArry[1];

	long Low(0), High(0);
	hr = SafeArrayGetLBound(pArray, 1, &Low);//维数索引从1开始
	hr = SafeArrayGetUBound(pArray, 1, &High);//维数索引从1开始

	SafeArrayUnaccessData(pArray);
	SafeArrayDestroy(pArray);

	//	cin.get();
}

void TestSafeArry()
{
	LearnSafeArray();
	//CComSafeArrayBound bound(2);
	//CComSafeArray<GUID>  guid_Array;
	//GUID guid, guid2;
	//CoCreateGuid(&guid);
	//CoCreateGuid(&guid2);
	//guid_Array.Add(guid);
	//guid_Array.Add(guid2);

	//auto count = guid_Array.GetCount();
	//auto demention = guid_Array.GetDimensions();
	//auto upperbound = guid_Array.GetUpperBound();
	//auto p_safeArry = &guid_Array;
	//GUID guid3;
	//CoCreateGuid(&guid3);
	//p_safeArry->SetAt(1, guid3);
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestSafeArry();
	//Put1GuidInSafeArry();
	Put2GuidInSafeArry();
	Put1GuidInSafeArryByStack();
	return 0;
}