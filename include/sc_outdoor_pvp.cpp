/* Copyright (C) 2006 - 2011 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#include "precompiled.h"


void OutdoorPvP::DoUpdateWorldState(PlayerSet sPlayerSet, uint32 uiStateId, uint32 uiStateData)
{
    for(PlayerSet::const_iterator itr = sPlayerSet.begin(); itr != sPlayerSet.end(); ++itr)
    {
        if (Player* pPlayer = instance->GetPlayer(*itr))
            pPlayer->SendUpdateWorldState(uiStateId, uiStateData);
    }
}

Player* OutdoorPvP::GetPlayerInMap(PlayerSet sPlayerSet, bool bOnlyAlive /*=false*/, bool bCanBeGamemaster /*=true*/)
{
    for(PlayerSet::const_iterator itr = sPlayerSet.begin(); itr != sPlayerSet.end(); ++itr)
    {
        Player* pPlayer = instance->GetPlayer(*itr);
        if (pPlayer && (!bOnlyAlive || pPlayer->isAlive()) && (bCanBeGamemaster || !pPlayer->isGameMaster()))
            return pPlayer;
    }

    return NULL;
}

void OutdoorPvP::DoProcessTeamBuff(PlayerSet sPlayerSet, Team uiTeamId, uint32 uiSpellId, bool bRemove /*= false*/)
{
    for(PlayerSet::const_iterator itr = sPlayerSet.begin(); itr != sPlayerSet.end(); ++itr)
    {
        if (Player* pPlayer = instance->GetPlayer(*itr))
        {
            if (pPlayer->GetTeam() == uiTeamId)
            {
                if (!bRemove)
                    pPlayer->CastSpell(pPlayer, uiSpellId, true);
                else
                {
                    if (pPlayer->HasAura(uiSpellId))
                        pPlayer->RemoveAurasDueToSpell(uiSpellId);
                }
            }
        }
    }
}
