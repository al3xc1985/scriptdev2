/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_TRIAL_OF_THE_CRUSADER_H
#define DEF_TRIAL_OF_THE_CRUSADER_H

enum
{
    MAX_ENCOUNTER          = 6,
    MAX_WIPES              = 50,

    TYPE_NORTHREND_BEASTS  = 1,
    TYPE_JARAXXUS          = 2,
    TYPE_FACTION_CHAMPIONS = 3,
    TYPE_TWIN_VALKYR       = 4,
    TYPE_ANUBARAK          = 5,
    TYPE_WIPE_COUNTER      = 6,     // used to count the raid wipes
    TYPE_STAGE             = 7,     // stage event (store the remaining boss)
    // implement this in order to avoid the valkyrs
    // to cast their special spell in the same time
    TYPE_TWINS_CASTING     = 8,

    // event npcs
    // why so many of him?!?
    // my guess is that there are 4 of them for each faction: before beasts; before jaraxxus; before valkyrs; before anub
    NPC_BARRETT                 = 34816,    // 35035, 35766, 35770, 35771, 35909, 35895, 35910
    NPC_TIRION                  = 34996,
    NPC_TIRION_END              = 36095,    // used to teleport players outside
    NPC_WILFRED                 = 35458,    // used in the jaraxxus event
    NPC_GARROSH                 = 34995,    // used in the champions event
    NPC_VARIAN                  = 34990,
    NPC_LICH_KING               = 35877,    // used in the event after the valkyrs
    NPC_BEASTS_CONTROLLER       = 35014,    // use unk
    NPC_CHAMPIONS_CONTROLLER    = 34781,    // use unk
    NPC_VALKYR_CONTROLLER       = 34783,    // use unk


    // dummy, purpose not clear
    NPC_THRALL                  = 34994,
    NPC_JAINA                   = 34992,
    NPC_PORTAL                  = 19224,
    NPC_TRIGGER                 = 22517,

    // beasts and jaraxxus
    NPC_ICEHOWL                 = 34797,
    NPC_GORMOK                  = 34796,
    NPC_DREADSCALE              = 34799,
    NPC_ACIDMAW                 = 35144,
    NPC_JARAXXUS                = 34780,

    // champions aly
    NPC_DUSKBLADE               = 34461,    // dk
    NPC_GROVESONG               = 34460,    // druid balance
    NPC_VALESTRIDER             = 34469,    // druid resto
    NPC_MOONSTALKER             = 34467,    // hunter
    NPC_WHIZZLESTICK            = 34468,    // mage
    NPC_VALENAA                 = 34465,    // paly holy
    NPC_LIGHTBEARER             = 34471,    // paly retri
    NPC_FORGEMENDER             = 34466,    // priest disciple
    NPC_NIGHTFELL               = 34473,    // priest shadow
    NPC_SHADOWSTEP              = 34472,    // rogue
    NPC_SHAABAD                 = 34463,    // shamy ench
    NPC_SAAMUL                  = 34470,    // shamy resto
    NPC_GRIMDABBLER             = 34474,    // lock
    NPC_SHOCUUL                 = 34475,    // warr

    // champions horde
    NPC_SHADOWCLEAVE            = 34458,    // dk
    NPC_STORMHOOF               = 34451,    // druid balance
    NPC_MISTHOOF                = 34459,    // druid resto
    NPC_RUJKAH                  = 34448,    // hunter
    NPC_BLIGHTSLINGER           = 34449,    // mage
    NPC_SUNCALLER               = 34445,    // paly holy
    NPC_BRIGHTBLADE             = 34456,    // paly retri
    NPC_STERN                   = 34447,    // priest disciple
    NPC_BLACKWHISPER            = 34441,    // priest shadow
    NPC_MAZDINAH                = 34454,    // rogue
    NPC_STOUTHORM               = 34455,    // shamy ench
    NPC_THRAKGAR                = 34444,    // shamy resto
    NPC_HARKZOG                 = 34450,    // lock
    NPC_STEELBREAKER            = 34453,    // warr

    // pets
    // to be moved in script
    NPC_CAT                     = 35610,
    NPC_ZHAAGRYM                = 35465,

    NPC_FJOLA                   = 34497,
    NPC_EYDIS                   = 34496,

    // portals
    NPC_DARK_ESSENCE            = 34567,
    NPC_LIGHT_ESSENCE           = 34568,

    NPC_ANUBARAK                = 34564,

    // objects
    // crusaders chest
    GO_CRUSADERS_CACHE_10       = 195631,
    GO_CRUSADERS_CACHE_25       = 195632,
    GO_CRUSADERS_CACHE_10_H     = 195633,
    GO_CRUSADERS_CACHE_25_H     = 195635,

    // grand crusader chest
    GO_TRIBUTE_CHEST_10H_25     = 195665,   // 1-25
    GO_TRIBUTE_CHEST_10H_45     = 195666,   // 25-44
    GO_TRIBUTE_CHEST_10H_50     = 195667,   // 45-49
    GO_TRIBUTE_CHEST_10H_99     = 195668,   // no wipe

    GO_TRIBUTE_CHEST_25H_25     = 195669,
    GO_TRIBUTE_CHEST_25H_45     = 195670,
    GO_TRIBUTE_CHEST_25H_50     = 195671,
    GO_TRIBUTE_CHEST_25H_99     = 195672,

    // doors
    GO_MAIN_GATE                = 195647,
    GO_WEST_GATE                = 195589,
    GO_SOUTH_GATE               = 195590,
    GO_NORTH_GATE               = 195591,
    GO_COLISEUM_FLOOR           = 195527,
    GO_WEB_DOOR                 = 195485,

    DESPAWN_TIME                = 30*MINUTE*IN_MILLISECONDS,

