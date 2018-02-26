﻿#include "stdafx.h"
#include "Funtion.h"
#include "CommonRead.h"
#include "AddressData.h"
#include <cmath>


//-------------------------------------------------------------------------------------
char* GetGoodsName(DWORD dwData)
{
	return Read_RS(dwData + 0x5c);
}

DWORD GetGoodsPostion(DWORD dwData)
{
	return Read_RB(dwData + 0x1F4);
}

DWORD GetGoodsIDforName(CString strName)
{
	for (DWORD i=0;i<36;i++)
	{
		DWORD dwNation = Read_RD(Read_RD(GoodsBaseAddress) + i*4 +GoodsBaseOffestAddress);
		if (0x0 == dwNation)
		{
			continue;
		}
		if (GetGoodsName(dwNation) == strName)
		{
			return GetGoodsPostion(dwNation);
		}
	}
	return 0x0FFFF;
}

BOOL UseTheGoodsCall(DWORD dwPostion)
{
	if (0x0FFFF == dwPostion)
	{
		return FALSE;
	}
	_asm
	{
		mov edi,GoodsBaseAddress
		mov edi,[edi]
		MOV EAX,[EDI+0x1608]
		MOV ECX,[EDI+0x1BD0]
		push dwPostion
		push eax
		push ecx
		mov ecx,edi
		mov ebx,GoodsUseCallAddress
		CALL ebx
	}
	return TRUE;
}

//--------------------------------------------------------------------
char* GetEntityName(DWORD dwData)
{
	return Read_RS(dwData + EntityNameOffset);
}

DWORD GetEntityType(DWORD dwData)
{
	return Read_RD(dwData + EntityTypeOffset);
}

DWORD GetEntityId(DWORD dwData)
{
	return Read_RD(dwData + EntityIdOffset);
}

float GetEntityDistance(DWORD dwData)
{
	return Read_RF(dwData + EntityDistOffset);
}

DWORD GetEntityDeath(DWORD dwData)
{
	return Read_RD(dwData + EntityDeadOffset);
}

DWORD GetEntityHP(DWORD dwData)
{
	return Read_RD(dwData + EntityHalfOffset);
}

DWORD GetEntityDengJi(DWORD dwData)
{
	return Read_RD(dwData + EntityLevelOffset);
}

DWORD GetEntityJueming(DWORD dwData)
{
	return Read_RD(dwData + EntityKillOffset);
}

DWORD GetEntitySelID()
{
	return Read_RD(Read_RD(EntityBaseAddress) + EntitySelOffset);
}

float Convert2Float(DWORD dwAddr)
{
	DWORD dwMem = *((DWORD*)dwAddr);
	DWORD dwOri = dwMem;
	//revert

	DWORD* pMem = &dwMem;
	float* pRet = (float*)pMem;
	float ret = *pRet;
	return ret;
	/*DWORD dwVal = 0x42af147b;
	DWORD* pdw = &dwVal;
	float temp = 87.54;
	float* pf = &temp;

	pf = (float*)pdw;
	temp = *pf;*/
}

DWORD CheckEntity()
{
	DWORD dwSelID = 0;
	if (ENTITY_NOTSEL_ID == GetEntitySelID())
	{
		DWORD dwTempNation = 0;
		float dwDistion = 0.0f;
		for (DWORD dwID = 0x10; dwID < 0x2710; dwID++)
		{
			DWORD dwNation = Read_RD(EntityPropAddress + dwID * 4);
			if (0x0 == dwNation)
			{
				continue;
			}
			// 类型为野怪，NPC等级为0
			if (EntityType_Monster == GetEntityType(dwNation) && GetEntityDengJi(dwNation) > 0)
			{
				// 未死亡
				if (0x0 == GetEntityDeath(dwNation))
				{
					float dist = Convert2Float(dwNation + EntityDistOffset);
					//float asmdist = GetEntityDistance(dwNation);
					if (dwID < 0x1000 || dwID > 0x1600)
					{
						char szmsg[512] = { 0 };
						sprintf_s(szmsg, 512, "rxjh: ID=%x, dist=%f", dwID, dist);
						::OutputDebugStringA(szmsg);
					}
					if (dwDistion == 0.0f || dwDistion > dist)
					{
						dwDistion = dist;
						dwTempNation = dwNation;
						dwSelID = dwID;
					}
				}
			}
		}
		if (dwTempNation != 0)
		{
			_asm
			{
				MOV ESI, dwTempNation
				MOV EAX, [ESI]
				MOV EDX, [EAX + 0x4]
				PUSH 0x1
				PUSH 0x450
				MOV ECX, ESI
				CALL EDX
				MOV EAX, [ESI + 0x0C]
				MOV ECX, EntityBaseAddress
				mov ecx, [ecx]
				mov[ecx + 0x1a3c], eax
			}
		}
	}
	return dwSelID;
}

