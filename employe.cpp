#include "employe.h"
#include <QSqlQuery>

employe::employe()
{
    cin="";
    nom="";
    prenom="";
    salaire="";
    gendre="";
    ville="";
    adresse="";
    image="";    
}

employe::employe(QString cin,QString nom,QString prenom,QString salaire,QString gendre,QString ville,QString adresse,QString image,QString date_ajout,int age)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->salaire=salaire;
    this->gendre=gendre;
    this->ville=ville;
    this->adresse=adresse;
    this->image=image;
    this->date_ajout=date_ajout;
    this->age=age;
}

int employe::get_id(){return id;}
QString employe::get_cin(){return cin;}
QString employe::get_nom(){return nom;}
QString employe::get_prenom(){return prenom;}
QString employe::get_salaire(){return salaire;}
QString employe::get_gendre(){return gendre;}
QString employe::get_ville(){return ville;}
QString employe::get_adresse(){return adresse;}
QString employe::get_image(){return image;}
QString employe::get_dateajout(){return date_ajout;}
int employe::get_age(){return age;}

bool employe::ajouter()
{
    QSqlQuery query;
    //QString res= QString::number(id);
    query.prepare("INSERT INTO employe (cin,nom,prenom,salaire,gendre,ville,adresse,image,date_ajout,age)"
                  "VALUES (:cin, :nom, :prenom, :salaire, :gendre, :ville, :adresse, :image,SYSDATE,:age)");
    query.bindValue(":cin",cin);
    query.bindValue(":age",age);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":salaire",salaire);
    query.bindValue(":gendre",gendre);
    query.bindValue(":ville",ville);
    query.bindValue(":adresse",adresse);
    query.bindValue(":image",image);
    return query.exec();

}

QSqlQueryModel * employe::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select cin,nom,prenom,concat(concat(adresse,' '),ville) as lieu,salaire from employe");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE"));
    return model;
}

bool employe::modifier(QString cin)
{
    QSqlQuery query;
    query.prepare("Update employe set nom = :nom , prenom = :prenom , salaire = :salaire , gendre = :gendre, ville = :ville , adresse = :adresse , image = :image,date_ajout = SYSDATE,age=:age where cin= :cin");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":salaire",salaire);
    query.bindValue(":gendre",gendre);
    query.bindValue(":ville",ville);
    query.bindValue(":adresse",adresse);
    query.bindValue(":image",image);
    query.bindValue(":age",age);
    return query.exec();

}
bool employe::supprimer(QString cin)
{
    QSqlQuery query;
    //QString res= QString::number(id);
    query.prepare("Delete from employe where cin = :cin ");
    query.bindValue(":cin", cin);
    return    query.exec();
}
QSqlQueryModel* employe::tri()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM employe ORDER BY ID");
    q->exec();
    model->setQuery(*q);
    return model;
}

QSqlQueryModel* employe::tri2()
{

    QSqlQuery * q = new  QSqlQuery ();
    QSqlQueryModel * model = new  QSqlQueryModel ();
    q->prepare("SELECT * FROM employe ORDER BY ID desc");
    q->exec();
    model->setQuery(*q);
    return model;
}
employe employe::remplirFiche(QString cin)
{
 QSqlQuery  q;
 q.prepare("SELECT cin,nom,prenom,salaire,ville,adresse,image,age,gendre FROM employe where cin=:cin");
 q.bindValue(":cin",cin);
 q.exec();
 q.first();
 employe e(q.value(0).toString(),q.value(1).toString(),q.value(2).toString(),q.value(3).toString(),q.value(8).toString(),q.value(4).toString(),q.value(5).toString(),q.value(6).toString(),"",q.value(7).toInt());
return e;
}
QString employe::getC(int id)
{
    QSqlQuery  q;
    q.prepare("SELECT cin FROM employe where id=:id");
    q.bindValue(":id",id);
    q.exec();
    q.first();
    return q.value(0).toString();
}
