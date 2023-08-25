import openai

openai.api_key = "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"
end = False


# suppression des retours à la ligne que rajoute l'IA avant sa réponse
def remove_return(string):
    return string.replace("\n", "")


# On sauvegarde le texte de l'utilisateur
def user_talk(file):
    user_text = input("Entrez votre mesaage : ")
    with open(file, "a") as data:
        data.write("User : {}\n".format(user_text))


# On sauvegarde ce que répond l'IA
def AI_talk(file):
    # create a completion
    with open(file) as data:
        user_text = data.read()

    completion = openai.Completion.create(
        model="text-davinci-003",
        prompt=user_text,
        temperature=1,
        max_tokens=1000,
        top_p=1.0,
        frequency_penalty=0.8,
        presence_penalty=0.0
    )

    # On enregistre la réponse de la completion
    ai_text = completion.choices[0].text

    # On met en forme le message
    ai_text = remove_return(ai_text)
    if "AI :" in ai_text: ai_text = ai_text[5:]

    # On enregistre la réponse dans le fichier pour la conversation
    with open(file, "a") as data:
        data.write("AI : {}\n".format(ai_text))
    print("IA : {}".format(ai_text))

    end = "au revoir" in ai_text
    if end == True:
        with open(file, "w") as data:
            data.write("")


# list engines
engines = openai.Engine.list()

# print the first engine's id
print(engines.data[0].id)

# La conversation
while end == False:
    user_talk("conv.txt")
    AI_talk("conv.txt")