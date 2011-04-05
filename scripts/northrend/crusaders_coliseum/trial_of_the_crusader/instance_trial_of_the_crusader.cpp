/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: instance_trial_of_the_crusader
SD%Complete: 100
SDComment:
SDCategory: Crusader Coliseum
EndScriptData */

#include "precompiled.h"
#include "trial_of_the_crusader.h"

/* Trial Of The Crusader encounters:
0 - Northrend Beasts
1 - Jaraxxus
2 - Faction Champions
3 - Twin Valkyr
4 - Anubarak
*/

instance_trial_of_the_crusader::instance_trial_of_the_crusader(Map* pMap) : ScriptedInstance(pMap),
    m_uiGormokGUID(0),
    m_uiAcidmawGUID(0),
    m_uiDreadscaleGUID(0),
    m_uiIcehowlGUID(0),
    m_uiJaraxxusGUID(0),
    m_uiFjolaGUID(0),
    m_uiEydisGUID(0),
    m_uiAnubarakGUID(0),
    m_uiBarrettGUID(0),
    m_uiTirionGUID(0),
    m_uiFizzlebangGUID(0),
    m_uiGarroshGUID(0),
    m_uiVarianGUID(0),
    m_uiLichGUID(0),
    m_uiJainaGUID(0),
    m_uiThrallGUID(0),
    m_uiCrusader1GUID(0),
    m_uiCrusader2GUID(0),
    m_uiCrusader3GUID(0),
    m_uiCrusader4GUID(0),
    m_uiCrusader5GUID(0),
    m_uiCrusader6GUID(0),
    m_uiCrusader7GUID(0),
    m_uiCrusader8GUID(0),
    m_uiCrusader9GUID(0),
    m_uiCrusader10GUID(0),
    m_uiCrusadersCacheGUID(0),
    m_uiFloorGUID(0),
    m_uiTributeChest25GUID(0),
    m_uiTributeChest45GUID(0),
    m_uiTributeChest50GUID(0),
    m_uiTributeChest99GUID(0),
    m_uiMainGateDoorGUID(0),
    m_uiSouthDoorGUID(0),
    m_uiWestDoorGUID(0),
    m_uiNorthDoorGUID(0),
    m_uiWebDoorGUID(0),
    m_uiTwinsCasting(0),
    m_uiEventState(0),
    m_bNeedSave(false)
{
    Initialize();
}

void instance_trial_of_the_crusader::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
}

bool instance_trial_of_the_crusader::IsEncounterInProgress() const
{
    for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
        if (m_auiEncounter[i] == IN_PROGRESS) return true;

    return false;
}

void instance_trial_of_the_crusader::OnPlayerEnter(Player* pPlayer)
{
    // update world state for heroic version
    if (instance->GetDifficulty() == RAID_DIFFICULTY_10MAN_HEROIC || instance->GetDifficulty() == RAID_DIFFICULTY_25MAN_HEROIC)
    {
        pPlayer->SendUpdateWorldState(WORLD_STATE_WIPES_SHOW, 1);
        pPlayer->SendUpdateWorldState(WORLD_STATE_WIPES_COUNT, MAX_WIPES - GetData(TYPE_WIPE_COUNTER));
    }
}

void instance_trial_of_the_crusader::OnCreatureCreate(Creature* pCreature)
{
    switch(pCreature->GetEntry())
    {
        case NPC_GORMOK:        m_uiGormokGUID     = pCreature->GetGUID(); break;
        case NPC_ACIDMAW:       m_uiAcidmawGUID    = pCreature->GetGUID(); break;
        case NPC_DREADSCALE:    m_uiDreadscaleGUID = pCreature->GetGUID(); break;
        case NPC_ICEHOWL:       m_uiIcehowlGUID    = pCreature->GetGUID(); break;
        case NPC_JARAXXUS:      m_uiJaraxxusGUID   = pCreature->GetGUID(); break;
        case NPC_FJOLA:         m_uiFjolaGUID      = pCreature->GetGUID(); break;
        case NPC_EYDIS:         m_uiEydisGUID      = pCreature->GetGUID(); break;
        case NPC_ANUBARAK:      m_uiAnubarakGUID   = pCreature->GetGUID(); break;
        // others
        case NPC_BARRETT:       m_uiBarrettGUID    = pCreature->GetGUID(); break;
        case NPC_TIRION:        m_uiTirionGUID     = pCreature->GetGUID(); break;
        case NPC_WILFRED:       m_uiFizzlebangGUID = pCreature->GetGUID(); break;
        case NPC_GARROSH:       m_uiGarroshGUID    = pCreature->GetGUID(); break;
        case NPC_VARIAN:        m_uiVarianGUID     = pCreature->GetGUID(); break;
        case NPC_LICH_KING:     m_uiLichGUID       = pCreature->GetGUID(); break;
        case NPC_JAINA:         m_uiJainaGUID      = pCreature->GetGUID(); break;
        case NPC_THRALL:        m_uiThrallGUID     = pCreature->GetGUID(); break;
    }
}

