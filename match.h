#ifndef MATCH_H
#define MATCH_H
#include<QString>
#include<QSqlQueryModel>
#include <QDate>
#include <QTime>



class Match
{ private:
    int idd;
    QDate dated;
    int nb;
    QString type_m;
    QTime heure_m;
    QString equipe_ad;
    QString lieu;


public:
    Match();
    Match(int,QDate,int,QString,QTime,QString,QString);

    int get_idd(){return idd;};
    QDate get_dated(){return dated;};
    int get_nb(){return nb;};
    QString get_type_m(){return  type_m;};
    QTime get_heure_m(){return heure_m;};
    QString get_equipe_ad(){return equipe_ad;};
    QString get_lieu(){return  lieu;};

      void set_Date(QDate val){dated = val;};
    void set_idd(int val){idd = val ;};
    void set_nb(int val){nb = val ;};
        void set_type_m(QString val){type_m = val ;};

        void set_heure_m(QTime val){heure_m = val;};
          void set_equipe_ad(QString val){equipe_ad= val ;};


          void set_lieu(QString val){lieu= val ;};
    Match getMatchById(QString id);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier(int,QDate,int,QString,QTime,QString,QString);//////////
      QSqlQueryModel* tri();
QSqlQueryModel * rechercherId(QString id);


};


#endif // MATCH_H
