#ifndef COMPTE_H
#define COMPTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Compte
{
public:
    Compte();
    Compte(QString,QString,int,QString);
    QString get_password();
    QString get_asq();
    int get_id();
    QString get_nom();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool  recherche(int);
    bool modifier();
    QSqlQueryModel *tri_compte();


private :
    QString password , asq, nom;
    int id;
};


#endif // COMPTE_H
