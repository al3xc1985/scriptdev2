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
SDName: boss_marwyn
SD%Complete: 0%
SDComment:
SDCategory: Halls of Reflection
EndScriptData */

#include "precompiled.h"
#include "halls_of_reflection.h"

enum
{
    SAY_INTRO1                  = -1610109,
    SAY_INTRO2                  = -1610110,
    SAY_AGGRO                   = -1610111,
    SAY_CORRUPTED_FLESH1        = -1610112,
    SAY_CORRUPTED_FLESH2        = -1610113,
    SAY_SLAY1                   = -1610114,
    SAY_SLAY2                   = -1610115,
    SAY_DEATH                   = -1610116,

    SPELL_OBLITERATE            = 72360,
    SPELL_OBLITERATE_H          = 72434,
    SPELL_SHARED_SUFFERING      = 72368,
    SPELL_SHARED_SUFFERING_H    = 72369,
    SPELL_WELL_OF_CORRUPTION    = 72362,
    SPELL_CORRUPTED_FLESH       = 72363,
    SPELL_CORRUPTED_FLESH_H     = 72436,
};

struct MANGOS_DLL_DECL boss_marwynAI : public ScriptedAI
{
    boss_marwynAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_halls_of_reflection*)pCreature->GetInstanceData();
        m_bIsRegularMode = pCreature->GetMap()->IsRegularDifficulty();
        Reset();
    }

    instance_halls_of_reflection* m_pInstance;
    bool m_bIsRegularMode;

    uint32 m_uiSharedSufferingTimer;
    uint32 m_uiWellTimer;
    uint32 m_uiTouchTimer;
    uint32 m_uiFleshTimer;
    uint32 m_uiObliterateTimer;
    uint32 m_uiSummonTimer;
    uint32 m_uiExploitCheckTimer;

    uint8 m_uiSummonCount;
    bool m_bHasIntro;

    uint8 m_uiCalledSoldiers;
    uint8 m_uiDeadSoldiers;
    uint8 m_uiMaxMobs;
    bool m_bDelaySet;

    uint32 m_uiLocNo;
    std::list<uint64> m_lSoldiersGUIDList;
    bool m_bIsCall;

    void Reset()
    {
        m_uiExploitCheckTimer       = 1000;
        m_uiSharedSufferingTimer    = 4000;
        m_uiWellTimer               = 5000;
        m_uiTouchTimer              = 8000;
        m_uiFleshTimer              = 10000;
        m_uiObliterateTimer         = 1000;
        m_uiSummonCount             = 0;
        m_uiSummonTimer             = 60000;
        m_bHasIntro                 = false;

        m_uiCalledSoldiers          = 0;
        m_uiDeadSoldiers            = 0;
        m_uiMaxMobs                 = 4;
        m_bDelaySet                 = true;

        m_bIsCall                   = false;
        m_lSoldiersGUIDList.clear();

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    void JustReachedHome()
    {
        if (m_pInstance) 
        {
            m_pInstance->SetData(TYPE_MARWYN, NOT_STARTED);
            m_pInstance->DoUpdateWorldState(WORLD_STATE_WAVES, 0);
        }

        ResetEvent();
    }

    void ResetEvent()
    {
        uint32 TeamInInstance = 0;

        Map *map = m_creature->GetMap();
        if (map->IsDungeon())
        {
            Map::PlayerList const &PlayerList = map->GetPlayers();

            if (!PlayerList.isEmpty())
            {
                if (Player* pPlayer = PlayerList.begin()->getSource())
                    TeamInInstance = pPlayer->GetTeam();
            }
        }
        if(TeamInInstance == ALLIANCE)
        {
            if(Creature *pJaina = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(NPC_JAINA_START)))
            {
                pJaina->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                pJaina->SetVisibility(VISIBILITY_ON);
                pJaina->GetMap()->CreatureRelocation(pJaina, 5266.78f, 1953.42f, 707.697f, 0.740877f);
                pJaina->SendMonsterMove(5266.78f, 1953.42f, 707.697f, SPLINETYPE_NORMAL, pJaina->GetSplineFlags(), 1);
            }
        }
        else if(TeamInInstance == HORDE) 
        {
            if(Creature *pSylvanas = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(NPC_SYLVANAS_START)))
            {
                pSylvanas->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                pSylvanas->SetVisibility(VISIBILITY_ON);
                pSylvanas->GetMap()->CreatureRelocation(pSylvanas, 5266.78f, 1953.42f, 707.697f, 0.740877f);
                pSylvanas->SendMonsterMove(5266.78f, 1953.42f, 707.697f, SPLINETYPE_NORMAL, pSylvanas->GetSplineFlags(), 1);
            }
        }
        m_creature->ForcedDespawn();
    }

    void Summon()
    {
        uint32 m_uiSummonId;
        m_uiLocNo = 18;

        for(uint8 i = 0; i < 18; ++i)
        {
            switch(urand(0,3))
            {
            case 0:
                switch(urand(1, 3))
                {
                case 1: m_uiSummonId = NPC_SHADOWY_MERCENARY;   break;
                case 2: m_uiSummonId = NPC_SPECTRAL_FOOTMAN;    break;
                case 3: m_uiSummonId = NPC_GHOSTLY_PRIEST;      break;
                }
                break;
            case 1: 
                switch(urand(1, 3))
                {
                case 1: m_uiSummonId = NPC_TORTURED_RIFLEMAN;   break;
                case 2: m_uiSummonId = NPC_SPECTRAL_FOOTMAN;    break;
                case 3: m_uiSummonId = NPC_PHANTOM_MAGE;        break;
                }
                break;
            case 2: 
                switch(urand(1, 3))
                {
                case 1: m_uiSummonId = NPC_TORTURED_RIFLEMAN;       break;
                case 2: m_uiSummonId = NPC_SPECTRAL_FOOTMAN;        break;
                case 3: m_uiSummonId = NPC_GHOSTLY_PRIEST;          break;
                }
                break;
            case 3: 
                switch(urand(1, 3))
                {
                case 1: m_uiSummonId = NPC_SHADOWY_MERCENARY;       break;
                case 2: m_uiSummonId = NPC_TORTURED_RIFLEMAN;       break;
                case 3: m_uiSummonId = NPC_PHANTOM_MAGE;            break;
                }
                break;
            }

            if(Creature* pSummon = m_creature->SummonCreature(m_uiSummonId, m_aSpiritsSpawnLocs[m_uiLocNo].m_fX, m_aSpiritsSpawnLocs[m_uiLocNo].m_fY, m_aSpiritsSpawnLocs[m_uiLocNo].m_fZ, m_aSpiritsSpawnLocs[m_uiLocNo].m_fO, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000))
                m_lSoldiersGUIDList.push_back(pSummon->GetGUID());
            m_uiLocNo += 1;
        }
    }

    void CallFallSoldier()
    {
        for(uint8 i = 0; i < m_uiMaxMobs; ++i)
        {
            if(!m_lSoldiersGUIDList.empty())
            {
                std::list<uint64>::iterator iter = m_lSoldiersGUIDList.begin();

                if (Creature* pTemp = m_creature->GetMap()->GetCreature(*iter))
                {
                    if(pTemp->isAlive())
                    {
                        m_uiCalledSoldiers += 1;
                        pTemp->setFaction(14);
                        pTemp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pTemp->SetInCombatWithZone();
                        m_lSoldiersGUIDList.remove(*iter);
                    }
                }
            }
        }
    }

    void SummonedCreatureJustDied(Creature* pSummon)
    {
        m_uiDeadSoldiers += 1;
    }

    void AttackStart(Unit* pWho)
    {
        if (!m_pInstance)  
            return;

        if (m_pInstance->GetData(TYPE_MARWYN) != IN_PROGRESS)
            return;

        if (m_creature->Attack(pWho, true)) 
        {
            m_creature->AddThreat(pWho);
            m_creature->SetInCombatWith(pWho);
            pWho->SetInCombatWith(m_creature);
            DoStartMovement(pWho);
        }
    }

    void Aggro(Unit *who) 
    {
        DoScriptText(SAY_AGGRO, m_creature);
        if(m_pInstance) 
            m_pInstance->SetData(TYPE_MARWYN, IN_PROGRESS);
    }

    void KilledUnit(Unit *victim)
    {
        switch(urand(0, 1))
        {
        case 0: DoScriptText(SAY_SLAY1, m_creature); break;
        case 1: DoScriptText(SAY_SLAY2, m_creature); break;
        }
    }

    void JustDied(Unit *killer)
    {
        DoScriptText(SAY_DEATH, m_creature);
        if(m_pInstance) 
        {
            m_pInstance->SetData(TYPE_MARWYN, DONE);
            m_pInstance->DoUpdateWorldState(WORLD_STATE_WAVES, 0);
        }
    }

    bool IsPlayerInside()
    {
        Map *map = m_creature->GetMap();
        if (map->IsDungeon())
        {
            Map::PlayerList const &PlayerList = map->GetPlayers();

            if (PlayerList.isEmpty())
                return false;

            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            {
                if(GameObject* pAltar = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(GO_FROSTMOURNE_ALTAR)))
                {
                    if (i->getSource()->isAlive() && i->getSource()->GetDistance2d(pAltar) < 75.0f)
                        return true;
                }
            }
        } 

        return false;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (m_pInstance->GetData(TYPE_FALRIC) == SPECIAL) 
        {
            if(!m_bIsCall) 
            {
               m_bIsCall = true;
               Summon();
            }
        }

        if (m_pInstance->GetData(TYPE_MARWYN) == SPECIAL) 
        {
            // ToDo - move this to instance script
            if(m_uiExploitCheckTimer < uiDiff)
            {
                if(!IsPlayerInside())
                    EnterEvadeMode();
                m_uiExploitCheckTimer = 1000;
            }
            else m_uiExploitCheckTimer -= uiDiff;

            if(m_uiDeadSoldiers == m_uiCalledSoldiers && !m_bDelaySet && m_uiSummonCount < 5)
            {
                m_uiSummonTimer = 10000;
                m_bDelaySet = true;
            }

            if (m_uiSummonTimer < uiDiff)
            {
                if(!m_bHasIntro)
                {
                    DoScriptText(SAY_INTRO1, m_creature);
                    m_bHasIntro = true;
                }

                ++m_uiSummonCount;
                if (m_uiSummonCount > 4)
                {
                    if(m_pInstance)
                    {
                        m_pInstance->SetData(TYPE_MARWYN, IN_PROGRESS);
                        m_pInstance->DoUpdateWorldState(WORLD_STATE_WAVES_COUNT, m_uiSummonCount + 5);
                    }
                    m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    m_creature->SetInCombatWithZone();
                }
                else
                {
                    if(m_pInstance)
                        m_pInstance->DoUpdateWorldState(WORLD_STATE_WAVES_COUNT, m_uiSummonCount + 5);
                    // change the no. of mobs per wave
                    switch(m_uiSummonCount)
                    {
                    case 1:
                    case 2:
                        m_uiMaxMobs = 4;
                        break;
                    case 3:
                    case 4:
                        m_uiMaxMobs = 5;
                        break;
                    }
                    CallFallSoldier();
                }
                m_bDelaySet = false;
                m_uiSummonTimer = 90000;
            }
            else
                m_uiSummonTimer -= uiDiff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
        {
            if(m_pInstance && m_pInstance->GetData(TYPE_MARWYN) == IN_PROGRESS)
                EnterEvadeMode();
            return;
        }

        if (m_uiSharedSufferingTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                DoCast(pTarget, m_bIsRegularMode ? SPELL_SHARED_SUFFERING : SPELL_SHARED_SUFFERING_H);
            m_uiSharedSufferingTimer = 20000;
        }
        else
            m_uiSharedSufferingTimer -= uiDiff;

        if (m_uiWellTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                DoCast(pTarget, SPELL_WELL_OF_CORRUPTION);
            m_uiWellTimer = 30000;
        }
        else
            m_uiWellTimer -= uiDiff;

        if (m_uiFleshTimer < uiDiff)
        {
            switch(urand(0, 1))
            {
            case 0: DoScriptText(SAY_CORRUPTED_FLESH1, m_creature); break;
            case 1: DoScriptText(SAY_CORRUPTED_FLESH2, m_creature); break;
            }
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                DoCast(pTarget, m_bIsRegularMode ? SPELL_CORRUPTED_FLESH : SPELL_CORRUPTED_FLESH_H);
            m_uiFleshTimer = 10000;
        }
        else
            m_uiFleshTimer -= uiDiff;

        if (m_uiObliterateTimer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->getVictim(), m_bIsRegularMode ? SPELL_OBLITERATE : SPELL_OBLITERATE_H);
            m_uiObliterateTimer = urand(8000,12000);
        }
        else
            m_uiObliterateTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_marwyn(Creature* pCreature)
{
    return new boss_marwynAI(pCreature);
}

void AddSC_boss_marwyn()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_marwyn";
    pNewScript->GetAI = &GetAI_boss_marwyn;
    pNewScript->RegisterSelf();
}
