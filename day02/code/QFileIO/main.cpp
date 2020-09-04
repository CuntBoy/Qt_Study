#include <QFile>
#include <QDebug>
#include <QDataStream>
int main(void)
{
    QByteArray buf("hello world \n");
    QFile file("E:/Study/My_C++/Qt_study/day02/test_file/a.txt");
    file.open(QIODevice::ReadWrite|QIODevice::Text);  //|QIODevice::Truncate |QIODevice::Append
//    buf = file.read(5);      读指定字节
//    buf = file.readLine(11); 读一行
//    qDebug()<<buf<<endl;
//    buf = file.readLine(11);
//    qDebug()<<buf<<endl;

    //buf = file.readAll();   // 全部读取
    //qDebug()<<buf<<endl;

/*
*   file.write(buf);
*/

    QDataStream stream(&file);
    int num = 100;
    QString str("hello");
    stream <<num<<str;
    stream >> num >> str;
    qDebug()<<str<<num<<endl;

    file.close();

    return 0;
}
