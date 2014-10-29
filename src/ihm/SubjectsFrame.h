#ifndef SUBJECTSFRAME_H
#define SUBJECTSFRAME_H

#include <QWidget>

namespace Ui {
class SubjectsFrame;
}

class SubjectsFrame : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectsFrame(QWidget *parent = 0);
    ~SubjectsFrame();

private slots:
    void on_dataDirectory_textChanged(const QString &arg1);

    void on_browserButton_clicked();

private:
    Ui::SubjectsFrame *ui;
};

#endif // SUBJECTSFRAME_H
