#include "office_tool.h"
#include "ui_office_tool.h"

Office_tool::Office_tool(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Office_tool)
{
    ui->setupUi(this);
}

Office_tool::~Office_tool()
{
    delete ui;
}

