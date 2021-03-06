/*  Adds public variable event handler that triggers when player's group gets a new score value
*
*   executed via initPlayerLocal.sqf on player
*/

waitUntil {!isNil "isSpectator"};
if (isSpectator) exitWith {};
waitUntil {sleep 0.5; (player getVariable ["groupname", "GROUPNAMEUNDEFINED"]) != "GROUPNAMEUNDEFINED"};

_groupname = player getVariable "groupname";
call compile (format ["'%1' addPublicVariableEventHandler {[_this select 1] call mcd_fnc_upgradeWeapon; playSound 'switchsound'}", _groupname]);

//do this shit on localhost
if (isServer && hasInterface) then {
  [_groupname] spawn compile (format [
    "while {true} do {
      _oldValue = %1;
      waitUntil {_oldValue != %1};
      [%1] call mcd_fnc_upgradeWeapon;
    };", _groupname
  ]);
};
