#include "statistique.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stade.h"
#include <QMessageBox>
#include <QSystemTrayIcon>
#include "mailing/SmtpMime"
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include "compte.h"
#include "reclamation.h"
#include "ticket.h"
#include "match.h"
#include<QTime>
#include <QVector>
#include <iostream>
#include<string>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tablejoueur->setModel(tmpjoueur.afficher());
    ui->tablestade->setModel(tmpstade.afficher());
    ui->tabcompte->setModel(tmpcompte.afficher());
    ui->liste_reclamation->setModel(tmpreclamations.afficher());
    ui->tableticket->setModel(tmpticket.afficher());
     ui->tableMatch->setModel(tmpmatch.afficher());

    mysystem=new QSystemTrayIcon(this);
    mysystem->setIcon(QIcon(":/user.png"));
    mysystem->setVisible(true);
   QObject::connect(ui->comboBox,&QComboBox::currentTextChanged,this,&MainWindow::on_comboBox_3_activated);
  //  ui->lineEdit->setValidator( new QIntValidator(0, 999999, this) );
   // ui->lineEdit1->setValidator( new QIntValidator(0, 999999, this) );

   QPixmap pix("C:/Users/khalil/Desktop/img/logo-ess-4.png");
   ui->label_pic->setPixmap(pix);
   ui-> lineEdit_iddM->setValidator(new QIntValidator(0, 99999999, this));
   ui-> lineEdit_RechC->setValidator(new QIntValidator(0, 99999999, this));
   ui-> lineEdit_recherM->setValidator(new QIntValidator(0, 99999999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_stade_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}









/******************************************************************************************************************/
/******************************************************************************************************************/
/********************************************************STADE*****************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/

void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    /*if(arg1=="...")
    {
    ui->comboBox->clear();
    ui->comboBox->addItem("Ariana");
    ui->comboBox->addItem("Bizerte");
    ui->comboBox->addItem("Beja");
    ui->comboBox->addItem("Gabes");
    ui->comboBox->addItem("Gafsa");
    ui->comboBox->addItem("Jendouba");
    ui->comboBox->addItem("Kairouan");
    ui->comboBox->addItem("Monastir");
    ui->comboBox->addItem("Sfax");
    ui->comboBox->addItem("Sousse");
    ui->comboBox->addItem("Tunis ");
    }*/
    if(arg1=="Ariana")

{
ui->comboBox_5->clear();
ui->comboBox_5->addItem("Ariana Ville");
ui->comboBox_5->addItem("Borj Louzir");
ui->comboBox_5->addItem("Chotrana");
ui->comboBox_5->addItem("Ennasr");
ui->comboBox_5->addItem("Ettadhmen");
ui->comboBox_5->addItem("Ghazela");
ui->comboBox_5->addItem("La Soukra");
ui->comboBox_5->addItem("Mnihla");
ui->comboBox_5->addItem("Raoued");
ui->comboBox_5->addItem("Sidi Thabet");
}
if(arg1=="Bizerte")
{
ui->comboBox_5->clear();
ui->comboBox_5->addItem("Bizerte Nord");
ui->comboBox_5->addItem("Bizerte Sud");
ui->comboBox_5->addItem("Ghar El Melh");
ui->comboBox_5->addItem("Mateur");
ui->comboBox_5->addItem("Menzel Bourguiba");
ui->comboBox_5->addItem("Ras Jebel");
ui->comboBox_5->addItem("Sejenane");
ui->comboBox_5->addItem("Tinja");
ui->comboBox_5->addItem("Utique");
ui->comboBox_5->addItem("Zarzouna");
}
if(arg1=="Beja")
{
ui->comboBox_5->clear();
ui->comboBox_5->addItem("Beja Nord");
ui->comboBox_5->addItem("Beja Sud");
ui->comboBox_5->addItem("El Kasr");
ui->comboBox_5->addItem("Goubellat");
ui->comboBox_5->addItem("Medjez el-Beb");
ui->comboBox_5->addItem("Nefza");
ui->comboBox_5->addItem("Testour");
ui->comboBox_5->addItem("Thibar");
ui->comboBox_5->addItem("Teboursouk");
}
if(arg1=="Gabes")
{
ui->comboBox_5->clear();
ui->comboBox_5->addItem("El Hamma");
ui->comboBox_5->addItem("Gabes Medina");
ui->comboBox_5->addItem("Gabes Ouest");
ui->comboBox_5->addItem("Gabes Sud");
ui->comboBox_5->addItem("Ghanouch");
ui->comboBox_5->addItem("Mareth");
ui->comboBox_5->addItem("Matmata");
ui->comboBox_5->addItem("Metouia");
ui->comboBox_5->addItem("Nouvelle Matmata");
}if(arg1=="Gafsa")
{
ui->comboBox_5->clear();
ui->comboBox_5->addItem("Belkhir");
ui->comboBox_5->addItem("El Guettar");
ui->comboBox_5->addItem("Gafsa Nord");
ui->comboBox_5->addItem("Gafsa sud");
ui->comboBox_5->addItem("Mdhila");
ui->comboBox_5->addItem("Metlaoui");
ui->comboBox_5->addItem("Oum El Araies");
ui->comboBox_5->addItem("Redeyef");
ui->comboBox_5->addItem("Sened");
ui->comboBox_5->addItem("Sidi Aich");
}if(arg1=="Jendouba")
{
ui->comboBox_5->clear();
ui->comboBox_5->addItem("Ain Draham");
ui->comboBox_5->addItem("Bou Salem");
ui->comboBox_5->addItem("Fernana");
ui->comboBox_5->addItem("Ghardimaou");
ui->comboBox_5->addItem("Jendouba Nord");
ui->comboBox_5->addItem("Oued Meliz");
ui->comboBox_5->addItem("Tabarka");
}if(arg1=="Kairouan")
{
ui->comboBox_5->clear();
ui->comboBox_5->addItem("Bouhajla");
ui->comboBox_5->addItem("Chebika");
ui->comboBox_5->addItem("Echrada");
ui->comboBox_5->addItem("El Alaa");
ui->comboBox_5->addItem("El Ouslatia");
ui->comboBox_5->addItem("Haffouz");
ui->comboBox_5->addItem("Hajeb El Ayoun");
ui->comboBox_5->addItem("Kairouan Nord");
ui->comboBox_5->addItem("Kairouan Sud");
ui->comboBox_5->addItem("Nasralah");
ui->comboBox_5->addItem("Sbikha");
}if(arg1=="Monastir")
{
ui->comboBox_5->clear();
ui->comboBox_5->addItem("Bekalta");
ui->comboBox_5->addItem("Bembla");
ui->comboBox_5->addItem("Beni Hassen");
ui->comboBox_5->addItem("Jemmal");
ui->comboBox_5->addItem("Ksar Hellal");
ui->comboBox_5->addItem("Moknine");
ui->comboBox_5->addItem("Ouerdanine");
ui->comboBox_5->addItem("Sahline");
ui->comboBox_5->addItem("Teboulba");
ui->comboBox_5->addItem("Zeramdine");
}if(arg1=="Sfax")
{
ui->comboBox_5->clear();
ui->comboBox_5->addItem("agareb");
ui->comboBox_5->addItem("Bir Ali Ben Khlifa");
ui->comboBox_5->addItem("El Amra");
ui->comboBox_5->addItem("El Hencha");
ui->comboBox_5->addItem("Ghraiba");
ui->comboBox_5->addItem("Jebiniana");
ui->comboBox_5->addItem("Kerkennah");
ui->comboBox_5->addItem("Mahres");
ui->comboBox_5->addItem("Menzel Cheker");
ui->comboBox_5->addItem("Sakiet Eddaier");
ui->comboBox_5->addItem("Sakiet Ezzit");
ui->comboBox_5->addItem("Sfax Medina");
ui->comboBox_5->addItem("Sfax Ville");
ui->comboBox_5->addItem("Skhira");
ui->comboBox_5->addItem("Thyna");
}if(arg1=="Sousse")
{
ui->comboBox_5->clear();
ui->comboBox_5->addItem("Akouda");
ui->comboBox_5->addItem("Bouficha");
ui->comboBox_5->addItem("Enfidha");
ui->comboBox_5->addItem("Hamem Sousse");
ui->comboBox_5->addItem("Hergla");
ui->comboBox_5->addItem("Kalaa Kebira");
ui->comboBox_5->addItem("Kalaa Sghir");
ui->comboBox_5->addItem("Kantaoui");
ui->comboBox_5->addItem("Kondar");
ui->comboBox_5->addItem("M'saken");
ui->comboBox_5->addItem("Sahloul");
ui->comboBox_5->addItem("Sidi Bou Ali");
ui->comboBox_5->addItem("Sidi El Heni");
ui->comboBox_5->addItem("Sousse medina");
ui->comboBox_5->addItem("Sousse Riadh");
ui->comboBox_5->addItem("Zaouit-Ksibat");
}if(arg1=="Tunis")
{
ui->comboBox_5->clear();
ui->comboBox_5->addItem("Agba");
ui->comboBox_5->addItem("Carthage");
ui->comboBox_5->addItem("Centre ville");
ui->comboBox_5->addItem("Cité El khadra");
ui->comboBox_5->addItem("Cité olympique");
ui->comboBox_5->addItem("Djebel Jelloud");
ui->comboBox_5->addItem("El Kabaria");
ui->comboBox_5->addItem("El Omrane");
ui->comboBox_5->addItem("El Ouardia");
ui->comboBox_5->addItem("Ettahrir");
ui->comboBox_5->addItem("Ezzouhour");
ui->comboBox_5->addItem("Hrairia");
ui->comboBox_5->addItem("L'aouina");
ui->comboBox_5->addItem("La Goulette");
ui->comboBox_5->addItem("La Marsa");
ui->comboBox_5->addItem("Le Bardo");
ui->comboBox_5->addItem("Le Kram");
ui->comboBox_5->addItem("Manar");
ui->comboBox_5->addItem("Menzah");
ui->comboBox_5->addItem("Menzel Jemil");
ui->comboBox_5->addItem("Mutuelleville");
ui->comboBox_5->addItem("Medina");
ui->comboBox_5->addItem("Sidi Daoud");
ui->comboBox_5->addItem("Sidi El Bechir");
ui->comboBox_5->addItem("Sidi Hassine");
ui->comboBox_5->addItem("Sejoumi");
ui->comboBox_5->addItem("Tunis");
}
}
void MainWindow::on_comboBox_4_activated(const QString &arg1)
{
    if(arg1=="Ariana")
    {
    ui->comboBox_6->clear();
    ui->comboBox_6->addItem("Ariana Ville");
    ui->comboBox_6->addItem("Borj Louzir");
    ui->comboBox_6->addItem("Chotrana");
    ui->comboBox_6->addItem("Ennasr");
    ui->comboBox_6->addItem("Ettadhmen");
    ui->comboBox_6->addItem("Ghazela");
    ui->comboBox_6->addItem("La Soukra");
    ui->comboBox_6->addItem("Mnihla");
    ui->comboBox_6->addItem("Raoued");
    ui->comboBox_6->addItem("Sidi Thabet");
    }
    if(arg1=="Bizerte")
    {
    ui->comboBox_6->clear();
    ui->comboBox_6->addItem("Bizerte Nord");
    ui->comboBox_6->addItem("Bizerte Sud");
    ui->comboBox_6->addItem("Ghar El Melh");
    ui->comboBox_6->addItem("Mateur");
    ui->comboBox_6->addItem("Menzel Bourguiba");
    ui->comboBox_6->addItem("Ras Jebel");
    ui->comboBox_6->addItem("Sejenane");
    ui->comboBox_6->addItem("Tinja");
    ui->comboBox_6->addItem("Utique");
    ui->comboBox_6->addItem("Zarzouna");
    }
    if(arg1=="Beja")
    {
    ui->comboBox_6->clear();
    ui->comboBox_6->addItem("Beja Nord");
    ui->comboBox_6->addItem("Beja Sud");
    ui->comboBox_6->addItem("El Kasr");
    ui->comboBox_6->addItem("Goubellat");
    ui->comboBox_6->addItem("Medjez el-Beb");
    ui->comboBox_6->addItem("Nefza");
    ui->comboBox_6->addItem("Testour");
    ui->comboBox_6->addItem("Thibar");
    ui->comboBox_6->addItem("Teboursouk");
    }
    if(arg1=="Gabes")
    {
    ui->comboBox_6->clear();
    ui->comboBox_6->addItem("El Hamma");
    ui->comboBox_6->addItem("Gabes Medina");
    ui->comboBox_6->addItem("Gabes Ouest");
    ui->comboBox_6->addItem("Gabes Sud");
    ui->comboBox_6->addItem("Ghanouch");
    ui->comboBox_6->addItem("Mareth");
    ui->comboBox_6->addItem("Matmata");
    ui->comboBox_6->addItem("Metouia");
    ui->comboBox_6->addItem("Nouvelle Matmata");
    }if(arg1=="Gafsa")
    {
    ui->comboBox_6->clear();
    ui->comboBox_6->addItem("Belkhir");
    ui->comboBox_6->addItem("El Guettar");
    ui->comboBox_6->addItem("Gafsa Nord");
    ui->comboBox_6->addItem("Gafsa sud");
    ui->comboBox_6->addItem("Mdhila");
    ui->comboBox_6->addItem("Metlaoui");
    ui->comboBox_6->addItem("Oum El Araies");
    ui->comboBox_6->addItem("Redeyef");
    ui->comboBox_6->addItem("Sened");
    ui->comboBox_6->addItem("Sidi Aich");
    }if(arg1=="Jendouba")
    {
    ui->comboBox_6->clear();
    ui->comboBox_6->addItem("Ain Draham");
    ui->comboBox_6->addItem("Bou Salem");
    ui->comboBox_6->addItem("Fernana");
    ui->comboBox_6->addItem("Ghardimaou");
    ui->comboBox_6->addItem("Jendouba Nord");
    ui->comboBox_6->addItem("Oued Meliz");
    ui->comboBox_6->addItem("Tabarka");
    }if(arg1=="Kairouan")
    {
    ui->comboBox_6->clear();
    ui->comboBox_6->addItem("Bouhajla");
    ui->comboBox_6->addItem("Chebika");
    ui->comboBox_6->addItem("Echrada");
    ui->comboBox_6->addItem("El Alaa");
    ui->comboBox_6->addItem("El Ouslatia");
    ui->comboBox_6->addItem("Haffouz");
    ui->comboBox_6->addItem("Hajeb El Ayoun");
    ui->comboBox_6->addItem("Kairouan Nord");
    ui->comboBox_6->addItem("Kairouan Sud");
    ui->comboBox_6->addItem("Nasralah");
    ui->comboBox_6->addItem("Sbikha");
    }if(arg1=="Monastir")
    {
    ui->comboBox_6->clear();
    ui->comboBox_6->addItem("Bekalta");
    ui->comboBox_6->addItem("Bembla");
    ui->comboBox_6->addItem("Beni Hassen");
    ui->comboBox_6->addItem("Jemmal");
    ui->comboBox_6->addItem("Ksar Hellal");
    ui->comboBox_6->addItem("Moknine");
    ui->comboBox_6->addItem("Ouerdanine");
    ui->comboBox_6->addItem("Sahline");
    ui->comboBox_6->addItem("Teboulba");
    ui->comboBox_6->addItem("Zeramdine");
    }if(arg1=="Sfax")
    {
    ui->comboBox_6->clear();
    ui->comboBox_6->addItem("agareb");
    ui->comboBox_6->addItem("Bir Ali Ben Khlifa");
    ui->comboBox_6->addItem("El Amra");
    ui->comboBox_6->addItem("El Hencha");
    ui->comboBox_6->addItem("Ghraiba");
    ui->comboBox_6->addItem("Jebiniana");
    ui->comboBox_6->addItem("Kerkennah");
    ui->comboBox_6->addItem("Mahres");
    ui->comboBox_6->addItem("Menzel Cheker");
    ui->comboBox_6->addItem("Sakiet Eddaier");
    ui->comboBox_6->addItem("Sakiet Ezzit");
    ui->comboBox_6->addItem("Sfax Medina");
    ui->comboBox_6->addItem("Sfax Ville");
    ui->comboBox_6->addItem("Skhira");
    ui->comboBox_6->addItem("Thyna");
    }if(arg1=="Sousse")
    {
    ui->comboBox_6->clear();
    ui->comboBox_6->addItem("Akouda");
    ui->comboBox_6->addItem("Bouficha");
    ui->comboBox_6->addItem("Enfidha");
    ui->comboBox_6->addItem("Hamem Sousse");
    ui->comboBox_6->addItem("Hergla");
    ui->comboBox_6->addItem("Kalaa Kebira");
    ui->comboBox_6->addItem("Kalaa Sghir");
    ui->comboBox_6->addItem("Kantaoui");
    ui->comboBox_6->addItem("Kondar");
    ui->comboBox_6->addItem("M'saken");
    ui->comboBox_6->addItem("Sahloul");
    ui->comboBox_6->addItem("Sidi Bou Ali");
    ui->comboBox_6->addItem("Sidi El Heni");
    ui->comboBox_6->addItem("Sousse medina");
    ui->comboBox_6->addItem("Sousse Riadh");
    ui->comboBox_6->addItem("Zaouit-Ksibat");
    }if(arg1=="Tunis")
    {
    ui->comboBox_6->clear();
    ui->comboBox_6->addItem("Agba");
    ui->comboBox_6->addItem("Carthage");
    ui->comboBox_6->addItem("Centre ville");
    ui->comboBox_6->addItem("Cité El khadra");
    ui->comboBox_6->addItem("Cité olympique");
    ui->comboBox_6->addItem("Djebel Jelloud");
    ui->comboBox_6->addItem("El Kabaria");
    ui->comboBox_6->addItem("El Omrane");
    ui->comboBox_6->addItem("El Ouardia");
    ui->comboBox_6->addItem("Ettahrir");
    ui->comboBox_6->addItem("Ezzouhour");
    ui->comboBox_6->addItem("Hrairia");
    ui->comboBox_6->addItem("L'aouina");
    ui->comboBox_6->addItem("La Goulette");
    ui->comboBox_6->addItem("La Marsa");
    ui->comboBox_6->addItem("Le Bardo");
    ui->comboBox_6->addItem("Le Kram");
    ui->comboBox_6->addItem("Manar");
    ui->comboBox_6->addItem("Menzah");
    ui->comboBox_6->addItem("Menzel Jemil");
    ui->comboBox_6->addItem("Mutuelleville");
    ui->comboBox_6->addItem("Medina");
    ui->comboBox_6->addItem("Sidi Daoud");
    ui->comboBox_6->addItem("Sidi El Bechir");
    ui->comboBox_6->addItem("Sidi Hassine");
    ui->comboBox_6->addItem("Sejoumi");
    ui->comboBox_6->addItem("Tunis");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
////////////////////////////////////////////////CONDITION DE SAISIE////////////////////////////////////////////////

    stade s1;
    //condition de saisie sur nom
      if(ui->lineEdit_nom2->text()=="" || ui->lineEdit_nom2->text()=="   *champ obligatoire")
          ui->lineEdit_nom2->setText("   *champ obligatoire");
       else
          s1.set_nom(ui->lineEdit_nom2->text());

      //condition de saisie sur capacite
            /*if( ui->spinBox_3->text().toInt()<0|| ui->spinBox_3->text().toInt()>=100000 || ui->spinBox_3->text().toInt()==0 || ui->spinBox_3->text()=="   *champ obligatoire")
            { if(ui->spinBox_3->text().toInt()==0)
                    ui->spinBox_3->setValue(;
                else
                    ui->lineEdit_cap->setText("   capacite non valide");}
             else
                s1.set_capacite(ui->lineEdit_cap->text().toInt());*/

    //condition de saisie sur ville

              /*          if(ui->comboBox_5->text()=="" || ui->lineEdit_ville->text()=="   *champ obligatoire")
                            ui->lineEdit_ville->setText("   *champ obligatoire");
             else
                s1.set_ville(ui->lineEdit_ville->text());*/


////////////////////////////////////////////////CONDITION DE SAISIE////////////////////////////////////////////////


    QString nom= ui->lineEdit_nom2->text();
    int capacite= ui->spinBox_3->text().toInt();
    QString region= ui->comboBox_3->currentText();
    QString ville= ui->comboBox_5->currentText();
    QDate dat= ui->dateEdit_3->date();
    stade s(nom,capacite,region,ville,dat);
    bool test=s.ajouter();
    if(test)
    {
//////////////////////////////////////////NOTIFICATION///////////////////////////////////////////////////////////////
          mysystem->showMessage(tr("notification"),tr("ajout avec succes"));
//////////////////////////////////////////NOTIFICATION///////////////////////////////////////////////////////////////

        ui->tablestade->setModel(tmpstade.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un stade"),
                          QObject::tr("stade ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else

        QMessageBox::information(nullptr, QObject::tr("Ajouter un stade"),
                          QObject::tr("erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    ui->lineEdit_nom2->clear();
    ui->spinBox_3->clear();
   /* ui->comboBox_3->clear();
    ui->comboBox_5->clear();*/

}



void MainWindow::on_pushButton_4_clicked()
{

    int id = ui->lineEdit_id1_2->text().toInt();
    bool test=tmpstade.supprimer(id);
    if(test)
    {ui->tablestade->setModel(tmpstade.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un stade"),
                    QObject::tr("Stade supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un stade"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    int id= ui->lineEdit_id1->text().toInt();
    QString nom= ui->lineEdit_nom2_2->text();
    int capacite= ui->spinBox_4->text().toInt();
    QString region= ui->comboBox_4->currentText();
    QString ville= ui->comboBox_6->currentText();
    QDate dat= ui->dateEdit_4->date();
     stade s(nom,capacite,region,ville,dat);
     bool test=s.modifier(id);
     if(test)
   {

         ui->tablestade->setModel(tmpstade.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("modifier un stade"),
                     QObject::tr("Stade modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("modifier un stade"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
///////////////////////////////////RECHERCHE///////////////////////////////

/*void MainWindow::on_pushButton_16_clicked()
{
    QString nom=ui->lineEdit_nom3_1->text();
    ui->tablestade->setModel(tmpstade.recherche(nom));

    QMessageBox::information(this, QObject::tr("Rechercher un stade"),
         QObject::tr("Stade recherché.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
}*/
void MainWindow::on_lineEdit_nom3_1_textChanged(const QString &arg1)
{
    stade s ;
    QString nom=ui->lineEdit_nom3_1->text();
     s.recherche_nom(ui->tablestade,nom) ;
}
///////////////////////////////////RECHERCHE///////////////////////////////

///////////////////////////////////TRI/////////////////////////////////////

/*void MainWindow::on_pushButton_15_clicked()
{
    ui->tablestade->setModel(tmpstade.tri());
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->tablestade->setModel(tmpstade.tri2());
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->tablestade->setModel(tmpstade.tri3());

}*/

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    if(arg1== "Trie croissante")
        ui->tablestade->setModel(tmpstade.tri());
    else if(arg1 == "Trie décroissante")
        ui->tablestade->setModel(tmpstade.tri2());

     else if(arg1 == "Trie A..Z")
        ui->tablestade->setModel(tmpstade.tri3());

}

///////////////////////////////////TRI/////////////////////////////////////

///////////////////////////////////AFFICHAGE///////////////////////////////

void MainWindow::on_pushButton_14_clicked()
{
    ui->tablestade->setModel(tmpstade.afficher());
}
///////////////////////////////////AFFICHAGE///////////////////////////////

///////////////////////////////////SELECTION///////////////////////////////

void MainWindow::on_tablestade_activated(const QModelIndex &index)
{
    QString val= ui->tablestade->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from stade where id= '"+val+"' or nom= '"+val+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_id1->setText(query.value(0).toString());
            ui->lineEdit_nom2_2->setText(query.value(1).toString());
            ui->spinBox_4->setValue(query.value(2).toInt());
            ui->comboBox_4->setCurrentText(query.value(3).toString());
            ui->comboBox_6->setCurrentText(query.value(4).toString());
            ui->dateEdit_4->setDate(query.value(5).toDate());
            ui->lineEdit_id1_2->setText(query.value(0).toString());
        }
    }
    else
        QMessageBox::information(nullptr, QObject::tr("Selection"),
                          QObject::tr("erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}
///////////////////////////////////SELECTION//////////////////////////////////


///////////////////////////////////statistique///////////////////////////////

void MainWindow::on_pushButton_17_clicked()
{
    statistique s;
    s.setModal(true);
    s.exec();

}
///////////////////////////////////statistique///////////////////////////////



///////////////////////////////////PDF/////////////////////////////////////



void MainWindow::on_pdf_clicked()
{
    //QDate datecreation = dateEdit.currentDateTime();
        //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
               QPdfWriter pdf("C:/Users/khalil/Desktop/PDFkhalil/pdf.pdf"); //hedha badlouh ca depend win thobou tsobou le fichier pdf
               QPainter painter(&pdf);
              int i = 4000;
                   painter.setPen(Qt::blue);
                   painter.setFont(QFont("Arial", 30));
                   painter.drawText(1100,1200,"Liste Des Stades");
                   painter.setPen(Qt::black);
                   painter.setFont(QFont("Arial", 15));
                  //painter.drawText(1100,2000,afficheDC);
                   painter.drawRect(100,100,7300,3000);
                   painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/khalil/Pictures/logo.png"));
                   painter.drawRect(0,3000,9600,500);
                   painter.setFont(QFont("Arial", 9));
                   painter.drawText(200,3300,"ID");
                   painter.drawText(1300,3300,"NOM");
                   painter.drawText(2100,3300,"CAPACITE");
                   painter.drawText(3200,3300,"REGION");
                   painter.drawText(4300,3300,"VILLE");
                   QSqlQuery query;
                   query.prepare("select * from stade");
                   query.exec();
                   while (query.next())
                   {
                       painter.drawText(200,i,query.value(0).toString());
                       painter.drawText(1300,i,query.value(1).toString());
                       painter.drawText(2200,i,query.value(2).toString());
                       painter.drawText(3200,i,query.value(3).toString());
                       painter.drawText(4300,i,query.value(4).toString());
                      i = i + 500;
                   }
                   int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                       if (reponse == QMessageBox::Yes)
                       {

                           painter.end();
                       }
                       if (reponse == QMessageBox::No)
                       {
                            painter.end();
                       }
}
///////////////////////////////////PDF/////////////////////////////////////














/******************************************************************************************************************/
/******************************************************************************************************************/
/********************************************************JOUEUR****************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/


void MainWindow::on_pushButton_8_clicked()
{
    ////////////////////////////////////////////////CONDITION DE SAISIE////////////////////////////////////////////////

    joueur j1;
    //condition de saisie sur nom
      if(ui->lineEdit_nom->text()=="" || ui->lineEdit_nom->text()=="   *champ obligatoire")
          ui->lineEdit_nom->setText("   *champ obligatoire");
       else
          j1.set_nom(ui->lineEdit_nom->text());

    //condition de saisie sur prenom
      if(ui->lineEdit_prenom->text()=="" || ui->lineEdit_prenom->text()=="   *champ obligatoire")
          ui->lineEdit_prenom->setText("   *champ obligatoire");
       else
          j1.set_prenom(ui->lineEdit_prenom->text());

   /* //condition de saisie sur poste
      if(ui->lineEdit_poste->text()=="" || ui->lineEdit_poste->text()=="   *champ obligatoire")
          ui->lineEdit_poste->setText("   *champ obligatoire");
       else
          j1.set_poste(ui->lineEdit_poste->text());*/
    //condition de saisie sur num
        /* if( ui->spinBox->text().toInt()<0|| ui->spinBox->text().toInt()>99 || ui->spinBox->text().toInt()==0 || ui->spinBox->text()=="   *champ obligatoire")
          { if(ui->spinBox->text().toInt()==0)
                  ui->spinBox->setValue("");
              else
                  ui->spinBox->setValue("   num non valide");}
           else
              j1.set_num(ui->spinBox->text().toInt());*/

    //condition de saisie sur tel
              if( ui->lineEdit_tel->text().toInt()<10000000|| ui->lineEdit_tel->text().toInt()>99999999 || ui->lineEdit_tel->text().toInt()==0 || ui->lineEdit_tel->text()=="   *champ obligatoire")
              { if(ui->lineEdit_tel->text().toInt()==0)
                      ui->lineEdit_tel->setText("   *champ obligatoire");
                  else
                      ui->lineEdit_tel->setText("   tel non valide");}
               else
                  j1.set_tel(ui->lineEdit_tel->text());

    //condition de saisie sur adresse
                        if(ui->lineEdit_add->text()=="" || ui->lineEdit_add->text()=="   *champ obligatoire")
                            ui->lineEdit_add->setText("   *champ obligatoire");
                         else
                            j1.set_adresse(ui->lineEdit_add->text());

////////////////////////////////////////////////CONDITION DE SAISIE////////////////////////////////////////////////


    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString poste= ui->comboBox_7->currentText();
    int num= ui->spinBox->text().toInt();
    QString tel= ui->lineEdit_tel->text();
    QString adresse= ui->lineEdit_add->text();
    QString dat= ui->dateEdit_dat->text();
    joueur j(nom,prenom,poste,num,tel,adresse,dat);
    bool test=j.ajouter();
    if(test)
    {
////////////////////////////////////////////////NOTIFICATION////////////////////////////////////////////////

        mysystem->showMessage(tr("notification"),tr("ajout avec succes"));

////////////////////////////////////////////////NOTIFICATION////////////////////////////////////////////////

        ui->tablejoueur->setModel(tmpjoueur.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un joueur"),
                          QObject::tr("Joueur ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else

        QMessageBox::information(nullptr, QObject::tr("Ajouter un joueur"),
                          QObject::tr("erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
  //  ui->lineEdit_poste->clear();
    ui->spinBox->clear();
    ui->lineEdit_tel->clear();
    ui->lineEdit_add->clear();
}




void MainWindow::on_pushButton_9_clicked()
{

    int id = ui->lineEdit_id2_2->text().toInt();
    bool test=tmpjoueur.supprimer(id);
    if(test)
    {
        ui->tablejoueur->setModel(tmpjoueur.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un joueur"),
                    QObject::tr("Joueur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un joueur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_10_clicked()
{
    int id= ui->lineEdit_id2->text().toInt();
    QString nom= ui->lineEdit_nom1->text();
    QString prenom= ui->lineEdit_prenom1->text();
    QString poste= ui->comboBox_8->currentText();
    int num= ui->spinBox_2->text().toInt();
    QString tel= ui->lineEdit_tel1->text();
    QString adresse= ui->lineEdit_add1->text();
    QString dat= ui->dateEdit_dat2->text();
     joueur j(nom,prenom,poste,num,tel,adresse,dat);
     bool test=j.modifier(id);
     if(test)
   {

         ui->tablejoueur->setModel(tmpjoueur.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("modifier un joueur"),
                     QObject::tr("Joueur modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else
         QMessageBox::critical(nullptr, QObject::tr("modifier un joueur"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

////////////////////////////////////////////////RECHERCHE////////////////////////////////////////////////

/*void MainWindow::on_pushButton_12_clicked()
{
    QString nom=ui->lineEdit_nom3->text();
    ui->tablejoueur->setModel(tmpjoueur.recherche(nom));

    QMessageBox::information(this, QObject::tr("Rechercher un joueur"),
         QObject::tr("joueur recherché.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
}
*/
void MainWindow::on_lineEdit_nom3_textChanged(const QString &arg1)
{
    joueur j ;
    QString nom=ui->lineEdit_nom3->text();
     j.recherche_nom(ui->tablejoueur,nom) ;
}
////////////////////////////////////////////////RECHERCHE////////////////////////////////////////////////

////////////////////////////////////////////////TRIE////////////////////////////////////////////////

/*void MainWindow::on_pushButton_13_clicked()
{
    ui->tablejoueur->setModel(tmpjoueur.tri());
}
void MainWindow::on_pushButton_18_clicked()
{
    ui->tablejoueur->setModel(tmpjoueur.tri2());
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->tablejoueur->setModel(tmpjoueur.tri3());
}*/


void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    if(arg1== "Trie croissante")
        ui->tablejoueur->setModel(tmpjoueur.tri());
    else if(arg1 == "Trie décroissante")
        ui->tablejoueur->setModel(tmpjoueur.tri2());

     else if(arg1 == "Trie A..Z")
        ui->tablejoueur->setModel(tmpjoueur.tri3());
}
////////////////////////////////////////////////TRIE////////////////////////////////////////////////


////////////////////////////////////////////////AFFICHAGE////////////////////////////////////////////////

void MainWindow::on_pushButton_11_clicked()
{

    ui->tablejoueur->setModel(tmpjoueur.afficher());

////////////////////////////////////////////////AFFICHAGE////////////////////////////////////////////////

}
////////////////////////////////////////////////SELECTION////////////////////////////////////////////////

void MainWindow::on_tablejoueur_activated(const QModelIndex &index)
{
    QString val= ui->tablejoueur->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from joueur where id= '"+val+"' or nom='"+val+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_id2->setText(query.value(0).toString());
            ui->lineEdit_nom1->setText(query.value(1).toString());
            ui->lineEdit_prenom1->setText(query.value(2).toString());
            ui->comboBox_8->setCurrentText(query.value(3).toString());
            ui->spinBox_2->setValue(query.value(4).toInt());
            ui->lineEdit_tel1->setText(query.value(6).toString());
            ui->lineEdit_add1->setText(query.value(5).toString());
            ui->dateEdit_dat2->setDate(query.value(7).toDate());
            ui->lineEdit_id2_2->setText(query.value(0).toString());
        }
    }
    else
        QMessageBox::information(nullptr, QObject::tr("Selection"),
                          QObject::tr("erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

////////////////////////////////////////////////SELECTION////////////////////////////////////////////////



////////////////////////////////////////////////MAILING////////////////////////////////////////////////


void MainWindow::on_pushButton_email_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("khalilosoltani15@gmail.com");
    smtp.setPassword("vikingsmarsois1515");


    MimeMessage message;

    message.setSender(new EmailAddress("khalilosoltani15@gmail.com", "Admin"));
    message.addRecipient(new EmailAddress(ui->lineEdit_add->text(), "zeineb"));
    message.setSubject("rejoindre l'equipe");

    MimeText text;

    text.setText(" Bonjour"

             " \n\nC’est avec un grand plaisir que j'ai accepté de vous écrire ces quelques mots de bienvenue au nom de notre equipe sportif l'Etoile De Sahel"

             " \n\nVous allez découvrir que nous menons des activités aussi diverses que variées avec pour objectif de passer des moments agréables,"

             " d'enrichir nos connaissance et de faire progresser nos droits "

             " \n\nNous aurons certainement aussi l’occasion de nous y croiser"

             " \n\nA bientôt donc et encore bienvenue parmi nous."

             " \n\n\nCordialement.");

    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
}
////////////////////////////////////////////////MAILING////////////////////////////////////////////////








/******************************************************************************************************************/
/******************************************************************************************************************/
/********************************************************compte*****************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/



void MainWindow::on_pushButton_AjouterC_clicked()
{
    int id = ui->lineEdit_idC->text().toInt();
    QString password = ui->lineEdit_mdpC->text();
    QString asq = ui->comboBox_C->currentText();
    QString nom = ui->lineEdit_nom_C->text();
    QString mail = ui->lineEditMailC->text();

     Compte e(password,asq,id,nom,mail);
     bool test=e.ajouter();
     if(test)
     {
 ui->tabcompte->setModel(tmpcompte.afficher());//refresh
 QMessageBox::information(nullptr, QObject::tr("Ajouter un compte"),
                   QObject::tr("compte ajouté.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}
     else
     {
      QMessageBox::information(nullptr, QObject::tr("Ajouter un compte"),
                        QObject::tr("erreur.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
     }
     ui->lineEdit_idC->clear();
     ui->lineEdit_mdpC->clear();
     ui->lineEdit_nom_C->clear();
     ui->lineEditMailC->clear();
}



void MainWindow::on_pushButton_ModifierC_clicked()
{
    int id = ui->lineEdit_idC->text().toInt();
    QString password = ui->lineEdit_mdpC->text();
    QString asq = ui->comboBox_C->currentText();
    QString nom = ui->lineEdit_nom_C->text();
    QString mail = ui->lineEditMailC->text();

     Compte e(password,asq,id,nom,mail);
     if (e.recherche(id))
     {
          bool test= e.modifier();
          ui->lineEdit_idC->clear();
          ui->lineEdit_mdpC->clear();
          ui->lineEditMailC->clear();
          ui->lineEdit_nom_C->clear();
          if(test)
          {
             ui->tabcompte->setModel(tmpcompte.afficher());//refresh
             QMessageBox::information(nullptr, QObject::tr("Modifier un compte"),
                               QObject::tr("Compte modifié.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
         }
         else
         {
             QMessageBox::information(nullptr, QObject::tr("Modifier un compte"),
                               QObject::tr("erreur.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
         }
            }
     ui->lineEdit_idC->clear();
     ui->lineEdit_mdpC->clear();
     ui->lineEditMailC->clear();
    ui->lineEdit_nom_C->clear();
}

void MainWindow::on_pushButton_listeC_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery();
    qry->prepare("SELECT id from compte");
    qry->exec();
    model->setQuery(*qry);
    ui->listViewC->setModel(model) ;
     ui->comboBox_listC->setModel(model) ;
}

void MainWindow::on_comboBox_listC_activated(const QString &arg1)
{
    QString id= ui->comboBox_listC->currentText();
    QSqlQuery query;
    query.prepare("select * from compte where id= '"+id+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_idC->setText(query.value(2).toString());
            ui->lineEdit_mdpC->setText(query.value(0).toString());
            ui->comboBox_C->setCurrentText(query.value(1).toString());
            ui->lineEdit_nom_C->setText(query.value(3).toString());
             ui->lineEdit_id2_C->setText(query.value(2).toString());
             ui->lineEditMailC->setText(query.value(4).toString());


        }
    }
    else
        QMessageBox::information(nullptr, QObject::tr("Selection"),
                          QObject::tr("erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_SupprimerC_clicked()
{
    int id = ui->lineEdit_id2_C->text().toInt();
    bool test=tmpcompte.supprimer(id);
    if (test)
    {int reponse = QMessageBox::question(this, "Supprimer un compte", "<>...Vous Voulez supprimer ce compte?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {ui->tabcompte->setModel(tmpcompte.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un compte"),
                              QObject::tr("Compte supprimé .\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

        }
        if (reponse == QMessageBox::No)
        {
            QMessageBox::information(nullptr, QObject::tr("Supprimer un compte"),
                              QObject::tr("erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}
}
ui->lineEdit_id2_C->clear();
}


void MainWindow::on_pushButton_AfficherC_clicked()
{
    ui->tabcompte->setModel(tmpcompte.afficher());//refresh
}


void MainWindow::on_comboBox_TriC_activated(const QString &arg1)
{
    if(arg1== "Trie croissante")
        ui->tabcompte->setModel(tmpcompte.tri_compte());
    else if(arg1 == "Trie décroissante")
        ui->tabcompte->setModel(tmpcompte.tri2());

     else if(arg1 == "Trie A..Z")
        ui->tabcompte->setModel(tmpcompte.tri3());

}


void MainWindow::on_lineEdit_RechC_cursorPositionChanged(int arg1, int arg2)
{
    Compte c;
        c.clearTable(ui->tabcompte);
        int mat=ui->lineEdit_RechC->text().toInt();
        c.searchRegexp(ui->tabcompte,mat);
}

void MainWindow::on_tabcompte_activated(const QModelIndex &index)
{
    QString val= ui->tabcompte->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from compte where id= '"+val+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_idC->setText(query.value(2).toString());
            ui->lineEdit_mdpC->setText(query.value(0).toString());
            ui->comboBox_C->setCurrentText(query.value(1).toString());
            ui->lineEdit_nom_C->setText(query.value(3).toString());
            ui->lineEdit_id2_C->setText(query.value(2).toString());
            ui->lineEditMailC->setText(query.value(4).toString());


        }
    }
    else
        QMessageBox::information(nullptr, QObject::tr("Selection"),
                          QObject::tr("erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

/******************************************************************************************************************/
/******************************************************************************************************************/
/********************************************************Reclamation*****************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/



void MainWindow::on_pushButton_AjoutR_clicked()
{
    int id= ui->lineEdit_iddM->text().toInt();
     QString asq=ui->comboBox_M->currentText();
      QDate datee =ui->dateEdit_dataM->date();
     QString reclm =ui->lineEdit_recl->text();
     QString nom =ui->lineEdit_nommM->text();
     QString mail =ui->lineEdit_mailM->text();
     QString treclm =ui->lineEdit_treclm->text();



     reclamation c(id,asq,datee,reclm,nom,mail,treclm);

         bool test=c.ajouter();

          if(test)
        { ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
              QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                                QObject::tr("Reclamation ajouté.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
             }
                  else
                  {
                   QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                                     QObject::tr("erreur.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
                  }
          ui->lineEdit_iddM->clear();
          ui->lineEdit_recl->clear();
          ui->lineEdit_nommM->clear();
          ui->lineEdit_mailM->clear();
          ui->lineEdit_treclm->clear();
}


void MainWindow::on_pushButton_listeM_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery* qry=new QSqlQuery();
    qry->prepare("SELECT id from compte");
    qry->exec();
    model->setQuery(*qry);
    ui->listViewM->setModel(model) ;
     ui->comboBox_1M->setModel(model) ;
}

void MainWindow::on_comboBox_1M_activated(const QString &arg1)
{

    QString id= ui->comboBox_1M->currentText();
    QSqlQuery query;
    query.prepare("select * from compte where id= '"+id+"'  ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_iddM->setText(query.value(2).toString());
            ui->comboBox_M->setCurrentText(query.value(1).toString());


            ui->lineEdit_nommM->setText(query.value(3).toString());
            ui->lineEdit_mailM->setText(query.value(4).toString());
        }
}}

void MainWindow::on_pushButton_ModifierR_clicked()
{
    int id= ui->lineEdit_iddM->text().toInt();
     QString asq =ui->comboBox_M->currentText();
      QDate datee =ui->dateEdit_dataM->date();
     QString reclm =ui->lineEdit_recl->text();
     QString nom =ui->lineEdit_nommM->text();
     QString mail =ui->lineEdit_mailM->text();
     QString treclm =ui->lineEdit_treclm->text();

     reclamation c(id,asq,datee,reclm,nom,mail,treclm);
     if (c.recherche(id))
     {
          bool test= c.modifier();

          if(test)
          {
             ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
             ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
             QMessageBox::information(nullptr, QObject::tr("Modifier une reclamation"),
                               QObject::tr("Reclamation modifié.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
            }
                 else
                 {
                  QMessageBox::information(nullptr, QObject::tr("Modifier une reclamation"),
                                    QObject::tr("erreur.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
                 }
}
     ui->lineEdit_iddM->clear();
     ui->lineEdit_recl->clear();
     ui->lineEdit_nommM->clear();
     ui->lineEdit_mailM->clear();
     ui->lineEdit_treclm->clear();
}


void MainWindow::on_pushButton_SupprimerM_clicked()
{
    int id = ui->lineEdit_idd2M->text().toInt();
    bool test=tmpreclamations.supprimer(id);
    if (test)
    {
        int reponse = QMessageBox::question(this, "Supprimer une reclamation", "<>...Vous Voulez supprimer cette reclamation ?", QMessageBox::Yes |  QMessageBox::No);
             if (reponse == QMessageBox::Yes)
             { ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
                 QMessageBox::information(nullptr, QObject::tr("Supprimer une reclamation"),
                                   QObject::tr("Reclamation supprimé .\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

             }
             if (reponse == QMessageBox::No)
             {
                 QMessageBox::information(nullptr, QObject::tr("Supprimer une reclamation"),
                                   QObject::tr("erreur.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
 }


     ui->lineEdit_idd2M->clear();
}
}

void MainWindow::on_comboBox_10M_activated(const QString &arg1)
{
    if(arg1== "Trie croissante")
        ui->liste_reclamation->setModel(tmpreclamations.tri_reclm());
    else if(arg1 == "Trie décroissante")
        ui->liste_reclamation->setModel(tmpreclamations.tri2());

     else if(arg1 == "Trie A..Z")
        ui->liste_reclamation->setModel(tmpreclamations.tri3());
}

void MainWindow::on_pushButton_afficherR_clicked()
{
    ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
}

void MainWindow::on_liste_reclamation_activated(const QModelIndex &index)
{
    QString val= ui->liste_reclamation->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from reclamation where id= '"+val+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_iddM->setText(query.value(0).toString());
            ui->comboBox_M->setCurrentText(query.value(1).toString());
            ui->dateEdit_dataM->setDate(query.value(2).toDate());
            ui->lineEdit_recl->setText(query.value(3).toString());
            ui->lineEdit_nommM->setText(query.value(4).toString());
            ui->lineEdit_mailM->setText(query.value(5).toString());
            ui->lineEdit_idd2M->setText(query.value(0).toString());
        }
    }
}

void MainWindow::on_lineEdit_recherM_textChanged(const QString &arg1)
{
    reclamation c;
        c.clearTable(ui->liste_reclamation);
        int mat=ui->lineEdit_recherM->text().toInt();
        c.searchRegexp(ui->liste_reclamation,mat);
}






void MainWindow::on_pushButtonMENU2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_Mcompte_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_Mreclm_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButtonMENU_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_pushButtonPdFr_clicked()
{
    QPdfWriter pdf("C:/Users/khalil/Desktop/PDFmaryem/pdf.pdf");
    QPainter painter(&pdf);
   int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1100,1200,"Liste Des reclamations");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 15));
       //painter.drawText(1100,2000,afficheDC);
        painter.drawRect(100,100,7300,3000);
        painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/dell/Pictures/logo.png"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"ID");
        painter.drawText(1300,3300,"TYPE");
        painter.drawText(2100,3300,"DATE");
        painter.drawText(4000,3300,"DESCRIPTION");
        painter.drawText(6000,3300,"NOM");
        painter.drawText(7000,3300,"MAIL");
        painter.drawText(9000,3300,"TYPE DE RECLAMATION");
        QSqlQuery query;
        query.prepare("select * from reclamation");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1300,i,query.value(1).toString());
            painter.drawText(2200,i,query.value(2).toString());
            painter.drawText(4000,i,query.value(3).toString());
            painter.drawText(6000,i,query.value(4).toString());
            painter.drawText(7000,i,query.value(5).toString());
            painter.drawText(9000,i,query.value(6).toString());
           i = i + 700;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {

                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
}}
/*************************************************************************************************************************************
****************************************************************************************************************
****************************************************************************************************************
 ********************************************************TICKET******************************************************/






  //  ui->tableMatch->setModel(tmpmatch.afficher());
   // stadenom = tmpstade.getleutStade();
  /*  for(QString nom : stadenom)
    {
       ui->comboBox_6->addItem(nom);
       ui->comboBox_7->addItem(nom);
    }
    for(QString nom : equipeAdv)
    {
        ui->comboBox_5->addItem(nom);
        ui->comboBox_8->addItem(nom);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}*/


void MainWindow::on_pushButton_tickett_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::on_pushButton_matchh_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


/*void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}*/


void MainWindow::on_pushButton_revenir_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_Rv_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/***********************************Ajout ticket ************************/

void MainWindow::on_pushButton_ajoutticket_clicked()
{
    if((ui->lineEdit->text()=="" ))
    {
        ui->lineEdit->setPlaceholderText("Champs obligatoire");
          }
    else
    {
        int id= ui->lineEdit->text().toInt();

             QDate datee =ui->dateEdit->date();
            QString zone =ui->comboBox_9->currentText();
            QString type =ui->comboBox_10->currentText();

            Ticket c(id,datee,zone,type);

            { bool test=c.ajouter();

             if(test)
           { ui->tableticket->setModel(tmpticket.afficher());//refresh

                 QMessageBox::information(nullptr, QObject::tr("Ajouter un ticket"),
                                   QObject::tr("ticket ajouté.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
             }
             else
             {
                 QMessageBox::information(nullptr, QObject::tr("Ajouter un ticket"),
                                   QObject::tr("erreur.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
             }

           }
    }}

/**************** **************/



void MainWindow::on_pushButton_supp_clicked()
{
        QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"supprimer ticket","Voulez-vous vraiment supprimer ce ticket ? ",QMessageBox::Yes | QMessageBox::No);
    if( reply == QMessageBox::Yes)
    {

    int id = ui->lineEdit_4->text().toInt();
    bool test=tmpticket.supprimer(id);
    if (test)
    {ui->tableticket->setModel(tmpticket.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("supprimer un ticket"),
                                 QObject::tr("ticket supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
           } }
    else
    {QMessageBox::critical(nullptr, QObject::tr("Supprimer un ticket"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

}


/*******************************/




void MainWindow::on_pushButton_18_clicked()
{  if((ui->lineEdit_4->text()=="" ))
    {
        ui->lineEdit->setPlaceholderText("Champs obligatoire");
          }
    else {
    int id= ui->lineEdit_3->text().toInt();
    QDate datee= ui->dateEdit_2->date();
    QString zone= ui->comboBox_11->currentText(); // lineEdit_6
    QString type= ui->comboBox_12->currentText();


    Ticket e(id,datee,zone,type);
    bool test=e.modifier(id,datee,zone,type);


         if(test)
        {
        QMessageBox::information(nullptr, QObject::tr("Modifier un ticket"),
                          QObject::tr("ticket modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tableticket->setModel(tmpticket.afficher());
        }


    else
        QMessageBox::information(nullptr, QObject::tr("Modifier un ticket"),
                          QObject::tr("erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}
}

/************************/

void MainWindow::on_pushButton_aff_clicked()
{
    ui->tableticket->setModel(tmpticket.afficher());
}

void MainWindow::on_pushButton_cherch_clicked()

{ QString id = ui->lineEdit_2->text();
 if(id == "Nord" || id =="Sud" || id== "Ouest" || id=="Est" )
 {
ui->tableticket->setModel(tmpticket.rechercher(id));
 }else {
 ui->tableticket->setModel(tmpticket.rechercherId(id));
}

}
/****************Trier*****************************************/
void MainWindow::on_pushButton_16_clicked()
{
    ui->tableticket->setModel(tmpticket.tri());
}
/*******************/
void MainWindow::on_tableticket_activated(const QModelIndex &index)
{
    idTicket = ui->tableticket->model()->data(index).toString();
    ui->lineEdit_4->setText(idTicket);
    Ticket t = tmpticket.getTicketById(idTicket);
    ui->lineEdit_3->setText(idTicket);
    ui->dateEdit_2->setDate(t.get_datee());

    ui->comboBox_11->setCurrentIndex(ui->comboBox_2->findText(t.get_zone()));
    ui->comboBox_12->setCurrentIndex(ui->comboBox_10->findText(t.get_type()));
}


/*********************************************************************************************************************
 ********************************************************************************************************************
 **********************************MATCH******************************************************************************/
void MainWindow::on_pushButton_ajout_match_clicked()
{
    if((ui->lineEdit_5->text()=="" ))
    {
        ui->lineEdit_5->setPlaceholderText("Champs obligatoire");
          }

    else {
            int idd= ui->lineEdit_5->text().toInt();
            QDate dated =ui->dateEdit_5->date();
            int nb= ui->spinBox_5->text().toInt();
            QString type_m =ui->comboBox_13->currentText();
            QTime heure_m = ui->timeEdit->time();
            QString equipe_ad =ui->comboBox_14->currentText();
            QString lieu =ui->comboBox_15->currentText();


        Match m(idd,dated,nb,type_m,heure_m,equipe_ad,lieu);

        { bool test=m.ajouter();

         if(test)
       { ui->tableMatch->setModel(tmpmatch.afficher());//refresh

             QMessageBox::information(nullptr, QObject::tr("Ajouter un match"),
                               QObject::tr("match ajouté.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
         }
         else
         {
             QMessageBox::information(nullptr, QObject::tr("Ajouter un match"),
                               QObject::tr("erreur.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
         }

       } }
}

void MainWindow::on_pushButton_AffichM_clicked()
{
    ui->tableMatch->setModel(tmpmatch.afficher());//refresh
}

void MainWindow::on_pushButton_chercher_Match_clicked()
{
 QString id = ui->lineEdit_7->text();
 ui->tableMatch->setModel(tmpmatch.rechercherId(id));
}

void MainWindow::on_pushButton_T_clicked()
{
    ui->tableMatch->setModel(tmpmatch.tri());
}

void MainWindow::on_pushButton_Spr_clicked()
{
    QMessageBox::StandardButton reply;
reply = QMessageBox::question(this,"supprimer match","Voulez-vous vraiment supprimer ce match ?",QMessageBox::Yes | QMessageBox::No);
if( reply == QMessageBox::Yes)
{

  //  int idd = ui->lineEdit_6->text().toInt();

        bool test=tmpmatch.supprimer(idMatch.toInt());
        if (test)
        {ui->tableMatch->setModel(tmpmatch.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("supprimer un match"),
                                     QObject::tr("match supprimé.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
               }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un match"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}
}

void MainWindow::on_pushButton_Modif_Match_clicked()
{   if((ui->lineEdit_8->text()=="" ))
    {
        ui->lineEdit_8->setPlaceholderText("Champs obligatoire");
          }
    else {
    int idd= ui->lineEdit_8->text().toInt();

         QDate dated =ui->dateEdit_6->date();

            int nb= ui->spinBox_6->text().toInt();
            QString type_m =ui->comboBox_16->currentText();
            QTime heure_m =ui->timeEdit_2->time();
            QString equipe_ad =ui->comboBox_17->currentText();
            QString lieu =ui->comboBox_18->currentText();

        Match m(idd,dated,nb,type_m,heure_m,equipe_ad,lieu);
        bool test=m.modifier(idd,dated,nb,type_m,heure_m,equipe_ad,lieu);///////////////////////////



            if(test)
           { ui->tableMatch->setModel(tmpmatch.afficher());//refresh
           QMessageBox::information(nullptr, QObject::tr("Modifier un match"),
                             QObject::tr("match modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
           }


       else
           QMessageBox::information(nullptr, QObject::tr("Modifier un match"),
                             QObject::tr("erreur.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}
}





void MainWindow::on_tableMatch_activated(const QModelIndex &index)
{
        idMatch = ui->tableMatch->model()->data(index).toString();
        Match m = tmpmatch.getMatchById(idMatch);
        ui->lineEdit_8->setText(idMatch);
        ui->dateEdit_6->setDate(m.get_dated());
        ui->timeEdit_2->setTime(m.get_heure_m());
        ui->spinBox_6->setValue(m.get_nb());
        ui->comboBox_16->setCurrentIndex(ui->comboBox_4->findText(m.get_type_m()));
        ui->comboBox_17->setCurrentIndex(ui->comboBox_8->findText(m.get_equipe_ad()));
        ui->comboBox_18->setCurrentIndex(ui->comboBox_7->findText(m.get_lieu()));
}

