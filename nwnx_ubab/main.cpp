#define _CRT_SECURE_NO_WARNINGS
#include "NWNXUbab.h"

CNWNXUbab ubab;

//Export the object
extern "C" __declspec(dllexport) CNWNXBase* GetClassObject(){
	return &ubab;
}

BOOL APIENTRY DllMain (HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved){
    return TRUE;
}