#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QDateEdit>
#include <QDate>
#include <QSqlQueryModel>
#include <QTableView>

class employe
{
public:
    employe();
    employe(QString,QString,QString,QString,QString,QString,QString,QString,QString,int);
    int get_id();
    QString get_cin();
    QString get_nom();
    QString get_prenom();
    QString get_salaire();
    QString get_gendre();
    QString get_departement();
    QString get_ville();
    QString get_adresse();
    QString get_image();
    int get_idagence();
    int get_age();
    QString get_dateajout();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier (QString);
    QSqlQueryModel * recherche(QString);
    QSqlQueryModel* tri();
    QSqlQueryModel* tri2();
    void recherchee(QTableView *table,QString n);
    employe remplirFiche(QString);
    int ajouterCompte(QString cin);
    QString getC(int id);
private:
    int id,age;
    QString cin,nom,prenom,gendre,ville,adresse,image,salaire,date_ajout;
};

#endif // EMPLOYE_H
