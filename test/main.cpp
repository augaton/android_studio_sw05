#include <iostream>
#include <string>
#include <string.h>
#include "IRClientTCP.h"
#include <unistd.h>

#define LENGTH_CHAINE 28

unsigned int ChaineHexaVersInt(char *chaine, int nbcar);
int CalculerVitesse(int vitesse);
int CalculerRegimeMoteur(int regime);

int CalculerVitesse(int vitesse)
{
    return vitesse * 2.55;
}

int CalculerRegimeMoteur(int vitesse)
{
    return (vitesse * 100) / 3.1;
}

unsigned int ChaineHexaVersInt(char *chaine, int nbcar)
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

int main(void)
{

    IRClientTCP monclient;
    char TrameCan[50], idCan[10];

    while (true)
    {

        strcpy(idCan, "128");
        monclient.SeConnecterAUnServeur("172.20.21.66", 4111);

        monclient.Envoyer(idCan, strlen(idCan));
        int n=monclient.Recevoir(TrameCan, 50);
        TrameCan[n]=0;
        std::cout << "TrameCan = " << TrameCan << std::endl;

        int chaine_int = ChaineHexaVersInt(TrameCan + 19, 2);
        int regime_moteur = CalculerRegimeMoteur(chaine_int);

        int second_chaine_int = ChaineHexaVersInt(TrameCan + 23, 2);
        int vitesse = CalculerVitesse(second_chaine_int);

        unsigned char octet = ChaineHexaVersInt(TrameCan + 27, 2);

        std::cout << "octet = " << (int)octet << std::endl;
        //std::cout << "regime moteur = " << regime_moteur << std::endl;
        // std::cout << "vitesse = " << vitesse << std::endl;

        monclient.SeDeconnecter();

        if (strcmp(idCan, "128") == 0)
        {
            strcpy(idCan, "0B6");
        }
        else
        {
            strcpy(idCan, "128");
        }

        sleep(3);
    }

    return 0;
}