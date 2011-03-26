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
SDName: instance_gundrak
SD%Complete: 80
SDComment: Not 100% tested
SDCategory: Oculus
EndScriptData */

#include "precompiled.h"
#include "oculus.h"

instance_oculus::instance_oculus(Map* pMap) : ScriptedInstance(pMap),
    m_uiDrakosGUID(0),
    m_uiVarosGUID(0),
    m_uiUromGUID(0),
    m_uiEregosGUID(0),
    m_uiEternosGUID(0),
    m_uiVerdisaGUID(0),
    m_uiBelgaristraszGUID(0),
    m_uiEregosCacheGUID(0)
{
    Initialize();
}

void instance_oculus::Initialize()
{
    memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
}

void instance_oculus::OnPlayerEnter(Player *pPlayer)
{
    // summon end bosses on reload
    DoSummonNextBossIfCan(true);

    // show world state if construct event is in progress
    if (GetData(TYPE_DRAKOS) == DONE && GetData(TYPE_VAROS) != DONE)
    {
        DoUpdateWorldState(WORLD_STATE_CON, 1);
        DoUpdateWorldState(WORLD_STATE_CON_COUNT, m_luiConstructsGUIDs.size());
    }
}

void instance_oculus::OnCreatureCreate(Creature* pCreature)
{
    switch(pCreature->GetEntry())
    {
        case NPC_DRAKOS:
            m_uiDrakosGUID = pCreature->GetGUID();
            break;
        case NPC_VAROS:
            m_uiVarosGUID = pCreature->GetGUID();
            break;
        case NPC_UROM:
            m_uiUromGUID = pCreature->GetGUID();
            break;
        case NPC_EREGOS:
            m_uiEregosGUID = pCreature->GetGUID();
            break;
        case NPC_ETERNOS:
            m_uiEternosGUID = pCreature->GetGUID();
            break;
        case NPC_VERDISA:
            m_uiVerdisaGUID = pCreature->GetGUID();
            break;
        case NPC_BELGARISTRASZ:
            m_uiBelgaristraszGUID = pCreature->GetGUID();
            break;
        case NPC_CONSTRUCT:
            m_luiConstructsGUIDs.push_back(pCreature->GetGUID());
            break;
    }
}

void instance_oculus::OnObjectCreate(GameObject* pGo)
{
    switch(pGo->GetEntry())
    {
        case GO_CACHE_EREGOS:
        case GO_CACHE_EREGOS_H:
            m_uiEregosCacheGUID = pGo->GetGUID();
            break;
        case GO_DRAGON_CAGE_DOOR:
            m_luiCageDoorGUIDs.push_back(pGo->GetGUID());
            if (m_auiEncounter[TYPE_DRAKOS] == DONE)
                pGo->SetGoState(GO_STATE_ACTIVE);
            break;
    }
}
void instance_oculus::Load(const char* chrIn)
{
    if (!chrIn)
    {
        OUT_LOAD_INST_DATA_FAIL;
        return;
    }

    OUT_LOAD_INST_DATA(chrIn);

    std::istringstream loadStream(chrIn);
    loadStream >> m_auiEncounter[TYPE_DRAKOS] >> m_auiEncounter[TYPE_VAROS] >> m_auiEncounter[TYPE_UROM] >> m_auiEncounter[TYPE_EREGOS];

    for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
    {
        if (m_auiEncounter[i] == IN_PROGRESS)
            m_auiEncounter[i] = NOT_STARTED;
    }

    OUT_LOAD_INST_DATA_COMPLETE;
}

void instance_oculus::SetData(uint32 uiType, uint32 uiData)
{
    switch(uiType)
    {
        case TYPE_DRAKOS:
            m_auiEncounter[TYPE_DRAKOS] = uiData;
            if (uiData == DONE)
            {
                // open cages
                DoOpenAllCages();

                // varos intro
                if (Creature* pVaros = instance->GetCreature(m_uiVarosGUID))
                    DoScriptText(SAY_VAROS_INTRO, pVaros);

                // update world state
                DoUpdateWorldState(WORLD_STATE_CON, 1);
                DoUpdateWorldState(WORLD_STATE_CON_COUNT, MAX_CONSTRUCTS);
            }
            break;
        case TYPE_VAROS:
            m_auiEncounter[TYPE_VAROS] = uiData;
            if (uiData == DONE)
            {
                // summon urom
                DoSummonNextBossIfCan();

                // update world state
                DoUpdateWorldState(WORLD_STATE_CON, 0);
            }
            break;
        case TYPE_UROM:
            m_auiEncounter[TYPE_UROM] = uiData;
            if (uiData == DONE)
                DoSummonNextBossIfCan();
            break;
        case TYPE_EREGOS:
            m_auiEncounter[TYPE_EREGOS] = uiData;
            if (uiData == DONE)
                DoRespawnGameObject(m_uiEregosCacheGUID);
            break;
    }

    if (uiData == DONE)
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << m_auiEncounter[TYPE_DRAKOS] << " " << m_auiEncounter[TYPE_VAROS] << " " << m_auiEncounter[TYPE_UROM] << " " << m_auiEncounter[TYPE_EREGOS];

        strInstData = saveStream.str();

        SaveToDB();
        OUT_SAVE_INST_DATA_COMPLETE;
    }
}

