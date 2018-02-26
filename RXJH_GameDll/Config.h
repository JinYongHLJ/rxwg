#pragma once
#include <set>
#include <map>
#include <vector>



class Config
{
public:
	Config();
	~Config();
	// �������
	void ResetData();

	// ����/������������
	bool LoadConfig();
	bool SaveConfig();

	// ��������
	int nProtectHP;
	int nProtectMP;
	CString szPriorHPDrug;
	CString szPriorMPDrug;

	// �һ�����
	POINT pt;
	CString szWorkMap;
	int nAttackType;
	int nAttackRange;
	BOOL bNearestPrior;
	BOOL bPickUp;
	int nFilterDist; // ���˽��ֵľ���
	BOOL bFilterMonster;
	BOOL bFixedPos;

	// �س�����
	BOOL bCheckHPDrugs;
	int nMinHPDrugs;
	BOOL bCheckMPDrugs;
	int nMinMPDrugs;
	BOOL bCheckArrows;
	int nMinArrows;
	BOOL bCheckPackage;
	CString szSupplyMap;

	// ��������: ��Ʒ���ƣ�����
	std::map<CString, DWORD> buys;

	std::vector<CString> hpDrugs;
	std::vector<CString> mpDrugs;
	std::vector<CString> armArrows;
	std::vector<CString> hcfs;

	std::vector<CString> buyGoods;
	// �������
	std::vector<CString> pickFilters;
};

