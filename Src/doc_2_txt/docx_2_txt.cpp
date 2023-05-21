#include "docx_2_txt.h"

#include <QDir>
#include <QTextStream>
#include <QXmlStreamReader>

docx_2_txt::docx_2_txt(const QString &filename) : docx_file(filename)
{
    if (QZipReader::NoError != docx_file.status())
    {
        err_msg = "无法打开docx文件";
    }
}

bool docx_2_txt::transfer_docx_2_txt(const QString &filepath)
{
    if (filepath.isEmpty())
    {
        return false;
    }

    QByteArray documentXmlBytes = docx_file.fileData("word/document.xml");
    if (documentXmlBytes.isEmpty())
    {
        err_msg = "无法从docx文件中获取document.xml";
        return false;
    }

    QXmlStreamReader document(documentXmlBytes);
    while (!document.atEnd())
    {
        if (document.isStartElement())
        {
            do
            {
                if ("p" == document.name())
                {
                    if (docx_data.isEmpty())
                    {
                        break;
                    }
                    docx_data.append('\n');
                    break;
                }

                if ("t" == document.name())
                {
                    docx_data.append(document.readElementText());
                    break;
                }
            } while (0);
        }
        document.readNext();
    }
    if (document.hasError())
    {
        err_msg = document.errorString();
        return false;
    }

    QFile output(get_txt_filename(filepath));
    if (!output.open(QIODevice::WriteOnly))
    {
        err_msg = "无法打开转换后的文本文件";
        return false;
    }
    QTextStream fp(&output);
    fp.setCodec("UTF-8");
    fp << docx_data;
    output.close();

    return true;
}

QString docx_2_txt::get_txt_filename(const QString &filepath)
{
    QDir target_dir(filepath);
    if (!target_dir.exists())
    {
        target_dir.setPath("");
        if (!target_dir.mkdir(filepath))
        {
            err_msg = "无法创建txt目录";
            return QString();
        }
    }

    QString filename(QDir::fromNativeSeparators(filepath));
    if ('/' != filepath.back())
    {
        filename += '/';
    }
    filename += "AllText.txt";

    return filename;
}
