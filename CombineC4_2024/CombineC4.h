//---------------------------------------------------------------------------

#ifndef CombineC4H
#define CombineC4H
//---------------------------------------------------------------------------
class CombineC4
{   private :
		char trameCAN[50];
		char idCAN[10];
		int vitesse;
		int regime;
		bool croisement,antiBrouillard,route,clignoD,clignoG;
	public :
		CombineC4();
		unsigned int ChaineHexaVersInt(char *chaineHexa, int nbCar);
		void EnregistreDonneesCAN(char *idCAN, char *trameCAN);
		int Vitesse();
		int Regime();
		bool Croisement();
		bool AntiBrouillard();
		bool Route();
		bool ClignoD();
		bool ClignoG();

};
#endif
