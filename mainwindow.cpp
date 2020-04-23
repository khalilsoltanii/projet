#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ticket.h"
#include "match.h"
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableticket->setModel(tmpticket.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
        /*******************   AJOUT ***********************************************/

void MainWindow::on_pushButton_5_clicked()
{
    if((ui->lineEdit->text()=="" ) || (ui->lineEdit->text()=="   *champ obligatoire"))
    {
        ui->lineEdit->setText("   *champ obligatoire");
          }
    else
    {
        int id= ui->lineEdit->text().toInt();

             QDate datee =ui->dateEdit->date();
            QString zone =ui->comboBox->currentText();
            QString type =ui->lineEdit_6->text();

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
    }
}

/**************** SUPPRIMER****************/



void MainWindow::on_pushButton_7_clicked()
{
    int id = ui->lineEdit_3->text().toInt();
    bool test=tmpticket.supprimer(id);
    if (test)
    {ui->tableticket->setModel(tmpticket.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("supprimer un ticket"),
                                 QObject::tr("ticket supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
           }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un ticket"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}




/***********************************MODIFIER****************/




void MainWindow::on_pushButton_8_clicked()
{  int id= ui->lineEdit_4->text().toInt();
    QDate datee= ui->dateEdit_2->date();

    QString zone= ui->comboBox->currentText(); // lineEdit_6
    QString type =ui->lineEdit_6->text();


    Ticket e(id, datee,zone,type);
     bool test=e.modifier(id);



         if(test)
        {
        QMessageBox::information(nullptr, QObject::tr("Modifier un ticket"),
                          QObject::tr("ticket modifié.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        }


    else
        QMessageBox::information(nullptr, QObject::tr("Modifier un ticket"),
                          QObject::tr("erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

/********************** AFFICHER ***********/

void MainWindow::on_pushButton_6_clicked()
{
    ui->tableticket->setModel(tmpticket.afficher());
}
/**************chercher*********/
void MainWindow::on_pushButton_9_clicked()
{
 QString id = ui->lineEdit_5->text();
 if(id == "Nord" || id =="Sud" || id== "Ouest" || id=="Est" )
 {
ui->tableticket->setModel(tmpticket.rechercher(id));
 }else {
 ui->tableticket->setModel(tmpticket.rechercherId(id));
}

}
/****************Trier*****************************************/
void MainWindow::on_pushButton_10_clicked()
{
    ui->tableticket->setModel(tmpticket.tri());
}
/*****************************************Match**********************/


void MainWindow::on_pushButton_26_clicked()
{
    int idd= ui->lineEdit_2->text().toInt();

         QDate dated =ui->dateEdit_3->date();
           QDate datef =ui->dateEdit_4->date();
            int nb= ui->lineEdit_9->text().toInt();

        Match m(idd,dated,datef,nb);

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

       }
}
/**********************Afficher*****************************/
void MainWindow::on_pushButton_12_clicked()
{
    ui->tableMatch->setModel(tmpmatch.afficher());//refresh
}
/**********************Recherche*****************************/
void MainWindow::on_pushButton_14_clicked()
{
 QString id = ui->lineEdit_11->text();
 ui->tableMatch->setModel(tmpmatch.rechercherId(id));
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->tableMatch->setModel(tmpmatch.tri());
}
/*********************Supprimer match *******************************/
void MainWindow::on_pushButton_11_clicked()
{
    int idd = ui->lineEdit_7->text().toInt();
    bool test=tmpmatch.supprimer(idd);
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
/**********************************Modifier*******************/
void MainWindow::on_pushButton_13_clicked()
{
    int idd= ui->lineEdit_8->text().toInt();

         QDate dated =ui->dateEdit_5->date();
           QDate datef =ui->dateEdit_6->date();
            int nb= ui->lineEdit_10->text().toInt();

        Match m(idd,dated,datef,nb);
        bool test=m.modifier(idd);



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




