/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_ULDUAR_H
#define DEF_ULDUAR_H

enum
{
    MAX_ENCOUNTER               = 15,
    HARD_MODE_ENCOUNTER         = 9,
    KEEPER_ENCOUNTER            = 4,
    TELEPORTER_ENCOUNTER        = 3,

    // Main boss types
    TYPE_LEVIATHAN              = 0,
    TYPE_IGNIS                  = 1,
    TYPE_RAZORSCALE             = 2,
    TYPE_XT002                  = 3,
    TYPE_ASSEMBLY               = 4,
    TYPE_KOLOGARN               = 5,
    TYPE_AURIAYA                = 6,
    TYPE_MIMIRON                = 7,
    TYPE_HODIR                  = 8,
    TYPE_THORIM                 = 9,
    TYPE_FREYA                  = 10,
    TYPE_VEZAX                  = 11,
    TYPE_YOGGSARON              = 12,
    TYPE_ALGALON                = 13,

    // Hard mode boss types
    // Used for hard mode bosses only
    TYPE_LEVIATHAN_HARD         = 14,
    TYPE_XT002_HARD             = 15,
    TYPE_ASSEMBLY_HARD          = 16,
    TYPE_MIMIRON_HARD           = 17,
    TYPE_HODIR_HARD             = 18,
    TYPE_THORIM_HARD            = 19,
    TYPE_FREYA_HARD             = 20,
    TYPE_VEZAX_HARD             = 21,
    TYPE_YOGGSARON_HARD         = 22,

    // Keeper types
    // Used to store the keepers which will be used at yogg
    TYPE_KEEPER_HODIR           = 23,
    TYPE_KEEPER_FREYA           = 24,
    TYPE_KEEPER_THORIM          = 25,
    TYPE_KEEPER_MIMIRON         = 26,

    // Teleporter types
    // Some teleporters aren't depending directly on a boss, so we use a distinct type for them (maybe use areatrigger?)
    TYPE_LEVIATHAN_TP           = 27,
    TYPE_XT002_TP               = 28,
    TYPE_MIMIRON_TP             = 29,

    TYPE_LEVIATHAN_EVENT        = 30,

    //other-> these won't be saved to db
    TYPE_RUNE_GIANT             = 39,
    TYPE_RUNIC_COLOSSUS         = 31,
    TYPE_LEVIATHAN_MK           = 32,
    TYPE_VX001                  = 33,
    TYPE_AERIAL_UNIT            = 34,
    TYPE_YOGG_BRAIN             = 35,
    TYPE_MIMIRON_PHASE          = 36,
    TYPE_YOGG_PHASE             = 37,
    TYPE_VISION_PHASE           = 38,

    TYPE_UNDYING_FAILED         = 16,                       // Achievements Undying and Immortal, needs to be saved to database

    MAX_SPECIAL_ACHIEV_CRITS    = 6,

    // naxx achievs - REMOVE!
    /*TYPE_ACHIEV_SAFETY_DANCE    = 0,
    TYPE_ACHIEV_KNOCK_YOU_OUT   = 1,
    TYPE_ACHIEV_HUNDRED_CLUB    = 2,
    TYPE_ACHIEV_SHOCKING        = 3,
    TYPE_ACHIEV_SPORE_LOSER     = 4,
    TYPE_ACHIEV_GET_ENOUGH      = 5,*/

    // The siege of ulduar
    NPC_LEVIATHAN               = 33113,
    NPC_IGNIS                   = 33118,
    NPC_RAZORSCALE              = 33186,
    NPC_COMMANDER               = 33210,
    NPC_XT002                   = 33293,

    // Leviathan preadds
    NPC_STEELFORGE_DEFENDER     = 33236,
    NPC_RUNEFORGED_SENTRY       = 34234,
    NPC_ULDUAR_COLOSSUS         = 33237,    // x > 280; y < 70

    // The antechamber of ulduar
    NPC_STEELBREAKER            = 32867,
    NPC_MOLGEIM                 = 32927,
    NPC_BRUNDIR                 = 32857,
    NPC_KOLOGARN                = 32930,
    NPC_RIGHT_ARM               = 32934,
    NPC_LEFT_ARM                = 32933,
    NPC_AURIAYA                 = 33515,
    NPC_SANCTUM_SENTRY          = 34014,
    NPC_FERAL_DEFENDER          = 34035,

