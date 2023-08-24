//////////////////////////////////////////////////////
//////////////////// DECLARATIONS ////////////////////
//////////////////////////////////////////////////////

//***** Bibliothèques.
#include <LiquidCrystal.h> //Gestion de l'afficheur LCD

//***** Déclaration des variables.
//LCD.
#define RS 12 //Broche de syncronisation.
#define E  11 //Broche d'activation de transmission donées
#define D4 5  //Broche de donnée.
#define D5 4  //Broche de donnée.
#define D6 3  //Broche de donnée.
#define D7 2  //Broche de donnée.

//BOUTONS POUSSOIR.
#define ENTREE 6 //Broche Bouton.
#define HAUT 7   //Broche Bouton.
#define BAS 8    //Broche Bouton.

//LED.
#define ROUGE 10 //Broche Led ROUGE.
#define VERT 9   //Broche Led VERTE.

//***** Variables globales du programme *****//
int unite;          //Chargement de la valeur de l'unité.
int dizaine;        //Chargement de la valeur de la dizaine.
int centaine;       //Chargement de la valeur de la centaine.
int val_donnee = 0; //Chargement de la valeur complète.
int charge_1 = 0;   //Chargement de la valeur dans.
int charge_2 = 0;   //Chargement de la valeur dans.
int charge_3 = 0;   //Chargement de la valeur dans.
int charge_4 = 0;   //Chargement de la valeur dans.
int curseur = 7;    //Positionnement du curseur.

//***** Variables globales de clavier(). *****//
int plus_moins; //Variable de sélection.
int valide;     //Variable de validation.

//***** Variables globales de menu(). *****//
int fenetre = 0;      //Variable de verrouillage fenêtre.
int action = 0;       //Variable de retour clavier().
int action_menu = 0;  //Variable de retour menu().

//***** Variables globales => saisi(). *****//
/*Selection du modede saisi.
  mode_saisi = W;
  W = 0 => Valeur NUMERIQUE NON LIMITE. ==> 999.
  W = 1 => Valeur NUMERIQUE LIMITE.     ==> X,Y,Z.
  W = 2 => Valeur en POURCENTAGE.       ==> %. */
int mode_saisi = 0; //Variable de paramétrage de saisi().

//Instanciation LCD.
LiquidCrystal lcd (RS, E, D4, D5, D6, D7); //Paramétrage de la classe.

//////////////////////////////////////////////////////
////// CONFIGURATIONS,INTIALISATIONS ET TEST /////////
//////////////////////////////////////////////////////

void setup() {
  /****************************/
  /****** CONFIGURATIONS ******/
  /****************************/

  //Moniteur série.
  Serial.begin(9600); //Configuration du moniteur série.

  //LCD.
  lcd.begin(16, 2);   //Configuration LCD.

  //Entrée
  pinMode (ENTREE, INPUT_PULLUP); //Configuration de broche en entrée.
  pinMode (HAUT, INPUT_PULLUP);   //            //
  pinMode (BAS, INPUT_PULLUP);    //Configuration de broche en entrée.

  //Sortie
  pinMode (ROUGE, OUTPUT); //Configuration de broche en sortie.
  pinMode (VERT, OUTPUT);  //Configuration de broche en sortie.

  /**************************/
  /***** Initialisation *****/
  /**************************/

  //Activation du mode de saisi.
  saisi(mode_saisi, 0, 0, 0); //Execution de saisi().

  /*****************/
  /****** TEST *****/
  /*****************/

  //Moniteur série.
  Serial.println("***** Moniteur pret *****");  //Affichage d'un message.
  Serial.println();                             //Saut de ligne.

  //LED.
  digitalWrite(ROUGE, HIGH);//Allumage.
  digitalWrite(VERT, HIGH); //Allumage.
  delay(2000);              //Temporisation.
  digitalWrite(ROUGE, LOW); //Extinction.
  digitalWrite(VERT, LOW);  //Extinction.
  delay(800);               //Temporisation.

  //LCD.
  lcd.print("****BONJOUR****"); //Affichage d'un message.
  lcd.setCursor(0, 1);          //Positionnment du curseur.
  lcd.print("**Projet pret**"); //Affichage d'un message.
  delay(500);                   //Temporisation.
  lcd.clear();                  //Effacement de l'afficheur.
  delay(80);                    //Temporisation.*/

}//Fin de setup().

//////////////////////////////////////////////////////
///////////// PROGRAMME PRINCIPALE ///////////////////
//////////////////////////////////////////////////////

void loop() {

  //***** Lecture de l'état des boutons *****//
  action = clavier(); //Execution de clavier().

  //***** Selection des fenêtres du menu. *****//
  action_menu = menu(action); //Execution de menu(x).

  //***** Saisi de la donnée. *****//
  if (action_menu != 0 && action_menu < 5 ) { //Contrôle de l'activation de la saisi.

    int ret_val_led = saisi(mode_saisi, 2, 5, 5); //Parametrage et éxecution de saisi().

    //***** Affichage de la saisi. => Actualisation. *****//
    lcd.setCursor(curseur, 1);  //Positionnement du curseur.
    lcd.print(plus_moins);      //Affichage de la valeur actuelle.

    if (mode_saisi == 2) {  //Conditionnement de l'unité d'affichage.
      lcd.print("%  "); //Affichage de l'unité pourcentage.
    }//if.

    //***** Affectation des données. *****//
    if (valide == 6) { //Contrôle de la validation.

      switch (action_menu) { //Selection de LED.

        case 1:
          charge_1 = val_donnee;            //Chargement de la donnée dans charge_1.
          analogWrite (ROUGE, ret_val_led); //Activation de la LED ROUGE.
          break;                            //Fin d'execution.

        case 2:
          charge_2 = val_donnee;           //Chargement de la donnée dans charge_2.
          analogWrite (VERT, ret_val_led); //Activation de la LED VERT.
          break;                           //Fin d'execution.

        case 3:
          charge_3 = val_donnee;            //Chargement de la donnée dans charge_3.
          analogWrite (ROUGE, ret_val_led); //Activation de la LED ROUGE.
          break;                            //Fin d'execution.

        case 4:
          charge_4 = val_donnee;           //Chargement de la donnée dans charge_4.
          analogWrite (VERT, ret_val_led); //Activation de la LED VERT.
          break;                           //Fin d'execution.
      }//switch.

      //Affichage au moniteur série des données finale => A activer dans le setup().
      Serial.print("val_donnee: "); Serial.println(val_donnee);
      Serial.print("ret_val_led: "); Serial.println(ret_val_led);
    }//if.valide
  }//if.fenetre

  action_menu = 0;  //Mise à zéro des actions menu.
}//Fin de loop().
