//***** Gestion des fenêtres du menu. *****//
/*"fennetre" permet le verouillage de l'affichage.
  "activation" permet la selection de la fenêtre.*/

int menu(int activation) {

  //***** Variable locale.
  int ret_menu;

  //***** Retour à la lecture des données depuis validation de saisi.
  if (valide == 6 && fenetre == 13) { //Contrôle de la validation de saisi.

    fenetre = 0;  //Verrouillage de la fenêtre de lecture.
    action = 0;   //Mise à zéro des actions menu.
    valide = 0;   //Mise à zéro de la validation.
    curseur = 7;  //Mise à l'origine du curseur.
    lcd.clear();  //Effacement de l'affichage.
    delay(100);   //Temporisation d'action.
  }//if.

  /*******************************/
  /***** lecture des données *****/
  /*******************************/

  //***** Fenetre 0. = Lecture des données 1 et 2.
  if (fenetre == 0 && activation == 0 ) { //Contrôle de la fenêtre sélectionné.

    //***** LED_1.
    lcd.setCursor(0, 0);      //Positionnement du curseur.
    lcd.print("   LED_1 =");  //Affichage d'un message.
    lcd.setCursor(11, 0);     //Positionnement du curseur.
    lcd.print(charge_1);      //Affichage de la donnée.

    if (mode_saisi == 2) {  //Conditionnement de l'affichage.
      lcd.print("%  "); //Affichage de l'unité pourcentage.
    }//if.

    //***** LED_2.
    lcd.setCursor(0, 1);      //Positionnement du curseur.
    lcd.print("   LED_2 =");  //Affichage d'un message.
    lcd.setCursor(11, 1);     //Positionnement du curseur.
    lcd.print(charge_2);      //Affichage de la donnée.

    if (mode_saisi == 2) { //Conditionnement de l'affichage.
      lcd.print("%  "); //Affichage de l'unité pourcentage.
    }//if.

  }//if.

  //***** Fenetre 10. = Lecture des données 3 et 4.
  if (fenetre == 0 && activation == 2) { //Contrôle de la fenêtre sélectionné.

    //***** LED_3.
    lcd.clear();              //Effacement de l'affichage.
    lcd.setCursor(0, 0);      //Positionnement du curseur.
    lcd.print("   LED_3 =");  //Affichage d'un message.
    lcd.setCursor(11, 0);     //Positionnement du curseur.
    lcd.print(charge_3);      //Affichage de la donnée.

    if (mode_saisi == 2) {  //Conditionnement de l'affichage.
      lcd.print("%  "); //Affichage de l'unité pourcentage.
    }

    //***** LED_4.
    lcd.setCursor(0, 1);      //Positionnement du curseur.
    lcd.print("   LED_4 =");  //Affichage d'un message.
    lcd.setCursor(11, 1);     //Positionnement du curseur.
    lcd.print(charge_4);      //Affichage de la donnée.

    if (mode_saisi == 2) {  //Conditionnement de l'affichage.
      lcd.print("%  "); //Affichage de l'unité pourcentage.
    }//if.

    fenetre = 10;   //Verrouillage de la fenêtre de lecture 3-4.
    plus_moins = 0; //Mise à zéro de la selection.
  }//if.

  //***** Retour à la fenètre de lecture 1-2.
  if (fenetre == 10 && activation == 3) { //Contrôle de la fenêtre sélectionné.
    fenetre = 0;    //Verrouillage de la fenêtre de lecture 1-2.
    plus_moins = 0; //Mise à zéro de la selection.
    lcd.clear();    //Effacement de l'affichage.
  }//if.

  /********************************************/
  /***** Proposition de sélections des LED *****/
  /********************************************/

  //fenetre 1. = Proposition de sélections.
  if (fenetre == 0 && activation == 1 || fenetre == 10 && activation == 1 ) { //Contrôle de la fenêtre sélectionné.
    lcd.clear();                //Effacement de l'affichage.
    lcd.setCursor(0, 0);        //Positionnement du curseur.
    lcd.print("Selection LED"); //Affichage d'un message.
    lcd.setCursor(0, 1);        //Positionnement du curseur.
    lcd.print("    => +");      //Affichage d'un message.
    fenetre = 1;                //Verrouillage de la fenêtre.
    activation = 0;             //Mise à zero de l'activation.
    valide = 0;                 //Mise à zero de la validation.
    plus_moins = 0;             //Mise à zéro de la selection.
  }//if.

  //***** Retour à la fenêtre de lecture données 1 et 2. *****//
  if (fenetre == 1 && activation == 1) { //Contrôle de la fenêtre sélectionné.
    fenetre = 0;    //Verrouillage de la fenêtre.
    plus_moins = 0; //Mise à zéro de la selection.
    lcd.clear();    //Effacement de l'affichage.
  }//if.

  /*****************************/
  /***** Sélection des LED *****/
  /*****************************/

  //***** Entré dans le menu de selection *****//
  //Fenetre 11. => Selection de LED.
  if (fenetre == 1 && activation == 2) { //Contrôle de la fenêtre active.
    fenetre = 11;   //Verrouillage de la fenêtre.
    plus_moins = 1; //Mise à un de la selection => Envoie vers le premier choix de selection.
  }//if.

  //Affichage des propositions de sélection d'une LED.
  if (fenetre == 11) {  //Contrôle de la fenêtre active.

    switch (plus_moins) { //Contrôle du choix de selection.

      //Fenêtre 11.1 => Proposition de sélection LED_1.
      case 1:
        lcd.clear();              //Effacement de l'affichage.
        lcd.setCursor(0, 0);      //Positionnement du curseur.
        lcd.print("     LED_1");  //Affichage d'un message.
        plus_moins++;             //incrémentation de la selection. => Verrouillage du choix.
        break;                    //Fin d'execution.

      //Fenêtre 11.2 => Proposition de sélection LED_2.
      case 3:
        lcd.clear();              //Effacement de l'affichage.
        lcd.setCursor(0, 0);      //Positionnement du curseur.
        lcd.print("     LED_2");  //Affichage d'un message.
        plus_moins++;             //incrémentation de la selection. => Verrouillage du choix.
        break;                    //Fin d'execution.

      //Fenêtre 11.3 => Proposition de sélection LED_3.
      case 5:
        lcd.clear();              //Effacement de l'affichage.
        lcd.setCursor(0, 0);      //Positionnement du curseur.
        lcd.print("     LED_3");  //Affichage d'un message.
        plus_moins++;             //incrémentation de la selection. => Verrouillage du choix.
        break;                    //Fin d'execution.

      //Fenêtre 11.4 => Proposition de sélection LED_4.
      case 7:
        lcd.clear();              //Effacement de l'affichage.
        lcd.setCursor(0, 0);      //Positionnement du curseur.
        lcd.print("     LED_4");  //Affichage d'un message.
        plus_moins++;             //incrémentation de la selection. => Verrouillage du choix.
        break;                    //Fin d'execution.

      //Fenêtre 11.5 => Proposition de sélection RAZ.
      case 9:
        lcd.clear();              //Effacement de l'affichage.
        lcd.setCursor(0, 0);      //Positionnement du curseur.
        lcd.print("     RAZ ?");  //Affichage d'un message.
        plus_moins = 0;           //Mise à zéro de la selection. => Verrouillage du choix.
        break;                    //Fin d'execution.
    }//switch.
  }//if.

  //***** Valiadation du choix de LED.
  //fenetre 12X. => X = Choix de LED.
  if (fenetre == 11 && activation == 1) { //Contrôle de la fenêtre sélectionné.
    switch (plus_moins) { //Contrôle du choix de selection.

      case 2:
        fenetre = 121; //Verrouillage fenêtre LED_1.
        plus_moins = charge_1;  //Chargement de la valeur actuelle.
        break;                  //Fin d'execution.

      case 4:
        fenetre = 122; //Verrouillage fenêtre LED_2.
        plus_moins = charge_2;  //Chargement de la valeur actuelle.
        break;         //Fin d'execution.

      case 6:
        fenetre = 123; //Verrouillage fenêtre LED_3.
        plus_moins = charge_3;  //Chargement de la valeur actuelle.
        break;         //Fin d'execution.

      case 8:
        fenetre = 124; //Verrouillage fenêtre LED_4.
        plus_moins = charge_4;  //Chargement de la valeur actuelle.
        break;         //Fin d'execution.

      case 0:
        fenetre = 125; //Verrouillage fenêtre RAZ.
        break;         //Fin d'execution.

    }//switch.
    if (mode_saisi != 2) {
      plus_moins = 0;
    }
  }//if

  //Validation de la fenêtre de paramétrage.
  //fenêtre 12. => Paramètrage LED.

  switch (fenetre) { //Contrôle du choix de selection.

    case 121:
      ret_menu = 1; //Chargement de la variable de retour.
      break;        //Fin d'execution.

    case 122:
      ret_menu = 2; //Chargement de la variable de retour.
      break;        //Fin d'execution.

    case 123:
      ret_menu = 3; //Chargement de la variable de retour.
      break;        //Fin d'execution.

    case 124:
      ret_menu = 4; //Chargement de la variable de retour.
      break;        //Fin d'execution.

    case 125:
      ret_menu = 5; //Chargement de la variable de retour.
      break;        //Fin d'execution.
  }//switch.

  //***** Affichage de la fenêtre de saisi.
  if (fenetre == 121 || fenetre == 122 || fenetre == 123 || fenetre == 124) { //Contrôle de la fenêtre sélectionné.
    fenetre = 13;               //Verrouillage de la fenêtre de configuration.
    lcd.setCursor(0, 1);        //Positionnement du curseur.
    lcd.print("Valeur:");       //Affichage d'un message.
    lcd.setCursor(curseur, 1);  //Positionnement du curseur.
    lcd.print(plus_moins);      //Affichage de la valeur actuelle.
    valide = 0;                 //Mise à zero de la validation.
    return ret_menu;            //Retour de fonction = Validation de sélection.
  }//if.

  //*****Fenêtre de remis à zéro des données.(RAZ).*****//
  //Fenetre 14. => Fenetre de confirmation.
  if (fenetre == 125) { //Contrôle de la fenêtre sélectionné.
    fenetre = 14;                 //Verrouillage de la fenêtre de confirmation.
    lcd.setCursor(0, 0);          //Positionnement du curseur.
    lcd.print("Etes vous sur ?"); //Affichage d'un message.
    lcd.setCursor(0, 1);          //Positionnement du curseur.
    lcd.print("Oui+/Non- => ");   //Affichage d'un message.
    plus_moins = 0;               //Mise à zéro de la selection.
  }//if.

  //*****Selection du choix. OUI / NON.
  //Fenêtre 15.
  //OUI.
  if (fenetre == 14 && activation == 2 || fenetre == 16 && activation == 2) { //Contrôle de la fenêtre sélectionné.
    fenetre = 15;         //Verrouillage de la selection de OUI.
    lcd.setCursor(13, 1); //Positionnement du curseur.
    lcd.print("O");       //Affichage de la selection "O".
  }//if.

  //Fenêtre 16.
  //NON.
  if (fenetre == 14 && activation == 3 || fenetre == 15 && activation == 3) {//Contrôle de la fenêtre sélectionné.
    fenetre = 16;         //Verrouillage de la selection de NON.
    lcd.setCursor(13, 1); //Positionnement du curseur.
    lcd.print("N");       //Affichage de la selection "N".
  }//if.

  //*****Validation des choix OUI/NON.
  //Validation de OUI.
  if (fenetre == 15 && activation == 1) { //Contrôle de la fenêtre sélectionné.

    lcd.clear();                  //Effacement de l'affichage.
    lcd.setCursor(0, 0);          //Positionnement du curseur.
    lcd.print("!!RAZ VALEURS!!"); //Affichage d'un message.
    delay(1500);                  //Temporisation d'affichage.

    charge_1 = 0;                  //Mise à zéro de la donnée charge_1.
    analogWrite (VERT, charge_1);  //Activation de la led ROUGE.
    charge_2 = 0;                  //Mise à zéro de la donnée charge_2.
    analogWrite (ROUGE, charge_2); //Activation de la led VERT.
    charge_3 = 0;                  //Mise à zéro de la donnée charge_3.
    analogWrite (VERT, charge_3);  //Activation de la led ROUGE.
    charge_4 = 0;                  //Mise à zéro de la donnée charge_4.
    analogWrite (ROUGE, charge_4); //Activation de la led VERT.

    fenetre = 13; //Verrouillage transitoir de la fenêtre RAZ => Retour lecture.
    valide = 6;   //Forcage validation.
  }//if.

  //Validation de NON.
  if (fenetre == 16 && activation == 1) { //Contrôle de la fenêtre sélectionné.
    fenetre = 13; //Verrouillage transitoir de la fenêtre RAZ => Retour lecture.
    valide = 6;   //Forcage validation.
  }//if.

  if (fenetre == 0) { //Contrôle de l'état du menu.
    return 0; //Retour de fonction si en mode lecture.
  }//if

}//Fin de menu().