    // The keepers of ulduar
    NPC_MIMIRON                 = 33350,
    NPC_LEVIATHAN_MK            = 33432,
    NPC_VX001                   = 33651,
    NPC_AERIAL_UNIT             = 33670,
    NPC_HODIR                   = 32845,
    NPC_THORIM                  = 32865,
    NPC_RUNIC_COLOSSUS          = 32872,
    NPC_RUNE_GIANT              = 32873,
    NPC_JORMUNGAR_BEHEMOTH      = 32882,
    NPC_FREYA                   = 32906,
    NPC_ELDER_BRIGHTLEAF        = 32915,
    NPC_ELDER_IRONBRACH         = 32913,
    NPC_ELDER_STONEBARK         = 32914,

    // The descent into madness
    NPC_VEZAX                   = 33271,
    NPC_SARONITE_ANIMUS         = 33524,
    NPC_YOGGSARON               = 33288,
    NPC_SARA                    = 33134,
    NPC_YOGG_BRAIN              = 33890,

    // Celestial planetarium
    NPC_ALGALON                 = 32871,

    // Keepers images
    // They spawn in the central room after they are released from Yogg's enslavement
    // You may talk to them and ask them to help you fight Yogg-Saron
    NPC_THORIM_IMAGE            = 33413,
    NPC_MIMIRON_IMAGE           = 33412,
    NPC_HODIR_IMAGE             = 33411,
    NPC_FREYA_IMAGE             = 33410,

    // Keepers used to fight Yogg-Saron
    NPC_KEEPER_FREYA            = 33241,
    NPC_KEEPER_HODIR            = 33213,
    NPC_KEEPER_MIMIRON          = 33244,
    NPC_KEEPER_THORIM           = 33242,

    // Loot chests
    // Kologarn
    GO_CACHE_OF_LIVING_STONE    = 195046,
    GO_CACHE_OF_LIVING_STONE_H  = 195047,

    // Hodir
    GO_CACHE_OF_WINTER          = 194307,
    GO_CACHE_OF_WINTER_H        = 194308,
    GO_CACHE_OF_RARE_WINTER     = 194200,
    GO_CACHE_OF_RARE_WINTER_H   = 194201,

    // Mimiron
    GO_CACHE_OF_INOV            = 194789,
    GO_CACHE_OF_INOV_H          = 194956,
    GO_CACHE_OF_INOV_HARD       = 194957,
    GO_CACHE_OF_INOV_HARD_H     = 194958,

    // Thorim
    GO_CACHE_OF_STORMS          = 194312,
    GO_CACHE_OF_STORMS_H        = 194314,
    GO_CACHE_OF_RARE_STORMS     = 194313,
    GO_CACHE_OF_RARE_STORMS_H   = 194315,

    // Alagon
    GO_GIFT_OF_OBSERVER_H       = 194821,
    GO_GIFT_OF_OBSERVER         = 194822,
    GO_GIFT_OF_OBSERVER_HH      = 194823,                   // Purpose Unknown

    // Doors and other Objects
    // The siege
    GO_SHIELD_WALL              = 194416,                   // Gate before Leviathan
    GO_LIGHTNING_DOOR           = 194905,                   // Gate after Leviathan
    GO_LEVIATHAN_GATE           = 194630,                   // Gate before Leviathan event -> this should be used before the boss enter the arena
    GO_XT002_GATE               = 194631,                   // Gate before Xt002
    GO_BROKEN_HARPOON           = 194565,                   // Broken harpoon from Razorscale

    // Antechamber
    GO_KOLOGARN_BRIDGE          = 194232,
    GO_SHATTERED_DOOR           = 194553,                   // Door before kologarn
    GO_IRON_ENTRANCE_DOOR       = 194554,                   // Door before iron council
    GO_ARCHIVUM_DOOR            = 194556,                   // Entrance door to the archivum
    GO_ARCHIVUM_CONSOLE         = 194555,                   // Used at some sort of cinematic
    GO_UNIVERSE_FLOOR_ARCHIVUM  = 194715,                   // Used for animation

