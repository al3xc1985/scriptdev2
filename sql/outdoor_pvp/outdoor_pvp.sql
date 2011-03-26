-- silithus
UPDATE gameobject_template SET ScriptName='go_silithyst' WHERE entry IN (181597,181598);
DELETE FROM scripted_areatrigger WHERE entry IN (4162,4168);
INSERT INTO scripted_areatrigger VALUES 
(4162,'at_silithus'),
(4168,'at_silithus');
UPDATE world_template SET `scriptName`='outdoor_pvp_silithus' WHERE map=1;

-- eastern plaguelands
UPDATE world_template SET `scriptName`='outdoor_pvp_eastern_plaguelands' WHERE map=0;
DELETE FROM scripted_event_id WHERE id IN (10567,10564,10687,10688,10701,10700,11153,11152);
INSERT INTO scripted_event_id VALUES
(10567,'event_plaguewood_tower'),
(10564,'event_plaguewood_tower'),
(10687,'event_plaguewood_tower'),
(10688,'event_plaguewood_tower'),
(10701,'event_plaguewood_tower'),
(10700,'event_plaguewood_tower'),
(11153,'event_plaguewood_tower'),
(11152,'event_plaguewood_tower');