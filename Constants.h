#ifndef _RTECONSTANTS_
#define _RTECONSTANTS_

namespace RTE {

#pragma region Buffer Constants
	constexpr static unsigned int c_MaxFileName = 256; ///! Maximum length of output file directory+name string.
	constexpr static unsigned int c_FileBufferSize = 8192; ///! Buffer to hold data read from the zip file.
	constexpr static unsigned int c_MaxUnzippedFileSize = 104857600; ///! Maximum size of single file being extracted from zip archive.
#pragma endregion

#pragma region Graphics Constants
	constexpr static unsigned int c_PaletteEntriesNumber = 256; ///! Number of indexes in the graphics palette.
	constexpr static unsigned int c_MOIDLayerBitDepth = 16; ///! Bit depth of MOID layer bitmap.

	constexpr static unsigned int c_GoldMaterialID = 2; ///! Index of gold material in the material palette.

	// GUI colors
	#define c_GUIColorWhite makecol(255, 255, 255)
	#define c_GUIColorYellow makecol(255, 255, 128)
	#define c_GUIColorRed makecol(255, 100, 100)
	#define c_GUIColorGreen makecol(128, 255, 128)
	#define c_GUIColorLightBlue makecol(109, 117, 170)
	#define c_GUIColorBlue makecol(59, 65, 83)
	#define c_GUIColorDarkBlue makecol(12, 20, 39)
	#define c_GUIColorGray makecol(232, 232, 248)

	#define c_PlayerSlotColorDefault makecol(161, 109, 20) 
	#define c_PlayerSlotColorHovered makecol(203, 130, 56) 
	#define c_PlayerSlotColorDisabled makecol(104, 67, 15)
#pragma endregion

#pragma region Math Constants
	constexpr static float c_TwoPI = 6.2831853;
	constexpr static float c_PI = 3.1415926;
	constexpr static float c_HalfPI = 1.5707963;
	constexpr static float c_QuarterPI = 0.7853982;
	constexpr static float c_EighthPI = 0.3926991;
	constexpr static float c_SixteenthPI = 0.1963495;
#pragma endregion
}
#endif