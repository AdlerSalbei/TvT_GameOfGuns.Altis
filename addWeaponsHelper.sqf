/*  Manually executed to help with adding weapons to the config
*
*/

doit = false;
sleep 1.5;

player sideChat "addWeaponsHelper now running.";
doit = true;

newWeapons = [];
newHandguns = [];

while {doit} do {
  _primaryWeapon = primaryWeapon player;
  _handgun = handgunWeapon player;

  if (_primaryWeapon != "" && newWeapons find _primaryWeapon == -1) then {
    newWeapons pushBack _primaryWeapon;
  };

  if (_handgun != "" && newHandguns find _handgun == -1) then {
	newHandguns pushBack _handgun;
  };

  sleep 0.5;
};
