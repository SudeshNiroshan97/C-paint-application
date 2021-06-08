#ifndef HEADER_FENTAILLE
#define HEADER_FENTAILLE



#include <QtWidgets>
#include <Canevas.h>
class FenTaille : public QWidget
{
    Q_OBJECT
public:
    FenTaille(Canevas *canevas );
    static int getLongueur();
    static int getHauteur();



public slots:
    void creerClick();
    void getLongueurLine(QString lLine);
    void getHauteurLine(QString hLine);

private:
    static int longueur;
    static int hauteur;
    QLineEdit *longueurLine;
    QLineEdit *hauteurLine;
    QPushButton *creer;



};

#endif
