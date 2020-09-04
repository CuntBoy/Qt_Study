#include <QString>
#include <QDebug>
#include <QByteArray>

int main(void)
{
#if 0
    // QString to QByteArray
    QString str("123中");
//    QByteArray byte = str.toLatin1();   //ascll 编解码
    QByteArray byte = str.toUtf8();

    qDebug()<<byte<<endl;

#endif
    QByteArray byte = "\x31\x32\x33";
    QString str(byte);
//    qDebug()<<str<<endl;

    /* QByteArray to char * */
    qDebug()<<byte.data()<<endl;




    /*QString to char *, 不能直接转  先转成 QByteArray,然后在char * */
    qDebug()<<str.toLatin1().data()<<endl;


    return 0;
}


int QByteArray_test(void)
{
    QByteArray byte("中");
    QString str("中\x12");
    qDebug()<<byte<<endl;
    //    qDebug()<<byte.toHex()<<endl;    // 字符数组到字符串
    //    qDebug()<<QByteArray::fromHex("e4b8ad")<<endl; // 字符串到字符数组

    qDebug()<<byte.data()<<endl;

    //    qDebug()<<str<<endl;






    return 0;
}

int Qstring_test(void)
{
    QString str("helloworld");
    //    qDebug()<<str<<endl;
    int age = 20;
    bool sex = true;
    QString name("dameng");

    str = QString("xmg %1 sex %2 name %3").arg(age).arg(sex).arg(name);
    qDebug()<<str<<endl;

    str = QString::asprintf("age %d name %s",age,name.toLatin1().data());
    qDebug()<<str<<endl;


    return 0;
}







