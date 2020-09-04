#include <QSqlDatabase>
#include <QSqlQuery>   //语句

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("************");
    db.setDatabaseName("testDb");
    QSqlQuery sql(db);

    sql.value("id");  //获取数据

    if(db.open())
        // 成功

    sql.next();


    db.close();
    return 0;
}
