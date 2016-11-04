#include "stdafx.h"
///////////////////////////////////////////////////////////////////////////////
// �ļ�����WeaponMastery.cpp
// ����˵����
//
// �޸ļ�¼��
//
//
//
///////////////////////////////////////////////////////////////////////////////

#include "Type.h"
#include "WeaponMastery.h"
#include "LogicManager.h"


namespace Combat_Module
{
	namespace Skill_Module
	{
		using namespace Combat_Module;
		using namespace Impact_Module;
		BOOL WeaponMastery_T::Refix_ItemEffect(SkillInfo_T & rThisPassiveSkill, INT nSlotID, INT nItemType, INT nAttrID, SHORT & rAttrValue) const
		{
			__ENTER_FUNCTION
			INT nRefixAttackPhysics = rThisPassiveSkill.GetDescriptorByIndex(BASE_ATTACK_PHYSICS_REFIX)->GetValue();
			INT nRefixAttackMagic = rThisPassiveSkill.GetDescriptorByIndex(BASE_ATTACK_MAGIC_REFIX)->GetValue();
			INT const nMasteryType1 = rThisPassiveSkill.GetDescriptorByIndex(MASTERY_OF_WEAPON_TYPE1)->GetValue();
			INT const nMasteryType2 = rThisPassiveSkill.GetDescriptorByIndex(MASTERY_OF_WEAPON_TYPE2)->GetValue();
			switch (nSlotID)
			{
				case	HEQUIP_WEAPON: 	//����	WEAPON
					{
						if(nMasteryType1 == nItemType || nMasteryType2 == nItemType)
						{
							switch (nAttrID)
							{
								case IATTRIBUTE_BASE_ATTACK_P:			//������������
									{
										rAttrValue = Float2Int((rAttrValue * nRefixAttackPhysics)/100.0f);
									}
									break;
								case IATTRIBUTE_BASE_ATTACK_M:			//����ħ������
									{
										rAttrValue = Float2Int((rAttrValue * nRefixAttackMagic)/100.0f);
									}
									break;
								default:
									break;
							}
						}
					}
					break;
					break;
				case	HEQUIP_CAP:		//ñ��	DEFENCE
				case	HEQUIP_ARMOR:	//����	DEFENCE
				case	HEQUIP_CUFF:	//����	DEFENCE
				case	HEQUIP_BOOT:	//Ь	DEFENCE
				case	HEQUIP_SASH:	//����	ADORN
				case	HEQUIP_RING:	//����	ADORN
				case	HEQUIP_NECKLACE://����	ADORN
				case	HEQUIP_RIDER:	//���  ADORN
				default:
					break;
			}
			return TRUE;
			__LEAVE_FUNCTION
			return FALSE;
		}
	};
};