    // Planetarium
    GO_CELESTIAL_ACCES          = 194628,                   // Acces console for 10 man mode
    GO_CELESTIAL_ACCES_H        = 194752,                   // Acces console for 25 man mode
    GO_CELESTIAL_DOOR           = 194767,                   // Entrance door to the planetarium
    GO_UNIVERSE_FLOOR_CELESTIAL = 194716,                   // For animation
    GO_AZEROTH_GLOBE            = 194148,                   // For animation

    // The keepers
    // Hodir
    GO_HODIR_EXIT               = 194634,
    GO_HODIR_ICE_WALL           = 194441,
    GO_HODIR_ENTER              = 194442,
    // Mimiron
    G0_MIMIRON_BUTTON           = 194739,                   // Used to start hard mode
    GO_MIMIRON_DOOR_1           = 194774,
    GO_MIMIRON_DOOR_2           = 194775,
    GO_MIMIRON_DOOR_3           = 194776,
    GO_MIMIRON_TEL1             = 194741,                   // Used to summon mobs in phase 3
    GO_MIMIRON_TEL2             = 194742,
    GO_MIMIRON_TEL3             = 194743,
    GO_MIMIRON_TEL4             = 194744,
    GO_MIMIRON_TEL5             = 194740,
    GO_MIMIRON_TEL6             = 194746,
    GO_MIMIRON_TEL7             = 194747,
    GO_MIMIRON_TEL8             = 194748,
    GO_MIMIRON_TEL9             = 194745,
    GO_MIMIRON_ELEVATOR         = 194749,                   // Central elevator
    // Thorim
    GO_DARK_IRON_PORTCULIS      = 194560,                   // Door from the arena to the hallway
    GO_RUNED_STONE_DOOR         = 194557,                   // Door after the runic colossus
    GO_THORIM_STONE_DOOR        = 194558,                   // Door after the ancient rune giant
    GO_LIGHTNING_FIELD          = 194559,                   // Thorim combat door
    GO_DOOR_LEVER               = 194264,                   // In front of the door

    // Descent to madness
    GO_ANCIENT_GATE             = 194255,                   // Door upstairs before vezax, opens when all keepers are freed
    GO_VEZAX_GATE               = 194750,                   // Door after vezax
    GO_YOGG_GATE                = 194773,                   // Yogg-Saron chamber door
    GO_BRAIN_DOOR1              = 194635,                   // Brain chamber doors
    GO_BRAIN_DOOR2              = 194636,
    GO_BRAIN_DOOR3              = 194637,

    // World state used for algalon timer
    WORLD_STATE_TIMER           = 4132,
    WORLD_STATE_TIMER_COUNT     = 4131,

