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
SDName: instance_ruby_sanctum
SD%Complete: 0
SDComment: Placeholder
SDCategory: Ruby Sanctum
EndScriptData */

#include "precompiled.h"
#include "ruby_sanctum.h"


instance_ruby_sanctum::instance_ruby_sanctum(Map* pMap) : ScriptedInstance(pMap),
    m_uiHalionRealGUID(0),
    m_uiHalionTwilightGUID(0),
    m_uiXerestraszaGUID(0),
    m_uiFireFieldGUID(0),
    m_uiFlameWallsGUID(0),
    m_uiFlameRingGUID(0),
    m_uiPortal1GUID(0),
    m_uiPortal2GUID(0),
    m_uiPortal3GUID(0)
{
    Initialize();
}

void instance_ruby_sanctum::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
}

bool instance_ruby_sanctum::IsEncounterInProgress() const
{
    for(uint8 i = 1; i < MAX_ENCOUNTER ; ++i)
    {
        if (m_auiEncounter[i] == IN_PROGRESS)
            return true;
    }
    return false;
}

void instance_ruby_sanctum::OnCreatureCreate(Creature* pCreature)
{
    switch(pCreature->GetEntry())
    {
        // when encounter[1] is done, open the door at the bottom of the giant tree
        // after door is opened, some cinematic begins with Xerestrasza, which gives a quest
        // finally, when all 3 minibosses are dead, she is used to summon Halion
        case NPC_XERESTRASZA:
            m_uiXerestraszaGUID = pCreature->GetGUID();
            if(m_auiEncounter[2] == DONE)
                DoSummonHalion(pCreature);
            break;
        case NPC_HALION_REAL:
            m_uiHalionRealGUID = pCreature->GetGUID();
            break;
        case NPC_HALION_TWILIGHT:
            m_uiHalionTwilightGUID = pCreature->GetGUID();
            break;
    }
}

void instance_ruby_sanctum::OnObjectCreate(GameObject* pGo)
{
    switch(pGo->GetEntry())
    {
        case GO_FLAME_WALLS:
            m_uiFlameWallsGUID = pGo->GetGUID();
            if(m_auiEncounter[0] == DONE && m_auiEncounter[1] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_FLAME_RING:
            m_uiFlameRingGUID = pGo->GetGUID();
            break;
        case GO_FIRE_FIELD:
            m_uiFireFieldGUID = pGo->GetGUID();
            if(m_auiEncounter[1] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
        case GO_HALION_PORTAL1:
            m_uiPortal1GUID = pGo->GetGUID();
            break;
        case GO_HALION_PORTAL2:
            m_uiPortal2GUID = pGo->GetGUID();
            break;
        case GO_HALION_PORTAL3:
            m_uiPortal3GUID = pGo->GetGUID();
            break;
    }
}

// void which checks if both Saviana and Balthaurus are done
// opens the door to the 3rd boss, Zarithrian
void instance_ruby_sanctum::DoHandleZarithrianDoor()
{
    if(m_auiEncounter[0] == DONE && m_auiEncounter[1] == DONE)
        DoUseDoorOrButton(m_uiFlameWallsGUID);
}

// void to summon the final boss Halion
// this can be summoned, only after General Zarithrian is dead
// there are two npcs to fitht
// one in the real world
// on in the twilight world, players will use aura 74807, in order to see him in phase 2 & 3
// there is also a npc used as a controller, needs more research in boss script
void instance_ruby_sanctum::DoSummonHalion(Unit* pSummoner)
{
    pSummoner->SummonCreature(NPC_HALION_REAL, 3155.19f, 538.71f, 72.88f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DAY);
    pSummoner->SummonCreature(NPC_HALION_TWILIGHT, 3155.19f, 538.71f, 72.88f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, DAY);
}

void instance_ruby_sanctum::SetData(uint32 uiType, uint32 uiData)
{
    switch(uiType)
    {
        case TYPE_SAVIANA:
            m_auiEncounter[0] = uiData;
            if(uiData == DONE)
                DoHandleZarithrianDoor();
            break;
        case TYPE_BALTHARUS:
            m_auiEncounter[1] = uiData;
            if(uiData == DONE)
            {
                DoHandleZarithrianDoor();
                // Open door to Xerestrasza
                DoUseDoorOrButton(m_uiFireFieldGUID);
            }
            break;
        case TYPE_ZARITHRIAN:
            m_auiEncounter[2] = uiData;
            DoUseDoorOrButton(m_uiFlameWallsGUID);
            if (uiData == DONE)
            {
                if(Creature* pXerestrasza = instance->GetCreature(m_uiXerestraszaGUID))
                    DoSummonHalion(pXerestrasza);
            }
            break;
        case TYPE_HALION:
            m_auiEncounter[3] = uiData;
            DoUseDoorOrButton(m_uiFlameRingGUID);
            break;
    }

    if (uiData == DONE)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " "
            << m_auiEncounter[3];

        strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

uint32 instance_ruby_sanctum::GetData(uint32 uiType)
{
    switch(uiType)
    {
    case TYPE_SAVIANA:
        return m_auiEncounter[0];
    case TYPE_BALTHARUS:
        return m_auiEncounter[1];
    case TYPE_ZARITHRIAN:
        return m_auiEncounter[2];
    case TYPE_HALION:
        return m_auiEncounter[3];
    }
    return 0;
}

uint64 instance_ruby_sanctum::GetData64(uint32 uiData)
{
    switch(uiData)
    {
    case NPC_HALION_REAL:
        return m_uiHalionRealGUID;
    case NPC_HALION_TWILIGHT:
        return m_uiHalionTwilightGUID;
    case NPC_XERESTRASZA:
        return m_uiXerestraszaGUID;
    case GO_HALION_PORTAL1:
        return m_uiPortal1GUID;
    case GO_HALION_PORTAL2:
        return m_uiPortal2GUID;
    case GO_HALION_PORTAL3:
        return m_uiPortal3GUID;
    }
    return 0;
}

void instance_ruby_sanctum::Load(const char* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    std::istringstream loadStream(chrIn);
    loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3];

    for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
    {
        if (m_auiEncounter[i] == IN_PROGRESS)
            m_auiEncounter[i] = NOT_STARTED;
    }

    OUT_LOAD_INST_DATA_COMPLETE;
}


InstanceData* GetInstanceData_instance_ruby_sanctum(Map* pMap)
{
    return new instance_ruby_sanctum(pMap);
}

void AddSC_instance_ruby_sanctum()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_ruby_sanctum";
    pNewScript->GetInstanceData = &GetInstanceData_instance_ruby_sanctum;
    pNewScript->RegisterSelf();
}
