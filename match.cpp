#include "match.h"
#include <QSqlQuery>
#include <QVariant>
#include <QTime>


Match:: Match()
{ idd=0;

    nb=0;
    type_m="";
    equipe_ad="";
    lieu="";
}
Match:: Match(int idd,QDate dated,int nb,QString type_m,QTime heure_m,QString adv,QString lieu)
{
    this->idd=idd;
    this->dated=dated;
    this->nb=nb;
    this->type_m=type_m;
    this->heure_m=heure_m;
    this->equipe_ad=adv;
    this->lieu=lieu;
}


bool Match ::ajouter()
{QSqlQuery query;
    QString res=QString::number(idd);


    query.prepare("INSERT INTO Match (IDD,DATED,NB_B,TYPE_M,HEURE_M,EQUIPE_AD,LIEU) "
                        "VALUES (:idd, :dated,  :nb, :type_m, :heure_m, :equipe_ad, :lieu)");
    query.bindValue(":idd",idd);
    query.bindValue(":dated",dated);
    query.bindValue(":nb",nb);
    query.bindValue(":type_m",type_m);
    query.bindValue(":heure_m",heure_m);
    query.bindValue(":equipe_ad",equipe_ad);
    query.bindValue(":lieu",lieu);

    return    query.exec();
}


QSqlQueryModel * Match ::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM Match");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Datedebut"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nb_ticket"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type_match"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("heure_m"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("equipe_ad"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("lieu"));
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


bool Match::modifier(int iid,QDate d,int n,QString typee,QTime h,QString adv,QString lieuu)////////////////////
{
    QSqlQuery query;
 QString res=QString::number(iid);
 query.prepare("Update Match set IDD = :idd, DATED = :dated , TYPE_M = :type_m , HEURE_M = :heure_m , EQUIPE_AD = :equipe_ad , LIEU = :lieu  WHERE IDD = :idd ");
 query.bindValue(":idd",res);//iid
 query.bindValue(":dated",d);
 query.bindValue(":nb",n);
 query.bindValue(":type_m",typee);
 query.bindValue(":heure_m",h);
 query.bindValue(":equipe_ad",adv);
 query.bindValue(":lieu",lieuu);
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
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nb_tickets"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type_match"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("heure_m"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("equipe_ad"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("lieu"));
    return model;
}

Match Match::getMatchById(QString id)
{

    QSqlQuery qry ;
    Match match;
    qry.prepare("Select IDD,DATED,NB_B,TYPE_M,HEURE_M,EQUIPE_AD,LIEU FROM Match WHERE IDD='"+id+"'");
    qry.exec() ;
    while (qry.next()) {
       match.set_idd(qry.value(0).toInt());
       match.set_Date(qry.value(1).toDate());
       match.set_nb(qry.value(2).toInt());
       match.set_type_m(qry.value(3).toString());
       match.set_heure_m(qry.value(4).toTime());
       match.set_equipe_ad(qry.value(5).toString());
       match.set_lieu(qry.value(6).toString());
    }
    return match;
}
