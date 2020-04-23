#ifndef MATCH_H
#define MATCH_H
#include<QString>
#include<QSqlQueryModel>
#include <QDate>


class Match
{ private:
    int idd;
    QDate dated;
    QDate datef;
    int nb;


public:
    Match();
    Match(int,QDate,QDate,int);
    QDate get_dated();
    QDate get_datef();
    int get_idd();
    int get_nb;


    void set_idd(int);
     void set_nb(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier(int);
      QSqlQueryModel* tri();
QSqlQueryModel * rechercherId(QString id);

};


#endif // MATCH_H
