#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "conge.h"
#include "employe.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
int id;
QString rech="",filtre="Toutes les congés",filename2="";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_gestionConges_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->rech->setPlaceholderText("chercher par nom ou cause du conge");
    ui->table_Conges->setModel(tmpconge.afficher(rech,filtre));
    ui->dateD->setDate(QDate::currentDate());
    ui->dateF->setDate(QDate::currentDate());
    ui->btnUpdate_Conges->setDisabled(true);
    ui->btnDelete_Conges->setDisabled(true);
    ui->accepter->setDisabled(true);
    ui->refuser->setDisabled(true);

}

void MainWindow::on_gestionEmployes_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->tableAgent->setModel(tmpemp.afficher());
    QImage image;
    bool valid=image.load("D:/ProjetFinale/ProjetFinale/projetA/none.png");
    if(valid)
    {
        image=image.scaledToWidth(ui->imgF->width(),Qt::SmoothTransformation);
        ui->imgF->setPixmap(QPixmap::fromImage(image));
    }
    ui->cinF->setDisabled(true);
}

void MainWindow::on_btnCREATE_Conges_clicked()
{
    bool test=true;
    QString msg="";
    QString cause=ui->cause->currentText();
    QString cin=ui->cinE->text();
    int id=tmpconge.getIdA(cin);
    QDate dated=ui->dateD->date();
    QDate datef=ui->dateF->date();
    QString dateD=ui->dateD->date().toString("dd/MM/yyyy");
    QString dateF=ui->dateF->date().toString("dd/MM/yyyy");
    if(id==-1)
    {
        test=false;
             ui->cinE->setText("");
            if(msg=="")
            msg="employe inexistant";
    }
    if(dated<QDate::currentDate())
    {test=false;
     ui->dateD->setDate(QDate::currentDate());
    if(msg=="")
    msg="date debut superieur a la date actuelle";
    }
    if(datef<dated)
    {
        test=false;
             ui->dateF->setDate(dated);
            if(msg=="")
            msg="date debut superieur a la date fin";
    }
    if(tmpconge.check(dated,id)==false)
    {
        test=false;
        if(msg=="")
        msg="une demande est deja en cours";

    }
    if(test==false)
    {
       QMessageBox::critical(this,"warning",msg);
    }
    else
     {conge c(cause,dateD,dateF,id,"en attente");
        c.ajouter();
        QMessageBox::critical(this,"warning","conge ajouté");
        ui->table_Conges->setModel(tmpconge.afficher(rech,filtre));
    }
}

void MainWindow::on_btnUpdate_Conges_clicked()
{
    bool test=true;
    QString msg="";
    QString cause=ui->cause->currentText();
    QString cin=ui->cinE->text();
    int ida=tmpconge.getIdA(cin);
    QDate dated=ui->dateD->date();
    QDate datef=ui->dateF->date();
    QString dateD=ui->dateD->date().toString("dd/MM/yyyy");
    QString dateF=ui->dateF->date().toString("dd/MM/yyyy");
    if(dated<QDate::currentDate())
    {test=false;
     ui->dateD->setDate(QDate::currentDate());
    if(msg=="")
    msg="date debut superieur a la date actuelle";
    }
    if(cin=="")
    {
        test=false;
            if(msg=="")
            msg="ajouter un CIN";
    }
    if(datef<dated)
    {
        test=false;
             ui->dateF->setDate(dated);
            if(msg=="")
            msg="date debut superieur a la date fin";
    }
    if(test==false)
    {
       QMessageBox::critical(this,"warning",msg);
    }
    else
     {conge c(cause,dateD,dateF,ida,"en attente");
        if(c.modifier(id)==false)
        QMessageBox::critical(this,"warning","employe inexistant");
        else
        {
        QMessageBox::critical(this,"warning","conge modifié");
        ui->accepter->setDisabled(true);
        ui->refuser->setDisabled(true);
        ui->btnDelete_Conges->setDisabled(true);
        ui->btnUpdate_Conges->setDisabled(true);
        id=-1;
        }
        ui->table_Conges->setModel(tmpconge.afficher(rech,filtre));
    }
}

void MainWindow::on_table_Conges_doubleClicked(const QModelIndex &index)
{
  id=ui->table_Conges->model()->data(index).toInt();
  ui->btnDelete_Conges->setEnabled(true);
  ui->btnUpdate_Conges->setEnabled(true);
  ui->accepter->setEnabled(true);
  ui->refuser->setEnabled(true);
  conge c=tmpconge.getConge(id);
  ui->cinE->setText(tmpemp.getC(c.get_id_agent()));
  ui->cause->setCurrentText(c.get_cause());
  QString dd=c.get_date_debut();
  ui->dateD->setDate(QDate::fromString(dd));
  ui->dateF->setDate(QDate::fromString(c.get_date_fin()));

}

void MainWindow::on_btnDelete_Conges_clicked()
{
    tmpconge.supprimer(id);
    ui->table_Conges->setModel(tmpconge.afficher(rech,filtre));
}

