#include "compte.h"
#include <QDebug>
#include "connexion.h"

#include <QDebug>
#include "connexion.h"

Compte::Compte()
{
id=0;
password="";
asq="";
nom="";
}

Compte::Compte(QString password,QString asq ,int id, QString nom)
{
    this->id=id;
    this->password=password;
    this->asq=asq;
    this->nom=nom;

}

QString Compte::get_password(){return password;}
QString Compte::get_asq(){return asq;}
int Compte::get_id(){return id;}
QString Compte::get_nom(){return nom;}


bool Compte::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("INSERT INTO compte ( PASSWORD, ASQ ,ID, NOM) "
                        "VALUES (:password, :asq,:id, :nom)");
    query.bindValue(":id", res);
    query.bindValue(":password", password);
    query.bindValue(":asq",asq);
    query.bindValue(":nom",nom);

    return  query.exec();



}

QSqlQueryModel * Compte::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from compte");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Mot de passe"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("En tant que "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));

    return model;
}

bool Compte::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from compte where ID = :id ");
    query.bindValue(":id",res);
    return   query.exec();
}


bool Compte:: recherche(int id)
{
    QSqlQuery query;
    query.prepare("select * from compte where id=:id");
    query.bindValue(":id",id);
    return query.exec() ;
}


bool Compte :: modifier()
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("UPDATE compte SET password=:modifPassword, asq=:modifAsq, nom=:modifNom WHERE id =:modifId");
    query.bindValue(":modifId",res);
    query.bindValue(":modifPassword",password);
    query.bindValue(":modifAsq",asq);
    query.bindValue(":modifNom",nom);

    return query.exec();
}


QSqlQueryModel * Compte::tri_compte()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from compte order by id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Mot de passe"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("En tant que "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));
        return model;
}

