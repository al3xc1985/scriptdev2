/* FORGE OF SOULS */
UPDATE creature_template SET ScriptName='npc_corrupted_soul_fragment' WHERE entry=36535;

/* PIT OF SARON */
-- Areatrigger:
delete from scripted_areatrigger where entry = 5578;
insert into scripted_areatrigger values (5578, 'at_tyrannus');
-- Boss
UPDATE `creature_template` SET `ScriptName`='boss_garfrost' WHERE `entry`=36494;
UPDATE `creature_template` SET `ScriptName`='boss_ick' WHERE `entry`=36476;
UPDATE `creature_template` SET `ScriptName`='boss_krick' WHERE `entry`=36477;
UPDATE `creature_template` SET `ScriptName`='mob_explosive_orb' WHERE `entry`=36610;
UPDATE `creature_template` SET `ScriptName`='boss_tyrannus' WHERE `entry`=36658;
UPDATE `creature_template` SET `ScriptName`='boss_rimefang' WHERE `entry`=36661;
UPDATE `creature_template` SET `ScriptName`='npc_colapsing_icicle' WHERE `entry`=36847;
-- npc
UPDATE `creature_template` SET `ScriptName`='npc_slyvanas_jaina_pos_start' WHERE `entry` in (36993, 36990);
UPDATE `creature_template` SET `ScriptName`='npc_slyvanas_jaina_pos_end' WHERE `entry` in (38188, 38189);
UPDATE `creature_template` SET `ScriptName`='npc_martin_gorkun' WHERE `entry` in (37591, 37592);

/* HALLS OF REFLECTION */
-- start npcs
-- jaina
-- Added custom GUID
DELETE FROM `creature` WHERE `id`=37221;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(300001, 37221, 668, 3, 128, 0, 0, 5266.78, 1953.42, 707.697, 0.740877, 7200, 0, 0, 5040000, 881400, 0, 0);
-- sylvanas
DELETE FROM `creature` WHERE `id`=37223;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(300002, 37223, 668, 3, 64, 0, 0, 5266.78, 1953.42, 707.697, 0.740877, 7200, 0, 0, 6972500, 85160, 0, 0);
-- trash
UPDATE `creature_template` SET `ScriptName`='mob_hallsOfReflectionSoul' WHERE `entry` in (38176, 38175, 38172, 38567, 38177, 38173);
-- boss
UPDATE `creature_template` SET `ScriptName`='boss_marwyn' WHERE `entry`=38113;
UPDATE `creature_template` SET `ScriptName`='boss_falric' WHERE `entry`=38112;
-- npc
UPDATE `creature_template` SET `ScriptName`='npc_slyvanas_jaina_hor_start' WHERE `entry` in (37221, 37223);
UPDATE `creature_template` SET `ScriptName`='npc_slyvanas_jaina_hor_end' WHERE `entry` in (36955, 37554);
UPDATE `creature_template` SET `ScriptName`='npc_lich_king_hor_start' WHERE `entry`=36954;
UPDATE `creature_template` SET `ScriptName`='boss_lich_king_hor_end' WHERE `entry`=37226;

update instance_template set scriptName = 'instance_halls_of_reflection' where map = 668;