/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_VAULT_OF_ARCHAVON_H
#define DEF_VAULT_OF_ARCHAVON_H

enum
{
    MAX_ENCOUNTER               = 4,

    TYPE_ARCHAVON               = 0,
    TYPE_EMALON                 = 1,
    TYPE_KORALON                = 2,
    TYPE_TORAVON                = 3,

    NPC_ARCHAVON                = 31125,
    NPC_EMALON                  = 33993,
    NPC_KORALON                 = 35013,
    NPC_TORAVON                 = 38433,
    NPC_TEMPEST_MINION          = 33998
};

class MANGOS_DLL_DECL instance_vault_of_archavon : public ScriptedInstance
{
    public:
        instance_vault_of_archavon(Map* pMap);
        ~instance_vault_of_archavon() {}

        void Initialize();
        bool IsEncounterInProgress() const;

        void OnCreatureCreate(Creature* pCreature);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);
        uint64 GetData64(uint32 uiData);

        const char* Save() { return strInstData.c_str(); }
        void Load(const char* chrIn);

        void HandleMinions(bool bIsDone);

    protected:
        std::string strInstData;
        uint32 m_auiEncounter[MAX_ENCOUNTER];

        uint64 m_uiEmalonGUID;
        std::list<uint64> m_luiMinionGUIDs;
};

#endif
