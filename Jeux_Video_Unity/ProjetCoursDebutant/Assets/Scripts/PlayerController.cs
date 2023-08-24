using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    // initialisation de la vitesse. private => variable existant uniquement dans cette classe
    private float speed = 12.0f;

    // variable vitesse dans les virage (moins rapide que tout droit)
    private float turnSpeed = 25.0f;

    // variable pour recuperer la valeur d'horizontal Input et de vertical Input
    public float horizontalInput;
    public float verticalInput;


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        // recuperer la valeur de l'input horizontal et vertical
        horizontalInput = Input.GetAxis("Horizontal");
        verticalInput = Input.GetAxis("Vertical") + 1;

        /* 
        avancer vers l'avant
        transform => classe et Translate => methode
        Time.deltaTime => mesure le temps entre deux frames (actualisation)
        forward => correspond a (0,0,1), on avance selon z
        Vector3 => un vecteur en 3 dimensions (x,y,z)
        */
        transform.Translate(Vector3.forward * Time.deltaTime * speed * verticalInput);

        // deplacement dans les virages
        transform.Rotate(Vector3.up, Time.deltaTime * turnSpeed * horizontalInput);
    }
}