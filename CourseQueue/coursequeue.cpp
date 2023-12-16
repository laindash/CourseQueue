#include "coursequeue.h"
#include "constnames.h"
#include <qmessagebox.h>
#include "filework.h"


CourseQueue::CourseQueue(QWidget *parent) : QMainWindow(parent), _ui(new Ui::CourseQueueClass()) {
    _ui->setupUi(this);
    setWindowIcon(QIcon(":/CourseQueue/img/queueIcon.png"));
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setWindowFlags(windowFlags() & ~(Qt::WindowFullscreenButtonHint | Qt::WindowMaximizeButtonHint));


    connect(_ui->settingsBtn, &QPushButton::clicked, this, &CourseQueue::settingsBtn_clicked);
    connect(_ui->plusBtn, &QPushButton::clicked, this, &CourseQueue::plusBtn_clicked);
    connect(_ui->minusBtn, &QPushButton::clicked, this, &CourseQueue::minusBtn_clicked);

    _ui->studentsTable->setColumnWidth(NAME, 470);
    _ui->studentsTable->setColumnWidth(GROUP, 80);
    _ui->studentsTable->setColumnWidth(CW1, 50);
    _ui->studentsTable->setColumnWidth(CW1_REP, 70);
    _ui->studentsTable->setColumnWidth(CW2, 50);
    _ui->studentsTable->setColumnWidth(CW2_REP, 70);
    _ui->studentsTable->setColumnWidth(CW3, 50);
    _ui->studentsTable->setColumnWidth(CW3_REP, 70);
    _ui->studentsTable->setColumnWidth(CW4, 50);
    _ui->studentsTable->setColumnWidth(CW4_REP, 70);
    _ui->studentsTable->setColumnWidth(DESCRIPTION, 100);
    _ui->studentsTable->setColumnWidth(TASK, 100);
    _ui->studentsTable->setColumnWidth(COURSEWORK, 100);
    _ui->studentsTable->setColumnWidth(NOTE, 100);
    _ui->studentsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    _ui->studentsTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    _ui->semesterChoice->setEnabled(false);
    _ui->passLine->setEchoMode(QLineEdit::Password);

    _dialog = new Settings(this);
    QPixmap pixSettings(":/CourseQueue/img/settingsBtnPic.png");
    _ui->settingsBtn->setIcon(pixSettings);
    _ui->settingsBtn->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    _ui->settingsBtn->setIconSize(_ui->settingsBtn->size());
    setWindowState(windowState() & ~Qt::WindowFullScreen);
    setWindowFlags(windowFlags() & ~Qt::WindowFullscreenButtonHint);
    changeTable();
}

CourseQueue::~CourseQueue() {
    delete _ui;
}

