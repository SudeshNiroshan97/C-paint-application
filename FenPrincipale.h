#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>


class FenPrincipale : public QMainWindow
{

   Q_OBJECT

public:
    FenPrincipale();
    bool getDrawEnable();
    bool getRectangleEnable();
    bool getCercleEnable();
    bool getTraitEnable();
    bool getRemplirEnable();
    QColor getCouleur();
    int getVeleurSlider();

public slots :

    void slotDraw();
    void slotRectangle();
    void slotCercle();
    void slotTrait();
    void slotRemplir();
    void slotCouleur();

    void slotSlider(int x);

private:
    bool drawEnable;
    bool rectangleEnable;
    bool cercleEnable;
    bool traitEnable;
    bool remplirEnable;
    int valeurSlider;
    QColorDialog *couleurDialogue;
    QColor couleur;
};

#endif
