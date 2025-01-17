using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class birdScript : MonoBehaviour
{

    public Rigidbody2D myRigidbody;
    public logicScript logic;

    public float flapStrength;

    public bool birdIsAlive = true;

    // Start is called before the first frame update
    void Start()
    {
        logic = GameObject.FindGameObjectWithTag("Logic").GetComponent<logicScript>();
    }

    // Update is called once per frame
    void Update()
    {
        //"=" make both task similar.
        //"==" checks to see if the task is the same as the one on the right, if not, false.
        if (Input.GetKeyDown(KeyCode.Space) && birdIsAlive)
        {

            //}

            myRigidbody.velocity = Vector2.up * flapStrength;
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        logic.gameOver();
        birdIsAlive = false;
    }
}
