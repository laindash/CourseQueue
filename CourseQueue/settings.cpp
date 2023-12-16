#include "coursequeue.h"
#include <qmessagebox.h>


Settings::Settings(QWidget *parent) : QMainWindow(parent), _uiSettings(new Ui::Settings) {
	_uiSettings->setupUi(this);
	setWindowIcon(QIcon(":/CourseQueue/img/settingsBtnPic.png"));
	_greenCircle = ":/CourseQueue/img/greenCircle.png";
	_yellowCircle = ":/CourseQueue/img/yellowCircle.png";
	_purpleCircle = ":/CourseQueue/img/purpleCircle.png";
	_redCircle = ":/CourseQueue/img/redCircle.png";
}

Settings::~Settings() {
	delete _uiSettings;
}

QString Settings::getCW1(Student& new_student) {
	if (_uiSettings->cw1Ready->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->cw1Corrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->cw1FirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->cw1NotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}

QString Settings::getCW1_REP(Student& new_student) {
	if (_uiSettings->cw1RepReady->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->cw1RepCorrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->cw1RepFirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->cw1RepNotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}

QString Settings::getCW2(Student& new_student) {
	if (_uiSettings->cw2Ready->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->cw2Corrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->cw2FirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->cw2NotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}

QString Settings::getCW2_REP(Student& new_student) {
	if (_uiSettings->cw2RepReady->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->cw2RepCorrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->cw2RepFirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->cw2RepNotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}

QString Settings::getCW3(Student& new_student) {
	if (_uiSettings->cw3Ready->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->cw3Corrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->cw3FirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->cw3NotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}

QString Settings::getCW3_REP(Student& new_student) {
	if (_uiSettings->cw3RepReady->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->cw3RepCorrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->cw3RepFirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->cw3RepNotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}

QString Settings::getCW4(Student& new_student) {
	if (_uiSettings->cw4Ready->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->cw4Corrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->cw4FirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->cw4NotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}

QString Settings::getCW4_REP(Student& new_student) {
	if (_uiSettings->cw4RepReady->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->cw4RepCorrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->cw4RepFirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->cw4RepNotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}

QString Settings::getDescription(Student& new_student) {
	if (_uiSettings->descReady->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->descCorrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->descFirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->descNotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}

QString Settings::getTask(Student& new_student) {
	if (_uiSettings->taskReady->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->taskCorrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->taskFirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->taskNotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}

QString Settings::getCourseWork(Student& new_student) {
	if (_uiSettings->courseReady->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->courseCorrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->courseFirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->courseNotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}

QString Settings::getNote(Student& new_student) {
	if (_uiSettings->noteReady->isChecked()) {
		new_student._workPoints += 3;
		return _greenCircle;
	}
	else if (_uiSettings->noteCorrections->isChecked()) {
		new_student._workPoints += 2;
		return _yellowCircle;
	}
	else if (_uiSettings->noteFirstTime->isChecked()) {
		new_student._workPoints++;
		return _purpleCircle;
	}
	else if (_uiSettings->noteNotReady->isChecked()) {
		return _redCircle;
	}
	else {
		isAllMarked = false;
	}
	return QString();
}


void Settings::clearValues() {
	_uiSettings->cw1Ready->setAutoExclusive(false);
	_uiSettings->cw2Ready->setAutoExclusive(false);
	_uiSettings->cw3Ready->setAutoExclusive(false);
	_uiSettings->cw4Ready->setAutoExclusive(false);
	_uiSettings->cw1Corrections->setAutoExclusive(false);
	_uiSettings->cw2Corrections->setAutoExclusive(false);
	_uiSettings->cw3Corrections->setAutoExclusive(false);
	_uiSettings->cw4Corrections->setAutoExclusive(false);
	_uiSettings->cw1FirstTime->setAutoExclusive(false);
	_uiSettings->cw2FirstTime->setAutoExclusive(false);
	_uiSettings->cw3FirstTime->setAutoExclusive(false);
	_uiSettings->cw4FirstTime->setAutoExclusive(false);
	_uiSettings->cw1NotReady->setAutoExclusive(false);
	_uiSettings->cw2NotReady->setAutoExclusive(false);
	_uiSettings->cw3NotReady->setAutoExclusive(false);
	_uiSettings->cw4NotReady->setAutoExclusive(false);

	_uiSettings->cw1RepReady->setAutoExclusive(false);
	_uiSettings->cw2RepReady->setAutoExclusive(false);
	_uiSettings->cw3RepReady->setAutoExclusive(false);
	_uiSettings->cw4RepReady->setAutoExclusive(false);
	_uiSettings->cw1RepCorrections->setAutoExclusive(false);
	_uiSettings->cw2RepCorrections->setAutoExclusive(false);
	_uiSettings->cw3RepCorrections->setAutoExclusive(false);
	_uiSettings->cw4RepCorrections->setAutoExclusive(false);
	_uiSettings->cw1RepFirstTime->setAutoExclusive(false);
	_uiSettings->cw2RepFirstTime->setAutoExclusive(false);
	_uiSettings->cw3RepFirstTime->setAutoExclusive(false);
	_uiSettings->cw4RepFirstTime->setAutoExclusive(false);
	_uiSettings->cw1RepNotReady->setAutoExclusive(false);
	_uiSettings->cw2RepNotReady->setAutoExclusive(false);
	_uiSettings->cw3RepNotReady->setAutoExclusive(false);
	_uiSettings->cw4RepNotReady->setAutoExclusive(false);

	_uiSettings->descReady->setAutoExclusive(false);
	_uiSettings->taskReady->setAutoExclusive(false);
	_uiSettings->courseReady->setAutoExclusive(false);
	_uiSettings->noteReady->setAutoExclusive(false);
	_uiSettings->descCorrections->setAutoExclusive(false);
	_uiSettings->taskCorrections->setAutoExclusive(false);
	_uiSettings->courseCorrections->setAutoExclusive(false);
	_uiSettings->noteCorrections->setAutoExclusive(false);
	_uiSettings->descFirstTime->setAutoExclusive(false);
	_uiSettings->taskFirstTime->setAutoExclusive(false);
	_uiSettings->courseFirstTime->setAutoExclusive(false);
	_uiSettings->noteFirstTime->setAutoExclusive(false);
	_uiSettings->descNotReady->setAutoExclusive(false);
	_uiSettings->taskNotReady->setAutoExclusive(false);
	_uiSettings->courseNotReady->setAutoExclusive(false);
	_uiSettings->noteNotReady->setAutoExclusive(false);

	_uiSettings->cw1Ready->setChecked(false);
	_uiSettings->cw2Ready->setChecked(false);
	_uiSettings->cw3Ready->setChecked(false);
	_uiSettings->cw4Ready->setChecked(false);
	_uiSettings->cw1Corrections->setChecked(false);
	_uiSettings->cw2Corrections->setChecked(false);
	_uiSettings->cw3Corrections->setChecked(false);
	_uiSettings->cw4Corrections->setChecked(false);
	_uiSettings->cw1FirstTime->setChecked(false);
	_uiSettings->cw2FirstTime->setChecked(false);
	_uiSettings->cw3FirstTime->setChecked(false);
	_uiSettings->cw4FirstTime->setChecked(false);
	_uiSettings->cw1NotReady->setChecked(false);
	_uiSettings->cw2NotReady->setChecked(false);
	_uiSettings->cw3NotReady->setChecked(false);
	_uiSettings->cw4NotReady->setChecked(false);

	_uiSettings->cw1RepReady->setChecked(false);
	_uiSettings->cw2RepReady->setChecked(false);
	_uiSettings->cw3RepReady->setChecked(false);
	_uiSettings->cw4RepReady->setChecked(false);
	_uiSettings->cw1RepCorrections->setChecked(false);
	_uiSettings->cw2RepCorrections->setChecked(false);
	_uiSettings->cw3RepCorrections->setChecked(false);
	_uiSettings->cw4RepCorrections->setChecked(false);
	_uiSettings->cw1RepFirstTime->setChecked(false);
	_uiSettings->cw2RepFirstTime->setChecked(false);
	_uiSettings->cw3RepFirstTime->setChecked(false);
	_uiSettings->cw4RepFirstTime->setChecked(false);
	_uiSettings->cw1RepNotReady->setChecked(false);
	_uiSettings->cw2RepNotReady->setChecked(false);
	_uiSettings->cw3RepNotReady->setChecked(false);
	_uiSettings->cw4RepNotReady->setChecked(false);

	_uiSettings->descReady->setChecked(false);
	_uiSettings->taskReady->setChecked(false);
	_uiSettings->courseReady->setChecked(false);
	_uiSettings->noteReady->setChecked(false);
	_uiSettings->descCorrections->setChecked(false);
	_uiSettings->taskCorrections->setChecked(false);
	_uiSettings->courseCorrections->setChecked(false);
	_uiSettings->noteCorrections->setChecked(false);
	_uiSettings->descFirstTime->setChecked(false);
	_uiSettings->taskFirstTime->setChecked(false);
	_uiSettings->courseFirstTime->setChecked(false);
	_uiSettings->noteFirstTime->setChecked(false);
	_uiSettings->descNotReady->setChecked(false);
	_uiSettings->taskNotReady->setChecked(false);
	_uiSettings->courseNotReady->setChecked(false);
	_uiSettings->noteNotReady->setChecked(false);

	_uiSettings->cw1Ready->setAutoExclusive(true);
	_uiSettings->cw2Ready->setAutoExclusive(true);
	_uiSettings->cw3Ready->setAutoExclusive(true);
	_uiSettings->cw4Ready->setAutoExclusive(true);
	_uiSettings->cw1Corrections->setAutoExclusive(true);
	_uiSettings->cw2Corrections->setAutoExclusive(true);
	_uiSettings->cw3Corrections->setAutoExclusive(true);
	_uiSettings->cw4Corrections->setAutoExclusive(true);
	_uiSettings->cw1FirstTime->setAutoExclusive(true);
	_uiSettings->cw2FirstTime->setAutoExclusive(true);
	_uiSettings->cw3FirstTime->setAutoExclusive(true);
	_uiSettings->cw4FirstTime->setAutoExclusive(true);
	_uiSettings->cw1NotReady->setAutoExclusive(true);
	_uiSettings->cw2NotReady->setAutoExclusive(true);
	_uiSettings->cw3NotReady->setAutoExclusive(true);
	_uiSettings->cw4NotReady->setAutoExclusive(true);

	_uiSettings->cw1RepReady->setAutoExclusive(true);
	_uiSettings->cw2RepReady->setAutoExclusive(true);
	_uiSettings->cw3RepReady->setAutoExclusive(true);
	_uiSettings->cw4RepReady->setAutoExclusive(true);
	_uiSettings->cw1RepCorrections->setAutoExclusive(true);
	_uiSettings->cw2RepCorrections->setAutoExclusive(true);
	_uiSettings->cw3RepCorrections->setAutoExclusive(true);
	_uiSettings->cw4RepCorrections->setAutoExclusive(true);
	_uiSettings->cw1RepFirstTime->setAutoExclusive(true);
	_uiSettings->cw2RepFirstTime->setAutoExclusive(true);
	_uiSettings->cw3RepFirstTime->setAutoExclusive(true);
	_uiSettings->cw4RepFirstTime->setAutoExclusive(true);
	_uiSettings->cw1RepNotReady->setAutoExclusive(true);
	_uiSettings->cw2RepNotReady->setAutoExclusive(true);
	_uiSettings->cw3RepNotReady->setAutoExclusive(true);
	_uiSettings->cw4RepNotReady->setAutoExclusive(true);

	_uiSettings->descReady->setAutoExclusive(true);
	_uiSettings->taskReady->setAutoExclusive(true);
	_uiSettings->courseReady->setAutoExclusive(true);
	_uiSettings->noteReady->setAutoExclusive(true);
	_uiSettings->descCorrections->setAutoExclusive(true);
	_uiSettings->taskCorrections->setAutoExclusive(true);
	_uiSettings->courseCorrections->setAutoExclusive(true);
	_uiSettings->noteCorrections->setAutoExclusive(true);
	_uiSettings->descFirstTime->setAutoExclusive(true);
	_uiSettings->taskFirstTime->setAutoExclusive(true);
	_uiSettings->courseFirstTime->setAutoExclusive(true);
	_uiSettings->noteFirstTime->setAutoExclusive(true);
	_uiSettings->descNotReady->setAutoExclusive(true);
	_uiSettings->taskNotReady->setAutoExclusive(true);
	_uiSettings->courseNotReady->setAutoExclusive(true);
	_uiSettings->noteNotReady->setAutoExclusive(true);
}