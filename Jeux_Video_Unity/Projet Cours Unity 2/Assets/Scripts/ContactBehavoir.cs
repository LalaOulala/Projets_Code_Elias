using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ContactBehavoir : MonoBehaviour
{
    public int score = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log(score);
    }

    private void OnTriggerEnter(Collider other)
    {
        string mainObjectName = gameObject.name;
        string collideObjectName = other.gameObject.name;

        Debug.Log(mainObjectName);
        Debug.Log(collideObjectName);
        Debug.Log(string.Format(" "));

        if(mainObjectName == "Food_Renne(Clone)" && collideObjectName == "Renne(Clone)")
        {
            Destroy(gameObject);
            Destroy(other.gameObject);
            score += 1;
        }

        else if(mainObjectName == "Food_Renard(Clone)" && collideObjectName == "Renard(Clone)")
        {
            Destroy(gameObject);
            Destroy(other.gameObject);
            score += 1;
        }

        else if(mainObjectName == "Food_Vache(Clone)" && collideObjectName == "Vache(Clone)")
        {
            Destroy(gameObject);
            Destroy(other.gameObject);
            score += 1;
        }
    }
}
