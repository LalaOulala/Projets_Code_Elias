// Le prix du voyage
let price = 1499.0

// L'argent de Joe
var money = 0.0

// Le nombre de jours pendant lesquels Joe doit économiser
var numberOfDay = 0

// La grange de Joe : [lait, blé, laine]
var barn = ["milk":0, "weat":0, "wool":0]


while money < price
{
    // On passe au jour suivant
    numberOfDay += 1
    
    // Joe nourrit les vaches tous les jours
    money -= 4
    
    // On calcule la taille de la grange
    var barnSize = 0
    for (_,value) in barn
    {
        barnSize += value
        print("la taille de la grange est de \(barnSize) \n")
    }

    
    if let milk = barn["milk"], let weat = barn["weat"], let wool = barn["wool"]
    {
        print("milk : \(milk), weat : \(weat), wool : \(wool)")
        
        
        if barnSize >= 500
        {
            
            // On vend !
            money += Double(milk) * 0.50 // Le lait
            money += Double(weat) * 0.30 // Le blé
            money += Double(wool) * 1 // La laine
            // On vide la grange
            barn = ["milk":0, "weat":0, "wool":0]
        }
       
       
        else
        {
            // C'est une journée normale
            
            if numberOfDay % 30 == 1
            {
                // Joe moissonne
                barn["weat"] = weat + 100
//                print("test milk \(milk)")
            }
            
            else if numberOfDay % 30 == 10 || numberOfDay % 30 == 20
            {
                // Joe tond les moutons
                barn["wool"] = wool + 30
                print("test weat \(weat)")
            }
            
            else
            {
                // Joe trait les vaches
                barn["milk"] = milk + 30
                print("test wool \(wool)")
                
            }
            print(barn)
        }
    }
}
   
print("Il aura fallu \(numberOfDay) jours à Joe pour économiser \(money) €")
