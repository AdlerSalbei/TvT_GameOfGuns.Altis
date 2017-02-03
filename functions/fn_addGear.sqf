if (!hasInterface) exitWith {};

_gear = player getVariable ["myUniform", ['U_LIB_GER_Recruit', 'V_LIB_GER_VestKar98']];
_uniform = _gear select 0;
_vest = _gear select 1;
//_vest = if (ISWOODLAND) then {"V_TacVest_oli"} else {"V_TacVest_khk"};

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
this forceAddUniform _uniform;
waitUntil {uniform player != ""};
for "_i" from 1 to 6 do {this addItemToUniform "ACE_fieldDressing";};
for "_i" from 1 to 4 do {this addItemToUniform "ACE_morphine";};
this addVest _vest;

comment "Add weapons";
this addWeapon (selectRandom ["LIB_Binocular_GER","LIB_Binocular_US","LIB_Binocular_SU"];

comment "Add items";
this linkItem "ItemMap";
this linkItem "ItemCompass";
this linkItem "ItemWatch";

