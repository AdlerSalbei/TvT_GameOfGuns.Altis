/*  Adds killed EH to units
*
*   only necessary on server
*   executed on mission start via server\setup\teamSetup.sqf for all playable units
*/


// THIS IS UNUSED RIGHT NOW!


params ["_unit"];

_unit addEventHandler ["killed", {[_this] spawn mcd_fnc_weaponCleanup}];
/*_unit addEventHandler ["killed", {[_this] call mcd_fnc_setScore;}];*/
diag_log format ["fnc_addKilledEH - Added killed EH to %1.", name _unit];
