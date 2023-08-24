using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnController : MonoBehaviour
{
    public GameObject[] animalsPrefabTab;
    public float totalTime = 0;
    public float lastInvokation = 0;
    private float coeffDifficulty = -0.07f;
    private float initialDelay = 6.0f;
    public double repeatInterval = 6.0f;    

    // Start is called before the first frame update
    void Start()
    {
        transform.position = new Vector3(-30.0f, 0, 40.0f);
        Debug.Log("repeatInterval dans le Start :" + repeatInterval.ToString());
    }

    // Update is called once per frame
    void Update()
    {
        totalTime = Time.time;

        if(totalTime - lastInvokation > repeatInterval)
        {
            AnimalsSpawn();
            lastInvokation = Time.time;

            if(repeatInterval < 1.0)
            {
                repeatInterval = 1.0;
            }
            else
            {
                repeatInterval = totalTime * coeffDifficulty + initialDelay;
            }
        }
    }

    void AnimalsSpawn()
    {
        int tabIndex = Random.Range(0, animalsPrefabTab.Length);
        float xRangeSpawn = 20.0f;
        Vector3 spawnPosition = new Vector3(Random.Range(-xRangeSpawn, xRangeSpawn) , 0f , 50.0f);
        Instantiate(animalsPrefabTab[tabIndex], spawnPosition, animalsPrefabTab[tabIndex].transform.rotation);
    }
}
