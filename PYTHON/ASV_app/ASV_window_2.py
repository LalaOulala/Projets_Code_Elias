"""

Cette deuxième fenêtre sert a sélectionner l'option français ou bien langue étrangère.

"""


import tkinter
from tkinter import messagebox # pour les messages d'erreurs
import tkinter as tk
import tkinter.font as tkFont # pour les polices de caractères

window2 = tkinter.Tk() # création de la deuxième fenêtre du GUI ASV (Apprendre Son Vocabulaire)
window2.geometry("350x125") # même taille que pour la première fenêtre

select_button_nativ = tkinter.Button(window2, text="langue française") # bouton sélection langue française
select_button_stranger = tkinter.Button(window2, text="langue étrangère") # bouton sélection langue étrangère

# Lorsque je clique sur un bouton, la fonction correspondante est appelé
# La fonction correspondante exécute le test d'apprentissage de vocadulaire qui correspond
# Possibilité de laisser les fonctions sur cette file (donc la file va être longue)
# ou bien de créer une nouvelle file d'où je ferai des imports des fonctions qui m'interresse

select_button_nativ.pack()
select_button_stranger.pack()

window2.mainloop()
