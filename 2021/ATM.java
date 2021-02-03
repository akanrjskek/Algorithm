package A202012;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ATM {
	private static int N;
	private static int temp;
	private static int answer;
	private static int[] people;
	private static int[] atm;
	public static void main(String[] args) throws Exception{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(bf.readLine());
		StringTokenizer st = new StringTokenizer(bf.readLine());
		people = new int[N+1];
		atm = new int[N+1];
		for(int i = 1; i <= N; ++i) {
			people[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(people);
		for (int i = 1; i <= N; i++) {
			temp = N - i + 1;
			answer += people[i] * temp;
		}
		System.out.println(answer);
		
	}

}
