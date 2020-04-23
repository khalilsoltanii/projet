#include "match.h"
#include <QSqlQuery>
#include <QVariant>

Match:: Match()
{ idd=0;

    nb=0;
}
Match:: Match(int idd,QDate dated,QDate datef,int nb)
{
    this->idd=idd;
    this->dated=dated;
    this->datef=datef;
    this->nb=nb;
}


bool Match ::ajouter()
{QSqlQuery query;
    QString res=QString::number(idd);


    query.prepare("INSERT INTO Match (IDD,DATED,DATEF,NB_B) "
                        "VALUES (:idd, :dated, :datef, :nb)");
    query.bindValue(":idd",idd);
    query.bindValue(":dated",dated);
    query.bindValue(":datef",datef);
     query.bindValue(":nb",nb);

    return    query.exec();
}


QSqlQueryModel * Match ::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM Match");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Datedebut"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Datefin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nb_buts"));
    return model;
}

bool Match::supprimer(int iid)
{
    QSqlQuery query;
    QString res= QString::number(iid);

    query.prepare("Delete from Match where IDD = :idd ");
    query.bindValue(":idd",res);
    return   query.exec();
}


bool Match::modifier(int iid)
{
    QSqlQuery query;
 QString res=QString::number(iid);
 query.prepare("Update Match set IDD = :idd, DATED = :dated , DATEF = :datef   WHERE IDD = :idd ");
 query.bindValue(":idd",res);
 query.bindValue(":dated",dated);
 query.bindValue(":datef",datef);
 query.bindValue(":nb",nb);
    return query.exec();

}
QSqlQueryModel* Match::tri()
{
    QSqlQuery * q1 = new  QSqlQuery ();
        QSqlQueryModel * model = new  QSqlQueryModel ();
        q1->prepare("SELECT * FROM Match ORDER BY NB_B ");
        q1->exec();
        model->setQuery(*q1);
        return model;

}
QSqlQueryModel * Match ::rechercherId(QString id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM Match WHERE IDD='"+id+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Datedebut"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Datefin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nb_buts"));
    return model;
}
