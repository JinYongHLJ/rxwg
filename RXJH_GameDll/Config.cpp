#include "stdafx.h"
#include "Config.h"


Config::Config()
{
	bPickUp = TRUE;
	bNearestPrior = TRUE;
	bFilterMonster = FALSE;
	bFixedPos = FALSE;
	nProtectHP = 150;
	nProtectMP = 50;
	nAttackType = 0;
	nAttackRange = 150;
	nFilterDist = 0;
	nMinHPDrugs = 3;
	nMinMPDrugs = 3;
	nMinArrows = 3;
	bCheckPackage = FALSE;
	szWorkMap = "������";
	szSupplyMap = "������";
	szPriorHPDrug = "��ҩ(С)";
	szPriorMPDrug = "�˲�";

	hpDrugs.push_back("��ҩ(С)");
	hpDrugs.push_back("��ҩ(��)");
	hpDrugs.push_back("��ҩ(��)");
	hpDrugs.push_back("��ҩ(��)");
	hpDrugs.push_back("��ҩ(��)");
	hpDrugs.push_back("���ƽ�ҩ");
	hpDrugs.push_back("ҩ�ɽ�ҩ");
	hpDrugs.push_back("�ʼ���ҩ");

	mpDrugs.push_back("�˲�");
	mpDrugs.push_back("Ұɽ��");
	mpDrugs.push_back("ѩԭ��");
	mpDrugs.push_back("��Ԫ��");
	mpDrugs.push_back("Ѫ��");
	mpDrugs.push_back("�����˲�");
	mpDrugs.push_back("������Ԫ��");
	mpDrugs.push_back("ҩ����Ԫ��");

	armArrows.push_back("�����");
	armArrows.push_back("����");
	armArrows.push_back("�ϵ�");
	armArrows.push_back("͸�Ƕ�");
	armArrows.push_back("������");
	armArrows.push_back("�Ƽ�׶");

	hcfs.push_back("����");
	hcfs.push_back("�سǷ�(������)");
	hcfs.push_back("�سǷ�(��а��)");
	hcfs.push_back("�سǷ�(������)");
	hcfs.push_back("�سǷ�(���Ƹ�)");
	hcfs.push_back("�سǷ�(������)");
	hcfs.push_back("�سǷ�(���¹�)");
	hcfs.push_back("�سǷ�(�����)");
	hcfs.push_back("�سǷ�(��Ȫ)");
	hcfs.push_back("�سǷ�(��������)");
	hcfs.push_back("�سǷ�(����)");
	hcfs.push_back("�سǷ�(��Ͽ��)");
	hcfs.push_back("�سǷ�(��ͤƽԭ)");

	pickFilters.push_back("����");
}


Config::~Config()
{
}

// �������
void Config::ResetData()
{

}

// ����/������������
bool Config::LoadConfig()
{
	/*m_nEnv = ::GetPrivateProfileIntA(CONFIG_SETTING, CONFIG_ENV, DEF_APPENV, m_configFile.c_str());
	int nValue = ::GetPrivateProfileIntA(CONFIG_SETTING, CONFIG_AUTORUN, 0, m_configFile.c_str());
	m_bAutoRun = nValue != 0;

	nValue = ::GetPrivateProfileIntA(CONFIG_SETTING, CONFIG_SENDTYPE, 1, m_configFile.c_str());
	m_bSendByEnter = nValue != 0;

	nValue = ::GetPrivateProfileIntA(CONFIG_SETTING, CONFIG_FLUSH, 1, m_configFile.c_str());
	m_bFlush = nValue != 0;

	nValue = ::GetPrivateProfileIntA(CONFIG_SETTING, CONFIG_REMIND, 1, m_configFile.c_str());
	m_bRemind = nValue != 0;

	char szTime[64] = { 0 };
	::GetPrivateProfileStringA(CONFIG_SETTING, CONFIG_RECOMMENDTIME, "", szTime, 64, m_configFile.c_str());
	m_updateTime = (time_t)_atoi64(szTime);*/
	return true;
}
bool Config::SaveConfig()
{
	// config
	char szValue[64] = { 0 };
	//sprintf_s(szValue, 64, ("%d"), m_nEnv);
	//::WritePrivateProfileStringA(CONFIG_SETTING, CONFIG_ENV, szValue, m_configFile.c_str());
	/*sprintf_s(szValue, 64, ("%d"), m_bAutoRun ? 1 : 0);
	::WritePrivateProfileStringA(CONFIG_SETTING, CONFIG_AUTORUN, szValue, m_configFile.c_str());
	sprintf_s(szValue, 64, ("%d"), m_bSendByEnter ? 1 : 0);
	::WritePrivateProfileStringA(CONFIG_SETTING, CONFIG_SENDTYPE, szValue, m_configFile.c_str());
	sprintf_s(szValue, 64, ("%d"), m_bFlush ? 1 : 0);
	::WritePrivateProfileStringA(CONFIG_SETTING, CONFIG_FLUSH, szValue, m_configFile.c_str());
	sprintf_s(szValue, 64, ("%d"), m_bRemind ? 1 : 0);
	::WritePrivateProfileStringA(CONFIG_SETTING, CONFIG_REMIND, szValue, m_configFile.c_str());*/

	return true;
}
