#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "compte.h"
#include "reclamation.h"
#include <QMessageBox>
#include <QDate>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabcompte->setModel(tmpcompte.afficher());
    ui->comboBox->addItem("Employee");
    ui->comboBox->addItem("Joueur");
    ui->comboBox_2->addItem("Employee");
    ui->comboBox_2->addItem("Joueur");






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


void MainWindow::on_pushButton_Menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_Menu2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}



void MainWindow::on_pushButton_Ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString password = ui->lineEdit_mdp->text();
    QString asq = ui->comboBox->currentText();
    QString nom = ui->lineEdit_nom->text();

     Compte e(password,asq,id,nom);
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
}


void MainWindow::on_pushButton_Supprimer_clicked()
{
    int id = ui->lineEdit_id2->text().toInt();
    bool test=tmpcompte.supprimer(id);
    if (test)
    {ui->tabcompte->setModel(tmpcompte.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("supprimer un compte"),
                                 QObject::tr("compte supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
           }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un compte"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_Modifier_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString password = ui->lineEdit_mdp->text();
    QString asq = ui->comboBox->currentText();
    QString nom = ui->lineEdit_nom->text();

     Compte e(password,asq,id,nom);
          bool test= e.modifier();
          if(test)
          {
             ui->tabcompte->setModel(tmpcompte.afficher());//refresh
              QMessageBox::information(nullptr, QObject::tr("modifer  un compte"),
                                                    QObject::tr("modification avec succés.\n"
                                                                "cliquez annuler pour sortir."), QMessageBox::Cancel);
                                }
                                    else
                                        QMessageBox::information(nullptr, QObject::tr("modifier un compte"),
                                                    QObject::tr("erreur de modification.\n"
                                                                "cliquez annuler pour sortir."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_6_clicked()
{
    int id1 = ui->lineEdit_2->text().toInt();
        QSqlQueryModel * model= new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery();
        qry->prepare("SELECT * from compte where id like concat (:id1,'%')");
        qry->bindValue(":id1",id1);
        qry->exec();
        model->setQuery(*qry);
        ui->tabcompte->setModel(model) ;
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tabcompte->setModel(tmpcompte.tri_compte());
}






void MainWindow::on_pushButton_Ajout2_clicked()
{
       int idd= ui->lineEdit_idd->text().toInt();
        QString ass =ui->comboBox_2->currentText();
         QDate datee =ui->dateEdit_data1->date();
        QString reclm =ui->lineEdit_recl->text();
        QString nom =ui->lineEdit_nomm->text();
        QString mail =ui->lineEdit_mail->text();

        reclamation c(idd,ass,datee,reclm,nom,mail);

            bool test=c.ajouter();

             if(test)
           { ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
                 QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                                   QObject::tr("reclamation ajouté.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
             }
             else
             {
                 QMessageBox::information(nullptr, QObject::tr("Ajouter un compte"),
                                   QObject::tr("erreur.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
             }

           }


void MainWindow::on_pushButton_Modifier2_clicked()
{
    int idd= ui->lineEdit_idd->text().toInt();
     QString ass =ui->comboBox_2->currentText();
      QDate datee =ui->dateEdit_data1->date();
     QString reclm =ui->lineEdit_recl->text();
     QString nom =ui->lineEdit_nomm->text();
     QString mail =ui->lineEdit_mail->text();

     reclamation c(idd,ass,datee,reclm,nom,mail);
          bool test= c.modifier();
          if(test)
          {
             ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
              QMessageBox::information(nullptr, QObject::tr("modifer  un compte"),
                                                    QObject::tr("modification avec succés.\n"
                                                                "cliquez annuler pour sortir."), QMessageBox::Cancel);
                                }
                                    else
                                        QMessageBox::information(nullptr, QObject::tr("modifier un compte"),
                                                    QObject::tr("erreur de modification.\n"
                                                                "cliquez annuler pour sortir."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_Supprimer2_clicked()
{

            int idd = ui->lineEdit_idd2->text().toInt();
            bool test=tmpreclamations.supprimer(idd);
            if (test)
            {ui->liste_reclamation->setModel(tmpreclamations.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("supprimer une reclamation"),
                                         QObject::tr("compte supprimé.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                   }
            else
                QMessageBox::critical(nullptr, QObject::tr("Supprimer une reclamation"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_3_clicked()
{
    int id2 = ui->lineEdit->text().toInt();
        QSqlQueryModel * model= new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery();
        qry->prepare("SELECT * from reclamation where idd like concat (:id2,'%')");
        qry->bindValue(":id2",id2);
        qry->exec();
        model->setQuery(*qry);
        ui->liste_reclamation->setModel(model) ;
}

void MainWindow::on_pushButton_4_clicked()
{
     ui->liste_reclamation->setModel(tmpreclamations.tri_reclm());
}



