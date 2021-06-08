#include "FenTaille.h"


int FenTaille::longueur = 500;
int FenTaille::hauteur = 500;

FenTaille::FenTaille(Canevas *canevas) : QWidget()
{

    QVBoxLayout *layout = new QVBoxLayout(this);
    longueurLine = new QLineEdit;
    hauteurLine = new QLineEdit;
    QFormLayout *donne = new QFormLayout;

    donne->addRow("Entrer la longeur (x)",longueurLine);
    donne->addRow("Entrer la hauteur (y)",hauteurLine);


    creer = new QPushButton("Creer");
    layout->addLayout(donne);
    layout->addWidget(creer);
    connect(creer,SIGNAL(clicked(bool)),canevas,SLOT(nouveauCanevas()));
    connect(longueurLine,SIGNAL(textChanged(QString)),this,SLOT(getLongueurLine(QString)));
    connect(hauteurLine,SIGNAL(textChanged(QString)),this,SLOT(getHauteurLine(QString)));

    connect(creer,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void FenTaille::creerClick()
{

    this->show();

}
//Fonctions slots
void FenTaille::getLongueurLine(QString lLine)
{
    longueur = lLine.toInt();
}
void FenTaille::getHauteurLine(QString hLine)
{
    hauteur = hLine.toInt();
}

//FOnctions
int FenTaille::getLongueur()
{
    return longueur;
}

int FenTaille::getHauteur()
{
    return hauteur;
}