void CheckNPC(DWORD dwID)
{
	DWORD dwNation = Read_RD(EntityPropAddress + dwID * 4);
	_asm
	{
		MOV ESI, dwNation
		MOV EAX, [ESI]
		MOV EDX, [EAX + 0x4]
		PUSH 0x1
		PUSH 0x450
		MOV ECX, ESI
		CALL EDX
		MOV EAX, [ESI + 0x0C]
		MOV ECX, EntityBaseAddress
		mov ecx, [ecx]
		mov[ecx + 0x1a3c], eax
	}
}

void OpenNPCTalk(DWORD dwID)
{
	DWORD dwNation = Read_RD(EntityPropAddress + dwID * 4);
	_asm
	{
		mov ecx, dwNation
		mov edx, [ecx]
		mov eax, [edx + 4]
		push 0
		push 0
		push 0x401
		call eax
	}
}

void ActionCall(DWORD dwIndex)
{
	DWORD dwNation = Read_RD(Read_RD(ActionBaseAddress) + dwIndex * 4 + 0x410);
	if (0 != dwNation)
	{
		_asm
		{
			mov eax, dwNation
			mov ecx, [eax + 0x4C]
			mov edx, 0x010C8CB8
			mov edx, [edx]
			push ecx
			mov ecx, [edx + 0x27C]
			call ActionCallAddress
		}
	}
}


//-----------------------------------------------------------------------
void UseTheF1_F10Call_(DWORD dwIndex)
{
	DWORD dwNation = Read_RD(F1_F10_BaseAddress);
	if (0x0 != dwNation)
	{
		_asm
		{
			push dwIndex
			mov ecx, dwNation
			mov ebx, F1_F10_CallAddress
			call ebx
		}
	}
}
BOOL UseTheF1_F10Call(DWORD dwPostion)
{
	DWORD dwNation = Read_RD(Read_RD(F1_F10_BaseAddress) + dwPostion*4 + F1_F10_BaseOffestAddress);
	if (0x0 == dwNation)
	{
		return FALSE;
	}
	_asm
	{
		push dwPostion
		mov ebx,F1_F10_CallAddress
		call ebx
	}
	return TRUE;
}
//---------------------------------------------------------------------------
void FindWalk(float x,float y)
{
	BYTE* pDate = new BYTE[84];
	memset(pDate,0,84);

	_asm
	{
		mov ebx,pDate
		mov eax,x
		mov [ebx],eax
		mov eax,y
		mov [ebx+8],eax
		mov [ebx+0x18],0xFFFF
		mov [ebx+0x1C],1
		mov BYTE PTR DS:[ebx+0x20],1

		push 0x54
		push pDate
		push 0x3EF
		mov ecx,EntityBaseAddress
		mov ecx,[ecx]
		mov edx,[ecx]
		mov edx,[edx+4]
		call edx

	}
	delete pDate;
	pDate = nullptr;
}
//----------------------------------------------------------------------------
void LogA(LPCSTR p_szFormat, ...)
{
	va_list args;
	va_start(args, p_szFormat);

	int nBuf;
	char szBuffer[1024] = { 0 };
	nBuf = _vsnprintf_s(szBuffer, sizeof(szBuffer) / sizeof(char) - 1, p_szFormat, args);
	if (nBuf < 0)
	{
		va_end(args);
		return;
	}

	::OutputDebugStringA(szBuffer);

	va_end(args);
}

bool IsNearPoint(PointF p1, PointF p2)
{
	float x = p1.x - p2.x;
	float y = p1.y - p2.y;
	double dist = x*x + y*y;
	if (dist < 1.0)
	{
		return true;
	}
	return false;
}

float CalcPointDist(PointF pt1, PointF pt2)
{
	int x = abs(pt1.x - pt2.x);
	int y = abs(pt1.y - pt2.y);
	double dist = x*x + y*y;
	float ret = sqrt(dist);
	return ret;
}

PointF CalcMoveDestPt(const PointF& a_start, const PointF& a_end, float a_moveDist)
{
	PointF destPt = a_start;
	float dwNeedWalkDist = a_moveDist;
	if (a_end.x == a_start.x)
	{
		if (a_end.y > a_start.y)
		{
			destPt.y += dwNeedWalkDist;
		}
		else
		{
			destPt.y -= dwNeedWalkDist;
		}
	}
	else
	{
		dwNeedWalkDist = dwNeedWalkDist * dwNeedWalkDist;
		float k = (float)(a_end.y - a_start.y) / (a_end.x - a_start.x);
		k = abs(k);
		float temp = 1 + k*k;
		float ret = (float)dwNeedWalkDist / temp;
		float x = sqrt(ret);
		float y = x * k;
		if (a_end.x > a_start.x)
		{
			destPt.x = (float)a_start.x + x;
		}
		else
		{
			destPt.x = (float)a_start.x - x;
		}
		if (a_end.y > a_start.y)
		{
			destPt.y = (float)a_start.y + y;
		}
		else
		{
			destPt.y = (float)a_start.y - y;
		}
	}
	return destPt;
}

bool IsFilterItem(const CString& a_item, const std::vector<CString>& a_filters)
{
	for (auto& item : a_filters)
	{
		if (item == a_item)
		{
			return true;
		}
	}
	return false;
}