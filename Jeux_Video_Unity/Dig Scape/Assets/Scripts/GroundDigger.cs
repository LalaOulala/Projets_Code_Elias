using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GroundDigger : MonoBehaviour
{
    Camera cam;
    public Vector3 mousePosition;

    public float totalTime = 0f;
    public float lastDigging = 0f;
    private float repeatInterval = 0.5f;

    public bool hitType;

    public GameObject Special;

    // Start is called before the first frame update
    void Start()
    {
        // Permet d'accéder au propriété de la caméra attaché à notre objet.
        // Ici, l'objet est la caméra elle-même.
        // Utile pour le ScreenPointToray car celui-ci utlise les propriétés intrinsèques à la caméra 3d (expliqué dans la documentation).
        cam = GetComponent<Camera>();
    }

    // Update is called once per frame
    void Update()
    {
        totalTime = Time.time;

        if(totalTime - lastDigging > repeatInterval && Input.GetMouseButtonDown(0))
        {
            Digger();
            lastDigging = Time.time;
        }     
    }

    // fonction permettant de détruire un cube (creuser) qaund celui-ci est cliqué par la souris.
    public void Digger()
    {
        mousePosition = Input.mousePosition;
        RaycastHit hit;

        // Déclaration du raycast qu'on va utiliser pour savoir où la souris a cliqué.
        // ScreenPointToRay sert a prendre un espace selon 2 axes (et non 3) car mousePosition est selon x et y seulement.
        Ray ray = cam.ScreenPointToRay(mousePosition);
        //Debug.DrawRay(ray.origin, ray.direction * 10, Color.red);

        // On vérifie que le clique gauche de la souris a été presser.
        if (Input.GetMouseButtonDown(0))
        {
            // la variable hit, de type RaycastHit sert a stocké l'objet entré en contact avec le Raycast.
            if(Physics.Raycast(ray, out hit, 3.0f /*distance maximale du raycast*/))
            {
                if (hit.transform.CompareTag("SpecialTag"))
                {
                    hitType = true;
                }

                else
                {
                    hitType = false;
                }

                Destroy(hit.transform.gameObject);                
            }
        }
    }
}