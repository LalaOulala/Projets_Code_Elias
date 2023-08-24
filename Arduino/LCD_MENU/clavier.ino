////***** Fonction de gestion du claviers. *****//

int clavier() {

  //Lecture de l'état des entrées de boutons.
  int entree = digitalRead(ENTREE);
  int haut = digitalRead(HAUT);
  int bas = digitalRead(BAS);


  //***** État des boutons.
  //Bouton ENTREE.
  if (entree == LOW) { //Si le bouton passe à l'état bas (LOW).
    valide++;          //Incrémentation des validations.
    delay(350);        //Temporisation de filtrage des appuis.
    return 1;          //Renvoie de la valeur 1 = Bouton "ENTREE" valide.
  }//if bouton ENTREE.

  //Bouton +.
  if (haut == LOW) {   //Si le bouton passe à l'état bas (LOW).
    delay(350);        //Temporisation de filtrage des appuis.
    plus_moins++;      //Incrémentation de la variable de paramétrage.
    return 2;          //Renvoie de la valeur 2 = Bouton "+" valide.
  }//if bouton +.

  //Bouton -.
  if (bas == LOW) {     //Si le bouton passe à l'état bas (LOW).
    delay(350);         //Temporisation de filtrage des appuis.
    plus_moins--;       //Décrémentation de la variable de paramétrage.
    return 3;           //Renvoie de la valeur 3 = Bouton "-" valide.
  }//if bouton -.

  //Sans action.
  return 0;             //Renvoie de la valeur 0 = Aucun boutons valide.

}//Fin de clavier().