void instance_trial_of_the_crusader::OnObjectCreate(GameObject *pGo)
{
    switch(pGo->GetEntry())
    {
        case GO_CRUSADERS_CACHE_10:
        case GO_CRUSADERS_CACHE_25:
        case GO_CRUSADERS_CACHE_10_H:
        case GO_CRUSADERS_CACHE_25_H:
            m_uiCrusadersCacheGUID = pGo->GetGUID();
            break;
        case GO_COLISEUM_FLOOR:
            m_uiFloorGUID = pGo->GetGUID();
            break;
        case GO_MAIN_GATE:
            m_uiMainGateDoorGUID = pGo->GetGUID();
            break;
        case GO_SOUTH_GATE:
            m_uiSouthDoorGUID = pGo->GetGUID();
            break;
        case GO_WEST_GATE:
            m_uiWestDoorGUID = pGo->GetGUID();
            break;
        case GO_NORTH_GATE:
            m_uiNorthDoorGUID = pGo->GetGUID();
            break;
        case GO_WEB_DOOR:
            m_uiWebDoorGUID = pGo->GetGUID();
            break;
        case GO_TRIBUTE_CHEST_10H_25:
        case GO_TRIBUTE_CHEST_25H_25:
            m_uiTributeChest25GUID = pGo->GetGUID();
            break;
        case GO_TRIBUTE_CHEST_10H_45:
        case GO_TRIBUTE_CHEST_25H_45:
            m_uiTributeChest45GUID = pGo->GetGUID();
            break;
        case GO_TRIBUTE_CHEST_10H_50:
        case GO_TRIBUTE_CHEST_25H_50:
            m_uiTributeChest50GUID = pGo->GetGUID();
            break;
        case GO_TRIBUTE_CHEST_10H_99:
        case GO_TRIBUTE_CHEST_25H_99:
            m_uiTributeChest99GUID = pGo->GetGUID();
            break;
    }
}

void instance_trial_of_the_crusader::SetData(uint32 uiType, uint32 uiData)
{
    debug_log("SD2: Instance Trial Of The Crusader: SetData received for type %u with data %u",uiType,uiData);

    switch(uiType)
    {
        case TYPE_NORTHREND_BEASTS:
            m_auiEncounter[0] = uiData;
            DoUseDoorOrButton(m_uiWestDoorGUID);
            break;
        case TYPE_JARAXXUS:
            m_auiEncounter[1] = uiData;
            DoUseDoorOrButton(m_uiWestDoorGUID);
            break;
        case TYPE_FACTION_CHAMPIONS:
            m_auiEncounter[2] = uiData;
            DoUseDoorOrButton(m_uiWestDoorGUID);
            if (uiData == DONE)
                DoRespawnGameObject(m_uiCrusadersCacheGUID, 30*MINUTE);
            break;
        case TYPE_TWIN_VALKYR:
            m_auiEncounter[3] = uiData;
            DoUseDoorOrButton(m_uiWestDoorGUID);
            break;
        case TYPE_ANUBARAK:
            m_auiEncounter[4] = uiData;
            // combat door
            DoUseDoorOrButton(m_uiWebDoorGUID);
            // tribute chest on heroic
            if (uiData == DONE)
            {
                if (instance->GetDifficulty() == RAID_DIFFICULTY_10MAN_HEROIC || instance->GetDifficulty() == RAID_DIFFICULTY_25MAN_HEROIC)
                {
                    if(MAX_WIPES - GetData(TYPE_WIPE_COUNTER) >= 1 && MAX_WIPES - GetData(TYPE_WIPE_COUNTER) < 25)
                        DoRespawnGameObject(m_uiTributeChest25GUID);
                    else if(MAX_WIPES - GetData(TYPE_WIPE_COUNTER) >= 25 && MAX_WIPES - GetData(TYPE_WIPE_COUNTER) < 45)
                        DoRespawnGameObject(m_uiTributeChest45GUID);
                    else if(MAX_WIPES - GetData(TYPE_WIPE_COUNTER) >= 45 && MAX_WIPES - GetData(TYPE_WIPE_COUNTER) < 50)
                        DoRespawnGameObject(m_uiTributeChest50GUID);
                    else if(MAX_WIPES - GetData(TYPE_WIPE_COUNTER) == 50)
                        DoRespawnGameObject(m_uiTributeChest99GUID);
                }
            }
            break;
        case TYPE_WIPE_COUNTER:
            // increase the wipe counter
            m_auiEncounter[5] += uiData;
            m_bNeedSave = true;
            break;
        case TYPE_STAGE:
            m_uiEventState = uiData;
            break;
        case TYPE_TWINS_CASTING:
            m_uiTwinsCasting = uiData;
            break;
         default:
            error_log("SD2: Instance Trial of The Crusader: ERROR SetData = %u for type %u does not exist/not implemented.",uiType,uiData);
            break;
    }

    // handle the wipes
    // if encounter is failed then increase the wipe counter and update the world state
    // applies only on heroic
    if (uiData == FAIL && instance->GetDifficulty() == RAID_DIFFICULTY_10MAN_HEROIC || instance->GetDifficulty() == RAID_DIFFICULTY_25MAN_HEROIC)
    {
        SetData(TYPE_WIPE_COUNTER, 1);
        DoUpdateWorldState(WORLD_STATE_WIPES_COUNT, MAX_WIPES - GetData(TYPE_WIPE_COUNTER));
    }

    if (uiData == DONE || m_bNeedSave)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " "
            << m_auiEncounter[3] << " " << m_auiEncounter[4] << " " << m_auiEncounter[5];

        strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;

        m_bNeedSave = false;
    }
}

