//---------------------------------------------------------------------------
#pragma hdrstop
#include "CombineC4.h"
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
CombineC4::CombineC4()
{
}
int CombineC4::Vitesse()
{   return vitesse;
}
int CombineC4::Regime()
{   return regime;
}
bool CombineC4::Croisement()
{   return croisement;
}
bool CombineC4::AntiBrouillard()
{   return antiBrouillard;
}
bool CombineC4::Route()
{   return route;
}
bool CombineC4::ClignoD()
{   return clignoD;
}
bool CombineC4::ClignoG()
{   return clignoG;
}
unsigned int CombineC4::ChaineHexaVersInt(char *chaineHexa, int nbCar)
{   int nombre=0,j;
	char caractere;
	for(j=0;j<nbCar;j++)
	{   caractere=chaineHexa[j];
		if(caractere>='0' && caractere<='9')
		{  nombre=nombre+((caractere-'0')<<(4*(nbCar-j-1)));
		}
		else nombre=nombre+((caractere-'A'+10)<<(4*(nbCar-j-1)));
	}
	return nombre;
}
void CombineC4::EnregistreDonneesCAN(char *idCAN, char *trameCAN)
{   if(!strcmp(idCAN,"0B6"))
	{	vitesse=ChaineHexaVersInt(trameCAN+23,2)*2.55;
		regime=ChaineHexaVersInt(trameCAN+19,2)*100/3.1;
	}
	else
	{   unsigned char octet=ChaineHexaVersInt(trameCAN+27,2);
		croisement=(bool)(octet&(0x01<<6));
		route=(bool)(octet&(0x01<<5));
		antiBrouillard=(bool)(octet&(0x01<<3));
		clignoD=(bool)(octet&(0x01<<2));
		clignoG=(bool)(octet&(0x01<<1));
	}

}
