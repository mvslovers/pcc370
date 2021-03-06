#include "ex.h"
#ifdef VISUAL
#include "ex_tty.h"
#include "ex_vis.h"
/*
 * Ex - a text editor
 * Bill Joy UCB September 1977
 */

char	Peekkey_;

ungetkey(c)
	char c;
{

	Peekkey_ = c;
}

getkey()
{
	register char c;

	do
		c = getbr();
	while (c == 0);
	return (c);
}

peekbr()
{
	register char c;

	Peekkey_ = getbr();
	return (Peekkey_ == 0);
}

getbr()
{
	char c;

	if (Peekkey_) {
		c = Peekkey_;
		Peekkey_ = 0;
		return (c);
	}
	if (vglobp) {
		if (*vglobp)
			return (*vglobp++);
		return (ESCAPE);
	}
	flusho();
	if (read(0, &c, 1) != 1)
		error("Input read error");
	c =& 0177;
	return (c);
}

getesc()
{
	register int c;

	c = getkey();
	switch (c) {
		case DELETE:
		case FS:
			ungetkey(c);
		case ESCAPE:
			return (0);
	}
	return (c);
}

peekkey()
{

	Peekkey_ = getkey();
	return (Peekkey_);
}
#endif
