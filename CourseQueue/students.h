#ifndef STUDENTS_H
#define STUDENTS_H

#include <QString>
#include <QTextStream>
#include <vector>
#include <string>

class Student {
	QString 
		_name{}, _group{}, _password{},
		_cw1{}, _cw2{}, _cw3{}, _cw4{},
		_cw1Rep{}, _cw2Rep{}, _cw3Rep{}, _cw4Rep{},
		_desc{}, _task{}, _course{}, _note{};

public:
	int _workPoints{};
	int getWorkPoints() const { return _workPoints; }
	int setWorkPoints(QTextStream& input) { return _workPoints = input.readLine().toInt(); }

	QString getName() { return _name; };
	QString getGroup() { return _group; };
	QString getPassword() { return _password; };
	QString getCW1() { return _cw1; };
	QString getCW2() { return _cw2; };
	QString getCW3() { return _cw3; };
	QString getCW4() { return _cw4; };
	QString getCW1Rep() { return _cw1Rep; };
	QString getCW2Rep() { return _cw2Rep; };
	QString getCW3Rep() { return _cw3Rep; };
	QString getCW4Rep() { return _cw4Rep; };
	QString getDescription() { return _desc; };
	QString getTask() { return _task; };
	QString getCourse() { return _course; };
	QString getNote() { return _note; };


	QString setName(QString name) { return _name = name; };
	QString setGroup(QString group) { return _group = group; };
	QString setPassword(QString password) { return _password = password; };
	QString setCW1(QString cw1) { return _cw1 = cw1; };
	QString setCW2(QString cw2) { return _cw2 = cw2; };
	QString setCW3(QString cw3) { return _cw3 = cw3; };
	QString setCW4(QString cw4) { return _cw4 = cw4; };
	QString setCW1Rep(QString cw1Rep) { return _cw1Rep = cw1Rep; };
	QString setCW2Rep(QString cw2Rep) { return _cw2Rep = cw2Rep; };
	QString setCW3Rep(QString cw3Rep) { return _cw3Rep = cw3Rep; };
	QString setCW4Rep(QString cw4Rep) { return _cw4Rep = cw4Rep; };
	QString setDescription(QString desc) { return _desc = desc; };
	QString setTask(QString task) { return _task = task; };
	QString setCourse(QString course) { return _course = course; };
	QString setNote(QString note) { return _note = note; };


	QString setNameFF(QTextStream &input) { return _name = input.readLine(); };
	QString setGroupFF(QTextStream& input) { return _group = input.readLine(); };
	QString setPasswordFF(QTextStream& input) { return _password = input.readLine(); };
	QString setCW1FF(QTextStream& input) { return _cw1 = input.readLine(); };
	QString setCW2FF(QTextStream& input) { return _cw2 = input.readLine(); };
	QString setCW3FF(QTextStream& input) { return _cw3 = input.readLine(); };
	QString setCW4FF(QTextStream& input) { return _cw4 = input.readLine(); };
	QString setCW1RepFF(QTextStream& input) { return _cw1Rep = input.readLine(); };
	QString setCW2RepFF(QTextStream& input) { return _cw2Rep = input.readLine(); };
	QString setCW3RepFF(QTextStream& input) { return _cw3Rep = input.readLine(); };
	QString setCW4RepFF(QTextStream& input) { return _cw4Rep = input.readLine(); };
	QString setDescriptionFF(QTextStream& input) { return _desc = input.readLine(); };
	QString setTaskFF(QTextStream& input) { return _task = input.readLine(); };
	QString setCourseFF(QTextStream& input) { return _course = input.readLine(); };
	QString setNoteFF(QTextStream& input) { return _note = input.readLine(); };
};

#endif