#include "ticket.h"
#include <QSqlQuery>
#include <QVariant>

Ticket:: Ticket()
{ id=0;

    zone="";
    type="";
}
Ticket:: Ticket(int id,QDate datee,QString zone,QString type)
{
    this->id=id;
    this->datee=datee;
    this->zone=zone;
    this->type=type;
}


bool Ticket ::ajouter()
{QSqlQuery query;
    QString res=QString::number(id);


    query.prepare("INSERT INTO Ticket (ID,DATEE,ZONE,TYPE) "
                        "VALUES (:id, :datee, :zone, :type)");
    query.bindValue(":id",id);
    query.bindValue(":datee",datee);
    query.bindValue(":zone", zone);
    query.bindValue(":type", type);

    return    query.exec();
}


QSqlQueryModel * Ticket ::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM Ticket");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Zone"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
    return model;
}

bool Ticket::supprimer(int iid)
{
    QSqlQuery query;
    QString res= QString::number(iid);

    query.prepare("Delete from ticket where ID = :id ");
    query.bindValue(":id",res);
    return   query.exec();
}


bool Ticket::modifier(int iid,QDate date,QString zone,QString type)
{
    QSqlQuery query;
 QString res=QString::number(iid);
 query.prepare("Update Ticket set ID = :id, DATEE = :datee , ZONE = :zone , TYPE = :type   WHERE ID = :id ");
 query.bindValue(":id",res);
 query.bindValue(":datee",date);
 query.bindValue(":zone",zone);
 query.bindValue(":type",type);
    return query.exec();

}

/*QSqlQueryModel *Ticket::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Ticket order by DATEE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ZONE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));




        return model;
}*/
QSqlQueryModel* Ticket::tri()
{
    QSqlQuery * q1 = new  QSqlQuery ();
        QSqlQueryModel * model = new  QSqlQueryModel ();
        q1->prepare("SELECT * FROM Ticket ORDER BY DATEE ");
        q1->exec();
        model->setQuery(*q1);
        return model;

}

QSqlQueryModel * Ticket ::rechercher(QString zone)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM Ticket WHERE zone LIKE'"+zone+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Zone"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
    return model;
}
QSqlQueryModel * Ticket ::rechercherId(QString id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM Ticket WHERE ID='"+id+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Zone"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type"));
    return model;
}
Ticket Ticket::getTicketById(QString id)
{

    QSqlQuery qry ;
    Ticket ticket;
    qry.prepare("Select ID,DATEE,ZONE,TYPE FROM Ticket WHERE ID='"+id+"'");
    qry.exec() ;
    while (qry.next()) {
       ticket.set_id(qry.value(0).toInt());
       ticket.set_datee(qry.value(1).toDate());
       ticket.set_zone(qry.value(2).toString());
       ticket.set_type(qry.value(3).toString());

    }
    return ticket;
}