void MainWindow::on_btnHome_Conges_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_filtre_currentTextChanged(const QString &arg1)
{
    filtre=arg1;
    ui->table_Conges->setModel(tmpconge.afficher(rech,filtre));
}

void MainWindow::on_rech_textEdited(const QString &arg1)
{
    rech=arg1;
    ui->table_Conges->setModel(tmpconge.afficher(rech,filtre));
}

void MainWindow::on_refuser_clicked()
{
tmpconge.modifierRefuse(id);
ui->table_Conges->setModel(tmpconge.afficher(rech,filtre));
}

void MainWindow::on_accepter_clicked()
{
    tmpconge.modifierAccepte(id);
    ui->table_Conges->setModel(tmpconge.afficher(rech,filtre));
}

void MainWindow::on_btnHome_Employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    filename2=QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images (*.png *.jpg *.bmp *.jpeg)"));
    if(QString::compare(filename2,QString())!=0)
    {
        QImage image;
        bool valid=image.load(filename2);
        if(valid)
        {
            image=image.scaledToWidth(ui->labe->width(),Qt::SmoothTransformation);
            ui->labe->setPixmap(QPixmap::fromImage(image));
        }
    }
}
bool chaineNum1(QString ch)
{
    bool test=true;
        for(int i=0;i<ch.length();i++)
        {
            if((ch[i]<'0')||(ch[i]>'9'))
                test=false;
        }
        return test;
}
bool chaineAlpha1(QString ch)
{bool test=true;
    for(int i=0;i<ch.length();i++)
    {
        if((ch[i]<'A')||(ch[i]>'z')||((ch[i]>'Z')&&(ch[i]<'a')))
        {test=false;
        }
    }
    return test;
}
void MainWindow::on_ajouterA_3_clicked()
{
    bool test=true;
        ui->lineEdit_cin_5->setReadOnly(false);
        QString msg="";
        QString gendre="";
        QString cin = ui->lineEdit_cin_5->text();
        QString nom = ui->lineEdit_nom_6->text();
        QString prenom = ui->lineEdit_prenom2_5->text();
        QString image =filename2;
        QString adresse = ui->lineEdit_adresse_5->text();
        QString ville = ui->lineEdit_ville_5->text();
        QString salaire = ui->lineEdit_salaire_5->text();
        int age = ui->lineEdit_age_5->text().toInt();
        if(ui->male_3->isCheckable())
        {
        gendre="male";
        }
        else  gendre="female";
        if(ui->ajouterA_3->text()=="Ajouter")
        {
            if((chaineNum1(cin)==false)||(cin.length()!=8))
            {
                test=false;
                ui->lineEdit_cin_5->clear();
                if(msg=="")
                msg="cin doit etre forme de 8 chiffres";
            }
            if((chaineAlpha1(nom)==false)||(nom.length()==0)||(nom.length()>20))
            {   test=false;
                ui->lineEdit_nom_6->clear();
                if(msg=="")
                msg="nom est une chaine de caracteres de longeur maximale egal a 20";
            }
            if((chaineAlpha1(prenom)==false)||(prenom.length()==0)||(prenom.length()>20))
            {
                test=false;
                ui->lineEdit_prenom2_5->clear();
                if(msg=="")
                msg="prenom est une chaine de caracteres de longeur maximale egal a 20";
            }

            if(gendre=="")
            {
                test=false;
                if(msg=="")
                msg="veuillez choisir votre sexe";
            }
            if((adresse.length()==0)||(adresse.length()>50))
            {
                test=false;
                ui->lineEdit_adresse_5->clear();
                if(msg=="")
                msg="Veuillez saisir une adresse";
            }
            if((chaineAlpha1(ville)==false)||(ville.length()==0)||(ville.length()>20))
            {
                test=false;
                ui->lineEdit_ville_5->clear();
                if(msg=="")
                msg="ville est une chaine de caracteres de longeur maximale egal a 20";
            }
            if(filename2=="")
            {
                test=false;
                if(msg=="")
                msg="le choix d'une image est obligatoire";
            }
         if(test==true)
         {employe e(cin,nom,prenom,salaire,gendre,ville,adresse,image,"",age);
         if(!(e.ajouter()))
            {
             QMessageBox::information(this,"erreur","erreur");
         }
         }
          else
          {
              QMessageBox::critical(this,"warning",msg);
          }
        }
        else
        {
         employe e(cin,nom,prenom,salaire,gendre,ville,adresse,image,"",age);
         if(e.modifier(e.get_cin()))
             QMessageBox::information(this,"erreur","agent modifier");
        }
        ui->tableAgent->setModel(tmpemp.afficher());
}

