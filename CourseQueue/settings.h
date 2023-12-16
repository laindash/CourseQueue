#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtWidgets/QMainWindow>
#include <QDialog>
#include <QDialogButtonBox>
#include "ui_Settings.h"
#include <QString>
#include "students.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Settings; }
QT_END_NAMESPACE

class Settings : public QMainWindow {
	Q_OBJECT

public:
	Settings(QWidget *parent = nullptr);
	~Settings();
	
    QString getCW1(Student& new_student);
    QString getCW1_REP(Student& new_student);
    QString getCW2(Student& new_student);
    QString getCW2_REP(Student& new_student);
    QString getCW3(Student& new_student);
    QString getCW3_REP(Student& new_student);
    QString getCW4(Student& new_student);
    QString getCW4_REP(Student& new_student);
    QString getDescription(Student& new_student);
    QString getTask(Student& new_student);
    QString getCourseWork(Student& new_student);
    QString getNote(Student& new_student);
    bool isAllMarked = true;
    void clearValues();

private:
	Ui::Settings *_uiSettings{};
    QString  _greenCircle{},  _yellowCircle{},  _purpleCircle{},  _redCircle{};
};

#endif