    // Achiev criterias
    // Siege of Ulduar
    // Leviathan
    ACHIEV_CRIT_UNBROKEN_N      = 10044,                    // Flame Leviathan, achievs 2905, 2906
    ACHIEV_CRIT_UNBROKEN_H      = 10045,
    ACHIEV_CRIT_CAR_GARAGE_N_1  = 10046,                    // Flame Leviathan, achievs 2907, 2908
    ACHIEV_CRIT_CAR_GARAGE_N_2  = 10047,
    ACHIEV_CRIT_CAR_GARAGE_N_3  = 10048,
    ACHIEV_CRIT_CAR_GARAGE_H_1  = 10049,
    ACHIEV_CRIT_CAR_GARAGE_H_2  = 10050,
    ACHIEV_CRIT_CAR_GARAGE_H_3  = 10051,
    ACHIEV_CRIT_SHUTOUT_N       = 10054,                    // Flame Leviathan, achievs 2911, 2912
    ACHIEV_CRIT_SHUTOUT_H       = 10055,
    ACHIEV_CRIT_BOMBARDMENT_N   = 10056,                    // Flame Leviathan, achievs 2913, 2918
    ACHIEV_CRIT_BOMBARDMENT_H   = 10061,
    ACHIEV_CRIT_DEVASTATION_N   = 10057,                    // Flame Leviathan, achievs 2914, 2916
    ACHIEV_CRIT_DEVASTATION_H   = 10059,
    ACHIEV_CRIT_NUKED_ORBIT_N   = 10058,                    // Flame Leviathan, achievs 2915, 2917
    ACHIEV_CRIT_NUKED_ORBIT_H   = 10060,
    ACHIEV_CRIT_ORBIT_UARY_N    = 10218,                    // Flame Leviathan, achievs 3056, 3057
    ACHIEV_CRIT_ORBIT_UARY_H    = 10219,
    // Ignis
    ACHIEV_CRIT_SHATTERED_N     = 10068,                    // Ignis, achievs 2925, 2926
    ACHIEV_CRIT_SHATTERED_H     = 10069,
    ACHIEV_CRIT_STOKIN_N        = 10073,                    // Ignis, achievs 2930, 2929
    ACHIEV_CRIT_STOKIN_H        = 10072,
    // Razorscale
    ACHIEV_CRIT_QUICK_SHAVE_N   = 10062,                    // Razorscale, achievs 2919, 2921
    ACHIEV_CRIT_QUICK_SHAVE_H   = 10063,
    ACHIEV_CRIT_MEDIUM_RARE_N   = 10066,                    // Razorscale, achievs 2923, 2924
    ACHIEV_CRIT_MEDIUM_RARE_H   = 10067,
    // XT 002
    ACHIEV_CRIT_ENGINEERING_N   = 10074,                    // Xt002, achievs 2931, 2932
    ACHIEV_CRIT_ENGINEERING_H   = 10075,
    ACHIEV_CRIT_GRAVITY_BOMBS_N = 10077,                    // Xt002, achievs 2934, 2936
    ACHIEV_CRIT_GRAVITY_BOMBS_H = 10079,
    ACHIEV_CRIT_SCRAPBOTS_N     = 10401,                    // Xt002, achievs 2933, 2935
    ACHIEV_CRIT_SCRAPBOTS_H     = 10402,                    // spell 65037
    ACHIEV_CRIT_DECONSTRUCT_N   = 10080,                    // Xt002, achievs 2937, 2938
    ACHIEV_CRIT_DECONSTRUCT_H   = 10081,
    ACHIEV_CRIT_HEARTBREAKER_N  = 10221,                    // Xt002, achievs 3058, 3059
    ACHIEV_CRIT_HEARTBREAKER_H  = 10220,

    // Antechamber of Ulduar
    // Assembly of iron
    ACHIEV_ON_YOUR_SIDE         = 2945,
    ACHIEV_ON_YOUR_SIDE_H       = 2946,
    SPELL_IRON_BOOT_AURA        = 58501,
    /*ACHIEV_CHOOSE_BRUNDIR       = 2940,
    ACHIEV_CHOOSE_BRUNDIR_H     = 2943,
    ACHIEV_CHOOSE_MOLGEIM       = 2939,
    ACHIEV_CHOOSE_MOLGEIM_H     = 2942,
    ACHIEV_CHOOSE_STEELBREAKER  = 2941,
    ACHIEV_CHOOSE_STEELBREAKER_H= 2944,
    // Kologarn
    ACHIEV_RUBBLE_AND_ROLL      = 2959,
    ACHIEV_RUBBLE_AND_ROLL_H    = 2960,
    ACHIEV_WITH_OPEN_ARMS       = 2951,
    ACHIEV_WITH_OPEN_ARMS_H     = 2952,
    ACHIEV_DISARMED             = 2953,
    ACHIEV_DISARMED_H           = 2954,
    ACHIEV_IF_LOOKS_COULD_KILL  = 2955,
    ACHIEV_IF_LOOKS_COULD_KILL_H= 2956,*/
    // Auriaya
    ACHIEV_CRIT_CRAZY_CAT_N     = 10400,                    // Auriaya, achievs 3006, 3007
    ACHIEV_CRIT_CRAZY_CAT_H     = 10184,
    ACHIEV_CRIT_NINE_LIVES_N    = 10399,                    // Auriaya, achievs 3076, 3077
    ACHIEV_CRIT_NINE_LIVES_H    = 10243,

