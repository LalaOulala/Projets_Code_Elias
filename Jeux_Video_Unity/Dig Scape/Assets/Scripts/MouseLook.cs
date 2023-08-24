using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MouseLook : MonoBehaviour
{
    private float mouseSensitivity = 100f;

    public float mouseX;

    public float mouseY;

    // on crée une variable pouvant contenir de objet. Le défnir avec Transform permet d'utiliser la classe Transform avec cet objet
    // par exemple, Transform.Rotate pour faire tourner l'objet en question
    public Transform playerBody;

    // rotation de la caméra autour de l'axe des X
    public float xRotation = 0f;

    // valeur maximale et minimale pour le mouvement vertival de la caméra
    private float bound = 60.0f;

    // Start is called before the first frame update
    void Start()
    {
        // on bloque le curseur au centre de l'écran, effet indésirable : curseur invisible
        // il faudra rajouter une croix au centre de l'écran pour savoir où se trouve le curseur
        Cursor.lockState = CursorLockMode.Locked;
    }

    // Update is called once per frame
    void Update()
    {
        // on récupère les déplacements du curseur sur les axes X et Y
        mouseX = Input.GetAxis("Mouse X") * Time.deltaTime * mouseSensitivity;
        mouseY = Input.GetAxis("Mouse Y") * Time.deltaTime * mouseSensitivity;

        // on fait moins pour que ça tourne dans le bon sens et une incrémentation pour avoir un mouvement continu
        xRotation -= mouseY;
        xRotation = Mathf.Clamp(xRotation, -bound, bound);
        
        // on fait tourner le player sur lui même selon les déplcements du curseur selon l'axe X
        playerBody.Rotate(new Vector3(0,1,0) * mouseX);

        // on met à jour la rotation de l'objet caméra à la valeur xRotation sur l'axe des X
        transform.localRotation = Quaternion.Euler(xRotation, 0f, 0f);
    }
}
