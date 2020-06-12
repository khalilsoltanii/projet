#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stade.h"
#include <QMainWindow>
#include "joueur.h"
#include "compte.h"
#include "reclamation.h"
#include "ticket.h"
#include "match.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QSystemTrayIcon;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    QVector<QString>   equipeAdv {"Css", "Est", "CA","CAB"}; //////
    QVector<QString>   stadenom;
    QString idMatch;
    QString idTicket;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_stade_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();
     void on_pushButton_revenir_clicked();
    void on_pushButton_ticket_clicked();



    //void on_pushButton_13_clicked();

   void on_pushButton_11_clicked();

    void on_tablejoueur_activated(const QModelIndex &index);

    //void on_pushButton_16_clicked();

   // void on_pushButton_15_clicked();

    void on_tablestade_activated(const QModelIndex &index);

    void on_pushButton_14_clicked();

   // void on_pushButton_18_clicked();

    //void on_pushButton_19_clicked();

   // void on_pushButton_20_clicked();

   // void on_pushButton_21_clicked();

   // void on_pushButton_email_clicked();

    //void on_pushButton_statistique_clicked();

   // void on_pdf_clicked();

  //  void on_pushButton_email_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_lineEdit_nom3_1_textChanged(const QString &arg1);

    void on_lineEdit_nom3_textChanged(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    //void on_lineEdit_nom3_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_17_clicked();

   // void on_lineEdit_cap_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_email_clicked();

    void on_pdf_clicked();


  void on_comboBox_3_activated(const QString &arg1);
  void on_comboBox_4_activated(const QString &arg1);

  void on_pushButton_AjouterC_clicked();

  void on_pushButton_ModifierC_clicked();

  void on_pushButton_listeC_clicked();

  void on_comboBox_listC_activated(const QString &arg1);

  void on_pushButton_SupprimerC_clicked();

  void on_pushButton_AfficherC_clicked();

  void on_comboBox_TriC_activated(const QString &arg1);

  void on_lineEdit_RechC_cursorPositionChanged(int arg1, int arg2);

  void on_tabcompte_activated(const QModelIndex &index);



  void on_pushButton_AjoutR_clicked();

  void on_pushButton_listeM_clicked();

  void on_comboBox_1M_activated(const QString &arg1);

  void on_pushButton_ModifierR_clicked();

  void on_pushButton_SupprimerM_clicked();

  void on_comboBox_10M_activated(const QString &arg1);

  void on_pushButton_afficherR_clicked();

  void on_liste_reclamation_activated(const QModelIndex &index);

  void on_lineEdit_recherM_textChanged(const QString &arg1);



  void on_pushButtonMENU2_clicked();

  void on_pushButton_Mcompte_clicked();

  void on_pushButton_Mreclm_clicked();

  void on_pushButtonMENU_clicked();



  void on_pushButtonPdFr_clicked();
  void on_pushButton_ajoutticket_clicked();
  void on_pushButton_tickett_clicked();
  void on_pushButton_supp_clicked();
  void on_pushButton_aff_clicked();
  void on_pushButton_cherch_clicked();
  void on_pushButton_16_clicked();
  void on_pushButton_18_clicked();
  void on_pushButton_Rv_clicked();
  void on_pushButton_matchh_clicked();
  void on_pushButton_Modif_Match_clicked();
  void on_pushButton_Spr_clicked();
  void on_pushButton_T_clicked();
  void on_pushButton_chercher_Match_clicked();
  void on_pushButton_AffichM_clicked();
  void on_pushButton_ajout_match_clicked();
   void on_tableticket_activated(const QModelIndex &index);
   void on_tableMatch_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    stade tmpstade;
    joueur tmpjoueur;
Compte tmpcompte;
 Ticket tmpticket;
 Match tmpmatch;
reclamation tmpreclamations;
    QSystemTrayIcon *mysystem;

};
#endif // MAINWINDOW_H
