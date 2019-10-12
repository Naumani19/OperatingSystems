/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Sameer Naumani
 */
import java.util.Random;

public class Philosopher implements Runnable {
    	
	private Random rndNum = new Random();
	
	private int ids;
	
	private Semaphore lf;
	private Semaphore rf;
	
	public Philosopher(int id, Semaphore left, Semaphore right)
	{
		ids = id;
		lf = left;
		rf = right;
	}
	
    @Override
	public void run() 
	{
		try 
		{
			while(true)
			{
				think();
				takeLeftFork();
				takeRightFork();
				eat();
				dropRightFork();
				dropLeftFork();
			}
		} 
		catch (InterruptedException ex) 
		{
			System.out.println("Philosopher " + ids + " was interrupted.\n");
		}
	}
	
	private void think() throws InterruptedException
	{
		System.out.println("Philosopher " + ids + " is thinking.\n");
		System.out.flush();
		Thread.sleep(rndNum.nextInt(10));
	}
	
	private void takeLeftFork()
	{
		lf.up();
		System.out.println("Philosopher " + ids + " took the left fork but needs 1 more fork.\n");
		System.out.flush();
	}
	
	private void takeRightFork()
	{
		rf.up();
		System.out.println("Philosopher " + ids + " took the right fork has both forks.\n");
	}
	
	private void eat() throws InterruptedException
	{
		System.out.println("Philosopher " + ids + " is eating.\n");
		System.out.flush();
		Thread.sleep(rndNum.nextInt(10));
	}
	
	private void dropLeftFork() throws InterruptedException
	{
		lf.down();
	}
	
	private void dropRightFork() throws InterruptedException
	{
		rf.down();
	}
}
