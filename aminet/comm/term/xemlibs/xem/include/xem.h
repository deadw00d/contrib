/**
*
*   Include file for External Emulator Handling
*
**/
/*
*   The structure
*/
struct XEM_IO {
	struct Window  *xem_window;	/* window to display text */
	struct TextFont *xem_font;		/* default font (like topaz.8) */
	APTR		xem_console;			/* PRIVATE DATA..!! */
	ULONG		xem_obsolete1;			/* */
	ULONG		*xem_signal;			/* signal mask generated by xem */
	UWORD		xem_screendepth;		/* count of bitplanes */
	UWORD		xem_pad;					/* just a pad */

/* Read a few bytes from the serial port (including timeouts) */
long		(*xem_sread)(char *buffer, long size, long timeout);

/* Send a few bytes across the serial line. */
	long		(*xem_swrite)(char *buffer, long size);

/* Release the contents of all serial buffers. */
	long		(*xem_sflush)(void);

/* Send a break signal across the serial line. */
	long		(*xem_sbreak)(void);

/* Check how many characters are present in the serial buffer. */
	long		(*xem_squery)(void);

/* Restart serial read activity. */
	void		(*xem_sstart)(void);

/* Stop serial read activity. */
	long		(*xem_sstop)(void);

/* Beep the terminal display. */
	void		(*xem_tbeep)(long ntimes, long delay);

/*	Get a string from the user. */
	long		(*xem_tgets)(char *prompt, char *buffer, long buflen);

/*	 Provide a polished user interface to set the emulator options. */
	long		(*xem_toptions)(long n, struct xem_option *opt[]);

/* Dispatch a macro key call. */
	long		(*xem_process_macrokeys)(struct XEmulatorMacroKey *key);
};


#define XEM_LIBRARY_VERSION 4


/*
*   The xemo_option structure
*/
struct xem_option {
	UBYTE	*xemo_description;	/* description of the option                  */
	ULONG	xemo_type;				/* type of option                             */
   UBYTE	*xemo_value;			/* pointer to a buffer with the current value */
   ULONG	xemo_length;			/* buffer size                                */
};
/*
*   Valid values for xemo_type are:
*/
#define XEMO_BOOLEAN 1L         /* xemo_value is "yes", "no", "on" or "off"   */
#define XEMO_LONG    2L         /* xemo_value is string representing a number */
#define XEMO_STRING  3L         /* xemo_value is a string                     */
#define XEMO_HEADER  4L         /* xemo_value is ignored                      */
#define XEMO_COMMAND 5L         /* xemo_value is ignored                      */
#define XEMO_COMMPAR 6L         /* xemo_value contains command parameters     */


struct XEmulatorMacroKey {
	struct MinNode xmk_Node;
	UWORD	xmk_Qualifier;
	UBYTE	xmk_Type;
	UBYTE	xmk_Code;
	APTR	xmk_UserData;
};

/*----- Qualifiers for XMK_QUALIFIER -----*/
#define XMKQ_NONE      0
#define XMKQ_SHIFT     1
#define XMKQ_ALTERNATE 2
#define XMKQ_CONTROL   3

/*----- Types for XMK_TYPE -----*/
#define XMKT_IGNORE 1
#define XMKT_RAWKEY 2
#define XMKT_COOKED 3


/*----- Types for XEmulatorInfo -----*/
#define XEMI_CURSOR_POSITION		1	/* home = 1,1 */
#define XEMI_CONSOLE_DIMENSIONS	2	/* */

/*----- Macros for XEmulatorInfo -----*/
		/* for use in xem.library */
#define XEMI_CREATE_POSITION(ypos,xpos) ((ypos << 16) + (xpos & 0xffff))
#define XEMI_CREATE_DIMENSIONS(columns,lines) ((columns << 16) + (lines & 0xffff))

		/* for use in comm-proggy */
#define XEMI_EXTRACT_Y_POSITION(result) (result >> 16)
#define XEMI_EXTRACT_X_POSITION(result) (result & 0xffff)

#define XEMI_EXTRACT_COLUMNS(result)	(result >> 16)
#define XEMI_EXTRACT_LINES(result)		(result & 0xffff)


/*----- Modes for XEmulatorPreferences -----*/
#define XEM_PREFS_RESET	0	/* Reset to builtin defaults	*/
#define XEM_PREFS_LOAD	1	/* Load preferences from file	*/
#define XEM_PREFS_SAVE	2	/* Save preferences to file	*/


struct XEmulatorHostData {
	UBYTE *Source;			/* Pointer to the source buffer */
	UBYTE *Destination;	/* Pointer to the destination buffer */
	BOOL InESC;			/* INTER-EMULATOR PRIVATE DATA..  DO NOT TOUCH 'EM..!! */
	BOOL InCSI;			/* INTER-EMULATOR PRIVATE DATA..  DO NOT TOUCH 'EM..!! */
};

