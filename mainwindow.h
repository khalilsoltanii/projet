#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "conge.h"
#include "employe.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_gestionConges_clicked();

    void on_gestionEmployes_clicked();

    void on_btnCREATE_Conges_clicked();

    void on_btnUpdate_Conges_clicked();

    void on_table_Conges_doubleClicked(const QModelIndex &index);

    void on_btnDelete_Conges_clicked();

    void on_btnHome_Conges_clicked();

    void on_filtre_currentTextChanged(const QString &arg1);

    void on_rech_textEdited(const QString &arg1);

    void on_refuser_clicked();

    void on_accepter_clicked();

    void on_btnHome_Employes_clicked();

    void on_pushButton_clicked();

    void on_ajouterA_3_clicked();

    void on_tableAgent_doubleClicked(const QModelIndex &index);

    void on_consulter_clicked();

    void on_suppA_clicked();

    void on_pdf_2_clicked();

private:
    Ui::MainWindow *ui;
    conge tmpconge;
    employe tmpemp;

};
#endif // MAINWINDOW_H
