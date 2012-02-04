/*
**
**	MUIBuilder.library
**
**	$VER: MUIBuilder.library 1.0
**
**		(c) copyright 1994
**		    Eric Totel
**
*/

#ifndef MUIB_H
#define MUIB_H

#ifndef UTILITY_TAGITEM_H
#include <utility/TagItem.h> 
#endif

/* MB_GetA Tags */
#define MUIB_FileName 		(TAG_USER + 200)
#define MUIB_CatalogName 	(TAG_USER + 201)
#define MUIB_GetStringName	(TAG_USER + 202)
#define MUIB_Code		(TAG_USER + 203)
#define MUIB_Environment	(TAG_USER + 204)
#define MUIB_Locale		(TAG_USER + 205)
#define MUIB_Declarations	(TAG_USER + 206)
#define MUIB_VarNumber		(TAG_USER + 207)
#define MUIB_Notifications	(TAG_USER + 212)
#define MUIB_Application	(TAG_USER + 213)

/* MB_GetVarInfoA Tags */
#define MUIB_VarSize		(TAG_USER + 208)
#define MUIB_VarName		(TAG_USER + 209)
#define MUIB_VarType		(TAG_USER + 210)
#define MUIB_VarInitPtr		(TAG_USER + 211)

/* types of datas */

	/* variables types */
#define TYPEVAR_BOOL		1
#define TYPEVAR_INT		2
#define TYPEVAR_STRING		3
#define TYPEVAR_TABSTRING	4
#define TYPEVAR_PTR		5
#define TYPEVAR_HOOK		6
#define TYPEVAR_IDENT		7
#define TYPEVAR_EXTERNAL	8
#define TYPEVAR_LOCAL_PTR	9
#define TYPEVAR_EXTERNAL_PTR   10

	/* Types of Code */
#define TC_CREATEOBJ		1
#define TC_ATTRIBUT		2
#define TC_END			3
#define TC_FUNCTION		4
#define TC_STRING		5
#define TC_INTEGER		6
#define TC_CHAR			7
#define TC_VAR_AFFECT		8
#define TC_VAR_ARG		9
#define TC_END_FUNCTION		10
#define TC_BOOL			11
#define	TC_MUIARG		12
#define TC_OBJFUNCTION		13
#define TC_LOCALESTRING		14
#define TC_EXTERNAL_CONSTANT    15
#define TC_EXTERNAL_FUNCTION    16
#define TC_MUIARG_ATTRIBUT      17
#define TC_MUIARG_FUNCTION	18
#define TC_MUIARG_OBJ		19
#define TC_BEGIN_NOTIFICATION	20
#define TC_END_NOTIFICATION	21
#define TC_EXTERNAL_VARIABLE    22
#define TC_MUIARG_OBJFUNCTION	23
#define TC_OBJ_ARG		24
#define	TC_LOCALECHAR		25


/* ALL Strings used in MUI                */
/* This array was generated automatically */
/* with the mui.h header file		  */

