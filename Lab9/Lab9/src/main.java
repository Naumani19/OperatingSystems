/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Sameer Naumani
 */
public class main {
    
    private static final int p_Num = 5;

    public static void main(String[] args) {

        Semaphore[] forks = new Semaphore[p_Num];
		
	for(int i = 0; i < p_Num; i++)
	{
		forks[i] = new Semaphore(0);
	}
	
	Philosopher[] philosophers = new Philosopher[p_Num];
	
	for(int i = 0; i < p_Num; i++)
	{
		philosophers[i] = new Philosopher(i, forks[i], forks[(i+1) % p_Num]);
		new Thread(philosophers[i]).start();
	}
    }
    
}


