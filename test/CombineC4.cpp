#include "CombineC4.h"

CombineC4::CombineC4(char trameCan, char idCan, int vitesse, int regime, bool croisement, bool antibrouillard, bool route, bool clignoD, bool clignoG)
{
}

int CombineC4::Vitesse()
{
    return this->vitesse;
}

int CombineC4::Regime()
{
    return this->regime;
}

int CombineC4::Antibrouillard()
{
    return this->antibrouillard;
}

int CombineC4::ClignoD()
{
    return this->clignoD;
}

int CombineC4::ClignoG()
{
    return this->clignoG;
}

unsigned int CombineC4::ChaineHexaVersInt(char *chaine, int nbcar)
{
    int nombre = 0, j;
    char caractere;

    for (j = 0; j < nbcar; j++)
    {
        caractere = chaine[j];

        if (caractere >= '0' && caractere <= '9')
        {
            nombre = nombre + ((caractere - '0') << (4 * (nbcar - j - 1)));
        }
        else
        {
            nombre = nombre + ((caractere - 'A' + 10) << (4 * (nbcar - j - 1)));
        }
    }

    return nombre;
}

void CombineC4::EngistreDonneesCAN(char *idCan, char *trameCAN)
{
    
}

CombineC4::~CombineC4()
{
}
