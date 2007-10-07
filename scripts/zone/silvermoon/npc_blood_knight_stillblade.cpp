/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "../../sc_defines.h"
#include "../../../../../game/Player.h"

// **** This script is still under Developement ****

#define SAY_HEAL "Thank you, dear Paladin, you just saved my life."

struct MANGOS_DLL_DECL npc_blood_knight_stillbladeAI : public ScriptedAI
{
    uint32 lifeTimer;
    bool spellHit;

    npc_blood_knight_stillbladeAI(Creature *c) : ScriptedAI(c) {EnterEvadeMode();}

    void EnterEvadeMode()
    {
        lifeTimer = 120000;
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        DoGoHome();
        m_creature->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 32);
        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1,7); // lay down
        spellHit = false;
	}

    void AttackStart(Unit *who)
    {
        return; //ignore all attackstart commands
    }

    void MoveInLineOfSight(Unit *who)
    {
        return;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->GetUInt32Value(UNIT_FIELD_BYTES_1))
        {
            if(lifeTimer < diff)
                m_creature->AI()->EnterEvadeMode();
            else 
                lifeTimer -= diff;
		}
	}

    void SpellHit(Unit *Hitter, const SpellEntry *Spellkind)
    {
        if(Spellkind->Id == 31225 && !spellHit)
        {
            DoCast(m_creature,32343);
            m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1,0);
            m_creature->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
            m_creature->RemoveAllAuras();
            DoSay(SAY_HEAL,LANG_COMMON,NULL);
            spellHit = true;
		}
	}

};

CreatureAI* GetAInpc_blood_knight_stillblade(Creature *_Creature)
{
    return new npc_blood_knight_stillbladeAI (_Creature);
}

void AddSC_npc_blood_knight_stillblade()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="blood_knight_stillblade";
    newscript->GetAI = GetAInpc_blood_knight_stillblade;
    m_scripts[nrscripts++] = newscript;
}