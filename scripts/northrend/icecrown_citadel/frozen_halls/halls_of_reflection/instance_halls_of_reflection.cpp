/* Copyright (C) 2006 - 2011 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: instance_halls_of_reflection
SD%Complete: 0
SDComment: Placeholder
SDCategory: Halls of Reflection
EndScriptData */

#include "precompiled.h"
#include "halls_of_reflection.h"

instance_halls_of_reflection::instance_halls_of_reflection(Map* pMap) : ScriptedInstance(pMap),
    m_uiFalrynGUID(0),
    m_uiMarwynGUID(0),
    m_uiLichKingGUID(0),
    m_uiJainaGUID(0),
    m_uiSylvanasGUID(0),
    m_uiCaptainsChestGUID(0),
    m_uiIcecrownDoorGUID(0),
    m_uiImpenetrableDoorGUID(0),
    m_uiFrostmourneGUID(0),
    m_uiFrostmourneAltarGUID(0),
    m_uiShadowThroneDoorGUID(0),
    m_uiShadowThroneExitDoorGUID(0),
    m_uiJainaIntroGUID(0),
    m_uiSylvanasIntroGUID(0)
{
    Initialize();
}

void instance_halls_of_reflection::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
}

void instance_halls_of_reflection::OnCreatureCreate(Creature* pCreature)
{
    switch(pCreature->GetEntry())
    {
        case NPC_FALRIC: 
            m_uiFalrynGUID = pCreature->GetGUID();
            break;
        case NPC_MARWYN: 
            m_uiMarwynGUID = pCreature->GetGUID();
            break;
        case NPC_LICH_KING: 
            m_uiLichKingGUID = pCreature->GetGUID();
            break;
        case NPC_JAINA_END:
            m_uiJainaGUID = pCreature->GetGUID();
            break;
        case NPC_SYLVANAS_END:
            m_uiSylvanasGUID = pCreature->GetGUID();
            break;
        case NPC_JAINA_START:
            m_uiJainaIntroGUID = pCreature->GetGUID();
            break;
        case NPC_SYLVANAS_START:
            m_uiSylvanasIntroGUID = pCreature->GetGUID();
            break;
    }
}

void instance_halls_of_reflection::OnObjectCreate(GameObject* pGo)
{
    switch(pGo->GetEntry())
    {
        case GO_CAPTAIN_CHEST_HORDE:
        case GO_CAPTAIN_CHEST_HORDE_H:
        case GO_CAPTAIN_CHEST_ALY:
        case GO_CAPTAIN_CHEST_ALY_H:
            m_uiCaptainsChestGUID = pGo->GetGUID();
            break;
        case GO_ICECROWN_DOOR:
            m_uiIcecrownDoorGUID = pGo->GetGUID(); 
            break;
        case GO_IMPENETRABLE_DOOR:
            m_uiImpenetrableDoorGUID = pGo->GetGUID();
            if(m_auiEncounter[3] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_FROSTMOURNE:
            m_uiFrostmourneGUID = pGo->GetGUID();
            break;
        case GO_FROSTMOURNE_ALTAR:
            m_uiFrostmourneAltarGUID = pGo->GetGUID();
            break;
        case GO_SHADOW_THRONE_DOOR:
            m_uiShadowThroneDoorGUID = pGo->GetGUID();
            if(m_auiEncounter[4] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_SHADOW_THROME_DOOR_EXIT:
            m_uiShadowThroneExitDoorGUID = pGo->GetGUID();
            if(m_auiEncounter[5] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
    }
}

void instance_halls_of_reflection::SetData(uint32 uiType, uint32 uiData)
{
    switch(uiType)
    {
        case TYPE_INTRO:
            m_auiEncounter[0] = uiData;
            break;
        case TYPE_SPIRIT_EVENT:
            m_auiEncounter[1] = uiData;
            break;
        case TYPE_FALRIC:
            m_auiEncounter[2] = uiData;
            if (uiData != IN_PROGRESS)
                DoUseDoorOrButton(m_uiIcecrownDoorGUID);
            break;
        case TYPE_MARWYN:
            m_auiEncounter[3] = uiData;
            if (uiData != IN_PROGRESS)
                DoUseDoorOrButton(m_uiIcecrownDoorGUID);
            else if (uiData == DONE)
            {
                DoUseDoorOrButton(m_uiImpenetrableDoorGUID);
                DoUseDoorOrButton(m_uiIcecrownDoorGUID);
            }
            break;
        case TYPE_GENERAL:
            m_auiEncounter[4] = uiData;
            if (uiData == DONE)
                DoUseDoorOrButton(m_uiShadowThroneDoorGUID);
            break;
        case TYPE_ESCAPE:
            m_auiEncounter[5] = uiData;
            if (uiData == DONE)
                DoRespawnGameObject(m_uiCaptainsChestGUID);
            break;
    }

    if (uiData == DONE)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
            << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4] << " "
            << m_auiEncounter[5];
        strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

uint32 instance_halls_of_reflection::GetData(uint32 uiType)
{
    switch(uiType)
    {
        case TYPE_INTRO:
            return m_auiEncounter[0];
        case TYPE_SPIRIT_EVENT:
            return m_auiEncounter[1];
        case TYPE_FALRIC:
            return m_auiEncounter[2];
        case TYPE_MARWYN:
            return m_auiEncounter[3];
        case TYPE_GENERAL:
            return m_auiEncounter[4];
        case TYPE_ESCAPE:
            return m_auiEncounter[5];
    }
    return 0;
}

uint64 instance_halls_of_reflection::GetData64(uint32 uiData)
{
    switch(uiData)
    {
        case NPC_FALRIC:                    return m_uiFalrynGUID;
        case NPC_MARWYN:                    return m_uiMarwynGUID;
        case NPC_LICH_KING:                 return m_uiLichKingGUID;
        case NPC_JAINA_END:                 return m_uiJainaGUID;
        case NPC_SYLVANAS_END:              return m_uiSylvanasGUID;
        case NPC_JAINA_START:               return m_uiJainaIntroGUID;
        case NPC_SYLVANAS_START:            return m_uiSylvanasIntroGUID;
        case GO_ICECROWN_DOOR:              return m_uiIcecrownDoorGUID;
        case GO_SHADOW_THROME_DOOR_EXIT:    return m_uiShadowThroneExitDoorGUID;
        case GO_FROSTMOURNE:                return m_uiFrostmourneGUID;
        case GO_IMPENETRABLE_DOOR:          return m_uiImpenetrableDoorGUID;
        case GO_FROSTMOURNE_ALTAR:          return m_uiFrostmourneAltarGUID;
    }
    return 0;
}

void instance_halls_of_reflection::Load(const char* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    std::istringstream loadStream(chrIn);
    loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >>
        m_auiEncounter[2] >> m_auiEncounter[3] >> m_auiEncounter[4] >>
        m_auiEncounter[5];

    for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
    {
        if (m_auiEncounter[i] != DONE)
            m_auiEncounter[i] = NOT_STARTED;
    }

    OUT_LOAD_INST_DATA_COMPLETE;
}

InstanceData* GetInstanceData_instance_halls_of_reflection(Map* pMap)
{
    return new instance_halls_of_reflection(pMap);
}

void AddSC_instance_halls_of_reflection()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_halls_of_reflection";
    pNewScript->GetInstanceData = &GetInstanceData_instance_halls_of_reflection;
    pNewScript->RegisterSelf();
}
