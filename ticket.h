#ifndef TICKET_H
#define TICKET_H
#include<QString>
#include<QSqlQueryModel>
#include <QDate>
#include <QSqlQuery> //sécurité (injection)
#include<QTableView>



class Ticket
{ private:
    int id;
    QDate datee;
    QString zone;
    QString type;

public:
    Ticket();
    Ticket(int,QDate,QString,QString);
    QDate get_datee();
    int get_id();
     QString get_zone();
     QString get_type();

     void set_id(int val){id =val ;}
     void set_datee(QDate val){ datee = val ;}
     void set_zone(QString val){zone = val ;};
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier(int);
     QSqlQueryModel* tri();
QSqlQueryModel * rechercher(QString zone);
QSqlQueryModel * rechercherId(QString id);

};

#endif // TICKET_H
