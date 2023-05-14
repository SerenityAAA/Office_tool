#ifndef OFFICE_TOOL_H
#define OFFICE_TOOL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Office_tool; }
QT_END_NAMESPACE

class Office_tool : public QMainWindow
{
    Q_OBJECT

public:
    Office_tool(QWidget *parent = nullptr);
    ~Office_tool();

private:
    Ui::Office_tool *ui;
};
#endif // OFFICE_TOOL_H
