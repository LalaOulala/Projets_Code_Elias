import openai
openai.api_key = "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"

# suppression des retours à la ligne que rajoute l'IA avant sa réponse
def remove_return(string):
  return string.replace("\n", "")

# prise de notes sur un texte
def AI_notes(string):
  # create a completion
  user = "fait un résumé sous forme de liste pour une base de donnée :" + string

  completion = openai.Completion.create(
    model="text-davinci-003",
    prompt=user,
    temperature=1,
    max_tokens=1000,
    top_p=1.0,
    frequency_penalty=0.8,
    presence_penalty=0.0
  )

  # print the completion
  ai_text = completion.choices[0].text

  # création de la base de donnée
  ai_text = remove_return(ai_text)

  with open("AI_data.txt", "a") as resume:
    for liste in resume:
      if liste == "-": resume.write("")

# list engines
engines = openai.Engine.list()

# print the first engine's id
print(engines.data[0].id)

# C'est l'utilisateur qui parle
with open("texte.txt", "r") as data:
  user = data.read()

AI_notes(user_text)