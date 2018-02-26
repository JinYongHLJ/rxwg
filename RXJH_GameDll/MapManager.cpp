#include "stdafx.h"
#include "MapManager.h"
#include "CommonRead.h"


MapManager::MapManager()
{
	InitMaps();
}


MapManager::~MapManager()
{
}


MapManager& MapManager::GetMgr()
{
	static MapManager s_instance;
	return s_instance;
}

const std::vector<MapInfo>& MapManager::GetAllMaps()
{
	return m_maps;
}

bool MapManager::GetMapInfoByName(const CString& a_szName, MapInfo& a_info)
{
	for (int i = 0; i < m_maps.size(); i++)
	{
		if (a_szName == m_maps[i].szName)
		{
			a_info = m_maps[i];
			return true;
		}
	}
	return false;
}

CString MapManager::GetCurrentMap()
{
	static const DWORD s_dwMapIndexAddress = 0x010c8cb8;
	static const DWORD s_dwMapPropAddress = 0x010F61B4;
	DWORD dwIndex = Read_RD(Read_RD(Read_RD(s_dwMapIndexAddress) + 0x2A0) + 0x248);
	char* pMapName = Read_RS(s_dwMapPropAddress + dwIndex * 0x2E8);
	return pMapName ? pMapName : "";
}

void MapManager::InitMaps()
{
	// ������
	//MapInfo xbp("������", "�سǷ�(������)", "Τ��", { 155, 1780 }, "ƽʮָ", { 742, 1958 });
	MapInfo xbp("������", "�سǷ�(������)", "Τ��", { 155, 1780 }, "ƽʮָ", { 742, 1958 }, "����Ц", { 1155, 2227 });
	xbp.newarMaps.push_back(NearMap("��а��", "", {2440, -338}));
	xbp.newarMaps.push_back(NearMap("������", "", {-2352, -460}));
	xbp.newarMaps.push_back(NearMap("��Ȫ", "����ͤ", {60, 1866}));
	xbp.newarMaps.push_back(NearMap("������", "", { -15, -2350 }));
	xbp.newarMaps.push_back(NearMap("��������", "�������", { 649, 1071 }));
	xbp.newarMaps.push_back(NearMap("��ħ��", "�������", { 649, 1071 }, 1));
	xbp.newarMaps.push_back(NearMap("����", "�������", { 649, 1071 }, 2));
	xbp.newarMaps.push_back(NearMap("��Ͽ��", "�������", { 649, 1071 }, 3));
	xbp.newarMaps.push_back(NearMap("��ͤƽԭ", "��������", { 574, 1032 }));
	m_maps.push_back(xbp);

	// ��Ȫ֮����Ҫ���⴦����
	MapInfo jq("��Ȫ֮��1��", "�سǷ�(��Ȫ)", "", { 0, 0 }, "����ͤ", { 0, -264 }, "", {0}, false);
	jq.newarMaps.push_back(NearMap("������", "����ͤ", {0, -264}, 1));
	jq.newarMaps.push_back(NearMap("��Ȫ֮��100��", "�Ŵ�� ����", { -2, 81}, 1));
	m_maps.push_back(jq);

	MapInfo sxg("��а��", "�سǷ�(��а��)", "����ͨ",{ 6610, 176 }, "½С��",{ 6599, 746 });
	sxg.newarMaps.push_back(NearMap("�����ᶽ��", "", { 7350, 1235 }));
	sxg.newarMaps.push_back(NearMap("������", "", { 2685, -369 }));
	m_maps.push_back(sxg);

	MapInfo lzg("������", "�سǷ�(������)", "����",{ -6832, 297 }, "����ˮ",{ -6639, 203 });
	lzg.newarMaps.push_back(NearMap("������", "", { -7432, 920 }));
	lzg.newarMaps.push_back(NearMap("������", "", { -2688, -292 }));
	m_maps.push_back(lzg);

	MapInfo nmh("������", "", "", { 0, 0 }, "", { 0, 0 });
	nmh.newarMaps.push_back(NearMap("������", "", { -104, 2418 }));
	nmh.newarMaps.push_back(NearMap("������", "����������", { 1346, 1156 }));
	m_maps.push_back(nmh);
	// ��Ȫ�ͱ�����������ʹ��������ͼ�ĻسǷ�
	//  �������������� ������� xbp:649 1071 bhbg:1578 1185 nl:-1063 265

	MapInfo lsf("�����ᶽ��", "�سǷ�(���Ƹ�)", "��ԯ����",{ 1176, 239 }, "������",{ 1142, 979 }, "��ʮ����", { 780, 922 });
	lsf.newarMaps.push_back(NearMap("��а��", "", { -2285, -525}));
	lsf.newarMaps.push_back(NearMap("���¹�", "", { 1346, 1156 }));
	lsf.newarMaps.push_back(NearMap("Ѫħ��", "�Ϲ���", { 0, 0 }));
	m_maps.push_back(lsf);

	MapInfo swm("������", "�سǷ�(������)", "ƽʮָ", { 742, 1958 }, "½С��", { 735, 1856 });
	swm.newarMaps.push_back(NearMap("������", "", { 2195, 393}));
	swm.newarMaps.push_back(NearMap("�����", "����������", { 0, 0 }));
	swm.newarMaps.push_back(NearMap("���鶴", "�Ϲ���", { 0, 0 }));
	m_maps.push_back(swm);

	MapInfo bhbg("��������", "�سǷ�(��������)", "��ʮ��", { 1792, -333 }, "���³�", { 2054, -308}, "˾������", { 1563, -844}, false);
	bhbg.newarMaps.push_back(NearMap("������", "�������", { 1578, 1185 }));
	m_maps.push_back(bhbg);

	MapInfo nl("����", "�سǷ�(����)", "�ƺƻ�", { 181, 464}, "�ջ���", { 55, 615}, "�����", { 86, -19 }, false);
	nl.newarMaps.push_back(NearMap("������", "�������", { -1063, 265}));
	m_maps.push_back(nl);
}