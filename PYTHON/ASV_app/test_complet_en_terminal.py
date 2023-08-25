dico = {}
a = ''
b = ''
answer = ''
score = 0
mauvaise = 0
jeu = True
sortie = True
entre = True
initia = True
while jeu:
    def init(dico):
        while initia:
            a = input('''(mot en langue étrangère) -> ''')
            if a == 'terminé':
                break
            b = input('''(mot en francais) -> ''')
            if b == 'terminé':
                break
            dico[a] = b
            print()
    init(dico)

    def fra(score,sortie,mauvaise,dico):
        while sortie:
            for key, value in dico.items():
                astuce = 'traduisez {} :'.format(key)
                answer = input(astuce)
                if answer == 'terminé':
                    print('Votre score est de',score)
                    if mauvaise == 1:
                        print('Vous avez fait',mauvaise,'mauvaise réponse')
                    if mauvaise == 0:
                        print('''Vous n'avez fait aucune faute BRAVO''')
                    else:
                        print('Vous avez fait',mauvaise,'mauvaises réponses')
                        sortie = False
                        break
                if answer == value:
                    score += 1
                    print('BONNE REPONSE, score =',score)
                else:
                    score -= 1
                    mauvaise += 1
                    print('MAUVAISE REPONSE, score =',score)
                    print('La bonne réponse était ->',value)
                print()

    def other(score,entre,mauvaise,dico):
        while entre:
            for key, value in dico.items():
                astuce = 'traduisez {} :'.format(value)
                answer = input(astuce)
                if answer == 'terminé':
                    print('Votre score est de',score)
                    if mauvaise == 1:
                        print('Vous avez fait',mauvaise,'mauvaise réponse')
                    if mauvaise == 0:
                        print('''Vous n'avez fait aucune faute BRAVO''')
                    else:
                        print('Vous avez fait',mauvaise,'mauvaises réponses')
                        entre = False
                        break
                if answer == key:
                    score += 1
                    print('BONNE REPONSE, score =',score)
                else:
                    score -= 1
                    mauvaise += 1
                    print('MAUVAISE REPONSE, score =',score)
                    print('La bonne réponse était ->',key)
                print()

    def destin(dico):
        if choose == 'fra':
            fra(score,sortie,mauvaise,dico)
        if choose == 'other':
            other(score,entre,mauvaise,dico)
            
    menu = True
    while menu:
        choose = input('choisissez votre option (fra / other / quitter / sauv / aide) -> ')
        destin(dico)

        if choose == 'quitter':
            menu = False
            jeu = False

        if choose == 'sauv':
            sauv = dico
            sauvegarde = True
            while sauvegarde:
                sup = input('Voulez vous réinitialiser votre liste de vocabulaire (oui/non) :')
                if sup == 'oui' or sup == 'Oui':
                    dico = {}
                    init(dico)
                    choose = input('choisissez votre option (fra / other) -> ')
                    destin(dico)
                if sup == 'non' or sup == 'Non':
                    print(dico)
                    print(sauv)
                    if dico != sauv:
                        what_dic = input('Veux tu utiliser la nouvelle liste ou la sauvegarde (nouvelle/sauvegarde) :')
                        if what_dic == 'sauvegarde':
                            choose = input('choisissez votre option (fra / other) -> ')
                            destin(sauv)
                        else:
                            choose = input('choisissez votre option (fra / other) -> ')
                            destin(dico)
                if sup == 'quitter':
                    sauvegarde = False

        if choose == 'aide':
            print(''' Vous avez deux options différentes :
- la première (fra) vous permez de répondre en français aux questions de vocabulaires posées
- la seconde (other) vous permez de répondre dans la langue étrangère définie dans l'onglet initialisation
à des questions de vocabulaires posées en français''')


    