    // Keepers of Ulduar
    // Freya
    /*ACHIEV_BACK_TO_NATURE           = 2982,
    ACHIEV_BACK_TO_NATURE_H         = 2983,
    ACHIEV_KNOCK_WOOD               = 3177,
    ACHIEV_KNOCK_WOOD_H             = 3185,
    ACHIEV_KNOCK_KNOCK_WOOD         = 3178,
    ACHIEV_KNOCK_KNOCK_WOOD_H       = 3186,
    ACHIEV_KNOCK_KNOCK_KNOCK_WOOD   = 3179,
    ACHIEV_KNOCK_KNOCK_KNOCK_WOOD_H = 3187,
    // Hodir
    ACHIEV_RARE_CACHE       = 3182,
    ACHIEV_RARE_CACHE_H     = 3184,
    ACHIEV_COOLEST_FRIEND   = 2963,
    ACHIEV_COOLEST_FRIEND_H = 2965,
    ACHIEV_GETTING_COLD     = 2967,
    ACHIEV_GETTING_COLD_H   = 2968,
    ACHIEV_CHEESE_FREEZE    = 2961,
    ACHIEV_CHEESE_FREEZE_H  = 2962,*/
    // Thorim
    ACHIEV_CRIT_LOSE_ILLUSION_N = 10440,                    // Thorim, achievs 3176, 3183
    ACHIEV_CRIT_LOSE_ILLUSION_H = 10457,
    ACHIEV_CRIT_SIFFED_N        = 10289,                    // Thorim, achievs 2977, 2978
    ACHIEV_CRIT_SIFFED_H        = 10314,
    // Mimiron
    ACHIEV_CRIT_FIREFIGHTER_N   = 10450,                    // Mimiron, achievs 3180, 3189
    ACHIEV_CRIT_FIREFIGHTER_H   = 10463,

    // Descent into Madness
    // Vezax
    ACHIEV_CRIT_SARONITE_N      = 10451,                    // Vezax, achievs 3181, 3188
    ACHIEV_CRIT_SARONITE_H      = 10462,
    // Yogg
    /*ACHIEV_ALONE                = 3159,
    ACHIEV_ALONE_H              = 3164,
    ACHIEV_ONE_LIGHT            = 3158,
    ACHIEV_ONE_LIGHT_H          = 3163,
    ACHIEV_TWO_LIGHTS           = 3141,
    ACHIEV_TWO_LIGHTS_H         = 3162,
    ACHIEV_THREE_LIGHTS         = 3157,
    ACHIEV_THREE_LIGHTS_H       = 3161,
    ACHIEV_NOT_GETTING_OLDER    = 3012,
    ACHIEV_NOT_GETTING_OLDER_H  = 3013,

    // Celestial planetarium
    // Algalon
    ACHIEV_FEED_TEARS               = 3004,
    ACHIEV_FEED_TEARS_H             = 3005,     // nobody dies in the raid lockout
    ACHIEV_HERALD_OF_TITANS         = 3316,
    ACHIEV_OBSERVED                 = 3036,
    ACHIEV_OBSERVED_H               = 3037,
    ACHIEV_SUPERMASSIVE             = 3003,
    ACHIEV_SUPERMASSIVE_H           = 3002,*/

    // Achiev Champion / conquerer of Ulduar; 2903, 2904
    ACHIEV_CRIT_CHAMP_KOLO      = 10348,
    ACHIEV_CRIT_CHAMP_LEVIATHAN = 10042,
    ACHIEV_CRIT_CHAMP_IGNIS     = 10342,
    ACHIEV_CRIT_CHAMP_RAZOR     = 10340,
    ACHIEV_CRIT_CHAMP_VEZAX     = 10349,
    ACHIEV_CRIT_CHAMP_YOGG      = 10350,
    ACHIEV_CRIT_CHAMP_XT002     = 10341,
    ACHIEV_CRIT_CHAMP_MIMIRON   = 10347,
    ACHIEV_CRIT_CHAMP_AURIAYA   = 10351,
    ACHIEV_CRIT_CHAMP_COUNCIL   = 10598,            // spell = 65915
    ACHIEV_CRIT_CHAMP_HODIR     = 10439,            // spell = 64899
    ACHIEV_CRIT_CHAMP_THORIM    = 10403,            // spell = 64985
    ACHIEV_CRIT_CHAMP_FREYA     = 10582,            // spell = 65074

    ACHIEV_CRIT_CONQ_KOLO       = 10357,
    ACHIEV_CRIT_CONQ_LEVIATHAN  = 10352,
    ACHIEV_CRIT_CONQ_IGNIS      = 10355,
    ACHIEV_CRIT_CONQ_RAZOR      = 10353,
    ACHIEV_CRIT_CONQ_VEZAX      = 10362,
    ACHIEV_CRIT_CONQ_YOGG       = 10364,
    ACHIEV_CRIT_CONQ_XT002      = 10354,
    ACHIEV_CRIT_CONQ_MIMIRON    = 10361,
    ACHIEV_CRIT_CONQ_AURIAYA    = 10363,
    ACHIEV_CRIT_CONQ_COUNCIL    = 10599,            // spell = 65195
    ACHIEV_CRIT_CONQ_HODIR      = 10719,            // spell = 64899
    ACHIEV_CRIT_CONQ_THORIM     = 10404,            // spell = 64985
    ACHIEV_CRIT_CONQ_FREYA      = 10583,            // spell = 65074



