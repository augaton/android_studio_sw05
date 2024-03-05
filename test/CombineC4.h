#ifndef COMBINEC4_H
#define COMBINEC4_H

class CombineC4
{
private:
    char *trameCan;
    char *idCan;
    int vitesse;
    int regime;
    int croisement;
    int antibrouillard;
    int route;
    bool clignoD;
    bool clignoG;

public:
    CombineC4(char trameCan, char idCan, int vitesse, int regime, bool croisement, bool antibrouillard, bool route, bool clignoD, bool clignoG);

    int Vitesse();
    int Regime();
    int Croisement();
    int Antibrouillard();
    int Route();
    int ClignoD();
    int ClignoG();
    unsigned int ChaineHexaVersInt(char *chaineHexa, int nbCar);
    void EngistreDonneesCAN(char *idCan, char *trameCAN);

    ~CombineC4();
};


CombineC4::CombineC4(char trameCan, char idCan, int vitesse, int regime, bool croisement, bool antibrouillard, bool route, bool clignoD, bool clignoG)
{
}

CombineC4::~CombineC4()
{
}

#endif