waitUntil {!isNil "isSpectator"};
if (isSpectator) exitWith {};

this = player;

comment "Exported from Arsenal by McDiod";

comment "Remove existing items";
removeAllWeapons this;
removeAllItems this;
removeAllAssignedItems this;
removeUniform this;
removeVest this;
removeBackpack this;
removeHeadgear this;
removeGoggles this;

comment "Add containers";
this forceAddUniform "U_LIB_GER_Recruit";
for "_i" from 1 to 6 do {this addItemToUniform "ACE_fieldDressing";};
for "_i" from 1 to 4 do {this addItemToUniform "ACE_morphine";};
this addVest "V_LIB_GER_VestKar98";

comment "Add weapons";
this addWeapon "Binocular";

comment "Add items";
this linkItem "ItemMap";
this linkItem "ItemCompass";
this linkItem "ItemWatch";