void instance_trial_of_the_crusader::SetData64(uint32 uiType, uint64 uiData)
{
    switch(uiType)
    {
        case DATA_CRUSADER_1:       m_uiCrusader1GUID = uiData; break;
        case DATA_CRUSADER_2:       m_uiCrusader2GUID = uiData; break;
        case DATA_CRUSADER_3:       m_uiCrusader3GUID = uiData; break;
        case DATA_CRUSADER_4:       m_uiCrusader4GUID = uiData; break;
        case DATA_CRUSADER_5:       m_uiCrusader5GUID = uiData; break;
        case DATA_CRUSADER_6:       m_uiCrusader6GUID = uiData; break;
        case DATA_CRUSADER_7:       m_uiCrusader7GUID = uiData; break;
        case DATA_CRUSADER_8:       m_uiCrusader8GUID = uiData; break;
        case DATA_CRUSADER_9:       m_uiCrusader9GUID = uiData; break;
        case DATA_CRUSADER_10:      m_uiCrusader10GUID = uiData;break;
    }
}

uint32 instance_trial_of_the_crusader::GetData(uint32 uiType)
{
    switch(uiType)
    {
        case TYPE_NORTHREND_BEASTS:  return m_auiEncounter[0];
        case TYPE_JARAXXUS:          return m_auiEncounter[1];
        case TYPE_FACTION_CHAMPIONS: return m_auiEncounter[2];
        case TYPE_TWIN_VALKYR:       return m_auiEncounter[3];
        case TYPE_ANUBARAK:          return m_auiEncounter[4];
        case TYPE_WIPE_COUNTER:      return m_auiEncounter[5];
        case TYPE_STAGE:             return m_uiEventState;
        case TYPE_TWINS_CASTING:     return m_uiTwinsCasting;
    }
    return 0;
}

uint64 instance_trial_of_the_crusader::GetData64(uint32 uiData)
{
    switch(uiData)
    {
        case NPC_GORMOK:     return m_uiGormokGUID;
        case NPC_ACIDMAW:    return m_uiAcidmawGUID;
        case NPC_DREADSCALE: return m_uiDreadscaleGUID;
        case NPC_ICEHOWL:    return m_uiIcehowlGUID;
        case NPC_JARAXXUS:   return m_uiJaraxxusGUID;
        case NPC_FJOLA:      return m_uiFjolaGUID;
        case NPC_EYDIS:      return m_uiEydisGUID;
        case NPC_ANUBARAK:   return m_uiAnubarakGUID;
        case NPC_BARRETT:    return m_uiBarrettGUID;
        case NPC_TIRION:     return m_uiTirionGUID;
        case NPC_GARROSH:    return m_uiGarroshGUID;
        case NPC_VARIAN:     return m_uiVarianGUID;
        case NPC_JAINA:      return m_uiJainaGUID;
        case NPC_THRALL:     return m_uiThrallGUID;

        case DATA_CRUSADER_1: return m_uiCrusader1GUID;
        case DATA_CRUSADER_2: return m_uiCrusader2GUID;
        case DATA_CRUSADER_3: return m_uiCrusader3GUID;
        case DATA_CRUSADER_4: return m_uiCrusader4GUID;
        case DATA_CRUSADER_5: return m_uiCrusader5GUID;
        case DATA_CRUSADER_6: return m_uiCrusader6GUID;
        case DATA_CRUSADER_7: return m_uiCrusader7GUID;
        case DATA_CRUSADER_8: return m_uiCrusader8GUID;
        case DATA_CRUSADER_9: return m_uiCrusader9GUID;
        case DATA_CRUSADER_10: return m_uiCrusader10GUID;

        case GO_COLISEUM_FLOOR: return m_uiFloorGUID;
        case GO_MAIN_GATE:      return m_uiMainGateDoorGUID;
    }
    return 0;
}

void instance_trial_of_the_crusader::Load(const char* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    std::istringstream loadStream(chrIn);
    loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3]
        >> m_auiEncounter[4] >> m_auiEncounter[5];

    for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
    {
        if (m_auiEncounter[i] == IN_PROGRESS)
            m_auiEncounter[i] = NOT_STARTED;
    }

    OUT_LOAD_INST_DATA_COMPLETE;
}

InstanceData* GetInstanceData_instance_trial_of_the_crusader(Map* pMap)
{
    return new instance_trial_of_the_crusader(pMap);
}

void AddSC_instance_trial_of_the_crusader()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_trial_of_the_crusader";
    pNewScript->GetInstanceData = &GetInstanceData_instance_trial_of_the_crusader;
    pNewScript->RegisterSelf();
}
