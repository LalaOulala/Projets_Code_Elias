using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMouvement : MonoBehaviour
{
    private float x;

    private float z;

    public CharacterController controller;

    private float speed = 5.0f;

    // booléen vrai quand il y a une collision avec le sol
    public bool isGrounded = false;

    // vecteur de l'accélération (velocity)
    Vector3 velocity;

    // le mask du sol
    public LayerMask groundMask;

    // le Empty Object groundCheck
    public Transform groundCheck;

    void Start()
    {
        controller = GetComponent<CharacterController>();
    }
    // Update is called once per frame
    void Update()
    {
        // on prend les valeurs des touches Z,S,Q,D pour les déplacements
        x = Input.GetAxis("Horizontal");
        z = Input.GetAxis("Vertical");

        // vecteur de la direction du mouvement
        // transform.forward veut dire qu'on se déplace vers l'avant mais relativement à la rotation/direction du player
        Vector3 move = transform.right * x + transform.forward * z;

        // controller.Move permet de gérer plus facilement les collisions, on se déplace dans la direction indiquée par move, à la vitesse speed
        controller.Move(move * Time.deltaTime * speed);


        // IMPLÉMENTATION DE LA GRAVITÉ

        // calcul de l'accélération
        velocity.y = -0.2f;

        // on applique une force appelé velocity, qui déterminera la vitesse de la chute
        controller.Move(velocity);
    }
}