void CourseQueue::settingsBtn_clicked() {
    _dialog->setWindowFlags(_dialog->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    _dialog->setWindowFlags(_dialog->windowFlags() & ~(Qt::WindowFullscreenButtonHint | Qt::WindowMaximizeButtonHint));
    _dialog->setWindowModality(Qt::ApplicationModal);
    //_dialog->setAttribute(Qt::WA_DeleteOnClose); //clear memory
    _dialog->show();
}

void CourseQueue::plusBtn_clicked() {
    bool allGood = true;
    _dialog->isAllMarked = true;
    Student new_student{};

    QString
        _name = _ui->nameLine->text(),
        _group = _ui->groupLine->text(),
        _password = _ui->passLine->text();
    QString
        _cw1Pix(_dialog->getCW1(new_student)),
        _cw1_repPix(_dialog->getCW1_REP(new_student)),
        _cw2Pix(_dialog->getCW2(new_student)),
        _cw2_repPix(_dialog->getCW2_REP(new_student)),
        _cw3Pix(_dialog->getCW3(new_student)),
        _cw3_repPix(_dialog->getCW3_REP(new_student)),
        _cw4Pix(_dialog->getCW4(new_student)),
        _cw4_repPix(_dialog->getCW4_REP(new_student)),
        _descriptionPix(_dialog->getDescription(new_student)),
        _taskPix(_dialog->getTask(new_student)),
        _courseworkPix(_dialog->getCourseWork(new_student)),
        _notePix(_dialog->getNote(new_student));

    
    if (_name.isEmpty()) {
        allGood = false;
        QMessageBox::critical(this, "Error", "Full name not specified!");
    }
    if (_group.isEmpty()) {
        allGood = false;
        QMessageBox::critical(this, "Error", "Group not specified!");
    }
    if (_password.isEmpty()) {
        allGood = false;
        QMessageBox::critical(this, "Error", "Password not specified!");
    }
    if (_dialog->isAllMarked == false) {
        allGood = false;
        QMessageBox::warning(this, "Warning", "Not all work statuses are marked!");
    }

    if (allGood) {
        new_student.setName(_name);
        new_student.setGroup(_group);
        new_student.setPassword(_password);
        new_student.setCW1(_cw1Pix);
        new_student.setCW1Rep(_cw1_repPix);
        new_student.setCW2(_cw2Pix);
        new_student.setCW2Rep(_cw2_repPix);
        new_student.setCW3(_cw3Pix);
        new_student.setCW3Rep(_cw3_repPix);
        new_student.setCW4(_cw4Pix);
        new_student.setCW4Rep(_cw4_repPix);
        new_student.setDescription(_descriptionPix);
        new_student.setTask(_taskPix);
        new_student.setCourse(_courseworkPix);
        new_student.setNote(_notePix);
        _students.push_back(new_student);

        _ui->nameLine->clear(),
        _ui->groupLine->clear(),
        _ui->passLine->clear();

        changeInfoInDB(_students);
        changeTable();
    }
}

void CourseQueue::clearTableWidget() {
    _ui->studentsTable->clearContents();

    while (_ui->studentsTable->rowCount() > 0) {
        _ui->studentsTable->removeRow(0);
    }

    for (int row = 0; row < _ui->studentsTable->rowCount(); ++row) {
        QTableWidgetItem* item = new QTableWidgetItem(QString::number(row + 1));
        _ui->studentsTable->setItem(row, 0, item);
    }
}



void CourseQueue::changeTable() {
    clearTableWidget();
    int row{};
    getStudentsFromFile(_students);
    sort(_students);
    for (std::vector<Student>::iterator it = _students.begin(); it != _students.end(); it++) {
        int rowC = _ui->studentsTable->rowCount(); // number of row
        _ui->studentsTable->insertRow(rowC); // insert new row

        _ui->studentsTable->setItem(row, NAME, new QTableWidgetItem(it->getName()));

        QTableWidgetItem* group = new QTableWidgetItem(it->getGroup());
        group->setTextAlignment(Qt::AlignCenter);
        _ui->studentsTable->setItem(row, GROUP, group);
        QPixmap
            _cw1Pix(it->getCW1()),
            _cw1_repPix(it->getCW1Rep()),
            _cw2Pix(it->getCW2()),
            _cw2_repPix(it->getCW2Rep()),
            _cw3Pix(it->getCW3()),
            _cw3_repPix(it->getCW3Rep()),
            _cw4Pix(it->getCW4()),
            _cw4_repPix(it->getCW4Rep()),
            _descriptionPix(it->getDescription()),
            _taskPix(it->getTask()),
            _courseworkPix(it->getCourse()),
            _notePix(it->getNote());

        QLabel
            * _cw1 = new QLabel(),
            * _cw1_rep = new QLabel(),
            * _cw2 = new QLabel(),
            * _cw2_rep = new QLabel(),
            * _cw3 = new QLabel(),
            * _cw3_rep = new QLabel(),
            * _cw4 = new QLabel(),
            * _cw4_rep = new QLabel(),
            * _description = new QLabel(),
            * _task = new QLabel(),
            * _coursework = new QLabel(),
            * _note = new QLabel();

        _cw1->setAlignment(Qt::AlignCenter);
        _cw1_rep->setAlignment(Qt::AlignCenter);
        _cw2->setAlignment(Qt::AlignCenter);
        _cw2_rep->setAlignment(Qt::AlignCenter);
        _cw3->setAlignment(Qt::AlignCenter);
        _cw3_rep->setAlignment(Qt::AlignCenter);
        _cw4->setAlignment(Qt::AlignCenter);
        _cw4_rep->setAlignment(Qt::AlignCenter);
        _description->setAlignment(Qt::AlignCenter);
        _task->setAlignment(Qt::AlignCenter);
        _coursework->setAlignment(Qt::AlignCenter);
        _note->setAlignment(Qt::AlignCenter);


        _cw1Pix = _cw1Pix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _cw1->setPixmap(_cw1Pix);
        _ui->studentsTable->setCellWidget(row, CW1, _cw1);

        _cw1_repPix = _cw1_repPix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _cw1_rep->setPixmap(_cw1_repPix);
        _ui->studentsTable->setCellWidget(row, CW1_REP, _cw1_rep);

        _cw2Pix = _cw2Pix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _cw2->setPixmap(_cw2Pix);
        _ui->studentsTable->setCellWidget(row, CW2, _cw2);

        _cw2_repPix = _cw2_repPix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _cw2_rep->setPixmap(_cw2_repPix);
        _ui->studentsTable->setCellWidget(row, CW2_REP, _cw2_rep);

        _cw3Pix = _cw3Pix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _cw3->setPixmap(_cw3Pix);
        _ui->studentsTable->setCellWidget(row, CW3, _cw3);

        _cw3_repPix = _cw3_repPix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _cw3_rep->setPixmap(_cw3_repPix);
        _ui->studentsTable->setCellWidget(row, CW3_REP, _cw3_rep);

        _cw4Pix = _cw4Pix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _cw4->setPixmap(_cw4Pix);
        _ui->studentsTable->setCellWidget(row, CW4, _cw4);

        _cw4_repPix = _cw4_repPix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _cw4_rep->setPixmap(_cw4_repPix);
        _ui->studentsTable->setCellWidget(row, CW4_REP, _cw4_rep);

        _descriptionPix = _descriptionPix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _description->setPixmap(_descriptionPix);
        _ui->studentsTable->setCellWidget(row, DESCRIPTION, _description);

        _taskPix = _taskPix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _task->setPixmap(_taskPix);
        _ui->studentsTable->setCellWidget(row, TASK, _task);

        _courseworkPix = _courseworkPix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _coursework->setPixmap(_courseworkPix);
        _ui->studentsTable->setCellWidget(row, COURSEWORK, _coursework);

        _notePix = _notePix.scaled(QSize(21, 21), Qt::KeepAspectRatio);
        _note->setPixmap(_notePix);
        _ui->studentsTable->setCellWidget(row, NOTE, _note);

        row++;
        _dialog->clearValues();
    }
}

void CourseQueue::minusBtn_clicked() {
    QString enteredPassword = _ui->passLine->text();

    int selectedRow = _ui->studentsTable->currentRow();
    if (selectedRow >= 0 && selectedRow < _students.size()) {
        Student& selectedStudent = _students[selectedRow];
        QString studentPassword = selectedStudent.getPassword();

        if (enteredPassword == studentPassword || enteredPassword == "sudosapr") {
            QMessageBox::StandardButton confirmResult = QMessageBox::question(this, "Confirm", "Are you sure you want to delete this student?", QMessageBox::Yes | QMessageBox::No);
            if (confirmResult == QMessageBox::Yes) {
                _students.erase(_students.begin() + selectedRow);
                changeInfoInDB(_students);
                changeTable();
            }
        }
        else {
            QMessageBox::warning(this, "Warning", "Invalid password!");
        }
    }
    else {
        QMessageBox::warning(this, "Warning", "Please select a student to delete.");
    }
    _ui->passLine->clear();
}


bool compareStudentsByWorkPoints(const Student& a, const Student& b) {
    return a.getWorkPoints() > b.getWorkPoints();
}

void CourseQueue::sort(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), compareStudentsByWorkPoints);
}
