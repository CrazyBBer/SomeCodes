// SafeArryGUID.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <objbase.h>
#include <string>  
#include<atlsafe.h>
using namespace std;

string GuidToString(const GUID &guid)  
{  
    char buf[64] = {0};  
    sprintf_s(buf,sizeof(buf),"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",  
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

	//TODO... put the guid into safearry..
	SAFEARRAY* p_safe_arry;
	SAFEARRAYBOUND safe_arry_bound[1]={0};
	auto guidsize= sizeof(GUID);
	safe_arry_bound[0].cElements =guidsize;
	safe_arry_bound[0].lLbound =0;

	p_safe_arry = SafeArrayCreate(VT_CLSID,1,safe_arry_bound);
	auto pnData = reinterpret_cast<GUID*>(p_safe_arry->pvData);
	memcpy_s(pnData,guidsize,&guid,guidsize);
	//TODO...
	//do something..	
	SafeArrayDestroy(p_safe_arry);
}

void Put2GuidInSafeArry()
{
		GUID guid,guid2;
	CoCreateGuid(&guid); 
	CoCreateGuid(&guid2); 

	//TODO... put the guid into safearry..
	SAFEARRAY* p_safe_arry;
	SAFEARRAYBOUND safe_arry_bound[2]={0};
	safe_arry_bound[0].cElements =2;
	safe_arry_bound[0].lLbound =0;
	safe_arry_bound[1].cElements =16;
	safe_arry_bound[1].lLbound =0;

	p_safe_arry = SafeArrayCreate(VT_CLSID,2,safe_arry_bound);
	auto pnData = reinterpret_cast<GUID*>(p_safe_arry->pvData);
	pnData[0]=guid;
	pnData[1]=guid2;
	//TODO...
	//do something..
	//TODO...

	SafeArrayDestroy(p_safe_arry);
}

void Put1GuidInSafeArryByStack()
{
	GUID guid;
	
	CoCreateGuid(&guid);  
	

	//TODO... put the guid into safearry..
	SAFEARRAY* pArray=nullptr;
	auto hr=SafeArrayAllocDescriptorEx(VT_CLSID,1,&pArray);
	pArray->cbElements=sizeof(GUID);
	pArray->rgsabound[0].cElements=1;
	pArray->rgsabound[0].lLbound=16;
	pArray->pvData=&guid;
	pArray->fFeatures=FADF_AUTO;
	_bstr_t bstr;
}

void CComSafeArrayGUID()
{
	
	//CComSafeArray<GUID> comsafeguid(10);



}



int _tmain(int argc, _TCHAR* argv[])
{

	Put1GuidInSafeArry();
	Put1GuidInSafeArry();
	Put1GuidInSafeArryByStack();
	return 0;
}
