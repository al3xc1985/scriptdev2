/* Copyright (C) 2006 - 2011 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_ICECROWN_HALLS_H
#define DEF_ICECROWN_HALLS_H

enum
{
    MAX_ENCOUNTER               = 6,

    TYPE_INTRO                  = 0,
    TYPE_SPIRIT_EVENT           = 1,
    TYPE_FALRIC                 = 2,
    TYPE_MARWYN                 = 3,
    TYPE_GENERAL                = 4,
    TYPE_ESCAPE                 = 5,

    NPC_FALRIC                  = 38112,
    NPC_MARWYN                  = 38113,
    NPC_LICH_KING               = 37226,

    NPC_JAINA_START             = 37221,
    NPC_JAINA_END               = 36955,
    NPC_SYLVANAS_START          = 37223,
    NPC_SYLVANAS_END            = 37554,

    GO_ICECROWN_DOOR            = 201976,
    GO_IMPENETRABLE_DOOR        = 197341,
    GO_FROSTMOURNE_ALTAR        = 202236,
    GO_FROSTMOURNE              = 202302,

    GO_SHADOW_THRONE_DOOR       = 197342,
    GO_SHADOW_THROME_DOOR_EXIT  = 197343,

    GO_ICE_WALL                 = 201385,
    GO_CAVE_IN                  = 201596,

    // these are the ships; not sure why there are 2 of each
    GO_SKY_BREAKER              = 201580,   // 201598
    GO_ORGRIMS_HAMMER           = 201581,   // 201599

    GO_CAPTAIN_CHEST_HORDE      = 202212,
    GO_CAPTAIN_CHEST_ALY        = 201710,
    GO_CAPTAIN_CHEST_HORDE_H    = 202337,
    GO_CAPTAIN_CHEST_ALY_H      = 202336,

    NPC_SPECTRAL_FOOTMAN        = 38173,
    NPC_SHADOWY_MERCENARY       = 38177,    // only 1 per wave
    NPC_PHANTOM_HALLUCINATION   = 38567,    // not on grid, summoned by mage
    NPC_PHANTOM_MAGE            = 38172,    // only 1 per wave
    NPC_GHOSTLY_PRIEST          = 38175,
    NPC_TORTURED_RIFLEMAN       = 38176,

    NPC_RAGING_GHOUL            = 36940,
    NPC_RISEN_WHITCH_DOCTOR     = 36941,
    NPC_LUMBERING_ABONIMATION   = 37069,

    WORLD_STATE_WAVES           = 4884,
    WORLD_STATE_WAVES_COUNT     = 4882,
};

struct sSpawnLocation
{
    float m_fX, m_fY, m_fZ, m_fO;
};

static sSpawnLocation m_aSpiritsSpawnLocs[]=
{
    {5313.3f,  1977.29f, 707.695f, 1.713f},
    {5301.35f, 1973.57f, 707.695f, 1.364f},
    {5338.87f, 1991.67f, 707.695f, 2.718f},
    {5341.95f, 1999.47f, 707.695f, 3.076f},
    {5312.76f, 2037.05f, 707.696f, 4.470f},
    {5298.75f, 2033.85f, 707.696f, 5.118f},
    {5281.8f,  2016.06f, 707.696f, 5.974f},
    {5276.48f, 1995.26f, 707.696f, 0.272f},
    {5320.44f, 1980.01f, 707.695f, 1.878f},
    {5293.43f, 1975.91f, 707.695f, 0.998f},
    {5339.06f, 2004.27f, 707.695f, 3.021f},
    {5318.5f,  2035.36f, 707.696f, 4.446f},
    {5280.03f, 2000.79f, 707.696f, 0.248f},
    {5280.14f, 1989.21f, 707.696f, 0.578f},
    {5309.83f, 1971.77f, 707.695f, 1.607f},
    {5338.58f, 2010.99f, 707.695f, 3.347f},
    {5306.13f, 2035.99f, 707.696f, 4.823f},
    {5293.49f, 2035.1f,  707.696f, 5.279f},
    {5279.73f, 2021.09f, 707.696f, 5.617f},
    {5280.1f,  2008.85f, 707.696f, 6.159f},
    {5298.49f, 1978.18f, 707.695f, 1.187f},
    {5342.10f, 2016.14f, 707.695f, 3.380f},
    {5309.06f, 2041.29f, 707.696f, 4.713f},
    {5281.38f, 1994.45f, 707.696f, 0.343f},
    {5305.88f, 1976.52f, 707.695f, 1.391f},
    {5336.48f, 1996.89f, 707.695f, 2.762f},
    {5336.75f, 2018.03f, 707.696f, 3.469f},
    {5325.29f, 2036.8f,  707.696f, 4.105f},
    {5301.08f, 2038.36f, 707.696f, 5.079f},
    {5277.07f, 2013.37f, 707.696f, 6.056f},
    {5325.33f, 1976.61f, 707.695f, 1.894f},
    {5318.86f, 1974.06f, 707.695f, 1.941f},
    {5343.66f, 2007.9f,  707.695f, 3.233f},
    {5338.7f,  2023.72f, 707.696f, 3.673f},
    {5316.15f, 2039.87f, 707.696f, 4.611f},
    {5274.96f, 2005.16f, 707.696f, 0.001f},
};

class MANGOS_DLL_DECL instance_halls_of_reflection : public ScriptedInstance
{
    public:
        instance_halls_of_reflection(Map* pMap);
        ~instance_halls_of_reflection() {}

        void Initialize();

        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);
        uint64 GetData64(uint32 uiData);

        const char* Save() { return strInstData.c_str(); }
        void Load(const char* chrIn);

    protected:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string strInstData;

        // Creature GUIDs
        uint64 m_uiFalrynGUID;
        uint64 m_uiMarwynGUID;
        uint64 m_uiLichKingGUID;
        uint64 m_uiJainaGUID;
        uint64 m_uiSylvanasGUID;
        uint64 m_uiJainaIntroGUID;
        uint64 m_uiSylvanasIntroGUID;

        // GameObject GUIDs
        uint64 m_uiCaptainsChestGUID;
        uint64 m_uiIcecrownDoorGUID;
        uint64 m_uiImpenetrableDoorGUID;
        uint64 m_uiFrostmourneGUID;
        uint64 m_uiFrostmourneAltarGUID;
        uint64 m_uiShadowThroneDoorGUID;
        uint64 m_uiShadowThroneExitDoorGUID;
};

#endif