    // Achievement related
    /* Naxx Achievs - REMOVE!
    ACHIEV_CRIT_SAFETY_DANCE_N  = 7264,                     // Heigan, achievs 1996, 2139
    ACHIEV_CRIT_SAFETY_DANCE_H  = 7548,
    ACHIEV_CRIT_KNOCK_YOU_OUT_N = 7265,                     // Faerlina, achievs 1997, 2140
    ACHIEV_CRIT_KNOCK_YOU_OUT_H = 7549,
    ACHIEV_CRIT_HUNDRED_CLUB_N  = 7567,                     // Sapphiron, achievs 2146, 2147
    ACHIEV_CRIT_HUNDRED_CLUB_H  = 7568,
    ACHIEV_CRIT_SHOCKING_N      = 7604,                     // Thaddius, achievs 2178, 2179
    ACHIEV_CRIT_SHOCKING_H      = 7605,
    ACHIEV_CRIT_SPORE_LOSER_N   = 7612,                     // Loatheb, achievs 2182, 2183
    ACHIEV_CRIT_SPORE_LOSER_H   = 7613,
    ACHIEV_CRIT_GET_ENOUGH_N    = 7614,                     // Kel'Thuzad, achievs 2184, 2185
    ACHIEV_CRIT_GET_ENOUGH_H    = 7615,

    // 'The Immortal'(25m) or 'Undying'(10m) - (achievs 2186, 2187)
    ACHIEV_CRIT_IMMORTAL_KEL    = 7616,
    ACHIEV_CRIT_IMMOORTAL_LOA   = 13236,
    ACHIEV_CRIT_IMMOORTAL_THAD  = 13235,
    ACHIEV_CRIT_IMMOORTAL_MAEX  = 13234,
    ACHIEV_CRIT_IMMOORTAL_HORSE = 13233,
    ACHIEV_CRIT_UNDYING_KEL     = 7617,
    ACHIEV_CRIT_UNDYING_HORSE   = 13237,
    ACHIEV_CRIT_UNDYING_MAEX    = 13238,
    ACHIEV_CRIT_UNDYING_LOA     = 13239,
    ACHIEV_CRIT_UNDYING_THAD    = 13240,*/
};

class MANGOS_DLL_DECL instance_ulduar : public ScriptedInstance
{
    public:
        instance_ulduar(Map* pMap);
        ~instance_ulduar() {}

        void Initialize();
        bool IsEncounterInProgress() const;

