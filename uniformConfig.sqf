/*  Defines uniforms and vests available to teams
*
*/

waitUntil {!isNil "ISWOODLAND"};

//WOODLAND =====================================================================
if (ISWOODLAND) then {
  randomUniforms = [
    //VANILLA
    ['U_LIB_GER_Recruit', 'V_LIB_GER_VestKar98'],
	['U_LIB_US_NAC_Uniform_2', 'V_LIB_US_Vest_Garand'],
	['U_LIB_SOV_Efreitor_summer', 'V_LIB_SOV_RA_MosinBelt']
    
  ];

//DESERT =======================================================================
} else {
  randomUniforms = [
    //VANILLA
    ['U_O_CombatUniform_oucamo', 'V_TacVest_blk'],

  ];
};