uint32 instance_oculus::GetData(uint32 uiType)
{
    switch(uiType)
    {
        case TYPE_DRAKOS:
            return m_auiEncounter[TYPE_DRAKOS];
        case TYPE_VAROS:
            return m_auiEncounter[TYPE_VAROS];
        case TYPE_UROM:
            return m_auiEncounter[TYPE_UROM];
        case TYPE_EREGOS:
            return m_auiEncounter[TYPE_EREGOS];
    }
    return 0;
}

void instance_oculus::DoOpenAllCages()
{
    // open all doors
    for(std::list<uint64>::const_iterator itr = m_luiCageDoorGUIDs.begin(); itr != m_luiCageDoorGUIDs.end(); ++itr)
        DoUseDoorOrButton(*itr);

    // get the prisoners out
    if(Creature* pEternos = instance->GetCreature(m_uiEternosGUID))
        pEternos->GetMotionMaster()->MovePoint(0, m_sPrisonersMoveLocs[0].m_fX, m_sPrisonersMoveLocs[0].m_fY, m_sPrisonersMoveLocs[0].m_fZ);

    if(Creature* pVerdisa = instance->GetCreature(m_uiVerdisaGUID))
        pVerdisa->GetMotionMaster()->MovePoint(0, m_sPrisonersMoveLocs[1].m_fX, m_sPrisonersMoveLocs[1].m_fY, m_sPrisonersMoveLocs[1].m_fZ);

    if(Creature* pBelgaristrasz = instance->GetCreature(m_uiBelgaristraszGUID))
        pBelgaristrasz->GetMotionMaster()->MovePoint(0, m_sPrisonersMoveLocs[2].m_fX, m_sPrisonersMoveLocs[2].m_fY, m_sPrisonersMoveLocs[2].m_fZ);
}

void instance_oculus::DoSummonNextBossIfCan(bool bByPlayerEnter)
{
    Player* pPlayer = GetPlayerInMap();
    if (!pPlayer)
        return;

    if (GetData(TYPE_UROM) == DONE)
    {
        // return if already summoned
        if (m_uiEregosGUID)
            return;

        if (bByPlayerEnter)
            pPlayer->SummonCreature(NPC_EREGOS, m_sOculusBossSpawnLocs[1].m_fX, m_sOculusBossSpawnLocs[1].m_fY, m_sOculusBossSpawnLocs[1].m_fZ, m_sOculusBossSpawnLocs[1].m_fO, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30*MINUTE*IN_MILLISECONDS);
        else
        {
            if (Creature* pEregos = pPlayer->SummonCreature(NPC_EREGOS, m_sOculusBossSpawnLocs[1].m_fX, m_sOculusBossSpawnLocs[1].m_fY, m_sOculusBossSpawnLocs[1].m_fZ, m_sOculusBossSpawnLocs[1].m_fO, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30*MINUTE*IN_MILLISECONDS))
                DoScriptText(SAY_EREGOS_SPAWN, pEregos);
        }
    }
    else if (GetData(TYPE_VAROS) == DONE)
    {
        // return if already summoned
        if (m_uiUromGUID)
            return;

        pPlayer->SummonCreature(NPC_UROM, m_sOculusBossSpawnLocs[0].m_fX, m_sOculusBossSpawnLocs[0].m_fY, m_sOculusBossSpawnLocs[0].m_fZ, m_sOculusBossSpawnLocs[0].m_fO, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30*MINUTE*IN_MILLISECONDS);
    }
}

void instance_oculus::OnCreatureEnterCombat(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_DRAKOS: SetData(TYPE_DRAKOS, IN_PROGRESS); break;
        case NPC_VAROS: SetData(TYPE_VAROS, IN_PROGRESS); break;
        case NPC_UROM: SetData(TYPE_UROM, IN_PROGRESS); break;
        case NPC_EREGOS: SetData(TYPE_EREGOS, IN_PROGRESS); break;
    }
}

void instance_oculus::OnCreatureEvade(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_DRAKOS: SetData(TYPE_DRAKOS, FAIL); break;
        case NPC_VAROS: SetData(TYPE_VAROS, FAIL); break;
        case NPC_UROM: SetData(TYPE_UROM, FAIL); break;
        case NPC_EREGOS: SetData(TYPE_EREGOS, FAIL); break;
    }
}

void instance_oculus::OnCreatureDeath(Creature* pCreature)
{
    switch (pCreature->GetEntry())
    {
        case NPC_DRAKOS: SetData(TYPE_DRAKOS, DONE); break;
        case NPC_VAROS: SetData(TYPE_VAROS, DONE); break;
        case NPC_UROM: SetData(TYPE_UROM, DONE); break;
        case NPC_EREGOS: SetData(TYPE_EREGOS, DONE); break;
        case NPC_CONSTRUCT:
            m_luiConstructsGUIDs.remove(pCreature->GetGUID());

            // update world state
            DoUpdateWorldState(WORLD_STATE_CON_COUNT, m_luiConstructsGUIDs.size());

            // check if event complete
            if (m_luiConstructsGUIDs.empty())
            {
                if (Creature* pVaros = instance->GetCreature(m_uiVarosGUID))
                    pVaros->RemoveAurasDueToSpell(SPELL_CENTRIFUGE_SHIELD);
            }
            break;
    }
}

InstanceData* GetInstanceData_instance_oculus(Map* pMap)
{
    return new instance_oculus(pMap);
}

void AddSC_instance_oculus()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_oculus";
    pNewScript->GetInstanceData = &GetInstanceData_instance_oculus;
    pNewScript->RegisterSelf();
}
