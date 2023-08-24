using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowPlayer : MonoBehaviour
{
    // creation d'un GameObject nomme player que notre camera devra suivre
    public GameObject player;

    // variable offset qui correspond a la position de camera voulu, relativement a player
    private Vector3 offset = new Vector3(0, 7.5f, -11);

    //creation de la la touche pour changer de camera
    public bool cameraInput;

    //controlleur appuis bouton
    public bool button = false;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void LateUpdate()
    {
        if(Input.GetKeyUp(KeyCode.Space))
        {
             button = !button;

             if (button)
             {
                offset = new Vector3(0, 2.2f, 1.1f);
             }

             if(!button)
             {
                offset = new Vector3(0, 7.5f, -11);
             }
        }
        //cameraInput = Input.GetKeyUp(KeyCode.Space);
/*         
        if (Input.GetKeyUp(KeyCode.Space) && button == false)
        {
            Debug.Log("1 - Passage en FirstPerson Camera\n");
            offset = new Vector3(0, 2.2f, 1.1f);
            button = true;
        }

        if (Input.GetKeyUp(KeyCode.Space) && button == true)
        {
            Debug.Log("2 - Passage en Main Camera\n");
            offset = new Vector3(0, 7.5f, -11);
            button = false;
        }
*/
        transform.position = player.transform.position + offset;
    }
}
