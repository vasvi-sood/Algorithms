import java.util.ArrayList;
import java.util.Scanner;

public class Combitronics {
	 ArrayList<Integer> a;
	public Combitronics() {
		a=new ArrayList<Integer>();
	}
	
	void print(int i,ArrayList<Integer> b)
	{
		if(i==a.size()-1)
		{
			for(int j=0;j<b.size();j++)
				System.out.print(b.get(j)+" ");
			System.out.println();
			return;
		}
		ArrayList<Integer> n= new ArrayList<Integer>(b);
				n.add(a.get(i+1));
				print(i+1,n);
				print(i+1,b);
				

				
				
	}
	
public static void main(String[] args) {
	Scanner in=new Scanner(System.in);
	int n;
	
	n=in.nextInt();
	Combitronics obj= new Combitronics();
	obj.a.add(0);
	for (int i = 0; i <n; i++) {
		obj.a.add(in.nextInt());
}
	obj.print(0, new ArrayList<Integer>());
}
}
