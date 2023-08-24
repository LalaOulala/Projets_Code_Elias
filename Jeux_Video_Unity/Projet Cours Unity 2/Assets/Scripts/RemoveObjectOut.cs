using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RemoveObjectOut : MonoBehaviour
{
    private float maxZ = 80.0f;
    private float minZ = -10.0f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (transform.position.z > maxZ) 
        {
            Destroy(gameObject);
        }

        if(transform.position.z < minZ)
        {
            Time.timeScale = 0f;
            Debug.Log("GAME OVER");
        }
    }
}
