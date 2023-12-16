#ifndef COURSEQUEUE_H
#define COURSEQUEUE_H

#include <QtWidgets/QMainWindow>
#include "ui_coursequeue.h"
#include "settings.h"
#include "students.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CourseQueueClass; };
QT_END_NAMESPACE

class CourseQueue : public QMainWindow {
    Q_OBJECT

public:
    CourseQueue(QWidget *parent = nullptr);
    ~CourseQueue();
    std::vector<Student> _students{};
    void clearTableWidget();
    void sort(std::vector<Student>& students);
    void changeTable();
    
private slots:
    void settingsBtn_clicked();
    void plusBtn_clicked();
    void minusBtn_clicked();

private:
    Ui::CourseQueueClass *_ui{};
    Settings *_dialog{};
}; 

bool compareStudentsByWorkPoints(const Student& a, const Student& b);

#endif