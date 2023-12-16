#include <filesystem>
#include <fstream>
#include "students.h"
#include <QString>
#include <QTextStream>
#include <QFile>

void getStudentsFromFile(std::vector<Student>& students) {
    QFile file("students_table.txt");
    students.clear();

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        while (!in.atEnd()) {
            Student new_student;
            new_student.setNameFF(in);
            new_student.setGroupFF(in);
            new_student.setPasswordFF(in);
            new_student.setCW1FF(in);
            new_student.setCW1RepFF(in);
            new_student.setCW2FF(in);
            new_student.setCW2RepFF(in);
            new_student.setCW3FF(in);
            new_student.setCW3RepFF(in);
            new_student.setCW4FF(in);
            new_student.setCW4RepFF(in);
            new_student.setDescriptionFF(in);
            new_student.setTaskFF(in);
            new_student.setCourseFF(in);
            new_student.setNoteFF(in);
            new_student.setWorkPoints(in);

            students.push_back(new_student);
        }

        file.close();
    }
}

void changeInfoInDB(std::vector<Student>& students) {
    QFile file("students_table.txt");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&file);

        for (std::vector<Student>::iterator it = students.begin(); it != students.end(); it++)
        {
            QString
                outName = (it)->getName(),
                outGroup = (it)->getGroup(),
                outPassword = (it)->getPassword(),
                outCW1 = (it)->getCW1(),
                outCW1Rep = (it)->getCW1Rep(),
                outCW2 = (it)->getCW2(),
                outCW2Rep = (it)->getCW2Rep(),
                outCW3 = (it)->getCW3(),
                outCW3Rep = (it)->getCW3Rep(),
                outCW4 = (it)->getCW4(),
                outCW4Rep = (it)->getCW4Rep(),
                outDesc = (it)->getDescription(),
                outTask = (it)->getTask(),
                outCourse = (it)->getCourse(),
                outNote = (it)->getNote();

             int outWorkPoints = (it)->getWorkPoints();

            if (it != students.begin())
                out << '\n';
            out << outName << '\n';
            out << outGroup << '\n';
            out << outPassword << '\n';
            out << outCW1 << '\n';
            out << outCW1Rep << '\n';
            out << outCW2 << '\n';
            out << outCW2Rep << '\n';
            out << outCW3 << '\n';
            out << outCW3Rep << '\n';
            out << outCW4 << '\n';
            out << outCW4Rep << '\n';
            out << outDesc << '\n';
            out << outTask << '\n';
            out << outCourse << '\n';
            out << outNote << '\n';
            out << outWorkPoints;
        }

        file.close();
    }
}
