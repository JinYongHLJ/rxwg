﻿#include "stdafx.h"
#include "AddressData.h"

// 可以从本地配置文件中读取地址信息
class AddressData
{
public:
	AddressData();
	void InitAddress();
};

AddressData g_addressData;

AddressData::AddressData()
{
	InitAddress();
}

void AddressData::InitAddress()
{
	UserBaseAddress = 0x02AEBC38;
	UserNameOffset = 0x0;
	UserCareerOffset = 0x30;
	UserLevelOffset = 0x34;
	UserHPOffset = 0x80; 
	UserMPOffset = 0x84; 
	UserMaxHPOffset = 0x8C;
	UserMaxMPOffset = 0x90;

	MapBaseAddress = 0x02D379F8;
	MapNameOffset = 0x231;

	CordinateBaseAddress = 0x02D37970;
	CordinateXOffset = 0x36C;
	CordinateYOffset = 0x370;

	GoodsBaseAddress = 0x02D105DC;
	GoodsBaseOffestAddress = 0x410;     
	GoodsNameOffset = 0x5C;
	GoodsNumberOffset = 0xC44;
	GoodsIDOffset = 0xD1C;
	GoodsPropOffset = 0xD24;

	GoodsUseCallAddress = 0x007FDC50;

	ShopBaseAddress = 0x02D37CF4;
	ShopBaseOffset = 0x410; 
	ShopItemIDOffset = 0x4C; 
	ShopItemNameOffset = 0x5C;
	ShopCallAddress = 0x004E0220;


	EntityBaseAddress = 0x02D36514;
	EntitySelOffset = 0x1A3C;
	EntityXOffset = 0x1C04;
	EntityYOffset = 0x1C0C;

	EntityPropAddress = 0x02D36518;
	EntityTypeOffset = 0x8;
	EntityIdOffset = 0xC;
	EntityNameOffset = 0x360;
	EntityDistOffset = 0x35C;
	EntityLevelOffset = 0x5F8;
	EntityHalfOffset = 0x5F4;
	EntityDeadOffset = 0x3C0;
	EntityKillOffset = 0x3C8;
	EntityCordinateXOffset = 0x1060;
	EntityCordinateYOffset = 0x1068;

	EntityType_Monster = 0x2E;
	EntityType_NPC = 0x2E; 
	EntityType_Player = 0x31;
	EntityType_Goods = 0x33; 

	EntityGoodsIDOffset = 0x78;
	EntityGoodsNameOffset = 0x94;


	F1_F10_BaseAddress = 0x02D11D40;
	F1_F10_BaseOffestAddress = 0x410; 
	F1_F10_CallAddress = 0x006E9020;

	ActionBaseAddress = 0x02D10B90;
	ActionCallAddress = 0x006E1EF0;
}

// 人物属性相关地址
DWORD UserBaseAddress; // 人物属性基址
DWORD UserNameOffset; // 名称偏移
DWORD UserCareerOffset; // 人物职业偏移
DWORD UserLevelOffset; // 等级偏移
DWORD UserHPOffset; // 血量偏移
DWORD UserMPOffset; // 蓝量偏移
DWORD UserMaxHPOffset; // 血量最大值偏移
DWORD UserMaxMPOffset; // 蓝量最大值偏移

DWORD CordinateBaseAddress; // 坐标基址
DWORD CordinateXOffset; // X坐标偏移
DWORD CordinateYOffset; // Y坐标偏移

DWORD MapBaseAddress; // 地图基址
DWORD MapNameOffset; // 当前地图名称偏移

						// 背包相关地址
DWORD GoodsBaseAddress;//背包的基址
DWORD GoodsBaseOffestAddress;     //背包基本的偏移
DWORD GoodsNameOffset; // 物品名称偏移
DWORD GoodsNumberOffset; // 物品数量偏移
DWORD GoodsIDOffset;
DWORD GoodsPropOffset;

DWORD GoodsUseCallAddress;// 使用背包物品call，参数为物品在背包中的索引下标(0-35)

DWORD ShopBaseAddress; // 商店基址
DWORD ShopBaseOffset; // 商店基本偏移值
DWORD ShopItemIDOffset; // 商店物品ID偏移
DWORD ShopItemNameOffset; // 商店物品名称偏移
DWORD ShopCallAddress; // 商店购买call

						  // 选中的怪物相关地址
DWORD EntityBaseAddress;// 选中怪物ID基址
DWORD EntitySelOffset; // 选中怪物ID偏移值
DWORD EntityXOffset; // x坐标偏移
DWORD EntityYOffset; // y坐标偏移
					   // 怪物属性相关
DWORD EntityPropAddress;// 怪物属性基址
DWORD EntityTypeOffset; // 类型偏移
DWORD EntityIdOffset; // ID偏移
DWORD EntityNameOffset; // 名称偏移
DWORD EntityDistOffset; // 距离偏移
DWORD EntityLevelOffset; // 等级偏移
DWORD EntityHalfOffset; // 血量偏移
DWORD EntityDeadOffset; // 是否死亡偏移
DWORD EntityKillOffset; // 是否可以施展绝命技的偏移，为1是可以
DWORD EntityCordinateXOffset; // 怪物X坐标偏移
DWORD EntityCordinateYOffset; // 怪物Y坐标偏移
						// 怪物类型 物品：0x33，玩家：0x31, 怪物/NPC：0x2E(NPC等级为0，血量为32000)
DWORD EntityType_Monster; // 野怪
DWORD EntityType_NPC; // NPC
DWORD EntityType_Player; // 其他玩家
DWORD EntityType_Goods; // 物品
DWORD EntityGoodsIDOffset; // 物品ID偏移
DWORD EntityGoodsNameOffset; // 物品名称偏移


						// 快捷键相关地址
DWORD F1_F10_BaseAddress;//快捷键基址
DWORD F1_F10_BaseOffestAddress;     //快捷键基本偏移
DWORD F1_F10_CallAddress;//快捷键call地址

						 // 人物动作相关地址
DWORD ActionBaseAddress; // 动作基址
DWORD ActionCallAddress; // 动作call地址
