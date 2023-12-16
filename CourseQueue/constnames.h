#ifndef CONSTNAMES_H
#define CONSTNAMES_H
#include <QString>

enum COLUMNS {
	NAME,
	GROUP,
	CW1,
	CW1_REP,
	CW2,
	CW2_REP,
	CW3,
	CW3_REP,
	CW4,
	CW4_REP,
	DESCRIPTION,
	TASK,
	COURSEWORK,
	NOTE
};

enum STATUS {
	READY,
	CORRECTIONS,
	FIRST_TIME,
	NOT_READY
};

const QString SUDO = "sudosapr";


#endif
