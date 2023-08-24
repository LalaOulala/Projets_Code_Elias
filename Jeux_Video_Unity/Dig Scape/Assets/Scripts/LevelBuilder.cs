using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LevelBuilder : MonoBehaviour
{
    public GameObject ground;
    public GameObject special;
    private Transform map;
    private int nombre_bloc_x = 22;
    private int nombre_bloc_y = 22;
    private int nombre_bloc_z = 22;

    // pourcentage de blocs spéciaux
    private int pourcentage = 1;

    private int arraySize;

    public int compteurSpecial = 0;
    public int compteurTotal = 0;

    public Vector3[] specialArray;

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("Entrer dans le Start()");

        arraySize = Mathf.RoundToInt(pourcentage * nombre_bloc_x * nombre_bloc_y * nombre_bloc_z * 0.01f);

        // j'ai eut une erreur de non-static qui se règle qaund je défini la taille ici
        specialArray = new Vector3[arraySize];

        SpecialCoordonate(specialArray);
        MapBuilder();
        
    }

    void SpecialCoordonate(Vector3[] tab)
    {
        for(int s=0; s<arraySize; s++)
        {
            Debug.Log(s);
            Vector3 coord = new Vector3(Random.Range(0, nombre_bloc_x-1), Random.Range(0, nombre_bloc_y-1), Random.Range(0, nombre_bloc_z-1));
            
            if(!IsVectorInArray(tab, coord))
            {
                tab[s] = coord;
            }

            else
            {
                s--;
            }
        }

    }

    void MapBuilder()
    {
        // création du parent des objets Ground
        if(map == null)
        {
            map = new GameObject("Map").transform;
        }

        for(float z = 0f; z<nombre_bloc_z; z++)
        {
            // construction d'une ligne, 50 itérations
            for(float y = 0f; y<nombre_bloc_y; y++)
            {
                // construction d'un bloc
                for(float x = 0f; x<nombre_bloc_x; x++)
                {
                    Vector3 coordinate = new Vector3(x, y, z);

                    if(IsVectorInArray(specialArray, coordinate))
                    {
                        Debug.Log("Création d'un bloc SPECIAL.");
                        Instantiate(special, coordinate, ground.transform.rotation, map);
                        compteurSpecial ++;
                        compteurTotal ++;
                    }
                    else
                    {
                        //Debug.Log("Création d'un bloc.");
                        Instantiate(ground, coordinate, ground.transform.rotation, map);
                        compteurTotal ++;
                    }                
                    
                }
            }
        }
    }

    // Vérifie si le Vector3 "vector" est présent dans le tableau vectorArray.
    bool IsVectorInArray(Vector3[] array, Vector3 vector)
    {
        for (int i = 0; i < array.Length; i++)
        {
            if (array[i] == vector)
            {
                return true;
            }
        }
        return false;
    }
}
