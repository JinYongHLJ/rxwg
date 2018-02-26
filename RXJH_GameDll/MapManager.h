#pragma once
#include <vector>

// �ڽ���ͼ��Ϣ
struct NearMap
{
	CString szName; // ��ͼ����
	CString szTransferNpc; // �ִ�õ�ͼ�Ĵ���NPC
	POINT transferPt; // ����NPC�������ʱ�ִ�õ�ͼ������
	DWORD dwTransIndex; // �㿪�Ի��󣬵�ͼ����ѡ�������

	NearMap(){}
	NearMap(char* a_name, char* a_transferNpc = "", POINT a_pt = { 0 }, DWORD a_transIndex = 0)
	:szName(a_name), transferPt(a_pt), szTransferNpc(a_transferNpc), dwTransIndex(a_transIndex)
	{

	}
};
// ��ͼ��Ϣ
struct MapInfo
{
	CString szName; // ��ͼ����
	CString szHCFName;// �سǷ�����
	CString szDepotNpc; // �ֿ�NPC����
	POINT depotPt; // �ֿ�NPC����
	CString szSupplyNpc; // ҩƷ����NPC����
	POINT supplyPt; // ҩƷ����NPC����
	CString szArmNpc; // ���ּ�ʸ����NPC����
	POINT armPt; // ���ּ�ʸ����NPC����
	bool bUseOtherHCF; // �Ƿ����ʹ��������ͼ�ĻسǷ�
	// ���ڵ�ͼ��Ϣ
	std::vector<NearMap> newarMaps;

	MapInfo(){}
	MapInfo(char* a_name, char* a_hcfName, char* a_depotNpc, POINT a_depotPt, \
		char* a_supplyNpc, POINT a_supplyPt, char* a_armNpc = "", POINT a_armPt = { 0 }, bool a_bOtherHCF = true)
	:szName(a_name), szHCFName(a_hcfName), szDepotNpc(a_depotNpc), depotPt(a_depotPt), \
		szSupplyNpc(a_supplyNpc), supplyPt(a_supplyPt), szArmNpc(a_armNpc), armPt(a_armPt), bUseOtherHCF(a_bOtherHCF)
	{

	}
};


class MapManager
{
public:
	static MapManager& GetMgr();

	const std::vector<MapInfo>& GetAllMaps();

	bool GetMapInfoByName(const CString& a_szName, MapInfo& a_info);

	CString GetCurrentMap();
private:
	MapManager();
	~MapManager();

	void InitMaps();

private:
	std::vector<MapInfo> m_maps;
};

