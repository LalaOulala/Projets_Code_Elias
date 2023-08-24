using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ControlPlayer : MonoBehaviour
{
    public float verticalInput;
    public float horizontalInput;
    private float speed = 3.0f;
    public float wayVariation;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        // récupérer les valeurs des axes de déplacement
        verticalInput = Input.GetAxis("Vertical"); // première mesure
        horizontalInput = Input.GetAxis("Horizontal");

        /*
        avancer selon les boutons
        si le signe de verticalInput change (changement de direction)
            alors on fait tourner le joueur de 180 degrès sur lui-même.
        */

        transform.Translate(new Vector3(0,0,1) * Time.deltaTime * speed * verticalInput);

        wayVariation = verticalInput * Input.GetAxis("Vertical");

        if(wayVariation < 0)
        {
            transform.Rotate(new Vector3(0, 180, 0), Space.Self);
        }
    }
}