    // data
    // 6 on 10 man - 10 on 25 man
    DATA_CRUSADER_1             = 31,
    DATA_CRUSADER_2             = 32,
    DATA_CRUSADER_3             = 33,
    DATA_CRUSADER_4             = 34,
    DATA_CRUSADER_5             = 35,
    DATA_CRUSADER_6             = 36,
    DATA_CRUSADER_7             = 37,
    DATA_CRUSADER_8             = 38,
    DATA_CRUSADER_9             = 39,
    DATA_CRUSADER_10            = 40,

    // world states
    WORLD_STATE_WIPES_SHOW      = 4390,
    WORLD_STATE_WIPES_COUNT     = 4389,
};

struct ColiseumLocations
{
    float m_fX, m_fY, m_fZ;
    uint32 id;
};

// need some tunnings
static ColiseumLocations ArenaSpawnLoc[]=
{
    {559.257996f, 90.266197f, 395.122986f},  // 0 Barrent
    {563.672974f, 139.571f, 393.837006f},    // 1 Center
    {563.833008f, 187.244995f, 394.5f},      // 2 Backdoor
    {577.347839f, 195.338888f, 395.14f},     // 3 - Right
    {550.955933f, 195.338888f, 395.14f},     // 4 - Left
    {575.042358f, 195.260727f, 395.137146f}, // 5 - Champions locations
    {552.248901f, 195.331955f, 395.132658f}, // 6
    {573.342285f, 195.515823f, 395.135956f}, // 7
    {554.239929f, 195.825577f, 395.137909f}, // 8
    {571.042358f, 195.260727f, 395.137146f}, // 9
    {556.720581f, 195.015472f, 395.132658f}, // 10
    {569.534119f, 195.214478f, 395.139526f}, // 11
    {569.231201f, 195.941071f, 395.139526f}, // 12
    {558.811610f, 195.985779f, 394.671661f}, // 13
    {567.641724f, 195.351501f, 394.659943f}, // 14
    {560.633972f, 195.391708f, 395.137543f}, // 15
    {565.816956f, 195.477921f, 395.136810f}, // 16
    {563.549f, 152.474f, 394.393f},          // 17 - Lich king start
    {563.547f, 141.613f, 393.908f},          // 18 - Lich king end
    {787.932556f, 133.28978f, 142.612152f},  // 19 - Anub'arak start location
    {618.157898f, 132.640869f, 139.559769f}, // 20 - Anub'arak move point location
    {508.104767f, 138.247345f, 395.128052f}, // 21 - Fizzlebang start location
    {586.060242f, 117.514809f, 394.314026f}, // 22 - Dark essence 1
    {541.602112f, 161.879837f, 394.587952f}, // 23 - Dark essence 2
    {541.021118f, 117.262932f, 395.314819f}, // 24 - Light essence 1
    {586.200562f, 162.145523f, 394.626129f}, // 25 - Light essence 2
    {563.833008f, 195.244995f, 394.585561f}, // 26 - outdoor
    {548.610596f, 139.807800f, 394.321838f}, // 27 - fizzlebang end
    {564.161133f, 230.246307f, 394.661560f}, // 28 - outside the door
};

class MANGOS_DLL_DECL instance_trial_of_the_crusader : public ScriptedInstance
{
    public:
        instance_trial_of_the_crusader(Map* pMap);
        ~instance_trial_of_the_crusader() {}

        void Initialize();
        bool IsEncounterInProgress() const;

        void OnCreatureCreate(Creature* pCreature);
        void OnPlayerEnter(Player* pPlayer);
        void OnObjectCreate(GameObject* pGo);

        void SetData(uint32 uiType, uint32 uiData);
        void SetData64(uint32 uiType, uint64 uiData);
        uint32 GetData(uint32 uiType);
        uint64 GetData64(uint32 uiType);

        const char* Save() { return strInstData.c_str(); }
        void Load(const char* chrIn);

    protected:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string strInstData;

        uint32 m_uiGormokGUID;
        uint32 m_uiAcidmawGUID;
        uint32 m_uiDreadscaleGUID;
        uint32 m_uiIcehowlGUID;
        uint32 m_uiJaraxxusGUID;
        uint32 m_uiFjolaGUID;
        uint32 m_uiEydisGUID;
        uint32 m_uiAnubarakGUID;

        uint64 m_uiBarrettGUID;
        uint64 m_uiTirionGUID;
        uint64 m_uiFizzlebangGUID;
        uint64 m_uiGarroshGUID;
        uint64 m_uiVarianGUID;
        uint64 m_uiLichGUID;
        uint64 m_uiJainaGUID;
        uint64 m_uiThrallGUID;

        uint64 m_uiCrusader1GUID;
        uint64 m_uiCrusader2GUID;
        uint64 m_uiCrusader3GUID;
        uint64 m_uiCrusader4GUID;
        uint64 m_uiCrusader5GUID;
        uint64 m_uiCrusader6GUID;
        uint64 m_uiCrusader7GUID;
        uint64 m_uiCrusader8GUID;
        uint64 m_uiCrusader9GUID;
        uint64 m_uiCrusader10GUID;

        uint64 m_uiCrusadersCacheGUID;
        uint64 m_uiFloorGUID;

        uint64 m_uiTributeChest25GUID;
        uint64 m_uiTributeChest45GUID;
        uint64 m_uiTributeChest50GUID;
        uint64 m_uiTributeChest99GUID;

        uint64 m_uiMainGateDoorGUID;
        uint64 m_uiSouthDoorGUID;
        uint64 m_uiWestDoorGUID;
        uint64 m_uiNorthDoorGUID;
        uint64 m_uiWebDoorGUID;

        uint8 m_uiTwinsCasting;
        uint8 m_uiEventState;

        bool m_bNeedSave;
};

#endif
