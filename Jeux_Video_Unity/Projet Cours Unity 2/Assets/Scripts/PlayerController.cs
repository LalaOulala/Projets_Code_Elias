using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private float horizontalInput;
    private float speed = 36.0f;
    private float xRange = 20.0f;
    public GameObject applePrefab;
    public GameObject carotPrefab;
    public GameObject meetPrefab;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        horizontalInput = Input.GetAxis("Horizontal");
        transform.Translate(Vector3.right * Time.deltaTime * speed * horizontalInput);
        
        if (transform.position.x > xRange)
        {
            transform.position = new Vector3(xRange, 0, 0);
        }

        if (transform.position.x < -xRange)
        {
            transform.position = new Vector3(-xRange, 0, 0);
        }

        if (Input.GetKeyDown(KeyCode.W))
        {
            Instantiate(applePrefab, transform.position, transform.rotation);
        }

        else if (Input.GetKeyDown(KeyCode.X))
        {
            Instantiate(carotPrefab, transform.position, transform.rotation);
        }

        else if (Input.GetKeyDown(KeyCode.C))
        {
            Instantiate(meetPrefab, transform.position, transform.rotation);
        }
    }
}
