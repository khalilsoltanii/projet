#include "reclamation.h"
#include <QDebug>
#include <QMessageBox>
#include<QDate>
#include <QSqlQuery>
#include<QTableView>
#include<QString>
reclamation::reclamation()
{
idd=0;

ass="-";

reclm="--";
nom="";


}
reclamation::reclamation(int idd,QString ass,QDate datee,QString reclm,QString nom,QString mail)
{
  this->idd=idd;


  this->ass=ass;
 this->datee=datee;

    this->reclm=reclm;
    this->nom=nom;
    this->mail=mail;

}


bool reclamation::ajouter()
{
QSqlQuery query;
QString res=QString::number(idd);

query.prepare("INSERT INTO reclamation (IDD,ASS,DATEE,RECLM,NOM,MAIL) "
                    "VALUES (:idd, :ass, :datee, :reclm , :nom, :mail)");
query.bindValue(":idd",res);
query.bindValue(":ass",ass);
query.bindValue(":datee",datee);
query.bindValue(":reclm", reclm);
query.bindValue(":nom", nom);
query.bindValue(":mail", mail);


return    query.exec();
}

QSqlQueryModel * reclamation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel(); //tekhou el view mel table ou takra menha

model->setQuery("select * from reclamation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("En tant que"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("reclamation"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));


    return model;
}

bool reclamation::supprimer(int idd)
{
QSqlQuery query;

query.prepare("Delete from reclamation where IDD = :idd ");
query.bindValue(":idd", idd);
return    query.exec();
}



bool reclamation::modifier()
  {  QSqlQuery query;
    QString res=QString::number(idd);

    query.prepare("update reclamation set ass=:ass ,datee=:datee ,reclm=:reclm ,nom=:nom, mail=:mail  where idd = :idd");
    query.bindValue(":idd",res);
    query.bindValue(":ass",ass);
    query.bindValue(":datee",datee);
    query.bindValue(":reclm", reclm);
    query.bindValue(":nom", nom);
    query.bindValue(":mail", mail);
    return query.exec();
}


QSqlQueryModel * reclamation::tri_reclm()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from reclamation order by idd");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("En tant que"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("reclamation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("mail"));
        return model;
}
