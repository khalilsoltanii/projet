#include "conge.h"
#include <QDebug>
#include "connexion.h"
#include <QSqlQuery>
#include <QDate>
conge::conge()
{ 


}

QString conge::get_cause(){return cause;}
int conge::get_id_agent(){return id_agent;}
QString conge::get_date_debut(){return date_debut;}
QString conge:: get_date_fin(){return date_fin;}

bool conge::ajouter()
{
    QSqlQuery query;
    //QString res= QString::number(id);
    query.prepare("INSERT INTO conge (cause,id_agent,date_debut,date_fin,etat)"
                  "VALUES (:cause, :id_agent, :date_debut, :date_fin,'en attente')");
    query.bindValue(":cause",cause);
    query.bindValue(":id_agent",id_agent);
    query.bindValue(":date_debut",date_debut);
    query.bindValue(":date_fin",date_fin);


    return query.exec();
}

QSqlQueryModel * conge::afficher(QString ch,QString ch1)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if (ch=="")
    {if(ch1=="Toutes les congés")
     model->setQuery("select c.id,c.cause,concat(e.nom,concat(' ',e.prenom)),c.date_debut,c.date_fin,c.etat from conge c inner join employe e on e.id=c.id_agent");
     else if(ch1=="Congés accepte")
     model->setQuery("select c.id,c.cause,concat(e.nom,concat(' ',e.prenom)),c.date_debut,c.date_fin,c.etat from conge c inner join employe e on e.id=c.id_agent where c.etat like 'accepte'");
     else if(ch1=="Congés refuse")
     model->setQuery("select c.id,c.cause,concat(e.nom,concat(' ',e.prenom)),c.date_debut,c.date_fin,c.etat from conge c inner join employe e on e.id=c.id_agent where c.etat like 'refuse'");
     else if(ch1=="Congés en attente")
     model->setQuery("select c.id,c.cause,concat(e.nom,concat(' ',e.prenom)),c.date_debut,c.date_fin,c.etat from conge c inner join employe e on e.id=c.id_agent where c.etat like 'en attente'");
    }
    else if(ch1=="Toutes les congés")
    model->setQuery("select c.id,c.cause,concat(e.nom,concat(' ',e.prenom)) as nom,c.date_debut,c.date_fin,c.etat from conge c inner join employe e on e.id=c.id_agent where (nom like'"+ch+"%' or cause like '"+ch+"%' or date_debut like '"+ch+"')");
    else if(ch1=="Congés accepte")
    model->setQuery("select c.id,c.cause,concat(e.nom,concat(' ',e.prenom)) as nom,c.date_debut,c.date_fin,c.etat from conge c inner join employe e on e.id=c.id_agent where c.etat like 'accepte' and (nom like'"+ch+"%' or cause like '"+ch+"%' or date_debut like '"+ch+"')");
    else if(ch1=="Congés refuse")
    model->setQuery("select c.id,c.cause,concat(e.nom,concat(' ',e.prenom)) as nom,c.date_debut,c.date_fin,c.etat from conge c inner join employe e on e.id=c.id_agent where c.etat like 'refuse' and (nom like'"+ch+"%' or cause like '"+ch+"%' or date_debut like '"+ch+"')");
    else if(ch1=="Congés en attente")
    model->setQuery("select c.id,c.cause,concat(e.nom,concat(' ',e.prenom)) as nom,c.date_debut,c.date_fin,c.etat from conge c inner join employe e on e.id=c.id_agent where c.etat like 'en attente' and (nom like'"+ch+"%' or cause like '"+ch+"%' or date_debut like '"+ch+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Cause"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom Agent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Debut"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Fin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat"));

    return model;
}
QSqlQueryModel * conge::afficherE(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    if(ch=="")
    model->setQuery("select id,concat(nom,concat(' ',prenom)) from employe");
    else
    model->setQuery("select id,concat(nom,concat(' ',prenom)) as nom from employe where nom like '"+ch+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Agent"));

    return model;
}
bool conge::modifierAccepte(int id)
{
    QSqlQuery query;
    //QString res= QString::number(idd);
    query.prepare("Update conge set  etat='accepte' where id= :id");
    query.bindValue(":id",id);
    return query.exec();
}
bool conge::modifierRefuse(int id)
{
    QSqlQuery query;
    //QString res= QString::number(idd);
    query.prepare("Update conge set  etat='refuse' where id= :id");
    query.bindValue(":id",id);
    return query.exec();
}
bool conge::supprimer(int id)
{
    QSqlQuery query;
    //QString res= QString::number(id);
    query.prepare("Delete from conge where id = :id ");
    query.bindValue(":id", id);
    return    query.exec();
}
int conge::getIdA(QString cin)
{
    QSqlQuery query;
    query.prepare("select id from employe where cin= :cin");
    query.bindValue(":cin",cin);
    query.exec();
    query.first();
    return query.value(0).toInt();
}
bool conge::check(QDate d,int id)
{int nb=0;
    QSqlQuery q;
    q.prepare("select * from conge where id_agent=:id and sysdate < date_debut and etat='en attente'");
    q.bindValue(":id", id);
    q.bindValue(":d",d);
    q.exec();
    while(q.next())
    {
        nb++;
    }
    if (nb==0)
      return true;
    else return false;
}

conge conge::getConge(int id)
{
    QSqlQuery q;
    q.prepare("select cause,date_debut,date_fin,id_agent,etat from conge where id=:id");
    q.bindValue(":id",id);
    q.exec();
    q.first();
    conge c(q.value(0).toString(),q.value(1).toString(),q.value(2).toString(),q.value(3).toInt(),q.value(4).toString());
    return c;
}
bool conge::modifier(int id)
{
    QSqlQuery query;
    //QString res= QString::number(idd);
    query.prepare("Update conge set id_agent= :ida, date_debut=:dd ,date_fin=:df,cause=:c where id= :id");
    query.bindValue(":id",id);
    query.bindValue(":ida",this->id_agent);
    query.bindValue(":dd",this->date_debut);
    query.bindValue(":df",this->date_fin);
    query.bindValue(":c",this->cause);

    return query.exec();
}
// last version
