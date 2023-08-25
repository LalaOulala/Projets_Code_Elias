import tkinter
from tkinter import messagebox # pour les messages d'erreurs
import tkinter as tk
import tkinter.font as tkFont # pour les polices de caractères
import os, sys

window1 = tkinter.Tk() # création de la fenêtre (name=window1)
window1.geometry("600x400") # taille de la fenêtre
window1.title("Apprendre Son Vocabulaire") # titre de la fenêtre
dico={} # création d'un dico
dico_reverse={} # le dico à l'envers
dico_final={} # le dico final
list_special_caracters = ["0","1","2","3","4","5","6","7","8","9","@","$","%","&","*","!","?","~","`","=","_"] # liste des caractères qui déclenche une erreur

def input_display(*args): # c'est une fonction observeur, cette fonction sert a afficher le texte saisi en direct
    label_word_nativ_var.set("mot français : {}".format(nativ_word_var.get())) # set pour modifier et get pour récupérer
    label_word_stranger_var.set("mot étranger : {}".format(stranger_word_var.get())) # get pour afficher


def append_list():
    passing_marker = False # un marqueur de passage pour détecteur les erreurs 
    if nativ_word_var.get() == "": # si le mot français n'est pas entré il y a une erreur, le marqueur de passage passe a True
        messagebox.showerror("Erreur", "La zone de saisi est vide !")
        passing_marker = True
    elif stranger_word_var.get() == "": # si le mot étranger n'est pas entré il y a une erreur, le marqueur de passage passe a True
        messagebox.showerror("Erreur", "La zone de saisi est vide !")
        passing_marker = True
        
    for caracter in nativ_word_var.get():
        for error in list_special_caracters:
            if caracter == error: # si le mot français contient un caractère interdit il y a une erreur et le marqueur de passage passe a True
                nativ_word.config(bg="red")
                #nativ_word.delete(0,"end")
                messagebox.showerror("Erreur", "Attention : caractere invalide !")
                passing_marker = True
                
        

    for caracter in stranger_word_var.get():
        for error in list_special_caracters:
            if caracter == error: # si le mot étranger contient un caractère interdit il y a une erreur et le marqueur de passage passe a True
                stranger_word.config(bg="red")
                #stranger_word.delete(0,"end")
                messagebox.showerror("Erreur", "Attention : caractere invalide !")
                passing_marker = True
                
                
    if passing_marker == False: # si il n'y a pas d'erreur 
        nativ_word.config(bg="white") # le background reste blanc (bg=background)
        stranger_word.config(bg="white")
        dico[nativ_word_var.get()]=stranger_word_var.get() # le dico prend le mot français en clé et la traduction en valeur
        nativ_word.delete(0,"end") # on supprime le texte saisi en entier (de 0 à la fin "end")
        stranger_word.delete(0,"end")
 

def finish_step1():
    for key, value in dico.items():
        dico[key]=value
    for key_reverse, value_reverse in dico.items():
        dico_reverse[value_reverse]=key_reverse
    for value_final, key_final in dico_reverse.items():
        dico_final[key_final]=value_final
    window1.destroy()


Font_base = tkFont.Font(size=50)
label_title = tkinter.Label(window1, text="Entrer le vocabulaire", font=Font_base,) # on précise la taille du texte affiché

label_word_nativ_var = tkinter.StringVar() # mémorisation de la chaine de carectère entrée 
label_word_nativ = tkinter.Label(window1, textvariable=label_word_nativ_var) # affichage du mot français

label_word_stranger_var = tkinter.StringVar()
label_word_stranger = tkinter.Label(window1, textvariable=label_word_stranger_var) # affichage du mot étranger

nativ_word_var = tkinter.StringVar() # création de la variable qui contiendra le texte saisi
nativ_word_var.trace("w", input_display) # lorsque nativ_word_var est modifié (w), on appelle la fonction observeur (input_display)
nativ_word = tkinter.Entry(window1, textvariable=nativ_word_var, width=30) # le textvariable sert ici a récuper le texte saisi dans une variable

# même chose que pour le mot nativ
stranger_word_var = tkinter.StringVar()
stranger_word_var.trace("w", input_display)
stranger_word = tkinter.Entry(window1, textvariable=stranger_word_var, width=30)

append_list_button = tkinter.Button(window1, text="OK", command=append_list) # bouton d'ajout à la liste

finish_step1_button = tkinter.Button(window1, text="Terminer", command=finish_step1) # bouton mettant fin à la phase de saisi

# Affichage Simple
label_title.pack()
nativ_word.pack()
stranger_word.pack()
label_word_nativ.pack()
label_word_stranger.pack()
append_list_button.pack()                                                 
finish_step1_button.pack()        

# Affichage Complexe (à terminer)
'''
label_title.place(x=250,y=0)
nativ_word.place(x=90,y=183)
stranger_word.place(x=(1000-(90+30)),y=650-(650-183))
label_word_nativ.place(y=0,x=0)
label_word_stranger.place(y=0,x=0)
append_list_button.place(y=0,x=0)
finish_step1_button.place(y=0,x=0)
'''

# Fin de la boucle pour la fenêtre 1 
window1.mainloop()