char  *MUIStrings[] =
	{
		"LIBRARIES_MUI_H",
		"MUIMASTER_NAME",
		"MUIMASTER_VMIN",
		"MC_TEMPLATE_ID",
		"MUI_RXERR_BADDEFINITION",
		"MUI_RXERR_OUTOFMEMORY",
		"MUI_RXERR_UNKNOWNCOMMAND",
		"MUI_RXERR_BADSYNTAX",
		"MUIE_OK",
		"MUIE_OutOfMemory",
		"MUIE_OutOfGfxMemory",
		"MUIE_InvalidWindowObject",
		"MUIE_MissingLibrary",
		"MUIE_NoARexx",
		"MUIE_SingleTask",
		"MUII_WindowBack",
		"MUII_RequesterBack",
		"MUII_ButtonBack",
		"MUII_ListBack",
		"MUII_TextBack",
		"MUII_PropBack",
		"MUII_ActiveBack",
		"MUII_SelectedBack",
		"MUII_ListCursor",
		"MUII_ListSelect",
		"MUII_ListSelCur",
		"MUII_ArrowUp",
		"MUII_ArrowDown",
		"MUII_ArrowLeft",
		"MUII_ArrowRight",
		"MUII_CheckMark",
		"MUII_RadioButton",
		"MUII_Cycle",
		"MUII_PopUp",
		"MUII_PopFile",
		"MUII_PopDrawer",
		"MUII_PropKnob",
		"MUII_Drawer",
		"MUII_HardDisk",
		"MUII_Disk",
		"MUII_Chip",
		"MUII_Volume",
		"MUII_PopUpBack",
		"MUII_Network",
		"MUII_Assign",
		"MUII_TapePlay",
		"MUII_TapePlayBack",
		"MUII_TapePause",
		"MUII_TapeStop",
		"MUII_TapeRecord",
		"MUII_GroupBack",
		"MUII_SliderBack",
		"MUII_SliderKnob",
		"MUII_TapeUp",
		"MUII_TapeDown",
		"MUII_Count",
		"MUII_BACKGROUND",
		"MUII_SHADOW",
		"MUII_SHINE",
		"MUII_FILL",
		"MUII_SHADOWBACK",
		"MUII_SHADOWFILL",
		"MUII_SHADOWSHINE",
		"MUII_FILLBACK",
		"MUII_FILLSHINE",
		"MUII_SHINEBACK",
		"MUII_FILLBACK2",
		"MUII_HSHINEBACK",
		"MUII_HSHADOWBACK",
		"MUII_HSHINESHINE",
		"MUII_HSHADOWSHADOW",
		"MUII_N1HSHINE",
		"MUII_LASTPAT",
		"MUIV_TriggerValue",
		"MUIV_EveryTime",
		"MUIV_Application_Save_ENV",
		"MUIV_Application_Save_ENVARC",
		"MUIV_Application_Load_ENV",
		"MUIV_Application_Load_ENVARC",
		"MUIV_Application_ReturnID_Quit",
		"MUIV_List_Insert_Top",
		"MUIV_List_Insert_Active",
		"MUIV_List_Insert_Sorted",
		"MUIV_List_Insert_Bottom",
		"MUIV_List_Remove_First",
		"MUIV_List_Remove_Active",
		"MUIV_List_Remove_Last",
		"MUIV_List_Select_Off",
		"MUIV_List_Select_On",
		"MUIV_List_Select_Toggle",
		"MUIV_List_Select_Ask",
		"MUIV_List_Jump_Active",
		"MUIV_List_GetEntry_Active",
		"MUIV_List_Select_Active",
		"MUIV_List_Select_All",
		"MUIV_List_Redraw_Active",
		"MUIV_List_Redraw_All",
		"MUIV_List_Exchange_Active",
		"MUIV_Colorpanel_GetColor_Active",
		"MUIV_Colorpanel_SetColor_Active",
		"MUIX_R",
		"MUIX_C",
		"MUIX_L",
		"MUIX_N",
		"MUIX_B",
		"MUIX_I",
		"MUIX_U",
		"MUIX_PT",
		"MUIX_PH",
		"MUIV_Palette_Entry_End",
		"WindowObject",
		"ImageObject",
		"NotifyObject",
		"ApplicationObject",
		"TextObject",
		"RectangleObject",
		"ListObject",
		"PropObject",
		"StringObject",
		"ScrollbarObject",
		"ListviewObject",
		"RadioObject",
		"VolumelistObject",
		"FloattextObject",
		"DirlistObject",
		"SliderObject",
		"CycleObject",
		"GaugeObject",
		"ScaleObject",
		"BoopsiObject",
		"ColorfieldObject",
		"ColorpanelObject",
		"ColoradjustObject",
		"PaletteObject",
		"GroupObject",
		"RegisterObject",
		"VirtgroupObject",
		"ScrollgroupObject",
		"PopstringObject",
		"PopobjectObject",
		"PopaslObject",
		"ScrmodelistObject",
		"VGroup",
		"HGroup",
		"ColGroup",
		"RowGroup",
		"PageGroup",
		"VGroupV",
		"HGroupV",
		"ColGroupV",
		"RowGroupV",
		"PageGroupV",
		"RegisterGroup",
		"End",
		"Child",
		"SubWindow",
		"WindowContents",
		"NoFrame",
		"ButtonFrame",
		"ImageButtonFrame",
		"TextFrame",
		"StringFrame",
		"ReadListFrame",
		"InputListFrame",
		"PropFrame",
		"SliderFrame",
		"GaugeFrame",
		"VirtualFrame",
		"GroupFrame",
		"GroupFrameT",
		"HVSpace",
		"HSpace",
		"VSpace",
		"HCenter",
		"VCenter",
		"InnerSpacing",
		"GroupSpacing",
		"String",
		"KeyString",
		"CheckMark",
		"KeyCheckMark",
		"SimpleButton",
		"KeyButton",
		"Cycle",
		"KeyCycle",
		"Radio",
		"KeyRadio",
		"Slider",
		"KeySlider",
		"PopButton",
		"Label",
		"Label1",
		"Label2",
		"LLabel",
		"LLabel1",
		"LLabel2",
		"KeyLabel",
		"KeyLabel1",
		"KeyLabel2",
		"KeyLLabel",
		"KeyLLabel1",
		"KeyLLabel2",
		"get",
		"set",
		"nnset",
		"setmutex",
		"setcycle",
		"setstring",
		"setcheckmark",
		"setslider",
		"MUIM_BoopsiQuery",
		"MUIP_BoopsiQuery",
		"MBQF_HORIZ",
		"MBQ_MUI_MAXMAX",
		"MUIC_Notify",
		"MUIM_CallHook",
		"MUIM_KillNotify",
		"MUIM_MultiSet",
		"MUIM_Notify",
		"MUIM_Set",
		"MUIM_SetAsString",
		"MUIM_WriteLong",
		"MUIM_WriteString",
		"MUIA_AppMessage",
		"MUIA_HelpFile",
		"MUIA_HelpLine",
		"MUIA_HelpNode",
		"MUIA_NoNotify",
		"MUIA_Revision",
		"MUIA_UserData",
		"MUIA_Version",
		"MUIC_Application",
		"MUIM_Application_GetMenuCheck",
		"MUIM_Application_GetMenuState",
		"MUIM_Application_Input",
		"MUIM_Application_InputBuffered",
		"MUIM_Application_Load",
		"MUIM_Application_PushMethod",
		"MUIM_Application_ReturnID",
		"MUIM_Application_Save",
		"MUIM_Application_SetMenuCheck",
		"MUIM_Application_SetMenuState",
		"MUIM_Application_ShowHelp",
		"MUIA_Application_Active",
		"MUIA_Application_Author",
		"MUIA_Application_Base",
		"MUIA_Application_Broker",
		"MUIA_Application_BrokerHook",
		"MUIA_Application_BrokerPort",
		"MUIA_Application_BrokerPri",
		"MUIA_Application_Commands",
		"MUIA_Application_Copyright",
		"MUIA_Application_Description",
		"MUIA_Application_DiskObject",
		"MUIA_Application_DoubleStart",
		"MUIA_Application_DropObject",
		"MUIA_Application_Iconified",
		"MUIA_Application_Menu",
		"MUIA_Application_MenuAction",
		"MUIA_Application_MenuHelp",
		"MUIA_Application_RexxHook",
		"MUIA_Application_RexxMsg",
		"MUIA_Application_RexxString",
		"MUIA_Application_SingleTask",
		"MUIA_Application_Sleep",
		"MUIA_Application_Title",
		"MUIA_Application_Version",
		"MUIA_Application_Window",
		"MUIC_Window",
		"MUIM_Window_GetMenuCheck",
		"MUIM_Window_GetMenuState",
		"MUIM_Window_ScreenToBack",
		"MUIM_Window_ScreenToFront",
		"MUIM_Window_SetCycleChain",
		"MUIM_Window_SetMenuCheck",
		"MUIM_Window_SetMenuState",
		"MUIM_Window_ToBack",
		"MUIM_Window_ToFront",
		"MUIA_Window_Activate",
		"MUIA_Window_ActiveObject",
		"MUIA_Window_AltHeight",
		"MUIA_Window_AltLeftEdge",
		"MUIA_Window_AltTopEdge",
		"MUIA_Window_AltWidth",
		"MUIA_Window_AppWindow",
		"MUIA_Window_Backdrop",
		"MUIA_Window_Borderless",
		"MUIA_Window_CloseGadget",
		"MUIA_Window_CloseRequest",
		"MUIA_Window_DefaultObject",
		"MUIA_Window_DepthGadget",
		"MUIA_Window_DragBar",
		"MUIA_Window_Height",
		"MUIA_Window_ID",
		"MUIA_Window_InputEvent",
		"MUIA_Window_LeftEdge",
		"MUIA_Window_Menu",
		"MUIA_Window_NoMenus",
		"MUIA_Window_Open",
		"MUIA_Window_PublicScreen",
		"MUIA_Window_RefWindow",
		"MUIA_Window_RootObject",
		"MUIA_Window_Screen",
		"MUIA_Window_ScreenTitle",
		"MUIA_Window_SizeGadget",
		"MUIA_Window_SizeRight",
		"MUIA_Window_Sleep",
		"MUIA_Window_Title",
		"MUIA_Window_TopEdge",
		"MUIA_Window_Width",
		"MUIA_Window_Window",
		"MUIV_Window_ActiveObject_None",
		"MUIV_Window_ActiveObject_Next",
		"MUIV_Window_ActiveObject_Prev",
		"MUIV_Window_AltHeight_MinMax",
		"MUIV_Window_AltHeight_Visible",
		"MUIV_Window_AltHeight_Screen",
		"MUIV_Window_AltHeight_Scaled",
		"MUIV_Window_AltLeftEdge_Centered",
		"MUIV_Window_AltLeftEdge_Moused",
		"MUIV_Window_AltLeftEdge_NoChange",
		"MUIV_Window_AltTopEdge_Centered",
		"MUIV_Window_AltTopEdge_Moused",
		"MUIV_Window_AltTopEdge_Delta",
		"MUIV_Window_AltTopEdge_NoChange",
		"MUIV_Window_AltWidth_MinMax",
		"MUIV_Window_AltWidth_Visible",
		"MUIV_Window_AltWidth_Screen",
		"MUIV_Window_AltWidth_Scaled",
		"MUIV_Window_Height_MinMax",
		"MUIV_Window_Height_Visible",
		"MUIV_Window_Height_Screen",
		"MUIV_Window_Height_Scaled",
		"MUIV_Window_Height_Default",
		"MUIV_Window_LeftEdge_Centered",
		"MUIV_Window_LeftEdge_Moused",
		"MUIV_Window_Menu_NoMenu",
		"MUIV_Window_TopEdge_Centered",
		"MUIV_Window_TopEdge_Moused",
		"MUIV_Window_TopEdge_Delta",
		"MUIV_Window_Width_MinMax",
		"MUIV_Window_Width_Visible",
		"MUIV_Window_Width_Screen",
		"MUIV_Window_Width_Scaled",
		"MUIV_Window_Width_Default",
		"MUIC_Area",
		"MUIM_AskMinMax",
		"MUIM_Cleanup",
		"MUIM_Draw",
		"MUIM_HandleInput",
		"MUIM_Hide",
		"MUIM_Setup",
		"MUIM_Show",
		"MUIA_ApplicationObject",
		"MUIA_Background",
		"MUIA_BottomEdge",
		"MUIA_ControlChar",
		"MUIA_Disabled",
		"MUIA_ExportID",
		"MUIA_FixHeight",
		"MUIA_FixHeightTxt",
		"MUIA_FixWidth",
		"MUIA_FixWidthTxt",
		"MUIA_Font",
		"MUIA_Frame",
		"MUIA_FramePhantomHoriz",
		"MUIA_FrameTitle",
		"MUIA_Height",
		"MUIA_HorizWeight",
		"MUIA_InnerBottom",
		"MUIA_InnerLeft",
		"MUIA_InnerRight",
		"MUIA_InnerTop",
		"MUIA_InputMode",
		"MUIA_LeftEdge",
		"MUIA_Pressed",
		"MUIA_RightEdge",
		"MUIA_Selected",
		"MUIA_ShowMe",
		"MUIA_ShowSelState",
		"MUIA_Timer",
		"MUIA_TopEdge",
		"MUIA_VertWeight",
		"MUIA_Weight",
		"MUIA_Width",
		"MUIA_Window",
		"MUIA_WindowObject",
		"MUIV_Font_Inherit",
		"MUIV_Font_Normal",
		"MUIV_Font_List",
		"MUIV_Font_Tiny",
		"MUIV_Font_Fixed",
		"MUIV_Font_Title",
		"MUIV_Frame_None",
		"MUIV_Frame_Button",
		"MUIV_Frame_ImageButton",
		"MUIV_Frame_Text",
		"MUIV_Frame_String",
		"MUIV_Frame_ReadList",
		"MUIV_Frame_InputList",
		"MUIV_Frame_Prop",
		"MUIV_Frame_Gauge",
		"MUIV_Frame_Group",
		"MUIV_Frame_PopUp",
		"MUIV_Frame_Virtual",
		"MUIV_Frame_Slider",
		"MUIV_Frame_Count",
		"MUIV_InputMode_None",
		"MUIV_InputMode_RelVerify",
		"MUIV_InputMode_Immediate",
		"MUIV_InputMode_Toggle",
		"MUIC_Rectangle",
		"MUIA_Rectangle_HBar",
		"MUIA_Rectangle_VBar",
		"MUIC_Image",
		"MUIA_Image_FontMatch",
		"MUIA_Image_FontMatchHeight",
		"MUIA_Image_FontMatchWidth",
		"MUIA_Image_FreeHoriz",
		"MUIA_Image_FreeVert",
		"MUIA_Image_OldImage",
		"MUIA_Image_Spec",
		"MUIA_Image_State",
		"MUIC_Text",
		"MUIA_Text_Contents",
		"MUIA_Text_HiChar",
		"MUIA_Text_PreParse",
		"MUIA_Text_SetMax",
		"MUIA_Text_SetMin",
		"MUIC_String",
		"MUIA_String_Accept",
		"MUIA_String_Acknowledge",
		"MUIA_String_AttachedList",
		"MUIA_String_BufferPos",
		"MUIA_String_Contents",
		"MUIA_String_DisplayPos",
		"MUIA_String_EditHook",
		"MUIA_String_Format",
		"MUIA_String_Integer",
		"MUIA_String_MaxLen",
		"MUIA_String_Reject",
		"MUIA_String_Secret",
		"MUIV_String_Format_Left",
		"MUIV_String_Format_Center",
		"MUIV_String_Format_Right",
		"MUIC_Prop",
		"MUIA_Prop_Entries",
		"MUIA_Prop_First",
		"MUIA_Prop_Horiz",
		"MUIA_Prop_Slider",
		"MUIA_Prop_Visible",
		"MUIC_Gauge",
		"MUIA_Gauge_Current",
		"MUIA_Gauge_Divide",
		"MUIA_Gauge_Horiz",
		"MUIA_Gauge_InfoText",
		"MUIA_Gauge_Max",
		"MUIC_Scale",
		"MUIA_Scale_Horiz",
		"MUIC_Boopsi",
		"MUIA_Boopsi_Class",
		"MUIA_Boopsi_ClassID",
		"MUIA_Boopsi_MaxHeight",
		"MUIA_Boopsi_MaxWidth",
		"MUIA_Boopsi_MinHeight",
		"MUIA_Boopsi_MinWidth",
		"MUIA_Boopsi_Object",
		"MUIA_Boopsi_Remember",
		"MUIA_Boopsi_TagDrawInfo",
		"MUIA_Boopsi_TagScreen",
		"MUIA_Boopsi_TagWindow",
		"MUIC_Colorfield",
		"MUIA_Colorfield_Blue",
		"MUIA_Colorfield_Green",
		"MUIA_Colorfield_Pen",
		"MUIA_Colorfield_Red",
		"MUIA_Colorfield_RGB",
		"MUIC_List",
		"MUIM_List_Clear",
		"MUIM_List_Exchange",
		"MUIM_List_GetEntry",
		"MUIM_List_Insert",
		"MUIM_List_InsertSingle",
		"MUIM_List_Jump",
		"MUIM_List_NextSelected",
		"MUIM_List_Redraw",
		"MUIM_List_Remove",
		"MUIM_List_Select",
		"MUIM_List_Sort",
		"MUIA_List_Active",
		"MUIA_List_AdjustHeight",
		"MUIA_List_AdjustWidth",
		"MUIA_List_CompareHook",
		"MUIA_List_ConstructHook",
		"MUIA_List_DestructHook",
		"MUIA_List_DisplayHook",
		"MUIA_List_Entries",
		"MUIA_List_First",
		"MUIA_List_Format",
		"MUIA_List_MultiTestHook",
		"MUIA_List_Quiet",
		"MUIA_List_SourceArray",
		"MUIA_List_Title",
		"MUIA_List_Visible",
		"MUIV_List_Active_Off",
		"MUIV_List_Active_Top",
		"MUIV_List_Active_Bottom",
		"MUIV_List_Active_Up",
		"MUIV_List_Active_Down",
		"MUIV_List_Active_PageUp",
		"MUIV_List_Active_PageDown",
		"MUIV_List_ConstructHook_String",
		"MUIV_List_CopyHook_String",
		"MUIV_List_CursorType_None",
		"MUIV_List_CursorType_Bar",
		"MUIV_List_CursorType_Rect",
		"MUIV_List_DestructHook_String",
		"MUIC_Floattext",
		"MUIA_Floattext_Justify",
		"MUIA_Floattext_SkipChars",
		"MUIA_Floattext_TabSize",
		"MUIA_Floattext_Text",
		"MUIC_Volumelist",
		"MUIC_Scrmodelist",
		"MUIC_Dirlist",
		"MUIM_Dirlist_ReRead",
		"MUIA_Dirlist_AcceptPattern",
		"MUIA_Dirlist_Directory",
		"MUIA_Dirlist_DrawersOnly",
		"MUIA_Dirlist_FilesOnly",
		"MUIA_Dirlist_FilterDrawers",
		"MUIA_Dirlist_FilterHook",
		"MUIA_Dirlist_MultiSelDirs",
		"MUIA_Dirlist_NumBytes",
		"MUIA_Dirlist_NumDrawers",
		"MUIA_Dirlist_NumFiles",
		"MUIA_Dirlist_Path",
		"MUIA_Dirlist_RejectIcons",
		"MUIA_Dirlist_RejectPattern",
		"MUIA_Dirlist_SortDirs",
		"MUIA_Dirlist_SortHighLow",
		"MUIA_Dirlist_SortType",
		"MUIA_Dirlist_Status",
		"MUIV_Dirlist_SortDirs_First",
		"MUIV_Dirlist_SortDirs_Last",
		"MUIV_Dirlist_SortDirs_Mix",
		"MUIV_Dirlist_SortType_Name",
		"MUIV_Dirlist_SortType_Date",
		"MUIV_Dirlist_SortType_Size",
		"MUIV_Dirlist_Status_Invalid",
		"MUIV_Dirlist_Status_Reading",
		"MUIV_Dirlist_Status_Valid",
		"MUIC_Group",
		"MUIA_Group_ActivePage",
		"MUIA_Group_Child",
		"MUIA_Group_Columns",
		"MUIA_Group_Horiz",
		"MUIA_Group_HorizSpacing",
		"MUIA_Group_PageMode",
		"MUIA_Group_Rows",
		"MUIA_Group_SameHeight",
		"MUIA_Group_SameSize",
		"MUIA_Group_SameWidth",
		"MUIA_Group_Spacing",
		"MUIA_Group_VertSpacing",
		"MUIC_Register",
		"MUIA_Register_Frame",
		"MUIA_Register_Titles",
		"MUIC_Virtgroup",
		"MUIA_Virtgroup_Height",
		"MUIA_Virtgroup_Left",
		"MUIA_Virtgroup_Top",
		"MUIA_Virtgroup_Width",
		"MUIC_Scrollgroup",
		"MUIA_Scrollgroup_Contents",
		"MUIC_Scrollbar",
		"MUIC_Listview",
		"MUIA_Listview_ClickColumn",
		"MUIA_Listview_DefClickColumn",
		"MUIA_Listview_DoubleClick",
		"MUIA_Listview_Input",
		"MUIA_Listview_List",
		"MUIA_Listview_MultiSelect",
		"MUIA_Listview_SelectChange",
		"MUIV_Listview_MultiSelect_None",
		"MUIV_Listview_MultiSelect_Default",
		"MUIV_Listview_MultiSelect_Shifted",
		"MUIV_Listview_MultiSelect_Always",
		"MUIC_Radio",
		"MUIA_Radio_Active",
		"MUIA_Radio_Entries",
		"MUIC_Cycle",
		"MUIA_Cycle_Active",
		"MUIA_Cycle_Entries",
		"MUIV_Cycle_Active_Next",
		"MUIV_Cycle_Active_Prev",
		"MUIC_Slider",
		"MUIA_Slider_Level",
		"MUIA_Slider_Max",
		"MUIA_Slider_Min",
		"MUIA_Slider_Quiet",
		"MUIA_Slider_Reverse",
		"MUIC_Coloradjust",
		"MUIA_Coloradjust_Blue",
		"MUIA_Coloradjust_Green",
		"MUIA_Coloradjust_ModeID",
		"MUIA_Coloradjust_Red",
		"MUIA_Coloradjust_RGB",
		"MUIC_Palette",
		"MUIA_Palette_Entries",
		"MUIA_Palette_Groupable",
		"MUIA_Palette_Names",
		"MUIC_Colorpanel",
		"MUIC_Popstring",
		"MUIM_Popstring_Close",
		"MUIM_Popstring_Open",
		"MUIA_Popstring_Button",
		"MUIA_Popstring_CloseHook",
		"MUIA_Popstring_OpenHook",
		"MUIA_Popstring_String",
		"MUIA_Popstring_Toggle",
		"MUIC_Popobject",
		"MUIA_Popobject_Follow",
		"MUIA_Popobject_Light",
		"MUIA_Popobject_Object",
		"MUIA_Popobject_ObjStrHook",
		"MUIA_Popobject_StrObjHook",
		"MUIA_Popobject_Volatile",
		"MUIC_Popasl",
		"MUIA_Popasl_Active",
		"MUIA_Popasl_StartHook",
		"MUIA_Popasl_StopHook",
		"MUIA_Popasl_Type",
		"MUI_MAXMAX",
		"MADF_DRAWOBJECT",
		"MADF_DRAWUPDATE",
		"MPEN_SHINE",
		"MPEN_HALFSHINE",
		"MPEN_BACKGROUND",
		"MPEN_HALFSHADOW",
		"MPEN_SHADOW",
		"MPEN_TEXT",
		"MPEN_FILL",
		"MPEN_ACTIVEOBJ",
		"MPEN_COUNT",
		"muiNotifyData",
		"muiAreaData",
		"muiGlobalInfo",
		"muiRenderInfo",
		"_app",
		"_win",
		"_dri",
		"_window",
		"_screen",
		"_rp",
		"_left",
		"_top",
		"_width",
		"_height",
		"_right",
		"_bottom",
		"_addleft",
		"_addtop",
		"_subwidth",
		"_subheight",
		"_mleft",
		"_mtop",
		"_mwidth",
		"_mheight",
		"_mright",
		"_mbottom",
		"_font",
		"_flags",
		"MAKE_ID",
		"ETKeyButton",
		"DoMethod",
		"MUIO_Label",
		"MUIO_Button",
		"MUIO_Checkmark",
		"MUIO_Cycle",
		"MUIO_Radio",
		"MUIO_Slider",
		"MUIO_String",
		"MUIO_PopButton",
		"MUIO_HSpace",
		"MUIO_VSpace",
		"MUIO_HBar",
		"MUIO_VBar",
		"MUIO_MenustripNM",
		"MUIO_Menuitem",
		"MUIO_BarTitle",
		"MUIO_Label_SingleFrame",
		"MUIO_Label_DoubleFrame",
		"MUIO_Label_LeftAligned",
		"MUII_PopupBack",
		"MUIV_NotTriggerValue",
		"MenustripObject",
		"MenuObject",
		"MenuObjectT",
		"MenuitemObject",
		"BitmapObject",
		"BodychunkObject",
		"PoplistObject",
		"MUIM_FindUData",
		"MUIM_GetUData",
		"MUIM_SetUData",
		"MUIC_Family",
		"MUIM_Family_AddHead",
		"MUIM_Family_AddTail",
		"MUIM_Family_Insert",
		"MUIM_Family_Remove",
		"MUIM_Family_Sort",
		"MUIM_Family_Transfer",
		"MUIA_Family_Child",
		"MUIC_Menustrip",
		"MUIA_Menustrip_Enabled",
		"MUIC_Menu",
		"MUIA_Menu_Enabled",
		"MUIA_Menu_Title",
		"MUIC_Menuitem",
		"MUIA_Menuitem_Checked",
		"MUIA_Menuitem_Checkit",
		"MUIA_Menuitem_Enabled",
		"MUIA_Menuitem_Exclude",
		"MUIA_Menuitem_Shortcut",
		"MUIA_Menuitem_Title",
		"MUIA_Menuitem_Toggle",
		"MUIA_Menuitem_Trigger",
		"MUIA_Application_ForceQuit",
		"MUIA_Application_HelpFile",
		"MUIA_Application_Menustrip",
		"MUIA_Window_FancyDrawing",
		"MUIA_Window_MenuAction",
		"MUIA_Window_Menustrip",
		"MUIV_Font_Big",
		"MUIC_Bitmap",
		"MUIA_Bitmap_Bitmap",
		"MUIA_Bitmap_Height",
		"MUIA_Bitmap_MappingTable",
		"MUIA_Bitmap_SourceColors",
		"MUIA_Bitmap_Transparent",
		"MUIA_Bitmap_Width",
		"MUIC_Bodychunk",
		"MUIA_Bodychunk_Body",
		"MUIA_Bodychunk_Compression",
		"MUIA_Bodychunk_Depth",
		"MUIA_Bodychunk_Masking",
		"MUIC_Poplist",
		"MUIA_Poplist_Array",
		"muiUserData",
		"MUI_MakeObject",
		"NM_BARLABEL"
	};

#endif