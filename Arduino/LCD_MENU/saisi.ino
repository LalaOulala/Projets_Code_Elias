int saisi(int mode, int saisi_centaine, int saisi_dizaine , int saisi_unite ) {

  //***** Variable locale.
  int val_out; //Variable de retour fonction => Activation des sorties.

  /*******************************************/
  /***** SANS LIMITATION DE VALEUR (999) *****/
  /*******************************************/

  //***** Saisi de la donnée. *****//
  if (mode == 0) {

    //***** Saisi de la donnée. ===> Limitatiopn de valeur.(255 pwm exemple)
    //Conditionnement de la saisi.
    //Ne peut pas être supérieur à 9.
    if (plus_moins > 9) { //Contrôle de la saisi.
      plus_moins = 0;
    }//if.
    //Ne peut pas être inferieur à 0.
    if (plus_moins < 0) { //Contrôle de la saisi.
      plus_moins = 9;
    }//if.
  }//if.mode no limite.

  /********************************/
  /***** LIMITATION DE VALEUR *****/
  /********************************/

  //***** Saisi de la donnée. *****//
  if (mode == 1) { //Contrôle du mode saisi choisi.

    //Première saisi la CENTAINE.
    if (valide == 0) {  //Contrôle de la validation.

      //Ne peut pas dépasser la valeur en parametre.
      if (plus_moins > saisi_centaine) {  //Contrôle si la selection est supperieur à la valeur de la centaine.
        plus_moins = 0;                   //Mise à zéro de la selection.
      }//if.
      //Ne peut pas dépasser la valeur de zéro (0).
      if (plus_moins < 0) {               //Contrôle si la selection est inférieur à zéro (0).
        centaine = plus_moins;            //Chargement de la valeur de la centaine parametré.
      }//if.
    }//if.valide.


    if (centaine == saisi_centaine * 100 ) {  //Contrôle de la saisi CENTAINE.

      //Seconde saisi LA DIZAINE.
      if (valide == 2) { //Contrôle de la validation.

        //Ne peut pas dépasser la valeur en parametre.
        if (plus_moins > saisi_dizaine) {  //Contrôle si la selection est supperieur à la valeur de la dizaine.
          plus_moins = 0;                  //Mise à zéro de la selection.
        }//if.

        if (plus_moins < 0) {         //Contrôle si la selection est inférieur à zéro.
          plus_moins = saisi_dizaine; //Chargement de la valeur de la dizainee parametré.
        }//if.
      }//if.

      //Troisième saisi L'UNITE.
      if (valide == 4) {  //Contrôle de la validation.

        if (dizaine == saisi_dizaine * 10 ) { //Conditionnement de la saisi de l'unité.

          //Ne peut pas dépasser la valeur en parametre.
          if (plus_moins > saisi_unite) {  //Contrôle si la selection est supperieur à la valeur de l'unité.
            plus_moins = 0;                //Mise à zéro de la selection.
          }//if.

          if (plus_moins < 0) {       //Contrôle si la selection est inférieur à zéro.
            plus_moins = saisi_unite; //Chargement de la valeur de l'unité parametré.
          }//if.
        }//if.
        else {

          //Ne peut pas être supérieur à 9.
          if (plus_moins > 9) { //Contrôle si la selection est supperieur à neuf (9).
            plus_moins = 0;     //Mise à zéro de la selection.
          }//if.
          //Ne peut pas être inferieur à 0.
          if (plus_moins < 0) { //Contrôle si la selection est inferrieur à zéro (0).
            plus_moins = 9;     //Chargement de la valeur neuf (9).
          }//if.
        }//else.
      }//if.valide
    }//if centaine.


    //Action par défaut.
    if (centaine <= saisi_centaine * 100 ) { //Contrôle si la saisi de la centaine est inferieur à

      //Ne peut pas être supérieur à 9.
      if (plus_moins > 9) { //Contrôle si la selection est supperieur à neuf (9).
        plus_moins = 0;     //Mise à zéro de la selection.
      }//if.
      //Ne peut pas être inferieur à 0.
      if (plus_moins < 0) { //Contrôle si la selection est inferrieur à zéro (0).
        plus_moins = 9;     //Chargement de la valeur neuf (9).
      }//if.
    }//if.
  }//if. mode 1 limitation.

  /***************************/
  /***** POURCENTAGE (%) *****/
  /***************************/

  //***** Saisi de la donnée. *****//
  if (mode == 2) {  //Contrôle du mode saisi choisi.

    //***** Traitement de la donnée. *****//
    //Ne peut pas dépasser 0 ou 100.

    //Action en positif. => Bouton PLUS +.
    if (plus_moins > 100) { //Contrôle si la selection est supperieur à zéro (0).
      plus_moins = 0;
    }//if.

    //Action en négatif. => Bouton MOINS -.
    if (plus_moins < 0) { //Contrôle si la selection est inferrieur à zéro (0).
      plus_moins = 100;
    }//if.
  }//if mode 2 pourcentage.

  //**********************************//
  //***** TRAITEMENT DE LA SAISI *****//
  //**********************************//

  //***** Saisi NUMERIQUE. *****//

  // Mode limitation ou libre.
  if (mode == 0 || mode == 1) { //Contrôle du mode de saisi.

    switch (valide) { //Selection de chiffre.

      //CENTAINE.
      case 1:                         //Validation de la troisième donnée = La centaine.
        centaine = (plus_moins * 100);//Calcul et chargement de la centaine.
        curseur++;                    //Incrémentation de la position du curseur.
        plus_moins = 0;               //Mise à zéro de la donnée selecté.
        Serial.print("CENTAINE: "); Serial.println(centaine);
        valide++;                     //Saut de selection.
        break;                        //Retour = Fin d'exécution.

      //DIZAINE.
      case 3:                         //Validation de la seconde donnée = La dizaine.
        dizaine = (plus_moins * 10);  //Calcul et chargement de la dizaine.
        curseur++;                    //Incrémentation de la position du curseur.
        plus_moins = 0;               //Mise à zéro de la donnée selecté.
        Serial.print("DIZAINE: "); Serial.println(dizaine);
        valide++;                     //Saut de selection.
        break;                        //Retour = Fin d'exécution.

      //UNITE.
      case 5:                         //Validation de la premère donnée = L'unité.
        unite  = plus_moins;          //Calcul et chargement de l'unité.
        curseur++;                    //Incrémentation de la position du curseur.
        plus_moins = 0;               //Mise à zéro de la donnée selecté.
        valide++;                     //Saut de selection.
        Serial.print("UNITE: "); Serial.println(unite);
        break;                        //Fin d'exécution.
    }//switch.

    if (valide == 6) {
      //RECONSTITUTION DE LA SAISI.
      val_out = unite + dizaine + centaine; //Reconstitution de la donnée par addition.
      val_donnee = val_out;                 //Chargement de la saisi reconstitué.
      Serial.print("RECONSTITUTION: "); Serial.println(val_donnee);
      return val_out;                       //Retour de fonction => Activation des sorties.
    }//if.
  }//if mode numérique.

  //***** Saisi POURCENTAGE. *****//

  if (mode == 2 && valide == 1) {//Contrôle du mode de saisi.
    val_donnee = plus_moins;            //Chargement de la saisi pour affichage.
    valide = 6;                         //Forçage de la validation.
    return val_out = plus_moins * 2.55; //Retour de fonction +> Conversion de saisi = Activation des sorties.
  }//if.
}//Fin de saisi().
