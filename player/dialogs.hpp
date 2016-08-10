#include "defines.hpp"

class RscText
{
	access = 0;
	type = 0;
	idc = -1;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {1, 1, 1, 1};
	text = "";
	fixedWidth = 0;
	x = 0;
	y = 0;
	h = 0.037;
	w = 0.3;
	style = 0;
	shadow = 1;
	colorShadow[] = {0, 0, 0, 0.5};
	font = "PuristaMedium";
	SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	linespacing = 1;
};

class mcd_RscMapText: RscText
{
	idc = -1;
	type = CT_STATIC;
	style = ST_LEFT;
	font = "PuristaLight";
	sizeEx = 0.04;
	colorBackground[] = { 0,0,0, 0.8 };
	text = "";
	w = 0.52 * 3/4;
	h = 0.05;
	duration = 1e+1000;
};

class mcd_RscMapTextSmall: RscText
{
	idc = -1;
	type = CT_STATIC;
	style = ST_LEFT;
	shadow = 2;
	font = "PuristaLight";
	sizeEx = 0.04;
	colorBackground[] = { 0,0,0, 0.8 };
	text = "";
	w = 0.52 * 3/4;
	h = 0.05;
	duration = 1e+1000;
};

class mcd_RscPicture
{
	shadow = 0;
	type = 0;
	style = 48;
	sizeEx = 0.023;
	font = "PuristaMedium";
	colorBackground[] = {};
	colorText[] = {};
	x = 0;
	y = 0;
	w = 0.2;
	h = 0.15;
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
};


class KillCamText
{
  access = 0;
  type = CT_STATIC;
  idc = -1;
  style = ST_CENTER;
  w = 0.1; h = 0.05;
  font = "PuristaMedium";
  sizeEx = 0.08;
  colorBackground[] = {0,0,0,0};
  colorText[] = {1,1,1,1};
  text = "";
  fixedWidth = 0;
  shadow = 0;
};

class ScoreBoardItem
{
 access = 0;
 type = CT_STATIC;
 idc = -1;
 style = ST_LEFT;
 x = sb_totalX + sb_scoreW + sb_itemSpacingX;
 w = sb_itemW;
 h = sb_itemH;
 font = "PuristaLight";
 sizeEx = (0.04 * TEXT_SCALE);
 colorBackground[] = {0,0,0,1};
 colorText[] = {1,1,1,1};
 text = "ASD";
 fixedWidth = 0;
 shadow = 0;
};

class ScoreBoardScore: ScoreBoardItem
{
  style = ST_CENTER;
  x = sb_totalX;
  w = sb_scoreW;
  text = "";
};

class RscTitles
{
  class voteCountdownTitle
  {
    idd = 1400;
    duration = 99999;

    enableSimulation = 1;
    enableDisplay = 1;
    onLoad = "disableSerialization; _this call mcd_fnc_voteDialogText;";

    class ControlsBackground
    {
      class statusMessage: mcd_RscMapText
      {
        moving = 1;
        idc = 1401;
        text = "PLAYZONE VOTING";
        x = safeZoneX + safeZoneW - 0.6 * 3/4;
        y = safeZoneY + safeZoneH - 1.600;
      };

			class skipMessage: mcd_RscMapTextSmall
			{
				idc = 1403;
				text = "";
				x = safeZoneX + safeZoneW - 0.6 * 3/4;
				y = safeZoneY + safeZoneH - 1.545;
			};

      class waitMessage: mcd_RscMapTextSmall
      {
        idc = 1402;
        text = "";
        x = safeZoneX + safeZoneW - 0.6 * 3/4;
        y = safeZoneY + safeZoneH - 1.490;
      };
    };
  };

	class upgradeWeaponTitle
	{
		idd = 1500;
		duration = 99999;

		enableSimulation = 1;
		enableDisplay = 1;

		onload = "disableSerialization; _this call mcd_fnc_upgradeWeaponTitle;";

		class ControlsBackground
		{
			#define uw_x (safeZoneX + safeZoneW - 0.5)
			#define uw_y (safeZoneY + safeZoneH - 1.6)
			#define uw_w (0.40)
			#define uw_h (0.40 * 3/4)
			#define uw_paddingX (uw_w * 0.1)
			#define uw_paddingY (uw_h * 0.1)

			class Background: IGUIBack
			{
				idc = 1501;
				x = uw_x;
        y = uw_y;
				w = uw_w;
				h = uw_h;
			};

			class WeaponPicture: mcd_RscPicture
			{
				idc = 1502;
				x = uw_x + uw_paddingX;
				y = uw_y;
				w = uw_w - 2*uw_paddingX;
				h = uw_h - uw_paddingY;
				text = "";
			};

			class WeaponText: RscText
			{
				idc = 1503;
				style = ST_CENTER;
				x = uw_x;
				y = uw_y + uw_h - uw_paddingY*1.4;
				w = uw_w;
				h = uw_paddingY;

			};
		};
	};

	class KillCamTitle
	{
	  idd = KILLCAMTITLE_DIALOG;
	  enableDisplay = true;
	  enableSimulation = true;
		duration = 8;
		onLoad = "uiNamespace setVariable [""KillCamTitle_Display"", _this select 0]";

	  class ControlsBackground
	  {
	    class Title: KillCamText
	    {
	      idc = KILLCAMTITLE_TITLE;
	      x = kc_titleX;
	      y = kc_titleY;
	      w = kc_W;
	      h = kc_H;
	    };
	  };
	};

	class ScoreBoard
	{
		idd = SCOREBOARD_DIALOG;
		enableDisplay = true;
		enableSimulation = true;
		duration = 1e+1000;
		onLoad = "uiNamespace setVariable [""ScoreBoard_Display"", _this select 0]";

		class ControlsBackground {
			class Item1: ScoreBoardItem
			{
				idc = SCOREBOARD_ITEM1;
				y = sb_totalY + ((sb_itemSpacingY + sb_itemH) * 0);
			};

			class Score1: ScoreBoardScore
			{
				idc = SCOREBOARD_SCORE1;
				y = sb_totalY + ((sb_itemSpacingY + sb_itemH) * 0);
			};

			class Item2: ScoreBoardItem
			{
				idc = SCOREBOARD_ITEM2;
				y = sb_totalY + ((sb_itemSpacingY + sb_itemH) * 1);
			};

			class Score2: ScoreBoardScore
			{
				idc = SCOREBOARD_SCORE2;
				y = sb_totalY + ((sb_itemSpacingY + sb_itemH) * 1);
			};

			class Item3: ScoreBoardItem
			{
				idc = SCOREBOARD_ITEM3;
				y = sb_totalY + ((sb_itemSpacingY + sb_itemH) * 2);
			};

			class Score3: ScoreBoardScore
			{
				idc = SCOREBOARD_SCORE3;
				y = sb_totalY + ((sb_itemSpacingY + sb_itemH) * 2);
			};

			class Item4: ScoreBoardItem
			{
				idc = SCOREBOARD_ITEM4;
				y = sb_totalY + ((sb_itemSpacingY + sb_itemH) * 3);
			};

			class Score4: ScoreBoardScore
			{
				idc = SCOREBOARD_SCORE4;
				y = sb_totalY + ((sb_itemSpacingY + sb_itemH) * 3);
			};
		};
	};
};
