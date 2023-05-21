#ifndef DOCX_2_TXT_H
#define DOCX_2_TXT_H

#include "QtGui/private/qzipreader_p.h"

#include <QString>

class docx_2_txt
{
public:
    docx_2_txt(const QString &filename);

    bool transfer_docx_2_txt(const QString &filepath);

    inline const QString &get_err_msg() const
    {
        return err_msg;
    }

private:
    QString get_txt_filename(const QString &filepath);

private:
    QString    docx_data;
    QString    err_msg = "";
    QZipReader docx_file;
};

#endif // DOCX_2_TXT_H