        void OnCreatureCreate(Creature* pCreature);
        void OnObjectCreate(GameObject* pGo);
        void OnCreatureEnterCombat(Creature* pCreature);
        void OnCreatureDeath(Creature* pCreature);
        void OnPlayerEnter(Player* pPlayer);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);
        uint64 GetData64(uint32 uiData);

        const char* Save() { return strInstData.c_str(); }
        void Load(const char* chrIn);

        bool CheckConditionCriteriaMeet(Player const* pSource, uint32 uiMapId, uint32 uiInstanceConditionId);
        void SetSpecialAchievementCriteria(uint32 uiType, bool bIsMet);
        bool CheckAchievementCriteriaMeet(uint32 uiCriteriaId, Player const* pSource, Unit const* pTarget, uint32 uiMiscValue1 /* = 0*/);

        void DoSpawnFlameLeviathanIfCan();
        void DoOpenMadnessDoorIfCan();
        void OpenXtDoor();
        void SpawnFriendlyKeeper(uint32 uiWho);

    protected:
        std::string strInstData;
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        uint32 m_auiHardBoss[HARD_MODE_ENCOUNTER];
        uint32 m_auiUlduarKeepers[KEEPER_ENCOUNTER];
        uint32 m_auiUlduarTeleporters[TELEPORTER_ENCOUNTER];
        bool m_abAchievCriteria[MAX_SPECIAL_ACHIEV_CRITS];
        uint32 m_auiMiniBoss[6];

        uint32 m_uiMimironPhase;
        uint32 m_uiYoggPhase;
        uint32 m_uiVisionPhase;

        // Creatures
        uint64 m_uiLeviathanGUID;
        uint64 m_uiIgnisGUID;
        uint64 m_uiRazorscaleGUID;
        uint64 m_uiCommanderGUID;
        uint64 m_uiXT002GUID;
        uint64 m_uiBrundirGUID;
        uint64 m_uiMolgeimGUID;
        uint64 m_uiSteelbreakerGUID;
        uint64 m_uiKologarnGUID;
        uint64 m_uiAuriayaGUID;
        uint64 m_uiMimironGUID;
        uint64 m_uiHodirGUID;
        uint64 m_uiThorimGUID;
        uint64 m_uiFreyaGUID;
        uint64 m_uiVezaxGUID;
        uint64 m_uiYoggSaronGUID;
        uint64 m_uiAlgalonGUID;
        uint64 m_uiRightArmGUID;
        uint64 m_uiLeftArmGUID;
        uint64 m_uiFeralDefenderGUID;
        uint64 m_uiElderBrightleafGUID;
        uint64 m_uiElderStonebarkGUID;
        uint64 m_uiElderIronbrachGUID;
        uint64 m_uiSaroniteAnimusGUID;
        uint64 m_uiRunicColossusGUID;
        uint64 m_uiRuneGiantGUID;
        uint64 m_uiJormungarGUID;
        uint64 m_uiLeviathanMkGUID;
        uint64 m_uiSaraGUID;
        uint64 m_uiYoggBrainGUID;

        // Doors & Objects
        // The siege
        uint64 m_uiShieldWallGUID;
        uint64 m_uiLightningDoorGUID;
        uint64 m_uiLeviathanGateGUID;
        uint64 m_uiXT002GateGUID;
        uint64 m_uiBrokenHarpoonGUID;
        // Archivum
        uint64 m_uiIronCouncilDoorGUID;
        uint64 m_uiArchivumDoorGUID;
        uint64 m_uiArchivumConsoleGUID;
        uint64 m_uiUniverseFloorArchivumGUID;
        // Celestial planetarium
        uint64 m_uiCelestialDoorGUID;
        uint64 m_uiCelestialConsoleGUID;
        uint64 m_uiUniverseFloorCelestialGUID;
        uint64 m_uiAzerothGlobeGUID;
        // Kologarn
        uint64 m_uiShatteredHallsDoorGUID;
        uint64 m_uiKologarnBridgeGUID;
        // Hodir
        uint64 m_uiHodirEnterDoorGUID;
        uint64 m_uiHodirWallGUID;
        uint64 m_uiHodirExitDoorGUID;
        // Mimiron
        uint64 m_uiMimironButtonGUID;
        uint64 m_uiMimironDoor1GUID;
        uint64 m_uiMimironDoor2GUID;
        uint64 m_uiMimironDoor3GUID;
        uint64 m_uiMimironElevatorGUID;
        uint64 m_auiMimironTelGUID[9];
        // Thorim
        uint64 m_uiArenaEnterDoorGUID;
        uint64 m_uiArenaExitDoorGUID;
        uint64 m_uiHallwayDoorGUID;
        uint64 m_uiThorimEnterDoorGUID;
        uint64 m_uiThorimLeverGUID;
        // Prison
        uint64 m_uiAncientGateGUID;
        uint64 m_uiVezaxGateGUID;
        uint64 m_uiYoggGateGUID;
        uint64 m_uiBrainDoor1GUID;
        uint64 m_uiBrainDoor2GUID;
        uint64 m_uiBrainDoor3GUID;

        // Chests
        uint64 m_uiKologarnLootGUID;
        uint64 m_uiHodirLootGUID;
        uint64 m_uiHodirRareLootGUID;
        uint64 m_uiThorimLootGUID;
        uint64 m_uiThorimRareLootGUID;
        uint64 m_uiMimironLootGUID;
        uint64 m_uiMimironHardLootGUID;
        uint64 m_uiAlagonLootGUID;

        std::list<uint64> m_luiLeviathanPreadds;
        std::set<uint32> m_suiSortedLeviathanAdds;
};

#endif
