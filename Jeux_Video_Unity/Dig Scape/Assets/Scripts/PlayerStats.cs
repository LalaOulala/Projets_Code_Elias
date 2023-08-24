using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerStats : MonoBehaviour
{

    [SerializeField] private float currentHealth;
    
    [SerializeField] private float maxHealth = 100f;

    [SerializeField] private Image healthBar;

    [SerializeField] private float totalTime = 0f;
    [SerializeField] private float loopTime = 0f;
    [SerializeField] private float repeatInterval = 5f;

    [SerializeField] GroundDigger hitObject;

    public GameObject gameOverScreen;

    // Start is called before the first frame update
    void Start()
    {
        currentHealth = maxHealth;
    }

    // Update is called once per frame
    void Update()
    {
        bool ressourceCollect = hitObject.hitType;

        totalTime = Time.time;

        if(totalTime - loopTime > repeatInterval)
        {
            TakeDamage(5f);
            loopTime = Time.time;
        }

        if(currentHealth < 0f)
        {
            Time.timeScale = 0f;
            gameOverScreen.SetActive(true);
            Debug.Log("GAME OVER");
        }

        if(ressourceCollect)
        {
            RegenerateLife();
        }

    }

    void RegenerateLife()
    {
        currentHealth = maxHealth;
        UpdateBarFill();
    }

    void TakeDamage(float damage)
    {
        currentHealth -= damage;
        UpdateBarFill();
    }

    void UpdateBarFill()
    {
        healthBar.fillAmount = currentHealth / maxHealth;
    }
}
