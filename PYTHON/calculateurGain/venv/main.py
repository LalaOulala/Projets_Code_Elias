année_simulation = 3
def salaire_CR(année_simulation):
    gain = 1771
    for i in range(année_simulation):
        if année_simulation <= 3 : gain = gain + 1771
        elif année_simulation > 3 and année_simulation <= 5 : gain = gain + 1887
        elif année_simulation > 5 and année_simulation <= 10 : gain = gain + 2058
        else : gain = gain + 2317
    return gain

def salaire_DRH(année_simulation):
    gain = 0
    for i in range(année_simulation):
        if année_simulation <= 3 : gain = gain + 2452
        elif année_simulation > 3 and année_simulation <= 5 : gain = gain + 2653
        elif année_simulation > 5 and année_simulation <= 10 : gain = gain + 2846
        else : gain = gain + 3131
    return gain

print("POUR CHARGÉ DE RECRUTEMENT : \nSur une période de {} ans, le cumul des gains est de : {} €".format(année_simulation, salaire_CR(année_simulation)))
print("POUR DIRECTEUR RESSOURCES HUMAINES : \nSur une période de {} ans, le cumul des gains est de : {} €".format(année_simulation, salaire_DRH(année_simulation)))
