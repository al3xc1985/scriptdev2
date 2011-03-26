
-- Archavon warder
UPDATE `creature_template` SET `AIName`='EventAI' WHERE `entry`=32353;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=32353;
INSERT INTO `creature_ai_scripts` (`id`,`creature_id`,`event_type`,`event_inverse_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action1_type`,`action1_param1`,`action1_param2`,`action1_param3`,`action2_type`,`action2_param1`,`action2_param2`,`action2_param3`,`action3_type`,`action3_param1`,`action3_param2`,`action3_param3`,`comment`) VALUES 
('3235301','32353','0','0','100','3','10000','15000','15000','25000','11','60919','0','0','0','0','0','0','0','0','0','0', 'Archavon warder (normal) - cast rock shower'),
('3235302','32353','0','0','100','5','10000','15000','15000','25000','11','60923','0','0','0','0','0','0','0','0','0','0', 'Archavon warder (heroic) - cast rock shower'),
('3235303','32353','0','0','100','3','5000','7000','5000','13000','11','60897','1','0','0','0','0','0','0','0','0','0', 'Archavon warder (normal) - cast shield crush'),
('3235304','32353','0','0','100','5','5000','7000','5000','13000','11','60899','1','0','0','0','0','0','0','0','0','0', 'Archavon warder (heroic) - cast shield crush'),
('3235305','32353','0','0','100','3','8000','10000','17000','20000','11','60902','0','0','0','0','0','0','0','0','0','0', 'Archavon warder (normal) - cast whirl'),
('3235306','32353','0','0','100','5','8000','10000','17000','20000','11','60916','0','0','0','0','0','0','0','0','0','0', 'Archavon warder (heroic) - cast whirl');

-- Tempest warder
UPDATE `creature_template` SET `AIName`='EventAI' WHERE `entry`=34015;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=34015;
INSERT INTO `creature_ai_scripts` (`id`,`creature_id`,`event_type`,`event_inverse_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action1_type`,`action1_param1`,`action1_param2`,`action1_param3`,`action2_type`,`action2_param1`,`action2_param2`,`action2_param3`,`action3_type`,`action3_param1`,`action3_param2`,`action3_param3`,`comment`) VALUES 
('3401501','34015','0','0','100','7','5000','8000','4000','7000','11','64363','4','0','0','0','0','0','0','0','0','0', 'Tempest warder - cast shock'),
('3401502','34015','2','0','100','6','33','33','0','0','11','64379','0','0','0','0','0','0','0','0','0','0', 'Tempest warder - cast overcharge at 33% hp'),
('3401503','34015','8','0','100','6','64217','0','10','10','11','64219','0','0','0','0','0','0','0','0','0','0', 'Tempest warder - cast overcharged blast at 10 overcharged stacks');

-- Flame warder
UPDATE `creature_template` SET `AIName`='EventAI' WHERE `entry`=35143;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=35143;
INSERT INTO `creature_ai_scripts` (`id`,`creature_id`,`event_type`,`event_inverse_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action1_type`,`action1_param1`,`action1_param2`,`action1_param3`,`action2_type`,`action2_param1`,`action2_param2`,`action2_param3`,`action3_type`,`action3_param1`,`action3_param2`,`action3_param3`,`comment`) VALUES 
('3514301','35143','0','0','100','3','5000','8000','4000','7000','11','66813','4','0','0','0','0','0','0','0','0','0', 'Flame warder (normal) - cast lava burst'),
('3514302','35143','0','0','100','5','5000','8000','4000','7000','11','67330','4','0','0','0','0','0','0','0','0','0', 'Flame warder (heroic) - cast lava burst'),
('3514303','35143','0','0','100','3','10000','15000','20000','25000','11','66808','0','0','0','0','0','0','0','0','0','0', 'Flame warder (normal) - cast meteor fists'),
('3514304','35143','0','0','100','5','10000','15000','20000','25000','11','68160','0','0','0','0','0','0','0','0','0','0', 'Flame warder (heroic) - cast meteor fists');

-- Frost warder
UPDATE `creature_template` SET `AIName`='EventAI' WHERE `entry`=38482;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=38482;
INSERT INTO `creature_ai_scripts` (`id`,`creature_id`,`event_type`,`event_inverse_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action1_type`,`action1_param1`,`action1_param2`,`action1_param3`,`action2_type`,`action2_param1`,`action2_param2`,`action2_param3`,`action3_type`,`action3_param1`,`action3_param2`,`action3_param3`,`comment`) VALUES 
('3848201','38482','0','0','100','3','5000','8000','4000','7000','11','72123','4','0','0','0','0','0','0','0','0','0', 'Frost warder (normal) - cast frost blast'),
('3848202','38482','0','0','100','5','5000','8000','4000','7000','11','72124','4','0','0','0','0','0','0','0','0','0', 'Frost warder (heroic) - cast frost blast');


