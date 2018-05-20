import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int v[]=new int[n];

		for(int i=0; i<n; i++){
			v[i]=scan.nextInt();
		}
	
		long max=v[0];
		for(int i=1; i<n; i++){
			if(v[i-1]>0 && v[i-1]+v[i]>0){v[i]=v[i-1]+v[i];}
			if(v[i]>max) max=v[i];
		}

		System.out.println(max);
	}
}
