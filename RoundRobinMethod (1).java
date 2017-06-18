import java.util.*;
class Process{
	int pn;	//process number
	int at;	//arival time
	int bt; //burst time
	int ct; //completion time - time when the process left the queue for last time
	int tat; //total turnaround time
	double wt;	//waiting time
	
	public Process(int p,int a,int b)
	{
		pn = p;
		at = a;
		bt = b;
		ct = 0;
		tat = 0;
		wt = 0.0;
	}
}
class RoundRobinMethod
	{
		public static int tq;
		public RoundRobinMethod(int t)
		{
			tq = t;
		}
		
		public static int findMin(int ar[])
		{
			int min = ar[0];
			int min_index = 0;
			for(int i = 1;i<ar.length;i++)
			{
				if(ar[i]<min)
				{
					min = ar[i];
					min_index = i;
				}
			}
			return min_index;
		}
		public static void main(String rgs[])
		{
			
			Scanner sc = new Scanner(System.in);
			System.out.println("enter time quantum");
			int tq = sc.nextInt();
			RoundRobinMethod rrm = new RoundRobinMethod(tq);
			System.out.println("enter no.of process");
			int n = sc.nextInt();
			int gat[] = new int[n];	//given arrival time
			int gbt[] = new int[n];	//given burst time
			for(int i = 0;i<n;i++)
			{
				System.out.println("Enter arival time :");
				gat[i] = sc.nextInt();
				System.out.println("Enter burst time :");
				gbt[i] = sc.nextInt();
			}
			System.out.println("input given");
		double twt = calculateTotalWaitingTime(gat,gbt);
		double awt = twt/n;
		System.out.println("total waiting time is:"+twt+"\nAvg waiting time is : "+awt);
		}
		public static double calculateTotalWaitingTime(int gat[],int gbt[])
		{
			Queue<Process> queue = new LinkedList<Process>();
			Process p[] = new Process[gat.length+1];
			for(int i = 0;i<gat.length;i++)
			{
				 p[i] = new Process(i,gat[i],gbt[i]);
			}
			int min_at = findMin(gat);
			int time = 0;
			queue.add(p[min_at]);
			while(!queue.isEmpty())
			{
				Process q = queue.remove();
				int pbt = q.bt;
				if(q.bt!=0){
					if(q.bt>=tq)	{q.bt = q.bt - tq; time = time + tq;}
					else	{time = time + q.bt; q.bt = 0;}
					if(pbt!=q.bt)
					q.ct = time;
					}
				
				//System.out.println(q.pn+" "+q.at+" "+q.bt+" "+q.ct+" "+time);
				for(int i = 0;i<gat.length;i++)
				{
					if(time>=p[i].at && i!=q.pn && p[i].bt!=0)
					{
						if(!queue.contains(p[i]))
						{
							queue.add(p[i]);
							//System.out.println("process added : "+i+" "+p[i].bt);
						}
					}
				}
				if(q.bt!=0)
				{
					queue.add(q);
					//System.out.println("Process add   : "+q.pn+" "+q.bt);
				}
					
			}
			double totalWT = 0.0;
			System.out.println("Waiting time");
			for(int i = 0;i<gbt.length;i++)
			{
				p[i].tat = p[i].ct - p[i].at;
				p[i].wt = p[i].tat - gbt[i];
				totalWT = totalWT + p[i].wt;
				//System.out.println(p[i].ct+" "+p[i].tat+" "+p[i].wt);
			}
			return totalWT;
				
		}
		
}
	
			

