#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QTableView>

class conge
{
public:
    conge();
    conge(QString c,QString dateD,QString dateF,int idA,QString etat)
{
        this->cause=c;
        this->date_debut=dateD;
        this->date_fin=dateF;
        this->id_agent=idA;
        this->etat=etat;
}
    int get_id();
    QString get_cause();
    int get_id_agent();
    QString get_etat();
    QString get_date_debut();
    QString get_date_fin();
    bool ajouter();
    QSqlQueryModel * afficher(QString ch,QString ch1);
    bool supprimer(int);
    bool modifierRefuse(int);
    bool modifierAccepte (int);
    QSqlQueryModel *afficherE(QString);
    int getIdA(QString cin);
    bool check(QDate d, int id);
    conge getConge(int id);
    bool modifier(int id);
private:
    int id_agent,id;
    QString cause,date_debut,date_fin,etat ;

};

#endif // CONGE_H
