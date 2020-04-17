#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQuery> //sécurité (injection)
#include <QSqlQueryModel>
#include <QDate>
#include<QTableView>

 class reclamation
 {public:
            reclamation();
            reclamation(int,QString,QDate,QString,QString,QString);

           int get_idd()
            {return idd;}
           void setid(int idd)
           {this->idd=idd;}

            bool ajouter();
            QSqlQueryModel * afficher();
            bool supprimer(int);
            bool recherche(int);
            bool modifier();
             QSqlQueryModel *tri_reclm();
             ~reclamation(){}
        private:

            int idd;

            QString ass;
            QDate datee;
            QString reclm,nom , mail;



        };

#endif // RECLAMATION_H
