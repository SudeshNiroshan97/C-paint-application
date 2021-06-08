#include "FenPrincipale.h"
#include "Canevas.h"
#include "FenTaille.h"

FenPrincipale::FenPrincipale()
{
    resize(500,500);
    //Initialisation variables
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    traitEnable = 0;
    valeurSlider = 1;


    Canevas *canevas = new Canevas(this);
    FenTaille *fenetretaille = new FenTaille(canevas);
    setCentralWidget(canevas);

    //Menu Fichier
    QMenu *menuFichier = menuBar()->addMenu("Fichier");

    QAction *actionNouveau = new QAction("Nouveau",this);
    menuFichier->addAction(actionNouveau);
    QAction *actionSauvegarder = new QAction("Sauvegarder",this);
    menuFichier->addAction(actionSauvegarder);
    QAction *actionOuvrir = new QAction("Ouvrir",this);
    menuFichier->addAction(actionOuvrir);

    connect(actionNouveau,SIGNAL(triggered(bool)),fenetretaille,SLOT(creerClick()));
    connect(actionSauvegarder,SIGNAL(triggered(bool)),canevas,SLOT(sauvegarderCanevas()));
    connect(actionOuvrir,SIGNAL(triggered(bool)),canevas,SLOT(ouvrirCanevas()));

    //Menu forme
    QMenu *menuForme = menuBar()->addMenu("&Forme");

    QAction *actionDraw = new QAction("Dessiner",this);
    menuForme->addAction(actionDraw);
    QAction *actionRectangle = new QAction("Rectangle",this);
    menuForme->addAction(actionRectangle);
    QAction *actionCercle = new QAction("Cercle",this);
    menuForme->addAction(actionCercle);
    QAction *actionTrait = new QAction("Trait",this);
    menuForme->addAction(actionTrait);


    connect(actionDraw,SIGNAL(triggered(bool)),this,SLOT(slotDraw()));
    connect(actionRectangle,SIGNAL(triggered(bool)),this,SLOT(slotRectangle()));
    connect(actionCercle,SIGNAL(triggered(bool)),this,SLOT(slotCercle()));
    connect(actionTrait,SIGNAL(triggered(bool)),this,SLOT(slotTrait()));

    //Menu outils
    QMenu *menuOutils = menuBar()->addMenu("Outils");

    QAction *actionRemplir = new QAction("Remplir",this);
    menuOutils->addAction(actionRemplir);
    QAction *actionRetour = new QAction("Retour en arrière",this);
    actionRetour->setShortcut(QKeySequence("Ctrl+Z"));
    menuOutils->addAction(actionRetour);

    connect(actionRemplir,SIGNAL(triggered(bool)),this,SLOT(slotRemplir()));
    connect(actionRetour,SIGNAL(triggered(bool)),canevas,SLOT(retourCanevas()));
    //Barre d'outil
    QToolBar *toolBar = addToolBar("Couleur");

    QPushButton *boutonCouleur = new QPushButton;
    boutonCouleur->setText("Couleur");
    couleurDialogue = new QColorDialog;
    toolBar->addWidget(boutonCouleur);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(1,15);
    toolBar->addWidget(slider);

    connect(boutonCouleur,SIGNAL(clicked(bool)),this,SLOT(slotCouleur()));
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(slotSlider(int)));
}
//FONCTIONS

bool FenPrincipale::getDrawEnable()
{
    return drawEnable;
}
bool FenPrincipale::getRectangleEnable()
{
    return rectangleEnable;
}
bool FenPrincipale::getCercleEnable()
{
    return cercleEnable;
}
bool FenPrincipale::getTraitEnable()
{
    return traitEnable;
}

bool FenPrincipale::getRemplirEnable()
{
    return remplirEnable;
}

QColor FenPrincipale::getCouleur()
{
    return couleur;
}
int FenPrincipale::getVeleurSlider()
{
    return valeurSlider;
}

//SLOTS
void FenPrincipale::slotDraw()
{
    drawEnable = 1;
    rectangleEnable = 0;
    cercleEnable = 0;
    remplirEnable = 0;
    traitEnable = 0;
}
void FenPrincipale::slotRectangle()
{
    drawEnable = 0;
    rectangleEnable = 1;
    cercleEnable = 0;
    remplirEnable = 0;
    traitEnable = 0;
}
void FenPrincipale::slotCercle()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 1;
    remplirEnable = 0;
    traitEnable = 0;
}
void FenPrincipale::slotRemplir()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    remplirEnable = 1;
    traitEnable = 0;
}

void FenPrincipale::slotTrait()
{
    drawEnable = 0;
    rectangleEnable = 0;
    cercleEnable = 0;
    remplirEnable = 0;
    traitEnable = 1;
}

void FenPrincipale::slotCouleur()
{
    couleur = couleurDialogue->getColor();
}

void FenPrincipale::slotSlider(int x)
{
    valeurSlider = x;
}