void MainWindow::on_tableAgent_doubleClicked(const QModelIndex &index)
{
    QString cin=ui->tableAgent->model()->data(index).toString();
        employe e=tmpemp.remplirFiche(cin);
        ui->lineEdit_cin_5->setText(e.get_cin());
        ui->lineEdit_nom_6->setText(e.get_nom());
        ui->lineEdit_prenom2_5->setText(e.get_prenom());
        ui->lineEdit_salaire_5->setText(e.get_salaire());
        ui->lineEdit_age_5->setText(QString::number(e.get_age()));
        ui->lineEdit_ville_5->setText(e.get_ville());
        ui->lineEdit_adresse_5->setText(e.get_adresse());
        if(e.get_gendre()=="male")
            ui->male_3->setChecked(true);
        else
        ui->female_3->setChecked(true);
        QImage image;
        filename2=e.get_image();
        bool valid=image.load(e.get_image());
        if(valid)
        {
            image=image.scaledToWidth(ui->labe->width(),Qt::SmoothTransformation);
            ui->labe->setPixmap(QPixmap::fromImage(image));
        }
        ui->ajouterA_3->setText("Modifier");
        ui->lineEdit_cin_5->setReadOnly(true);
}

void MainWindow::on_consulter_clicked()
{
    QModelIndex index = ui->tableAgent->currentIndex();
    QString cin = index.data(Qt::DisplayRole).toString();
    employe e=tmpemp.remplirFiche(cin);
    ui->cinF->setText(e.get_cin());
    ui->cinF->setDisabled(true);
    ui->nomF->setText(e.get_nom());
    ui->nomF->setDisabled(true);
    ui->prenomF->setText(e.get_prenom());
    ui->prenomF->setDisabled(true);
    ui->ageF->setText(QString::number(e.get_age()));
    ui->ageF->setDisabled(true);
    ui->villeF->setText(e.get_ville());
    ui->villeF->setDisabled(true);
    ui->adresseF->setText(e.get_adresse());
    ui->adresseF->setDisabled(true);
    QImage image;
    bool valid=image.load(e.get_image());
    if(valid)
    {
        image=image.scaledToWidth(ui->imgF->width(),Qt::SmoothTransformation);
        ui->imgF->setPixmap(QPixmap::fromImage(image));
    }
}

void MainWindow::on_suppA_clicked()
{
    QItemSelectionModel *select = ui->tableAgent->selectionModel();
    QModelIndexList list;
    if(select->hasSelection())
    list=select->selectedRows();
    for(int i=0; i< list.count(); i++)
    {
        tmpemp.supprimer(list[i].data().toString());
    }
    ui->tableAgent->setModel(tmpemp.afficher());
}

void MainWindow::on_pdf_2_clicked()
{
    employe e=tmpemp.remplirFiche(ui->cinF->text());
        QString strStream;
           QTextStream out(&strStream);

           out <<"<html>\n"
                 "<head>\n"
                  "<meta Content=\"Text/html; charset=Windows-1251\">\n"
               << "<title>Fiche Technique</title>\n "
               << "<style>"
                  "input{font_weight:bold; font_size:17px;}"
                  "h2{text-align: center;}"
                  "</style>\n "
               << "</head>\n"
               "<body background-color=#ffffff >\n"
               "<h2> Fiche Technique </h2>";
                  out <<"<br>";
                  out <<"<br>";
                  out <<"<br>";
                  out <<"<br>";
                  out <<"<br>";
                 "<form>\n"
                 "<fieldset>\n";
           QString d_cin=e.get_cin();
           out << QString("<label>Cin: </label><input type=\"text\"> %1").arg((!d_cin.isEmpty()) ? d_cin : QString("&nbsp;"));
           out <<"<br>";
           out <<"<br>";
           out <<"<br>";
           QString d_nom=e.get_nom();
           out << QString("<label>Nom: </label><input type=\"text\"> %1").arg((!d_nom.isEmpty()) ? d_nom : QString("&nbsp;"));
           out <<"<br>";
           out <<"<br>";
           out <<"<br>";
           QString d_prenom=e.get_prenom();
           out << QString("<label>Prenom: </label><input type=\"text\"> %1").arg((!d_prenom.isEmpty()) ? d_prenom : QString("&nbsp;"));
           out <<"<br>";
           out <<"<br>";
           out <<"<br>";
           QString d_age=QString::number(e.get_age());
           out << QString("<label>Age: </label><input type=\"text\"> %1").arg((!d_age.isEmpty()) ? d_age : QString("&nbsp;"));
           out <<"<br>";
           out <<"<br>";
           out <<"<br>";
           QString d_ville=e.get_ville();
           out << QString("<label>Ville: </label><input type=\"text\"> %1").arg((!d_ville.isEmpty()) ? d_ville : QString("&nbsp;"));
           out <<"<br>";
           out <<"<br>";
           out <<"<br>";
           QString d_adresse=e.get_adresse();
           out << QString("<label>Adresse: </label><input type=\"text\"> %1").arg((!d_adresse.isEmpty()) ? d_adresse : QString("&nbsp;"));
           out <<"<br>";
           out <<"<br>";
           out <<"<br>";
           out <<  "</fieldset>\n"
                   "</form>\n"
               "</body>\n"
               "</html>\n";

           QTextDocument *document = new QTextDocument();
           document->setHtml(strStream);

           QPrinter printer;

           QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
           if (dialog->exec() == QDialog::Accepted) {
               document->print(&printer);
           }

           delete document;
}
