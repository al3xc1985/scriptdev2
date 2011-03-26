/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_RUBY_SANCTUM_H
#define DEF_RUBY_SANCTUM_H

enum
{
    MAX_ENCOUNTER                  = 4,

    TYPE_SAVIANA                   = 0,
    TYPE_BALTHARUS                 = 1,
    TYPE_ZARITHRIAN                = 2,
    TYPE_HALION                    = 3,

    NPC_HALION_REAL                = 39863, // Halion Physical Realm NPC
    NPC_HALION_TWILIGHT            = 40142, // Halion Twilight Realm NPC
    NPC_HALION_CONTROLLER          = 40146, // Halion controller

    // minibosses
    NPC_SAVIANA                    = 39747,
    NPC_BALTHARUS                  = 39751,
    NPC_ZARITHRIAN                 = 39746,

    NPC_XERESTRASZA                = 40429, // friendly npc, used for some cinematic and quest

    // rotating shadow orbs
    // used in phase 2 and 3 for Halion
    // need more research
    NPC_SHADOW_PULSAR_N            = 40083, // spinning orb N spawn
    NPC_SHADOW_PULSAR_S            = 40100, // spinning orb S spawn
    NPC_ORB_CARRIER                = 40081, // vehicle which carries the 2 orbs
    NPC_ORB_ROTATION_FOCUS         = 40091, // vehicle which carries the 2 orbs and helps the spell casting

    // there are 3 portals in the final encounter
    // the first portal, is spawned at the end of phase one, and teleports all the players to the twilight realm with aura 74807
    // the 2nd and 3rd portals are spawned at the beginning of phase 3, and are used to teleport players from twilight to real world
    // this way all 3 portals are spawned in phase 3, and players can balance DPS in order to proper handle corporeality
    GO_HALION_PORTAL1              = 202794, // real to twilight
    GO_HALION_PORTAL2              = 202795, // twilight to real
    GO_HALION_PORTAL3              = 202796, // twilight to real

    GO_FIRE_FIELD                  = 203005, // xerestrasza flame door
    GO_FLAME_WALLS                 = 203006, // zarithrian flame walls
    GO_FLAME_RING                  = 203007, // halion flame ring

    // world state to show corporeality in phase 3
    // needs more research
    UPDATE_STATE_UI_SHOW            = 5049,
    UPDATE_STATE_UI_COUNT           = 5050,
};

class MANGOS_DLL_DECL instance_ruby_sanctum : public ScriptedInstance
{
    public:
        instance_ruby_sanctum(Map* pMap);
        ~instance_ruby_sanctum() {}

        void Initialize();
        bool IsEncounterInProgress() const;

        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);
        uint64 GetData64(uint32 uiData);

        const char* Save() { return strInstData.c_str(); }
        void Load(const char* chrIn);

        void DoHandleZarithrianDoor();
        void DoSummonHalion(Unit* pSummoner);

    protected:
        std::string strInstData;
        uint32 m_auiEncounter[MAX_ENCOUNTER];

        uint64 m_uiHalionRealGUID;
        uint64 m_uiHalionTwilightGUID;
        uint64 m_uiXerestraszaGUID;

        uint64 m_uiFireFieldGUID;
        uint64 m_uiFlameWallsGUID;
        uint64 m_uiFlameRingGUID;

        uint64 m_uiPortal1GUID;
        uint64 m_uiPortal2GUID;
        uint64 m_uiPortal3GUID;
};

#endif
