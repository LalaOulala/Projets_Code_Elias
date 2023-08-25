print("Start app.py file\n")

from tkinter import *
from tkinter import ttk
import traductor
entryTraduction = ""
liste = ["Anglais", "Français", "Allemand", "Espagnol"]


#functions
def Traduction():
    print("Button pressed")
    entry = entrySaisie.get(1.0, "end")
    language = comboboxChoix.get()
    entrySaisie.delete(1.0, "end")
    textTraduit.delete(1.0, "end")
    entryTraduction = traductor.gptTraduction(entry, language)
    textTraduit.insert(1.0, entryTraduction)

def LanguagesList():
    with open("languages_list", "r") as file:
        contenu = file.read()
    language = ""
    languages_list = []

    for c in contenu:
        language += c
        if (c == ","):
            languages_list.append(language[1:len(language) - 1])
            language = ""

    return languages_list


# settings
window = Tk()
window.title("GPTraduction")
window.geometry("800x500")
window.minsize(400,250)
window.config(background="#405685") # idée de couleur pour les boutons et le texte : #C16868

#styles
"""
style = ttk.Style(window)
style.configure("frameSaisie.TFrame", bg= "#C16868")
style.configure("frameOutput.TFrame", bg="#405685")

frameSaisie = ttk.Frame(window, width=100, height=200, style="frameSaisie.TFrame")
frameOutput = ttk.Frame(window, width=20, height=20, style="frameOutput.TFrame")
"""

# widgets
frameSaisie = ttk.Frame(window)
frameOutput = ttk.Frame(window)
labelSaisie = Label(window, text="\nÉcrivez votre texte ci-dessous", font=("Georgia", 30), bg= "#405685", fg="#C16868")
labelOutput = Label(window, text="\nTraduction", font=("Georgia", 30), bg= "#405685", fg="#C16868")
entrySaisie = Text(window, font=("Georgia", 15), fg="#A7A7A7", width=50, height=7)
traductionButton = Button(window, text="Traduire", command=Traduction, bg="#405685")
textTraduit = Text(window, font=("Georgia", 20), fg="#C16868", width=50, height=7)
comboboxChoix = ttk.Combobox(window, values=LanguagesList())
comboboxChoix.current(0)


# affichage
"""
frameSaisie.pack()
frameOutput.pack()
"""
labelSaisie.pack()
entrySaisie.pack()
traductionButton.pack()
comboboxChoix.pack()
labelOutput.pack()
textTraduit.pack()

window.mainloop()
print("Fermeture de la fenêtre")