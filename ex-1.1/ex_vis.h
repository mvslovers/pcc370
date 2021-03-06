/*
 * Ex - a text editor
 * Bill Joy UCB June 1977
 */

/* #define	CTRL(c)	(c & 037) */
#define	FS	/* CTRL(\\\\) */ 0x1c
#define	NL	/* CTRL(j) */ 0x0a
#define	CR	/* CTRL(m) */ 0x0d

#define	INF	30000

#define	DELETE	0177
#define	ESCAPE	033

#ifdef VISUAL
extern char	visual;
extern char	*cursor, *wcursor, *tcursor;
extern int	dir;

extern int	vlast;

#define vputc(c)	putc(c, &obuf)

#define	TUBELINES	24
#define	TUBECOLS	160
#define	TUBESIZE	1920

extern char	vliny[TUBELINES + 2];
extern int	vcline, vcnt;

#define	ESCAPE	033

extern char	vch, *vtube[TUBELINES], *vtube0;

extern int	VLINES, VCOLUMNS;

#define	vlast	vliny[vcnt]

extern char vmoving;
extern char vmovcol;

#endif

extern int	vdelete(), (*Outchar_)(), qcount(), vputchar();

#ifdef VISUAL

extern char	vholdmove;

#define	beep	obeep

extern int	vcntcol;

extern char	holdat, splitw, hadup, *nextic;

#define	VNONE	0
#define	VCHNG	1
#define	VMANY	2

extern char	vundkind, *vutmp;
extern int	vulines[TUBELINES], vylines[TUBELINES], *vresaddr;
extern int	vrestore(), vrescnt, vresCNT_, vdelcnt, vrescurs, vyancnt;
extern char	wdkind;
extern int	vSCROLL_;

extern int	(*Pline_)(), numbline(), normline();
#define	BUFSIZE	128

extern char	Xhadcnt;
extern int	Xcnt;

extern char	lasthad;
extern int	lastcnt;

extern char	lastcmd[5], *lastcp, workcmd[5];
extern char	DEL[BUFSIZE], INS[BUFSIZE];

#define	OVERBUF	CR

extern char	*vglobp;

extern char	HADUP_, HADZERO;
extern int	CDCNT;

extern int	ZERO_;

extern char	*ogcursor;
#endif
