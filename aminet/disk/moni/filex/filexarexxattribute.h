struct Attr
{
	UBYTE *name;
	BYTE typ;		/* 0=String,1=Number,2=Bool */
};

struct AttrObject
{
	UBYTE *name;
	struct Attr *attr;
};

enum { SCREEN_APPATTR, VERSION_APPATTR, REGNUMBER_APPATTR,
REGNAME_APPATTR, AREXX_APPATTR, MAXUNDOMEMSIZE_APPATTR,
MAXUNDOLEVEL_APPATTR, ALTJUMP_APPATTR, SCROLLBORDER_APPATTR,
CLIPBOARDUNIT_APPATTR, COMMANDSHELLWINDOW_APPATTR,
COMMANDWINDOW_APPATTR, OVERWRITE_APPATTR, USEASL_APPATTR,
PRIORITY_APPATTR, SEARCHSTRING_APPATTR, REPLACESTRING_APPATTR,
STRINGSEARCH_APPATTR, CASESENSITIVSEARCH_APPATTR, WILDSEARCH_APPATTR,
FILLSTRING_APPATTR, STRINGFILL_APPATTR };

struct Attr applicationattributes[] = {
	"SCREEN",0,
	"VERSION",0,
	"REGNUMBER",1,
	"REGNAME",0,
	"AREXX",0,
	"MAXUNDOMEMSIZE",1,
	"MAXUNDOLEVEL",1,
	"ALTJUMP",1,
	"SCROLLBORDER",1,
	"CLIPBOARDUNIT",1,
	"COMMANDSHELLWINDOW",0,
	"COMMANDWINDOW",0,
	"OVERWRITE",2,
	"USEASL",2,
	"PRIORITY",1,
	"SEARCHSTRING",0,
	"REPLACESTRING",0,
	"STRINGSEARCH",2,
	"CASESENSITIVSEARCH",2,
	"WILDSEARCH",2,
	"FILLSTRING",0,
	"STRINGFILL",2,
	0,0
};


enum { FULLNAME_FILEATTR, PATH_FILEATTR, NAME_FILEATTR, CHANGES_FILEATTR,
FILELEN_FILEATTR, MEMPOS_FILEATTR, VIEWCOUNT_FILEATTR, VIEWS_FILEATTR };

struct Attr fileattributes[] = {
	"FULLNAME",0,
	"PATH",0,
	"NAME",0,
	"CHANGES",1,
	"FILELEN",1,
	"MEMPOS",1,
	"VIEWCOUNT",1,
	"VIEWS",0,
	0,0
};


enum {LEFT_WNDATTR,TOP_WNDATTR,WIDTH_WNDATTR,HEIGHT_WNDATTR,TITLE_WNDATTR,MIN_WIDTH_WNDATTR,MIN_HEIGHT_WNDATTR,MAX_WIDTH_WNDATTR,MAX_HEIGHT_WNDATTR,VIEWCOUNT_WNDATTR,VIEWS_WNDATTR};

struct Attr windowattributes[] = {
	"LEFT",1,
	"TOP",1,
	"WIDTH",1,
	"HEIGHT",1,
	"TITLE",0,
	"MIN_WIDTH",1,
	"MIN_HEIGHT",1,
	"MAX_WIDTH",1,
	"MAX_HEIGHT",1,
	"VIEWCOUNT",1,
	"VIEWS",0,
	0,0
};

enum { LINES_VIEWATTR, BYTESPERLINE_VIEWATTR, DISPLAYTYP_VIEWATTR,
DISPLAY_VIEWATTR, DISPLAYSPACES_VIEWATTR, CURSORPOS_VIEWATTR,
MARKPOS_VIEWATTR, EDITASCII_VIEWATTR, MARK_VIEWATTR, FILE_VIEWATTR,
WINDOW_VIEWATTR };

struct Attr viewattributes[] = {
	"LINES",1,
	"BYTESPERLINE",1,
	"DISPLAYTYP",1,
	"DISPLAY",1,
	"DISPLAYSPACES",1,
	"CURSORPOS",1,
	"MARKPOS",1,
	"EDITASCII",2,
	"MARK",2,
	"FILE",1,
	"WINDOW",1,
	0,0
};

enum {APPLICATION_ATTRNUM,WINDOW_ATTRNUM,WINDOWS_ATTRNUM,FILE_ATTRNUM,FILES_ATTRNUM,VIEW_ATTRNUM};

struct AttrObject attributeobjects[] = {
	"APPLICATION", applicationattributes,
	"WINDOW", windowattributes,
	"WINDOWS", 0,
	"FILE", fileattributes,
	"FILES",0,
	"VIEW", viewattributes,
	0,0
};

/*
ID Angabe bei VIEWS.
*/